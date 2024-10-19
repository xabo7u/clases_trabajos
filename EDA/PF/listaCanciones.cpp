#include <iostream>
#include <string.h>
#include <set>
#include <windows.h>
#include "listaCanciones.h"


using namespace std;

void crearLista(listaCanciones &l){
	l = NULL;
}

bool esVacia(listaCanciones l){
	return l == NULL;
}

void insertFront(listaCanciones &l, CANCION can){
	listaCanciones nuevo = new nodoSong;
	if(!esVacia(l))
		l->sig = nuevo;
	nuevo->c = can;
	nuevo->ant = l;
	nuevo->sig = NULL;
	l = nuevo;
}



void mostrarListaR(listaCanciones l){
	if (esVacia(l))
		cout << " " << endl;
	else{
		mostrarListaR(l->ant);
    	std::cout << "\n	ID:      "  << l->c.idSong << std::endl;
    	std::cout << "	Nombre:  "  << l->c.nombre_song << std::endl;
    	std::cout << "	Autor:   "  << l->c.nombre_autor << std::endl;
	}
}

void insertLastR(listaCanciones &l, CANCION can) {
	if(esVacia(l)){
		listaCanciones nuevo = new nodoSong;
		nuevo->c = can;
		nuevo->ant = NULL;
		nuevo->sig = NULL;
		l = nuevo;
	}
	else if (l->ant == NULL) {
		listaCanciones nuevo = new nodoSong;
		nuevo->c = can;
		nuevo->ant = NULL;
		nuevo->sig = l;
		l->ant = nuevo;
	}
	else {
		insertLastR(l->ant, can);
	}
}

void deleteCancionR(listaCanciones &l, CANCION can) {
	if (l == NULL) {
		std::cout << "Cancion no existe" << std::endl;
	}
	else if (strcmp(l->c.nombre_song, can.nombre_song) == 0 && strcmp(l->c.nombre_autor, can.nombre_autor) == 0) {
		if (l->ant != NULL) {
			l->ant->sig = l->sig;
		} else {
			l->sig->ant = NULL;
			return;
		}
		if (l->sig != NULL) {
			l->sig->ant = l->ant;
		} else {
			l->ant->sig = NULL;
			l = l->ant;
			return;
		}
	}
	else {
		deleteCancionR(l->ant, can);
	}
}

void BuscarCancionNombreR(listaCanciones &l, CANCION can) {
	if (l == NULL){
		std::cout << "\n" << std::endl;
	} else if (strcmp(l->c.nombre_song, can.nombre_song) == 0) {
		std::cout << "\n	ID:      "  << l->c.idSong << std::endl;
    	std::cout << "	Nombre:  "  << l->c.nombre_song << std::endl;
    	std::cout << "	Autor:   "  << l->c.nombre_autor << std::endl;
		BuscarCancionNombreR(l->ant, can);
	}
	else {
		BuscarCancionNombreR(l->ant, can);
	}
}

void mostrarCancionAnteriorR(listaCanciones l, int id){
	if (l == NULL){
		std::cout << "\nLa cancion ingresada no existe." << std::endl;
	} else if (l->c.idSong == id) {
		std::cout << "\n	ID:      "  << l->ant->c.idSong << std::endl;
    	std::cout << "	Nombre:  "  << l->ant->c.nombre_song << std::endl;
    	std::cout << "	Autor:   "  << l->ant->c.nombre_autor << std::endl;
	}
	else {
		mostrarCancionAnteriorR(l->ant, id);
	}
}

void actualizarCancionR(listaCanciones &l, int id){
	if (l == NULL){
		std::cout << "\nLa cancion ingresada no existe." << std::endl;
	} else if (l->c.idSong == id) {
			std::cout << "Ingrese nuevo nombre de la Cancion." << std::endl;
			std::cin >> l->c.nombre_song;
			std::cout << "Ingrese nuevo autor de la Cancion." << std::endl;
			std::cin >> l->c.nombre_autor;
			std::cout << "Cancion modificado con exito." << std::endl;
	}
	else {
		actualizarCancionR(l->ant, id);
	}
}

void mostrarCancionesArtistaR(listaCanciones l, char artista[50]){
	if (esVacia(l))
		cout << " " << endl;
	else if (strcmp(l->c.nombre_autor, artista) == 0) { 
    	std::cout << "\n	ID:      "  << l->c.idSong << std::endl;
    	std::cout << "	Nombre:  "  << l->c.nombre_song << std::endl;
    	std::cout << "	Autor:   "  << l->c.nombre_autor << std::endl;
		mostrarCancionesArtistaR(l->ant, artista);
	} else {
		mostrarCancionesArtistaR(l->ant, artista);
	}
}

void borrarListaR(listaCanciones &l) {
    if (l == NULL) {
        return;
    }
    borrarListaR(l->ant);
    l = NULL;
}

int cantidadCancionesR(listaCanciones l){
    if (l == NULL) {
        return 0;
    }
    return 1 + cantidadCancionesR(l->ant);
}

void ordenarPorIdR(listaCanciones &l) {
    if (l == NULL || l->ant == NULL) {
        return;
    }

    listaCanciones primerNodo = l;
    l = l->ant;

    ordenarPorIdR(l);
    insertarOrdenadoPorId(l, primerNodo);
}

void insertarOrdenadoPorId(listaCanciones &l, listaCanciones nodo) {
    if (l == NULL || l->c.idSong >= nodo->c.idSong) {
        nodo->ant = l;
        if (l != NULL) {
            l->sig = nodo;
        }
        l = nodo;
    } else {
        insertarOrdenadoPorId(l->ant, nodo);
    }
}

void listarArtistasR(listaCanciones l) {
    if (esVacia(l)) {
        return;
    }
    std::set<std::string> artistas;
    listarArtistasAuxR(l, artistas);
    std::cout << "Artistas en la lista:" << std::endl;
    for (const std::string& artista : artistas) {
        std::cout << artista << std::endl;
    }
}

void listarArtistasAuxR(listaCanciones l, std::set<std::string>& artistas) {
    if (esVacia(l)) {
        return;
    }
    artistas.insert(l->c.nombre_autor);
    listarArtistasAuxR(l->ant, artistas);
}


//ITERATIVA

void mostrarListaI(listaCanciones l){
	int size = cantidadCancionesR(l);
	for(int i = 0; i < size; i++){
		std::cout << "\n	ID:      "  << l->c.idSong << std::endl;
    	std::cout << "	Nombre:  "  << l->c.nombre_song << std::endl;
    	std::cout << "	Autor:   "  << l->c.nombre_autor << std::endl;
		l = l->ant;
	}
}

void insertLastI(listaCanciones &l, CANCION can){
 listaCanciones nuevo = new nodoSong;
    nuevo->c = can;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    if (esVacia(l)) {
        l = nuevo;
        return;
    } else {
		int size = cantidadCancionesI(l);
		int cont = 0;
		for(int i = 0; i < size; i++){
			if(l->ant == NULL){
				nuevo->sig = l;
				l->ant = nuevo;
				break;
			}
			l = l->ant;
			cont++;
		}
		for(int i = 0; i < cont; i++){
			l = l->sig;
		}
	}
}

void deleteCancionI(listaCanciones &l, CANCION can){
    int size = cantidadCancionesI(l);
    int cont = 0;
    bool existe = false;
    for(int i = 0; i < size; i++){
        if(strcmp(l->c.nombre_autor, can.nombre_autor) == 0 && strcmp(l->c.nombre_song, can.nombre_song) == 0){
			existe = true;
            if(l->sig != NULL) {
                l->sig->ant = l->ant;
			} else {
				l->ant->sig = NULL;
				l = l->ant;
				return;
			}
            if(l->ant != NULL) {
                l->ant->sig = l->sig;
			} else {
				l->sig->ant = NULL;
				for(int i = 0; i < cont; i++){
        			l = l->sig;
    			}
				return;
			}
            break;
        }
        l = l->ant;
        cont++;
    }
    
	if(!existe){
		std::cout << "La cancion no existe." << std::endl;
		return;
	}

    for(int i = 0; i < cont; i++){
        l = l->sig;
    }

}

void BuscarCancionNombreI(listaCanciones l, CANCION can){
	int size = cantidadCancionesI(l);
	int cont = 0;
	bool existe = false;

	for(int i = 0; i < size; i++){
		if(strcmp(l->c.nombre_song, can.nombre_song) == 0){
			existe = true;
			std::cout << "\n	ID:      "  << l->c.idSong << std::endl;
    		std::cout << "	Nombre:  "  << l->c.nombre_song << std::endl;
    		std::cout << "	Autor:   "  << l->c.nombre_autor << std::endl;
		}
		l = l->ant;
		cont++;
	}

	if(!existe){
		std::cout << "La cancion no existe" << std::endl;
		return;
	}
}

void actualizarCancionI(listaCanciones &l, int id){
	int size = cantidadCancionesI(l);
	int cont = 0;
	bool existe = false;
	for(int i = 0; i < size; i++){
		if (l->c.idSong == id) {
			existe = true;
			std::cout << "Digite el nuevo nombre de la cancion" << std::endl;
			std::cin >> l->c.nombre_song;
    		std::cout << "Digite el nuevo autor"  << l->c.nombre_autor << std::endl;
			std::cin >> l->c.nombre_autor;
			break;
		}
		l = l->ant;
		cont++;
	}

	if(!existe){
		std::cout << "La cancion no existe" << std::endl;
		return;
	}
	
	for(int i = 0; i < cont; i++){
		l = l->sig;
	}
}

void mostrarCancionesArtistaI(listaCanciones l, char artista[50]){
	int size = cantidadCancionesI(l);
	for(int i = 0; i < size; i++){
		if (strcmp(l->c.nombre_autor, artista) == 0) {
			std::cout << "\n	ID:      "  << l->c.idSong << std::endl;
    		std::cout << "	Nombre:  "  << l->c.nombre_song << std::endl;
    		std::cout << "	Autor:   "  << l->c.nombre_autor << std::endl;
		}
		l = l->ant;
	}
}

void borrarListaI(listaCanciones &l){
	int size = cantidadCancionesI(l);
	for(int i = 0; i < size; i++){
		delete l->sig;
		l = l->ant;
	}
	l == NULL;
}

void mostrarCancionAnteriorI(listaCanciones l, int id){
	int size = cantidadCancionesI(l);
	for(int i = 0; i < size; i++){
		if (l->c.idSong == id) {
			if(l->ant != NULL){
				std::cout << "\n	ID:      "  << l->ant->c.idSong << std::endl;
    			std::cout << "	Nombre:  "  << l->ant->c.nombre_song << std::endl;
    			std::cout << "	Autor:   "  << l->ant->c.nombre_autor << std::endl;
				return;
			} else {
				std::cout << "No tiene cancion anterior" << std::endl;
				return;
			}
		}
		l = l->ant;
	}
	std::cout << "La cancion no existe" << std::endl;
}

listaCanciones ordenarCancionesIdI(listaCanciones &l) {
	if(l == NULL){
		return l;
	}
	int size = cantidadCancionesI(l);
	CANCION c[size];
	for (int i = 0; i < size; i++) {
		c[l->c.idSong - 1] = l->c;
		l = l->ant;
	}
	listaCanciones LC = new nodoSong;
	crearLista(LC);
	for (int i = 0; i < size; i++) {
		insertFront(LC,c[i]);
	}
	return LC;
}

void mostrarArtistasI(listaCanciones l){
	if(l != NULL){
	int size = cantidadCancionesI(l);
	int cont = 0;
	bool existe = false;
	CANCION c[size];

	for (int i = 0; i < size && l != NULL; i++) {
		for (int j = 0; j < cont + 1 && !existe; j++){
			if(strcmp(l->c.nombre_autor, c[j].nombre_autor) == 0)
				existe = true;
		}
		if (!existe){
			c[cont] = l->c;
			cont = cont + 1;
		}
		existe = false;
		l = l->ant;
	}
	
	std::cout << "\nLista de autores:" << std::endl;

	for (int i = 0; i < cont; i++) {
		std::cout << "\n" << c[i].nombre_autor;
	}

	} else {
		std::cout << "No hay artistas" << std::endl;
	}
}

int cantidadCancionesI(listaCanciones l){
	int cantidad = 0;
	while(l != NULL){
		l = l->ant;
		cantidad++;
	}
	return cantidad;
}