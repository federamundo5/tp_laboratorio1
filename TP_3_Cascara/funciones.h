#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int status;
}EMovie;



/** \brief Inicializacion del array
 *
 * \param Estructura movies
 * \param longitud del array
 * \return
 *
 */

void inicializacion(EMovie* movies, int longitud);



/** \brief
 *
 * \param estructura de  EMovie*
 * \param cantidad
 * \return void
 *
 */


void OpenArchivo(EMovie *movies, int longitud);


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no

 */


void setMovie(EMovie* Movies,char auxTitulo[],char auxGenero[],int auxDuracion,char auxDescripcion[],int auxPuntaje,char auxImagen[]);

void generarPaginaWeb(EMovie Movies[], int longitud);

void GuardarBinario(EMovie *Movies, int longitud);

int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
