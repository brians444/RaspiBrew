#include "nrftask.h"
#include <QElapsedTimer>
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

void debug_now(QString d);


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
    timer.start();

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
        timer.restart();
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
    else
    {
        debug_now("Funcion Leer - Estado ="+QString((char)estado)+" var = "+QString((int)var));
    }
#endif

}

void nRFTask::WaitingResponse(long cmd)
{
#ifdef LINUX
    if(radio.available())
    {
        long len = radio.getPayloadSize();
        debug_now("Waiting response - cmd= "+QString((char)cmd));
        debug_now("Longitud leida ="+QString::number((unsigned int)len)+" - COMANDO ="+QString((char)cmd));
        if(cmd == GET_TEMPS)
        {
            radio.read(&sens, sizeof(sens));
            for(int i = 0; i < CANT; i++)
            {
                debug_now("Temperatura["+QString::number(i)+"] = "+QString::number(sens.temp[i]));
            }
            emit TempGetReady(sens);
            estado = END_TRANSMISSION;
            this->sleep(2); //Delay after payload responded to, minimize RPi CPU time
        }
        else if(cmd == GET_TARGET)
        {
            if( get_target_status == 0x01)
            {
                radio.read(&st_target, sizeof(st_target));
                for(int i = 0; i < CANT; i++)
                {
                    debug_now("Temperatura objetivo["+QString::number(i)+"] = "+QString::number(st_target.set_temp[i]));
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
            if( get_config_status == 0x01)
            {
                radio.read(&configuracion, sizeof(configuracion));
                showConf(configuracion, len);
                if(configuracion.cte1 == 0xF0)
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
    else if(timer.elapsed() > 1000*5)
    {
        debug_now("Timeout Elapsed");
        estado = WAIT_START;
    }
}

void nRFTask::WaitingInit(long cmd)
{
    #ifdef LINUX
    debug_now("WAITING INIT - cmd ="+QString((char)cmd));
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
        debug_now("Transmitiendo comando cmd = "+QString((char)cmd));
        // First, stop listening so we can talk.
        radio.stopListening();
        radio.flush_tx();
        sleep(5);
        bool ok = radio.write(&cmd, sizeof(cmd));
        radio.startListening();
        if(ok)
        {
            debug_now("Transmision comando ok\n");
            estado = WAITING_RESPONSE;
            this->msleep(100);
        }
        else
        {
            debug_now("Transmision comando failed \n");
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
        else if(var==3)
        {
            sendTarget(obj);
        }
        else if(var ==4)
        {
            sendConfig(updatedConf);
        }
        else
        {
            var = 0;
        }
        this->msleep(5);
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

    if(set_target_status == 0x01)
    {
        debug_now("Iniciando transmision TARGET\n");
        radio.stopListening();
        long cm = SET_TARGET;
        bool resp = radio.write(&cm, sizeof(cm));
        if(resp)
        {
            resp = radio.write(&t, sizeof(t));
            if(resp)
            {
                debug_now("Transmision Target OK\n");
                set_target_status = 0;
                var++;
            }
            else
            {
                debug_now("Transmission Target Error\n");
            }
        }
        else
        {
            radio.flush_tx();
            debug_now("Transmission Comando Target Error\n");
        }
        radio.startListening();
    }
    else
    {
        var++;
    }
}

void nRFTask::sendConfig(conf t)
{
    if(set_config_status == 0x01)
    {
        debug_now("Iniciando transmision CONFIG\n");
        radio.stopListening();
        long cm = SET_CONFIG;
        bool resp = radio.write(&cm, sizeof(cm));
        if(resp)
        {
            resp = radio.write(&t, sizeof(t));
            if(resp)
            {
                debug_now("Transmision CONFIG OK\n");
                set_config_status = 0;
                var++;
            }
            else
            {
                debug_now("Transmission CONFIG Error\n");
            }
        }
        else
        {
            debug_now("Transmission Comando CONFIG Error\n");
        }
        radio.startListening();
    }
    else
    {
        var++;
    }
}


void showConf(conf configuracion, long len)
{
    debug_now("Longitud leida = "+QString::number(len));
    debug_now("Temperatura[9] = "+QString::number(configuracion.temp[0]));
    debug_now("Temperatura[10] = "+QString::number(configuracion.temp[1]));
    /* ERROR HERE WITH CONVERSION TO QSTRING
     *
    debug_now("salidas calor = "+QString::number( configuracion.salida_calor));
    debug_now("salidas frio = "+QString(configuracion.salida_frio));
    debug_now("habilitado= "+QString(configuracion.habilitado));
    debug_now("fulltime= "+QString(configuracion.fulltime));
    debug_now("calor= "+QString(configuracion.calor));
    debug_now("frio= "+QString(configuracion.frio));*/
}


void nRFTask::SimuloRecepcion(long cmd, long estado)
{
    debug_now("Simulando cmd="+QString((char)cmd)+"  Estado = "+QString::number(estado));
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

void debug_now(QString d)
{
#ifdef DEBUG
    qDebug() << d;
#endif
}
