//
// Created by Carlos on 27/2/2018.
//

#ifndef PROJECTO1_INTENTO2_DISCO_H
#define PROJECTO1_INTENTO2_DISCO_H
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Metadata.h"
#include "FAT.h"
#include "Data_Block.h"
#include <fstream>

using namespace std;

class Disco {
public:
    string diskname;
    long tamdisk;
    Metadata data;
    void abrir();
    void crear();
    void cerrar();
    void importar(string nombre);
    void exportar(string nombre);

private:
    long size;
    char*buffer;

};


#endif //PROJECTO1_INTENTO2_DISCO_H
