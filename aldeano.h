#ifndef ALDEANO_H
#define ALDEANO_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Aldeano
{
    string nombre;
    int edad;
    string genero;
    int salud;
public:
    Aldeano();
    string getNombre() const;
    void setNombre(const string &value);
    int getEdad() const;
    void setEdad(int value);
    string getGenero() const;
    void setGenero(const string &value);
    int getSalud() const;
    void setSalud(int value);
    friend istream & operator>> (istream &in , Aldeano &a){
        string s;
        int valor;
        cout << "Nombre: ";
        getline(cin, s);
        a.setNombre(s);
        cout << "Edad: ";
        cin>>valor;
        a.setEdad(valor);
        cin.ignore();
        cout << "Genero: ";
        getline(cin, s);
        a.setGenero(s);
        cout << "Salud: ";
        cin>>valor;
        a.setSalud(valor);
        return in;
    }
    friend ostream & operator<<(ostream &out, const Aldeano &a){
        cout << left;
        out << setw(10) << a.nombre;
        out << setw(10) << a.edad ;
        out << setw(10) << a.genero;
        out << setw(10) << a.salud;
        cout<<endl;
        return out;
    }
    bool operator==(const Aldeano &a) const{
        return nombre == a.nombre;
    }
};
#endif // ALDEANO_H
