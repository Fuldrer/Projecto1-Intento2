//
// Created by Carlos on 27/2/2018.
//

#ifndef PROJECTO1_INTENTO2_FAT_H
#define PROJECTO1_INTENTO2_FAT_H


class FAT {
public:
    char nombre;
    int tamano;
    char tipo;
    int padre;
    int primer_hijo;
    int hermano_derecho;
    int primer_bloque_data;
    bool libre;
};


#endif //PROJECTO1_INTENTO2_FAT_H
