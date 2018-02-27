//
// Created by Carlos on 27/2/2018.
//

#include "Disco.h"
#include <string.h>

void Disco::abrir() {
    cout<<"Nombre del disco a abrir"<<endl;
    cin>>diskname;
    ifstream diskopen;
    long tam2;
    filebuf *pbuf2;
    diskopen.open(diskname,ios::in|ios::binary);
    pbuf2=diskopen.rdbuf();
    tam2=pbuf2->pubseekoff (0,ios::end,ios::in);
    tamdisk = tam2;
}

void Disco::crear() {
    //Pedir el nombre del archivo, cant de bloques y cant de entradas
    string nombre;
    int canEntradas,canBloques;
    cout<<"--------Crear Disco--------"<<endl;
    cout<<"nombre"<<endl;
    cin>> nombre;
    cout<<"Ingrese cantidad de entradas: "<<endl;
    cin>>canEntradas;
    cout<<"Ingrese cantidad de bloques: "<<endl;
    cin>>canBloques;

    data.block_amount = canBloques;
    data.block_size = 1020;
    data.entry_amount = canEntradas;
    data.bm_size = canBloques/8;
    char*n = new char();
    strcpy(n,nombre.c_str());
    //char * apt = new char[];
    ofstream creacion(nombre,ios::out|ios::binary);
    //creacion.open(n,ios::out|ios::binary);
    //creacion<<"hola";
    creacion.seekp(0,ios::beg);
    char*bitmap = new char[data.bm_size];
    for(int x = 0;x<canEntradas;x++){
        FAT fat;
        creacion.write(reinterpret_cast<char*>(&fat),52);
    }
    creacion.seekp(ios::end);
    creacion.write(bitmap,data.bm_size);
    creacion.seekp(ios::end);
    for(int x = 0;x<canBloques;x++){
        Data_Block block;
        creacion.write(reinterpret_cast<char*>(&block),1020);
    }
    creacion.close();

}

void Disco::importar(string nombre) {
    ifstream prueba;
    filebuf *pbuf;
    char* data;
    long tam;
    prueba.open(nombre,ios::in|ios::binary);
    pbuf=prueba.rdbuf();
    tam=pbuf->pubseekoff (0,ios::end,ios::in);
    pbuf->pubseekpos (0,ios::in);
    data=new char[tam];
    buffer = new char[tam];
    size = tam;
    buffer = data;
    pbuf->sgetn (data,tam);
    prueba.close();
}

void Disco::exportar(string nombre) {
    ofstream prueba2;
    prueba2.open(nombre,ios::out|ios::binary);
    prueba2.write(this->buffer,this->size);
    prueba2.close();
}

