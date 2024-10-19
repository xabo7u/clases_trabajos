#ifndef SPOTIFY_H_INCLUDED
#define SPOTIFY_H_INCLUDED

typedef struct song{
	int idSong;
	char nombre_song[50];
	char nombre_autor[50];
}CANCION;

typedef struct nodoSong{
	CANCION c;
	nodoSong *sig;
	nodoSong *ant;
}*listaCanciones;

#endif // SPOTIFY_H_INCLUDED
