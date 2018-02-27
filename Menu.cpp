//
// Created by Carlos on 27/2/2018.
//

#include "Menu.h"


void Menu::menu1() {
    cout<<"Que desea hacer?"<<endl;
    cout<<"1.Crear Disco"<<endl;
    cout<<"2.Utilizar Disco Existente"<<endl;
    cout<<"3.Salir"<<endl;
    int opcion;
    cin>>opcion;
    switch (opcion){
        case 1:
            menu2();
            break;
        case 2:
            disk.abrir();
            menu3();
            break;
        case 3:
            break;
    }

}

void Menu::menu2() {
    disk.crear();
    menu3();
}

void Menu::menu3() {
    cout<<disk.diskname<<endl;
    cout<<"Espacio disponible:"<<disk.tamdisk<<endl;
    cout<<"2.1)Crear Directorio"<<endl;
    cout<<"2.2)Cambiar Directorio"<<endl;
    cout<<"2.3)Listar Directorio"<<endl;
    cout<<"2.4)Eliminar Directorio/Archivo "<<endl;
    cout<<"2.5)Importar Archivo"<<endl;
    cout<<"2.6)Exportar Archivo"<<endl;
    cout<<"2.7)Regresar"<<endl;
    int opcion;
    cout<<"Eliga una Opcion"<<endl;
    cin>>opcion;
    switch (opcion){
        case 1:
            menu4();
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            cout<<"Nombre de archivo que quiere importar?"<<endl;
            cin>>name;
            disk.importar(name);
            menu3();
            break;
        case 6:
            cout<<"Nombre de archivo que quiere exportar?"<<endl;
            cin>>nom;
            disk.exportar(nom);
            menu3();
            break;
        case 7:
            break;
    }

}

void Menu::menu4() {
    cout<<"Disco:Nombre";
    cout<<"Directorio:Nombre directorio";
    cout<<"-------Creacion Directorio-------"<<endl;
    cout<<"Ingrese Nombre:";

}

void Menu::menu5() {

}
