#ifndef DEFINITIONS_H
#define DEFINITIONS_H


struct conf{
    uint8_t frio;       // Utilizo los bits como booleanos
    uint8_t calor;      // Utilizo los bits como booleanos
    uint8_t salida_frio[8];
    uint8_t salida_calor[8];
    uint8_t habilitado; // Utilizo los bits como booleanos
    uint8_t fulltime;
    float temp[2];
    uint8_t cte1;
    uint8_t estado_bombas;
    uint8_t estado_salidas_cold, estado_salidas_hot;
};

struct sensores{
    float temp[8];
};

struct target{
    float set_temp[8];
};

struct historic_record{
    double ti;              // Tiempo
    double value;           // Valor de temperatura
};

/*
Q_DECLARE_METATYPE(sensores);
Q_DECLARE_METATYPE(conf);
Q_DECLARE_METATYPE(target);
*/
/*
qRegisterMetaType<sensores>("sensores&");
qRegisterMetaType<conf>("conf&");
qRegisterMetaType<target>("target&");
*/

#define SET_TARGET     'S'
#define GET_TARGET     'G'
#define SET_CONFIG     'C'
#define GET_CONFIG     'I'
#define GET_TEMPS     'T'

#define WAIT_START      1
#define IN_COMMAND     2
#define IN_MESSAGE      3
#define TRANSMIT       4
#define WAITING_RESPONSE 5
#define END_TRANSMISSION 6
#define UNDEFINED       9

#define CANT  8


#endif // DEFINITIONS_H
