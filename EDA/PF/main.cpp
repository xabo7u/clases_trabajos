#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <windows.h>

#include "listaCanciones.h"
#include "spotify.h"

int menu(int);

int main()
{
   listaCanciones LC;
   crearLista(LC);
   int id = 1;
   int opcion = 1;
   int formato;

   	std::cout << "\n \n \nIngrese 1 si queiere el programa de forma recursiva, ingrese 2 si lo quiere de forma iterativa: " << std::endl;
	std::cin >> formato;
	system("cls");

	while (formato == 1 && opcion != 0) {
		opcion = menu(2);
		switch (opcion) {
		case 1: {
			CANCION c;
			c.idSong = id++;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			std::cout << "Ingrese autor de la Cancion" << std::endl;
			std::cin >> c.nombre_autor;
			insertFront(LC, c);
			std::cout << "Ingreso correcto" << std::endl;
			sleep(1);
			break;
		}
		case 2: {
			CANCION c;
			c.idSong = id++;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			std::cout << "Ingrese autor de la Cancion" << std::endl;
			std::cin >> c.nombre_autor;
			insertLastR(LC, c);
			std::cout << "Ingreso correcto" << std::endl;
			sleep(1);
			break;
		}
		case 3: {
			CANCION c;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			BuscarCancionNombreR(LC,c);
			sleep(1);
			break;
		}
		case 4: {
			CANCION c;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			std::cout << "Ingrese autor de la Cancion" << std::endl;
			std::cin >> c.nombre_autor;
			deleteCancionR(LC, c);
			sleep(1);
			break;
		}
		case 5: {
			mostrarListaR(LC);
			sleep(3);
			break;
		}
		case 6: {
			ordenarPorIdR(LC);
			sleep(1);
			break;			
		}
		case 7: {
			int id;
			std::cout << "Ingrese ID para mostrar la cancion anterior." << std::endl;
			std::cin >> id;
			mostrarCancionAnteriorR(LC, id);
			sleep(2);
			break;			
		}
		case 8: {
			int id;
			std::cout << "Ingrese ID de la cancion a modificar" << std::endl;
			std::cin >> id;
			actualizarCancionR(LC,id);
			sleep(1);
			break;			
		}
		case 9: {
			int x = cantidadCancionesR(LC);
			std::cout << "Cantidad de canciones: " << x << std::endl;
			sleep(1);
			break;			
		}
		case 10: {
			char artista[50];
			std::cout << "Ingrese autor." << std::endl;
			std::cin >> artista;
			mostrarCancionesArtistaR(LC,artista);
			sleep(1);
			break;			
		}
		case 11: {
			listarArtistasR(LC);
			sleep(3);
			break;			
		}
		case 12: {
			borrarListaR(LC);
			crearLista(LC);
			id = 1;
			sleep(1);
			break;			
		}
		}
	}

	while (formato == 2 && opcion != 0) {
		opcion = menu(9);
		switch (opcion) {
		case 1: {
			CANCION c;
			c.idSong = id++;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			std::cout << "Ingrese autor de la Cancion" << std::endl;
			std::cin >> c.nombre_autor;
			insertFront(LC, c);
			std::cout << "Ingreso correcto" << std::endl;
			sleep(1);
			break;
		}
		case 2: {
			CANCION c;
			c.idSong = id++;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			std::cout << "Ingrese autor de la Cancion" << std::endl;
			std::cin >> c.nombre_autor;
			insertLastI(LC, c);
			std::cout << "Ingreso correcto" << std::endl;
			sleep(1);
			break;
		}
		case 3: {
			CANCION c;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			BuscarCancionNombreI(LC,c);
			sleep(1);
			break;
		}
		case 4: {
			CANCION c;
			std::cout << "Ingrese nombre de la Cancion" << std::endl;
			std::cin >> c.nombre_song;
			std::cout << "Ingrese autor de la Cancion" << std::endl;
			std::cin >> c.nombre_autor;
			deleteCancionI(LC, c);
			sleep(1);
			break;
		}
		case 5: {
			mostrarListaI(LC);
			sleep(3);
			break;
		}
		case 6: {
			LC = ordenarCancionesIdI(LC);
			sleep(1);
			break;			
		}
		case 7: {
			int id;
			std::cout << "Ingrese ID para mostrar la cancion anterior." << std::endl;
			std::cin >> id;
			mostrarCancionAnteriorI(LC, id);
			sleep(2);
			break;			
		}
		case 8: {
			int id;
			std::cout << "Ingrese ID de la cancion a modificar" << std::endl;
			std::cin >> id;
			actualizarCancionI(LC,id);
			sleep(1);
			break;			
		}
		case 9: {
			int x = cantidadCancionesI(LC);
			std::cout << "Cantidad de canciones: " << x << std::endl;
			sleep(1);
			break;			
		}
		case 10: {
			char artista[50];
			std::cout << "Ingrese autor." << std::endl;
			std::cin >> artista;
			mostrarCancionesArtistaI(LC,artista);
			sleep(1);
			break;			
		}
		case 11: {
			mostrarArtistasI(LC);
			sleep(3);
			break;			
		}
		case 12: {
			borrarListaI(LC);
			crearLista(LC);
			id = 1;
			sleep(1);
			break;			
		}
		}
	}
    return 0;
}


int menu(int color){
	system("cls");
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
	std::cout << "             @@@@@@@@@@@@@@@				 ";	SetConsoleTextAttribute(hconsole, 7);	std::cout <<"Menu principal\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "          @@@@@@@@@@@@@@@@@@@@@@         \n";
	std::cout << "       @@@@@@@@@@@@@@@@@@@@@@@@@@@       \n";
	std::cout << "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     \n";
	std::cout << "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	    ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	1 - Ingresar Cancion en la primera posicion.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	2 - Ingresar Cancion en la ultima posicion.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << " @@@@@@@@@               @@@@@@@@@@@@@@@  ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	3 - Buscar cancion por nombre.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << " @@@@@@                         @@@@@@@@  ";SetConsoleTextAttribute(hconsole, 7);	    std::cout<<"	4 - Eliminar una Cancion.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@       @@@@@@ ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	5 - Mostrar lista de Canciones.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@ ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	6 - Ordenar lista de canciones por ID.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "@@@@@@@@@                 @@@@@@@@@@@@@@@ ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"    	7 - Mostrar cancion anterior.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "@@@@@@@@   @@@@@@@@@@@@       @@@@@@@@@@@ ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	8 - Actualizar datos de una cancion.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@ ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	9 - Mostrar Cantidad de canciones de la lista.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "@@@@@@@@@@@@@@@     @@@@@@@@@@@@@@@@@@@@@ ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	10 - Mostrar las canciones de un artista.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << " @@@@@@@@     @@@@@@       @@@@@@@@@@@@@  ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	11 - Mostrar solo los artistas de la lista.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@  ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	12 - Borrar toda la lista de canciones.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ";SetConsoleTextAttribute(hconsole, 7);		std::cout<<"	0 - Salir.\n";SetConsoleTextAttribute(hconsole, color);
	std::cout << "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    \n";
	std::cout << "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     \n";
	std::cout << "       @@@@@@@@@@@@@@@@@@@@@@@@@@@       \n";
	std::cout << "         @@@@@@@@@@@@@@@@@@@@@@@         \n";
	std::cout << "             @@@@@@@@@@@@@@@             \n";
	SetConsoleTextAttribute(hconsole, 7);
	std::cout << std::endl;
	std::cout << "Opcion: ";
	int op;
	std::cin >> op;
	return op;
}
