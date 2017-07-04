#ifndef NRFTASK_H
#define NRFTASK_H

#undef LINUX

#include <QDebug>
#include <QObject>
#include <QMetaType>

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#ifdef LINUX
#include <RF24/RF24.h>
#endif

#include "definitions.h"

#include <QThread>
#include <QObject>
#include <QWidget>



class nRFTask : public QThread
{
	Q_OBJECT
public:
    void run() Q_DECL_OVERRIDE;
    nRFTask();


public slots:
    void GetTemp();
    void GetTarget();
    void GetConfig();

    void SetTarget();
    void SetConfig();


signals:
    void TempGetReady(sensores );
    void TargetGetReady(target );
    void ConfigGetReady(conf );

private:
    long comando;
    int estado;
    char var =0;

    char get_target_status, get_config_status;
    char set_target_status, set_config_status;

    sensores sens;
    conf configuracion;
    target st_target;

    void radioInit();
    void Leer(long cmd);
    void EnviarTarget(target t);
    void SimuloRecepcion(long cmd, long estado);
    void WaitingResponse(long );
    void WaitingInit(long );


    uint64_t pipes[2];
    bool radioNumber;

    unsigned long cmd;
    target obj;
};

#endif // NRFTASK_H
