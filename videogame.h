#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "civilizacion.h"

using namespace std;

class VideoGame
{
private:
    string nombre_usuario;
    vector<Civilizacion> civilizaciones;

public:
    VideoGame();
    void agregar_civilizacion(const Civilizacion &civ);
    void mostrar();
    void insertar_civilizacion(const Civilizacion &civ, size_t pos);
    void inicializar_civilizaciones(const Civilizacion &civ, size_t n);
    void primera_civilizacion();
    void ultima_civilizacion();
    void ordenar_nombre();
    void ordenar_ux();
    void ordenar_uy();
    void ordenar_punt();
    void eliminar(const Civilizacion &c);
    void getCivilizacion();
    void respaldar();
    void recuperar();

    Civilizacion* buscar(const Civilizacion &civ);


    size_t size()
    {
        return civilizaciones.size();
    }
    
    string getNombre_usuario()const;
    void setNombre_usuario(const string &value);
};

#endif// VIDEOGAME_H