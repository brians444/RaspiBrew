#include "database.h"

DataBase::DataBase()
{
    drivers();
    conectar();
    crearDb();

}

int DataBase::conexion()
{
    return db.isOpen();
}

QStringList DataBase::drivers()
{
    QStringList d = db.drivers();
    qDebug() << d;
    return d;
}

void DataBase::conectar()
{
    if(db.isDriverAvailable("QSQLITE"))
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("datab.sqlite");
        bool ok = db.open();
        if(ok)
        {
            qDebug() <<" Conectado";
        }
        else
        {
            QMessageBox::warning(0,"Error","No conecto la base de datos.");
        }


    }
    else
    {
        qDebug() << "Driver no disponible";
    }


    /************************ No se usan con SQLite
    db.setHostName("acidalia");
    db.setDatabaseName("customdb");
    db.setUserName("mojito");
    db.setPassword("J0a1m8");
    ******************/

}

void DataBase::crearDb()
{
    // Crea las tablas
    QSqlQuery query;

    /*************************** CONSTANTES ***********************/
    query.prepare("CREATE TABLE IF NOT EXISTS 'registro' ('id' integer primary key autoincrement, 'tiempo' TIMESTAMP, 'temp1' REAL, 'temp2' REAL, 'temp3' REAL, 'temp4' REAL, 'temp5' REAL, 'temp6' REAL, 'temp7' REAL, 'temp8' REAL)");
    query.exec();
    /*************************** FIN CONSTANTES ***********************/

    /*********************** REMITOS DE ENTRADA ************************/
    /*query.prepare("CREATE TABLE IF NOT EXISTS 'remitos_entrada' "
                  "('id' integer primary key autoincrement , 'cliente' varchar(20) not null, "
                  "'fecha' varchar(20) not null, 'observaciones' text not null, 'procedencia' text, 'orden_trabajo' integer, 'tubos1' integer,"
                  "'tubos2' integer, 'tubos3' integer, 'total' integer, 'remito_in' varchar(20), 'tiene_informe' tinyint)");

    // Para agregar el campo 'tiene_informe'
    // ALTER TABLE 'remitos_entrada' ADD 'tiene_informe' TINYINT;
    query.exec();
    /*********************** FIN REMITOS DE ENTRADA ************************/

}

bool DataBase::addTemperatures(sensores values)
{
    QSqlQuery query;
    QString tmp;
    QString val;
    val.append("CURRENT_TIMESTAMP, ");
    for(int i = 0; i< CANT; i++)
    {
        val.append("'"+QString::number(values.temp[i], 'f',2).replace('.', ",")+ "'");
        if(i<7)
            val.append(",");
    }
    tmp.append("INSERT INTO registro (tiempo, temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8) VALUES("+val+");" );
    query.prepare(tmp);
    qDebug()<< "Consulta = "<< tmp;
    bool ok = query.exec();
    if(ok)
    {
        qDebug()<< "Temperatura agregada correctamente";
    }
    else
    {
        qDebug()<< "Error al agregar temperatura";
    }
}

/*
//************************************** Dialogo Clientes/Pesos/Extremos ******************************************
bool DataBase::addSearchDialog(QString value)
{
    QSqlQuery query;
    QString tmp;
    tmp.append("INSERT INTO "+t1+" ("+t2+") VALUES (?);");
    qDebug() << "Str= "<< tmp;
    query.prepare(tmp);
    //query.bindValue(0, "0");
    query.bindValue(0, value);
    bool ok = query.exec();
    if(ok)
    {
        qDebug ()<<"OK = "<<ok;
    }
    else
    {
        qDebug() << "Error adding"<<query.lastError();
    }
    return ok;
}

void DataBase::setDialog(int tipo)
{
    t1.clear();t2.clear();
    switch (tipo) {
    case CLIENTE:
        t1.append("clientes"); // Nombre de la tabla
        t2.append("nombre");    // Nombre del campo
        break;
    case PESOS:
        t1.append("pesos"); // Nombre de la tabla
        t2.append("peso");    // Nombre del campo
        break;
    case EXTREMOS:
        t1.append("extremos"); // Nombre de la tabla
        t2.append("tipo_extremo");    // Nombre del campo
        break;
    case LBSPIE:
        t1.append("lbspie"); // Nombre de la tabla
        t2.append("lbs_pie");    // Nombre del campo
        break;
    case ESPESOR:
        t1.append("espesor"); // Nombre de la tabla
        t2.append("medida_espesor");    // Nombre del campo
        break;
    case MATERIAL:
        t1.append("material"); // Nombre de la tabla
        t2.append("tipo_material");    // Nombre del campo
        break;
    default:
        break;
    }
}

QStringList DataBase::getSearchDialog(int tipo)
{
    this->setDialog(tipo);
    QSqlQuery q;
    q.prepare("SELECT * FROM "+t1+";");
    QStringList busqueda;
    busqueda.clear();
    if(q.exec())
    {
        qDebug() << "Error al buscar "<<t1;

        while(q.next())
        {
            busqueda.append(q.value(1).toString());
        }
    }
    return busqueda;
}

bool DataBase::delSearchDialog(QString nom)
{
    QSqlQuery q;
    q.prepare("DELETE FROM "+t1+" WHERE "+t2+"=(:nombre);");
    q.bindValue(":nombre", nom);
    bool ok = q.exec();
    return ok;
}
*/

/*
bool DataBase::addRemitoIn(RemitoEntrada *remito)
{
    QString query;
    query.append("INSERT INTO remitos_entrada (cliente, fecha, observaciones, procedencia, orden_trabajo, tubos1, tubos2, tubos3"
                 ", total, remito_in, tiene_informe) VALUES('");
    query.append(remito->id_cliente+"', '");
    query.append("0');");

    //qDebug() << "COnsulta:"<< query;

    QSqlQuery q;
    q.prepare(query);
    bool ok = q.exec();
    return ok;
}


RemitoEntrada* DataBase::getRemitoIn(QString id)
{
    RemitoEntrada *remi = new RemitoEntrada;

    QString query;
    query.append("SELECT * FROM remitos_entrada WHERE id=");
    query.append(id);
    query.append(" ;");
    QSqlQuery q;
    q.prepare(query);
    bool ok = q.exec();
    q.first();

    remi->id_cliente = q.record().value("cliente").toString();
    remi->fecha = q.record().value("fecha").toString();
    remi->observaciones = q.record().value("observaciones").toString();
    remi->procedencia = q.record().value("procedencia").toString();
    remi->orden_trabajo = q.record().value("orden_trabajo").toString();
    remi->cantidadA = q.record().value("tubos1").toString();
    remi->cantidadB = q.record().value("tubos2").toString();
    remi->cantidadC =  q.record().value("tubos3").toString();
    remi->total_tub = q.record().value("total").toString();
    remi->remito_in = q.record().value("remito_in").toString();



    return remi;
}

QSqlTableModel* DataBase::searchRemitoIn()
{
    QSqlTableModel *model = new QSqlTableModel(NULL, db);
    model->setTable("remitos_entrada");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    //model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    //model->setHeaderData(1, Qt::Horizontal, tr("Salary"));
    return model;
}

QSqlTableModel* DataBase::searchRemitoIn(QString cliente = "", QString proc = "", QString fecha = "", QString obs = "", QString orden = "")
{
    QSqlTableModel *model = new QSqlTableModel(NULL, db);
    model->setTable("remitos_entrada");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setQuery();
    QString q;
    if(cliente != "")
        q.append("cliente LIKE '"+cliente+"'");
    if(fecha != "")
    {
        if(q.size() != 0)
            q.append(" AND ");
        q.append("fecha LIKE '"+fecha+"'");
    }
    if(proc != "")
    {
        if(q.size() != 0)
            q.append(" AND ");
        q.append("procedencia LIKE '%"+proc+"%'");
    }
    if(obs != "")
    {
        if(q.size() != 0)
            q.append(" AND ");
        q.append("observaciones LIKE '%"+obs+"%'");
    }
    if(orden != "")
    {
        if(q.size() != 0)
            q.append(" AND ");
        q.append("orden_trabajo LIKE '%"+orden+"%'");
    }
    if(q.size() != 0)
        q.append(" AND ");
    q.append("tiene_informe LIKE '"+QString::number(0)+"'");

    qDebug() << "filtro:"<<q;

    model->setFilter(q);
    model->select();
    //model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    //model->setHeaderData(1, Qt::Horizontal, tr("Salary"));
    return model;
}

bool DataBase::delRemitoIn(QString id)
{

}

int DataBase::getNextInformeTecnico()
{
    QString cad;
    cad.append("SELECT max(id) FROM informes_tecnicos;");
    QSqlQuery q;
    q.prepare(cad);
    bool ok = q.exec();
    int c=-1;
    if(ok)
    {
        q.first();
        c = q.record().value(0).toInt();
        c++;
    }

    return (c);
}

int DataBase::getNextInformeMaterial()
{
    QString cad;
    cad.append("SELECT max(id) FROM informe_material;");
    QSqlQuery q;
    q.prepare(cad);
    bool ok = q.exec();

    q.first();
    return (q.record().value(0).toInt()+1);
}

int DataBase::getNextRemitoIn()
{
    QString cad;
    cad.append("SELECT max(id) FROM remitos_entrada;");
    QSqlQuery q;
    q.prepare(cad);
    bool ok = q.exec();

    q.first();
    return (q.record().value(0).toInt()+1);
}

bool DataBase::addInformeTecnico(InformeTec *nuev)
{
    //**************** INFORME TECNICO ********************
    QString cad;
    cad.append("INSERT INTO informes_tecnicos (id_cliente, fecha, observaciones,"
                  " id_peso, id_espesor, id_extremos, id_lbspie, roscas_grado2_pin, roscas_grado3_pin, "
                  "roscas_grado2_box, roscas_grado3_box, id_material1, id_material2, id_material3 ) VALUES ('");
    //cad.append(nuev->numero_informe+"', '");    // numero_informe
    cad.append(nuev->id_cliente+"', '");        // id_cliente
    cad.append(nuev->fecha_informe+"', '");     // fecha_informe
    cad.append(nuev->observaciones+"', '");     // observaciones
    cad.append("15', '"); //id_peso
    cad.append("14', '"); //id_espesor
    cad.append("13', '"); //id_extremos
    cad.append("12', '"); //id_lbspie
    cad.append(nuev->grado2pin+"', '");         // roscas_grado2_pin
    cad.append(nuev->grado3pin+"', '");         // roscas_grado3_pin
    cad.append(nuev->grado2box+"', '");         // roscas_grado2_box
    cad.append(nuev->grado3box+"', '");         // roscas_grado3_box
    cad.append("01', '");                       // id_material1
    cad.append("01', '");                       // id_material2
    cad.append("01'");                       // id_material3
    cad.append(");");

    qDebug() <<"Consulta"<<cad;

    QSqlQuery q;
    q.prepare(cad);
    bool ok = q.exec();

    if(ok)
    {
            qDebug() << "Se agrego informe tecnico";
    }
    else
    {
            qDebug() << "Error al agregar informe tecnico"<< db.lastError();
    }


    //********************** INFORMES DE MATERIAL ***********************

    for(int j = 0; j < INFORME_TIPOSMATERIAL; j++)
    {
        // Agrego el material al stock - Necesito el ID obtenido
        int id = getNextInformeMaterial();
        QString strStock;
        strStock.append("INSERT INTO stock (id_informe_material, id_remitoin, id_cliente, id_tipo_material, cantG2, cantG3, cantG4, cantG5, total_tubos, vacio) VALUES(");
        strStock.append(" '"+QString::number(id)+"' ,");
        strStock.append(" '"+nuev->remito_in+"' ,");
        strStock.append(" '"+nuev->id_cliente+"' ,");


        cad.clear();
        cad.append("INSERT INTO informe_material (id_remitoin, id_cliente, id_informetecnico, id_tipo_material ,cant1, cant2, cant3,"
               " cant4, cant5, cant6, cant7, cant8, cant9, cant10, cantG2, cantG3, cantG4, cantG5) VALUES (");

        cad.append(" '"+nuev->remito_in+"' ,");
        cad.append(" '"+nuev->id_cliente+"' ,");
        cad.append(" '"+nuev->numero_informe+"' ,");
        // Busco el id para no poner toda la cadena
        QString idm = nuev->inspeccion[j][0];
        idm = this->getIdFromTipoMaterial(idm);

        cad.append(" '"+idm+"'");                            // id_tipo_material
        strStock.append(" '"+idm+"' ,");                  // id_tipo_material

        int total = 0;

        for(int i = 1; i <= INFORME_FILAS1; i++)
        {
            cad.append(", '"+nuev->inspeccion[j][i]+"'");
        }

        for(int i = 1; i <= INFORME_FILAS2; i++)
        {
            cad.append(", '"+nuev->grados[j][i]+"'");
            strStock.append(" '"+nuev->grados[j][i]+"' ,");                  // cantG2-3-4-5
            total += nuev->grados[j][i].toInt();
        }

        cad.append(");"); // Terminamos la consulta
        qDebug()<< "Consulta = "<< cad;

        strStock.append(" '"+QString::number(total));                  // total tubos
        strStock.append("' , 'FALSE' );");                             // vacio
        // FIN DE CONSULTA
        qDebug()<< "Consulta = "<< strStock;

        QSqlQuery q;
        q.prepare(cad);
        bool ok = q.exec();
        if(ok)
        {
            qDebug() << "Se agrego material correctamente";
            if(total>0)
            {
                QSqlQuery stock;
                bool termino = stock.exec(strStock);
                if(termino)
                    qDebug() << "Se agrego Stock correctamente";
                else
                    qDebug() << "No se pudo agregar Stock";
            }

        }
        else
        {
            qDebug() << "Error al agregar material";
        }

    }


    //************* CARGO EN REMITO DE ENTRADA QUE YA TIENE INFORME TECNICO ************************
    cad.clear();

    cad.append("UPDATE remitos_entrada SET tiene_informe = 1 WHERE remito_in = '"+nuev->remito_in+"';");
    qDebug() << "Actualizando remito";
    qDebug() << "Consulta "<<cad;
    q.clear();
    q.prepare(cad);
    ok = q.exec();
    if(ok)
    {
        qDebug() << "Se agrego actualizo el remito correctamente";
    }
    else
    {
        qDebug() << "Error al actualizar el remito";
    }

}

QList<SS> DataBase::getStockByClient(QString Cliente)
{
    QSqlQuery q;
    QString st;
    QList<SS> lista;


    int c = getIdFromClient(Cliente);
    qDebug() << "Id_Cliente = "<<c;


    QStringList tipo_material;
    QStringList cantidades;
    tipo_material = this->getSearchDialog(MATERIAL);
    //qDebug () << "Tipos material" << tipo_material;
    for(int i = 0; i < tipo_material.size() ; i++)
    {
        //int cant[4];

        struct SS p1;
        for(int j = 0; j < 4; j++)
            p1.cant[j] = 0;

        st.clear();
        QString dd = this->getIdFromTipoMaterial(tipo_material[i]);
        st.append("SELECT * FROM stock WHERE id_cliente='"+QString::number(c)+"' AND id_tipo_material='"+dd+"';");
        qDebug() << "Consulta" << st;
        bool ok = q.exec(st);
        if(ok)
        {
            while(q.next())
            {
                p1.cant[0] += q.record().value("cantG2").toInt();
                p1.cant[1] += q.record().value("cantG3").toInt();
                p1.cant[2] += q.record().value("cantG4").toInt();
                p1.cant[3] += q.record().value("cantG5").toInt();
            }
        }
        lista.append(p1);
        st.clear();
        st.append(QString::number(p1.cant[0])+" "+QString::number(p1.cant[1])+" "+QString::number(p1.cant[2])+" "+QString::number(p1.cant[3])+"");

        cantidades.append(st);
    }
    qDebug() <<"Cantidades: "<< cantidades;
    return lista;
}

QString DataBase::getIdFromTipoMaterial(QString c)
{
    QSqlQuery q;
    QString st;
    st.append("SELECT id FROM material WHERE tipo_material='"+c+"'");
    bool ok = q.exec(st);
    if(ok)
    {
        q.first();
        return q.record().value("id").toString();
    }
    else
    {
        return "";
    }
}

int DataBase::getIdFromClient(QString c)
{
    QSqlQuery q;
    QString st;
    st.append("SELECT id FROM clientes WHERE nombre='"+c+"'");
    bool ok = q.exec(st);
    if(ok)
    {
        q.first();
        return q.record().value("id").toInt();
    }
    else
    {
        return -1;
    }
}

QList<MyStock> DataBase::getActualStock(QString cliente)
{
    QList<MyStock> lista;
    lista.clear();

    int id_client = this->getIdFromClient(cliente);


    QSqlQuery query_in;
    QString st;
    st.append("SELECT s.*, mat.tipo_material FROM stock s LEFT JOIN material mat ON s.id_tipo_material=mat.id "
              "WHERE s.id_cliente='"+QString::number(id_client)+"' AND s.vacio IS 'FALSE';");
    bool ok = query_in.exec(st);
    if(ok)
    {
        qDebug()<< "Se ejecuto correctamente la consulta";
    }
    else
    {
        qDebug()<< "Error al ejecutar la consulta del stock";
    }

    int cont = 0;
    qDebug() <<"Consulta ="<<query_in.lastQuery();
    if(ok)
    {
        while(query_in.next())
        {
            //********************* BUSQUEDA DE MATERIAL EN STOCK ***********************
            MyStock tmp;
            tmp.cantidades[0] = query_in.record().value("cantG2").toInt();
            tmp.cantidades[1] = query_in.record().value("cantG3").toInt();
            tmp.cantidades[2] = query_in.record().value("cantG4").toInt();
            tmp.cantidades[3] = query_in.record().value("cantG5").toInt();

            tmp.id_informe_material = query_in.record().value("id_informe_material").toString();
            tmp.remito_in = query_in.record().value("id_remitoin").toString();

            //QString orden_trabajo;          //Me falta

            // ID TIPO MATERIAL- REEMPLAZAR POR MATERIAL CON LEFT JOIN
            tmp.tipo_material = query_in.record().value("tipo_material").toString(); // La consulta devuelve id_tipo_material y tipo_material (de la tabla material)
            lista.append(tmp);
            cont++;
            //********************** FIN ***********************

            qDebug() << "Numero informe Material = "<< tmp.id_informe_material;
        }
    }

    return lista;
}

// Hago el ingreso del remito de salida
bool DataBase::ingresarRemitoSalida(QList<MyStock> lista, RemitoOut remito)
{
    QSqlQuery q;
    QString cons1, cons2;

    QString cliente = remito.id_cliente;
    int remito_id = getNextRemitoOut();
    cons1.append("INSERT INTO remito_salida (id_cliente, fecha, cant_total, cant_mts, empresa_trasporte, domicilio_t, cuit, "
                 "transporte_chofer, num_registro, chapa_chasis,chapa_acoplado) VALUES ('");
    cons1.append(remito.id_cliente+"', '");
    cons1.append(remito.fecha+"', '");

    QString tot = remito.total;

    float total = tot.toFloat();
    total = total * 9.5;
    cons1.append(remito.total+"', '");       // total_tubos

    cons1.append(QString::number(total)+"', '");       // total


    //cons1.append(cliente+"', '");         //cant_mts
    cons1.append(remito.empresa_transp+"', '");
    cons1.append(remito.domicilio+"', '");
    cons1.append(remito.cuit+"', '");
    cons1.append(remito.chofer+"', '");
    cons1.append(remito.num_registro+"', '");
    cons1.append(remito.patente+"', '");
    cons1.append(remito.acoplado+"');");

    qDebug()<< "Consulta = "<<cons1;

    // Ejecuto la consulta
    bool ok = q.exec(cons1);
    if(ok)
    {
        qDebug() << "Se agrego remito de salida";
    }
    else
    {
        qDebug() << "Error al agregar remito de salida";
    }

    // Cargo los materiales
    int tam = lista.size();
    for(int i = 0; i < tam; i++ )
    {
        cons1.clear();
        cons2.clear();
        int grado = lista.at(i).grado;
        int cantidad_max = lista.at(i).cantidades[grado-2];
        int cant = cantidad_max - lista.at(i).cantidad;

        cons2.append("INSERT INTO salida_material (id_remito_out, id_cliente,"
                     " id_informe_material, id_tipo_material, grado, cantidad, observaciones) VALUES ('");
        cons2.append(QString::number(remito_id)+"', '");
        cons2.append(cliente+"', '");
        cons2.append(lista.at(i).id_informe_material+"', '");

        //lista[i].tipo_material = QString::number(this->getIdFromTipoMaterial());
        cons2.append(lista.at(i).tipo_material+"', '");
        cons2.append(QString::number(grado)+"', '");
        cons2.append(QString::number(lista.at(i).cantidad)+"', '");
        cons2.append(lista.at(i).observ+"');");

        qDebug()<< "Consulta salida material = "<<cons2;

        if(q.exec(cons2))
        {
            qDebug() << " Se agrego la salida de material(Informe Material, Grado, Cantidad)"<<lista.at(i).id_informe_material<<", "<<grado<<", "<<cant;

            cons1.append("UPDATE stock SET ");
            cons1.append("cantG"+QString::number(grado)+ "=");
            cons1.append(QString::number(cant));
            cons1.append(" WHERE id_informe_material = "+ lista.at(i).id_informe_material +" ;");

            qDebug()<< "Consulta actualizar stock = "<<cons1;

            if(q.exec(cons1))
            {
                qDebug() << "Se resto correctamente el stock - Stock final = "<<cant;
            }
            else
            {
                qDebug() << "Error al descontar stock";
            }
        }
        else
        {
            qDebug() << "Error al agregar la salida de material";
        }

    }

}

/*("CREATE TABLE IF NOT EXISTS 'stock' "
                  "('id_informe_material' integer primary key, 'id_remitoin' integer not null, 'id_cliente' integer not null,"
                  "'id_tipo_material' integer, 'total_tubos' integer, 'vacio' boolean,"
                  "'cantG2' integer, 'cantG3' integer,"
                  "'cantG4' integer, 'cantG5' integer);");
*/

/*
int DataBase::getNextInformeSalidaMaterial()
{
    QString cad;
    cad.append("SELECT max(id) FROM salida_material;");
    QSqlQuery q;
    q.prepare(cad);
    bool ok = q.exec();

    q.first();
    return (q.record().value(0).toInt()+1);
}
*/

QList<historic_record> DataBase::getHistory(int fermentador, QDateTime f1, QDateTime f2)
{
    QList<historic_record> lista;
    lista.clear();
    QString cad;

    cad.append("SELECT tiempo, temp"+QString::number(fermentador)+" FROM registro WHERE tiempo > '"
               +f1.toString("yyyy-MM-dd hh:mm:ss")+"' AND tiempo < '"+f2.toString("yyyy-MM-dd hh:mm:ss")+"' ;");
    // Formato en que guarda la base de datos : 2017-06-26 01:50:11

    #ifdef DEBUG
    qDebug() << f1.toString();
    qDebug() <<f1.toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << cad;
    #endif
    QSqlQuery q;
    q.prepare(cad);
    bool ok = q.exec();
    if(ok)
    {


        cad.clear(); cad.append("temp"); cad.append(QString::number(fermentador));
        int field1 = q.record().indexOf("tiempo");
        int field2 = q.record().indexOf(cad);

        #ifdef DEBUG
        qDebug() << "Query OK";
        qDebug() << "Query OK Campo1(tiempo)="<<field1<<" Campo2("<<cad<<")="<<field2;
        #endif
        while(q.next())
        {
            historic_record tmp;
            #ifdef DEBUG
            qDebug() << "Valores - X="<<q.value("tiempo").toString()<<"  Y="<<q.value(field2).toString();
            #endif
            tmp.ti = q.value(field1).toDateTime().toTime_t();
            tmp.value = q.value(field2).toString().replace(',', ".").toDouble();
            lista.append(tmp);
        }
    }
    else
    {
        qDebug() << "Query ERROR";
    }
    return lista;
}
