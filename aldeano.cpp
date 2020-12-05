#include "aldeano.h"

Aldeano::Aldeano()
{

}

string Aldeano::getNombre() const
{
    return nombre;
}

void Aldeano::setNombre(const string &value)
{
    nombre=value;
}

int Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setEdad(int value)
{
    edad= value;
}

string Aldeano::getGenero() const
{
    return genero;
}

void Aldeano::setGenero(const string &value)
{
    genero= value;
}

int Aldeano::getSalud() const
{
    return salud;
}

void Aldeano::setSalud(int value)
{
    salud= value;
}

