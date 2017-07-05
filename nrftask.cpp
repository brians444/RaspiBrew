#include "nrftask.h"
//
// Hardware configuration
// Configure the appropriate pins for your connections

/****************** Raspberry Pi ***********************/

// Radio CE Pin, CSN Pin, SPI Speed
// See http://www.airspayce.com/mikem/bcm2835/group__constants.html#ga63c029bd6500167152db4e57736d0939 and the related enumerations for pin information.

// Setup for GPIO 22 CE and CE0 CSN with SPI Speed @ 4Mhz
//RF24 radio(RPI_V2_GPIO_P1_22, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_4MHZ);

// NEW: Setup for RPi B+
#ifdef LINUX
RF24 radio(RPI_BPLUS_GPIO_J8_15,RPI_BPLUS_GPIO_J8_24, BCM2835_SPI_SPEED_8MHZ);
#endif
// Setup for GPIO 15 CE and CE0 CSN with SPI Speed @ 8Mhz
//RF24 radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);

// RPi generic:
//RF24 radio(22,0);

/*** RPi Alternate ***/
//Note: Specify SPI BUS 0 or 1 instead of CS pin number.
// See http://tmrh20.github.io/RF24/RPi.html for more information on usage

//RPi Alternate, with MRAA
//RF24 radio(15,0);

//RPi Alternate, with SPIDEV - Note: Edit RF24/arch/BBB/spi.cpp and  set 'this->device = "/dev/spidev0.0";;' or as listed in /dev
//RF24 radio(22,0);


/****************** Linux (BBB,x86,etc) ***********************/

// See http://tmrh20.github.io/RF24/pages.html for more information on usage
// See http://iotdk.intel.com/docs/master/mraa/ for more information on MRAA
// See https://www.kernel.org/doc/Documentation/spi/spidev for more information on SPIDEV

// Setup for ARM(Linux) devices like BBB using spidev (default is "/dev/spidev1.0" )
//RF24 radio(115,0);

//BBB Alternate, with mraa
// CE pin = (Header P9, Pin 13) = 59 = 13 + 46
//Note: Specify SPI BUS 0 or 1 instead of CS pin number.
//RF24 radio(59,0);




nRFTask::nRFTask()
{
    qRegisterMetaType<sensores>("sensores");
    qRegisterMetaType<conf>("conf");
    qRegisterMetaType<target>("target");

    /********** User Config *********/
    // Assign a unique identifier for this node, 0 or 1
    radioNumber = 1;
    // Radio pipe addresses for the 2 nodes to communicate.
    pipes[0] = 0xF0F0F0F0E1LL;
    pipes[1] = 0xF0F0F0F0D2LL;       // Pipe 0 Writing - Pipe 1 Reading
    estado = WAIT_START;

    #ifdef LINUX
    radioInit();
    #endif

    var = 0;

    for(int i = 0; i < CANT; i++)
    {
        obj.set_temp[i] = 0.0;
    }

    // Inicio Variables
    get_target_status = 0;
    get_config_status = 0;
    set_target_status = 0;
    set_config_status = 0;

}


void nRFTask::Leer(long cmd)
{
    #ifndef LINUX
    SimuloRecepcion(cmd, estado);
    #endif
    #ifdef LINUX
    if(estado == WAIT_START)
    {
        WaitingInit(cmd);
    }
    else if(estado == WAITING_RESPONSE)
    {
        WaitingResponse(cmd);
    }
    else if(estado == END_TRANSMISSION)
    {
        estado = WAIT_START;
        var++;
    }
#endif

}

void nRFTask::WaitingResponse(long cmd)
{
#ifdef LINUX
    if(radio.available())
    {
        long len = radio.getPayloadSize();
        if(cmd == GET_TEMPS)
        {
            qDebug() << "Waiting response - cmd GET TEMPS";
            radio.read(&sens, sizeof(sens));
            qDebug()<<"Longitud leida = %i "<< len;
            for(int i = 0; i < CANT; i++)
            {
                qDebug()<<"Temperatura["<<i<<"] = "<<sens.temp[i];
            }
            emit TempGetReady(sens);
            estado = END_TRANSMISSION;
            this->sleep(2); //Delay after payload responded to, minimize RPi CPU time
        }
        else if(cmd == GET_TARGET)
        {
            qDebug() << "Waiting response - cmd GET TARGET";
            if( (get_target_status &0x01) == 0x01)
            {
                radio.read(&st_target, sizeof(st_target));
                qDebug()<< "Longitud leida = "<< len <<" - COMANDO ="<<(char)cmd;
                for(int i = 0; i < CANT; i++)
                {
                    qDebug()<<"Temperatura objetivo["<<i<<"] = "<<st_target.set_temp[i];
                }
                emit TargetGetReady(st_target);
                get_target_status = 0;
                estado = END_TRANSMISSION;
            }
            else
            {
                estado = END_TRANSMISSION;
            }
            this->sleep(2); //Delay after payload responded to, minimize RPi CPU time
        }
        else if(GET_CONFIG)
        {
            qDebug() << "Waiting response - cmd GET CONFIG";
            if( (get_config_status&0x01) == 0x01)
            {

                radio.read(&configuracion, sizeof(configuracion));
                showConf(configuracion, len);
                if(configuracion.cte1 == 0xF0 && configuracion.cte4 == 0x0F && configuracion.cte3 == 0x11 && configuracion.cte2 == 0x99)
                {
                    emit ConfigGetReady(configuracion);
                    estado = END_TRANSMISSION;
                    get_config_status = 0;
                }
                else
                {
                    estado = WAIT_START;
                }
            }
            else
            {
                estado = END_TRANSMISSION;
            }
            this->sleep(2); //Delay after payload responded to, minimize RPi CPU time
        }
    }
#endif
}

void nRFTask::WaitingInit(long cmd)
{
    #ifdef LINUX
    qDebug() << "WAITING INIT - cmd ="<< (char)cmd;
    if(cmd == GET_CONFIG && get_config_status != 0x01)
    {
        estado = END_TRANSMISSION;
    }
    else if(cmd == GET_TARGET && get_target_status != 0x01)
    {
        estado = END_TRANSMISSION;
    }
    else
    {
        qDebug()<<"Transmitiendo comando cmd = "<<(char)cmd;
        // First, stop listening so we can talk.
        radio.stopListening();
        radio.flush_tx();
        sleep(5);
        radio.writeFast(&cmd, sizeof(cmd));
        bool ok = radio.txStandBy(1000);
        radio.startListening();
        if(ok)
        {
            qDebug()<<"Transmision comando ok\n";
            estado = WAITING_RESPONSE;
            this->msleep(100);
        }
        else
        {
            qDebug()<<"Transmision comando failed \n";
            estado = WAIT_START;
            radio.flush_tx();
        }
    }
#endif
}



void nRFTask::run()
{

    while(1)
    {
        if(var == 0)
        {
            Leer(GET_CONFIG);
        }
        else if(var == 1)
        {
            Leer(GET_TEMPS);
        }
        else if(var == 2)
        {
            Leer(GET_TARGET);
        }
        else if(var==3 && set_target_status == 0x01)
        {
            EnviarTarget(obj);
        }
        else if(var ==4 && set_config_status == 0x01)
        {
            EnviarConfig(updatedConf);
        }
        else
        {
            var = 0;
        }
    }
}


void nRFTask::radioInit()
{
  #ifdef LINUX
  // Setup and configure rf radio
  radio.begin();
  radio.setDataRate(RF24_1MBPS);
  // optionally, increase the delay between retries & # of retries
  radio.setRetries(15,15);
  // Dump the configuration of the rf unit for debugging
  radio.printDetails();

  // This simple sketch opens two pipes for these two nodes to communicate
  // back and forth.
  radio.openWritingPipe(pipes[1]); // Write to device address 'SimpleNode'
  radio.openReadingPipe(1, pipes[0]); // Write to device address 'SimpleNode'
  radio.startListening();
#endif
}



void nRFTask::GetTemp()
{

}

void nRFTask::GetTarget()
{
    get_target_status = 1;

}

void nRFTask::GetConfig()
{
    get_config_status = 1;

}

void nRFTask::SetTarget(target ss)
{
    this->obj = ss;
    set_target_status = 1;
}

void nRFTask::SetConfig(conf ss)
{
    this->updatedConf = ss;
    set_config_status = 1;

}



void nRFTask::sendTarget(target t)
{

    qDebug()<<"Iniciando transmision TARGET\n";
    #ifdef LINUX
    radio.stopListening();
    long cm = SET_TARGET;
    radio.writeFast(&cm, sizeof(cm));
    bool resp = radio.txStandBy(100);
    if(resp)
    {
        radio.writeFast(&t, sizeof(t));
        resp = radio.txStandBy(100);
        if(resp)
        {
            qDebug()<<"Transmision Target OK\n";
            set_target_status = 0;
        }
        else
        {
            qDebug()<<"Transmission Target Error\n";
        }
    }
    else
    {
        qDebug()<<"Transmission Comando Target Error\n";
    }
    radio.startListening();
#endif
    var++;
}

void nRFTask::sendConfig(conf t)
{

    qDebug()<<"Iniciando transmision CONFIG\n";
    #ifdef LINUX
    radio.stopListening();
    long cm = SET_CONFIG;
    radio.writeFast(&cm, sizeof(cm));
    bool resp = radio.txStandBy(100);
    if(resp)
    {
        radio.writeFast(&t, sizeof(t));
        resp = radio.txStandBy(100);
        if(resp)
        {
            qDebug()<<"Transmision CONFIG OK\n";
            set_config_status = 0;
        }
        else
        {
            qDebug()<<"Transmission CONFIG Error\n";
        }
    }
    else
    {
        qDebug()<<"Transmission Comando CONFIG Error\n";
    }
    radio.startListening();
#endif
    var++;
}



void nRFTask::SimuloRecepcion(long cmd, long estado)
{
    qDebug()<< "Simulando cmd="<<(char)cmd<<"  Estado = "<<estado;
    var++;
    if(cmd == GET_TEMPS)
    {
        sensores s;
        for(int i = 0; i < CANT; i++)
        {
            s.temp[i] = 18.00+(double)i;
        }
        emit TempGetReady( s );
    }
    else if(cmd == GET_TARGET && get_target_status ==0x01)
    {
        for(int i = 0; i < 8; i++)
        {
            st_target.set_temp[i] = 20.00;
        }
        emit TargetGetReady( st_target);
        get_target_status =0;
    }
    else if(cmd == GET_CONFIG && get_config_status == 0x01)
    {
        configuracion.calor = 0x00;
        configuracion.frio = 0x00;
        configuracion.fulltime = 0x01;
        configuracion.habilitado = 0xFF;
        configuracion.salida_calor[0] = 0x00;
        configuracion.salida_frio[0] = 0x00;
        configuracion.temp[0] = 23.00;
        configuracion.temp[1] = -5.00;
        emit ConfigGetReady(configuracion);
        get_config_status = 0;
    }
    this->sleep(4);

}

void showConf(conf configuracion, long len)
{
    qDebug()<<"Longitud leida = "<< len;
    qDebug()<<"Temperatura[9] = "<< configuracion.temp[0];
    qDebug()<<"Temperatura[10] = "<< configuracion.temp[1];
    qDebug()<<"salidas calor = "<< configuracion.salida_calor;
    qDebug()<<"salidas frio = "<< configuracion.salida_frio;
    qDebug()<<"habilitado= "<< configuracion.habilitado;
    qDebug()<<"habilitado= "<< configuracion.fulltime;
    qDebug()<<"calor= "<< configuracion.calor;
    qDebug()<<"habilitado= "<< configuracion.frio;
}
