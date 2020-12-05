#include <iostream>
#include <vector>
#include "videogame.h"
#include "menuseleccion.h"
using namespace std;
int main()
{
    VideoGame v;
    string op;
    while(true){
        cout<< "1) Nombre de usuario: "<<endl;
        cout<< "2) Agregar civilizacion: "<<endl;
        cout<< "3) Insertar civilizacion: "<<endl;
        cout<< "4) Crear civilizaciones: "<<endl;
        cout<< "5) Primera civilizacion: "<<endl;
        cout<< "6) Ultima vicilizacion: "<<endl;
        cout<< "7) Ordenar: "<<endl;
        cout<< "8) Eliminar civilizacion: "<<endl;
        cout<< "9) Buscar: "<<endl;
        cout<< "10) Modificar: "<<endl;
        cout<< "11) Resumen: "<<endl;
        cout<< "12) Respaldar: "<<endl;
        cout<< "13) Recuperar: "<<endl;
        cout<< "14) Salir: "<<endl;

        getline(cin, op);

        if(op== "1"){
            cout<<endl<<endl;
            system("cls");

            string nombre;
            cout<<"Nombre de usuario: ";
            getline(cin,nombre);
            cin.ignore();
            v.setNombre_usuario(nombre);
            system("pause");
        }
        else if(op=="2"){
            cout<<endl<<endl;
            system("cls");
            Civilizacion civ;
            cin>>civ;
            v.agregar_civilizacion(civ);
            system("pause");
        }
        else if(op=="3"){
            cout<<endl<<endl;
            system("cls");
            size_t p;
            cout<<"Posicion: ";
            cin>> p;
            cin.ignore();

            if (p>= v.size()){
                cout<<"Posicion no valida"<< endl;
                system("pause");
            }
            else{
                Civilizacion civ;
                cin>>civ;
                v.insertar_civilizacion(civ,p);
                system("pause");
            }
        }
        else if(op=="4"){
            cout<<endl<<endl;
            system("cls");
            size_t n;

            cout<<"n: ";
            cin>>n;
            cin.ignore();
            Civilizacion civ;
            cin>>civ;

            v.inicializar_civilizaciones(civ,n);
            system("pause");
        }
        else if(op=="5"){
            cout<<endl<<endl;
            system("cls");
            if(v.size()==0){
                cout<<"No hay elementos registrados"<<endl;
            }else{
                v.primera_civilizacion();
                system("pause");
            }
        }
        else if(op=="6"){
            cout<<endl<<endl;
            system("cls");
            if(v.size()==0){
                cout<<"No hay elementos registrados"<<endl;
            }else{
                v.ultima_civilizacion();
            }
            system("pause");
        }
        else if(op=="7"){
            cout<<endl<<endl;
            system("cls");
            if(v.size()==0){
                cout<<"No hay elementos registrados"<<endl;
            }else{
                size_t op1;
                cout<<endl<<"Ordenar por: "<< endl;
                cout<<"1) Nombre"<<endl;
                cout<<"2) Ubicacion x"<<endl;
                cout<<"3) Ubicacion y"<<endl;
                cout<<"4) Puntuacion"<<endl;

                cin>>op1;
                
                if(op1==1){
                    v.ordenar_nombre();
                }else if(op1==2){
                    v.ordenar_ux();
                }else if(op1==3){
                    v.ordenar_uy();
                }else if(op1==4){
                    v.ordenar_punt();}
                }
                system("pause");
        }
        else if(op=="8"){
            cout<<endl<<endl;
            system("cls");
            if(v.size()==0){
                cout<<"No hay elementos registrados"<<endl;
            }else{
                string nombre;
                Civilizacion c;

                cout<<"Nombre a eliminar: ";
                getline(cin,nombre);
                c.setNombre(nombre);
                Civilizacion* ptr=v.buscar(c);

                if(ptr==nullptr){
                    cout<<"No encontrado"<<endl<<endl;
                }
                else{
                    v.eliminar(*ptr);
                }
            }
            system("pause");
        }
        else if(op=="9"){
            cout<<endl<<endl;
            system("cls");

            string nombre;
            Civilizacion c;

            cout<<"Nombre a buscar: ";
            getline(cin,nombre);
            c.setNombre(nombre);
            Civilizacion* ptr=v.buscar(c);

            if(ptr==nullptr){
                cout<<"Civilizacion no encontrada"<<endl<<endl;
            }
            else{
                cout<<left;
                cout<<setw(15)<<"Nombre"
                <<setw(20)<<"Ubicacion x"
                <<setw(20)<<"Ubicacion y"
                <<setw(15)<<"Puntuacion"<<endl;
                cout<<*ptr<<endl<<endl;
                cout<<"Presiona una tecla para continuar";
                cin.ignore();
                menu(*ptr);
            }
            system("pause");
        }
        else if(op=="10"){
            cout<<endl<<endl;
            system("cls");

            size_t ux,uy,punt,op2;
            string nombre;
            Civilizacion c;

            cout<<"Nombre a modificar: ";
            getline(cin,nombre);
            c.setNombre(nombre);
            Civilizacion* ptr=v.buscar(c);

            if(ptr==nullptr){
                cout<<"Civilizacion no encontrada"<<endl<<endl;
            }
            else{
                cout<<endl<<"Menu de modificacion"<<endl;
                cout<<"1) Nombre"<<endl;
                cout<<"2) Ubicacion x"<<endl;
                cout<<"3) Ubicacion y"<<endl;
                cout<<"4) Puntuacion"<<endl;
                cin>>op2;

                if(op2==1){
                    cout<<"Ingrese un nombre: ";
                    cin>>nombre;
                    ptr->setNombre(nombre);
                }else if(op2==2){
                    cout<<"Ingrese la ubicacion en x: ";
                    cin>>ux;
                    ptr->setUbicacion_x(ux);
                }else if(op2==3){
                    cout<<"Ingrese la ubicacion en y: ";
                    cin>>uy;
                    ptr->setUbicacion_y(uy);
                }else if(op2==4){
                    cout<<"Ingrese la puntuacion: ";
                    cin>>punt;
                    ptr->setPuntuacion(punt);
                }
            }
            system("pause");
        }
        else if(op=="11"){
            cout<<endl<<endl;
            v.mostrar();
        }
        else if(op=="12"){
            v.respaldar();
        }
        else if(op=="13"){
            v.recuperar();
        }
        else if(op=="14"){
            break;
        }
    }
    return 0;
}