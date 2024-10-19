#ifndef LISTACANCIONES_H_INCLUDED
#define LISTACANCIONES_H_INCLUDED

#include "spotify.h"
#include <string.h>
#include <set>

void crearLista(listaCanciones &);
bool esVacia(listaCanciones);
void insertFront(listaCanciones &, CANCION);

//RECURSIVAS//
void mostrarCancionAnteriorR(listaCanciones, int);
void mostrarListaR(listaCanciones);
void insertLastR(listaCanciones &, CANCION);
void deleteCancionR(listaCanciones &, CANCION);
void BuscarCancionNombreR(listaCanciones &l, CANCION can);
void actualizarCancionR(listaCanciones &, int);
void mostrarCancionesArtistaR(listaCanciones, char [50]);
void borrarListaR(listaCanciones &);
int cantidadCancionesR(listaCanciones);

void ordenarPorIdR(listaCanciones &);
void insertarOrdenadoPorId(listaCanciones &, listaCanciones );

void listarArtistasR(listaCanciones );
void listarArtistasAuxR(listaCanciones , std::set<std::string>& );



//ITERATIVAS//
void mostrarCancionAnteriorI(listaCanciones, int);
void mostrarListaI(listaCanciones);
void insertLastI(listaCanciones &, CANCION);
void deleteCancionI(listaCanciones &, CANCION);
void BuscarCancionNombreI(listaCanciones , CANCION);
void actualizarCancionI(listaCanciones &, int);
void mostrarCancionesArtistaI(listaCanciones, char [50]);
void borrarListaI(listaCanciones &);
int cantidadCancionesI(listaCanciones);
listaCanciones ordenarCancionesIdI(listaCanciones &);
void mostrarArtistasI(listaCanciones);

#endif
