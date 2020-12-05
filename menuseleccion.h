#include "civilizacion.h"

Aldeano capturar()
{
    Aldeano a;
    string nombre;
    int edad;
    string genero;
    int salud;
    Civilizacion c;

    cout<< "Nombre: ";
    getline(cin,nombre);
    a.setNombre(nombre);

    cout<<"Edad: ";
    cin>>edad; cin.ignore();
    a.setEdad(edad);

    cout<< "Genero: ";
    getline(cin,genero);
    a.setGenero(genero);

    cout<<"Salud: ";
    cin>>salud; cin.ignore();
    a.setSalud(salud);

    return a;
}

void menu(Civilizacion &c)
{
int punt=0;
 int op;
 while (true) {
    system("cls");
    cout << "1) Agregar aldeano." << endl;
    cout << "2) Eliminar aldeano" << endl;
    cout << "3) Clasificar Aldeanos" << endl;
    cout << "4) Buscar aldeano" << endl;
    cout << "5) Modificar aldeano" << endl;
    cout << "6) Mostrar Aldeanos" << endl;
    cout << "7) Salir" << endl;
    cout << "Elige tu opcion: " << endl;
    cin>> op;
    system("pause");
    //Agregar aldeano
    if (op == 1) {
        system("cls");
        Aldeano a;
        int op2;
        cout << "-------Agregar Aldeano------" << endl;
        cin.ignore();
        cin >> a;
        cout << "1) Agregar el objeto aldeano al inicio." << endl;
        cout << "2) Agregar el objeto aldeano al final" << endl;
        cout << "Elige tu opcion: " << endl;
        cin>>op2; cout<<endl<<endl;
        //Agregar al inicio
        if(op2 == 1){
            c.agregarInicio(a);
            c.setPuntuacion(c.getPuntuacion()+100);
        }
        //Agregar al final
        else if (op2 == 2) {
            c.agregarFinal(a);
            c.setPuntuacion(c.getPuntuacion()+100);
        }
    }
    //Eliminar aldeano
    else if (op == 2) {
        system("cls");
        int n,ope;
        cout << "-------Eliminar Aldeano------" << endl;
        cout << "1) Eliminar por nombre." << endl;
        cout << "2) Eliminar aldeanos para salud sea menor a x"<< endl;
        cout << "3) Eliminar aldeanos donde su edad sea mayor igual a 60 " << endl;
        cout << "Elige tu opcion: " << endl;
        cin>>ope;
        //Eliminar por nombre.
        if (ope == 1) {
            cin.ignore();
            string s;
            cout<<"Ingrese el nombre: ";
            getline(cin, s);
            c.EliminarNombre(s);
            system("pause");
        }
        //Eliminar por salud
        else if (ope == 2) {
            cout<<"Ingrese x: ";cin>>n; cout<<endl;
            c.EliminarSalud(n);
        }
        //Eliminar Edad
        else if (ope == 3) {
            c.EliminarEdad();
        }
    }
    //Clasificar Aldeanos
    else if (op == 3) {
        system("cls");
        string nombre;
        int op2;
        cout << "-------Clasificar Aldeano------" << endl;
        cout << "1) Clasificar por nombre." << endl;
        cout << "2) Clasificar por edad" << endl;
        cout << "3) Clasificar por salud " << endl;
        cout << "Elige tu opcion: " << endl;
        cin>>op2;
        //Eliminar por nombre.
        if (op2 == 1) {
            c.ClasificarNombre();
        }
        else if (op2 == 2){
            c.ClasificarEdad();
        }
        else if (op2 == 3){
            c.ClasificarSalud();
        }
    }
    //Buscar Aldeanos
    else if (op ==4) {
        Aldeano a;
        string nombre;
        cout << "-------Buscar Aldeano------" << endl;
        cout<<"Ingrese el nombre del aldeano a buscar: ";
        cin.ignore();
        getline(cin, nombre);cout<<endl<<endl;
        a.setNombre(nombre);
        Aldeano *ptr=c.BuscarAldeano(a);
        if (ptr == nullptr) {
            cout << "Aldeano NO encontrado" << endl<< endl;
        }
        else {
            cout << left;
            cout << setw(10) << "Nombre"
            << setw(10) << "Edad"
            << setw(10) << "Genero"
            << setw(10) << "Salud" << endl;
            cout << *ptr << endl<< endl;
            system("pause");
            system("cls");
        }
        system("pause");
    }
    //Modificar Aldeanos
    else if (op== 5) {
        system("cls");
        Aldeano a;
        string nombre;
        cout<<"Ingrese el nombre del aldeano a modificar: ";
        cin.ignore();
        getline(cin, nombre);cout<<endl<<endl;
        a.setNombre(nombre);
        Aldeano *ptr=c.BuscarAldeano(a);
        string s;
        int n;
        if(ptr==nullptr){
            cout<<"NO se encontró el elemento"<<endl;
        }else{
            cout << left;
            cout << setw(10) << "Nombre"
            << setw(10) << "Edad"
            << setw(10) << "Genero"
            << setw(10) << "Salud" << endl;
            cout<<*ptr<<endl<<endl;
            int op2;
            cout << "-------Modificar Aldeano------" << endl;
            cout << "1) Modificar Nombre." << endl;
            cout << "2) Modificar Edad" << endl;
            cout << "3) Modificar Genero" << endl;
            cout << "4) Modificar Salud" << endl;
            cout << "Elige tu opcion: " << endl;
            cin>>op2;cin.ignore();
            if(op2==1){
                cout<<"Ingrese un nuevo nombre: ";
                getline(cin,s);
                ptr->setNombre(s);
            }else if(op2==2){
                cout<<"Ingrese la nueva edad: ";
                cin>>n;
                ptr->setEdad(n);
            }else if(op2==3){
                cout<<"Ingrese el nuevo genero: ";
                getline(cin,s);
                ptr->setGenero(s);
            } else if(op2==4){
                cout<<"Ingrese la nueva salud: ";
                cin>>n;
                ptr->setSalud(n);
            }
        }
    }
    //Mostrar Aldeanos
    else if(op == 6){
        c.MostrarAldeanos();
        system("pause");
    }
    else if(op == 7){
        cout<<"Volviendo al menu civilizacion "<<endl<<endl;
        break;
    }
}
}


