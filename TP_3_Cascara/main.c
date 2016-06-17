#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 5

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie Movies[50];
    iniciar(Movies,MAX);
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[100];
    char auxImagen[50];
    int auxDuracion;
    int auxPuntaje;
    int auxIndex;






    OpenArchivo(Movies,MAX);
    GuardarBinario(Movies,MAX);


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3 - Modificar Pelicula \n");
         printf("4- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            getString("Ingrese el titulo de la pelicula: ",auxTitulo);
            fflush(stdin);
            getString("Genero",auxTitulo);
            fflush(stdin);
            getString("Ingrese el genero de la pelicula: ",auxGenero);
            fflush(stdin);
            getString("Ingrese la imagen de la pelicula: ",auxImagen);
            fflush(stdin);
            getString("Ingrese descripcion ",auxDescripcion);
            fflush(stdin);
            auxDuracion=getInt("Ingrese duracion");
            auxPuntaje=getInt("Ingrese autonomia");
            setMovie(Movies,auxTitulo,auxGenero,auxDuracion,auxDescripcion,auxPuntaje,auxImagen);
            break;

                case 2:
                printf("Ingrese indice");
                scanf("%d", &auxIndex);
                fflush(stdin);
                   if(Movies[auxIndex].status==1)
                {
                    Movies[auxIndex].status=-1;
                   printf("Pelicula Borrada.\n.\n.\n");
                }
                else
                {
                    printf("Error.\n");
                }


                break;


                       case 3:
                        printf("Ingrese indice a modificar");
                        scanf("%d", &auxIndex);
                        fflush(stdin);
                           if(Movies[auxIndex].status==1)
                        {
                        getString("Ingrese el titulo de la pelicula: ",auxTitulo);
                        fflush(stdin);
                        getString("Genero",auxTitulo);
                        fflush(stdin);
                        getString("Ingrese el genero de la pelicula: ",auxGenero);
                        fflush(stdin);
                        getString("Ingrese la imagen de la pelicula: ",auxImagen);
                        fflush(stdin);
                        getString("Ingrese descripcion ",auxDescripcion);
                        fflush(stdin);
                        auxDuracion=getInt("Ingrese duracion");
                        auxPuntaje=getInt("Ingrese autonomia");
                        strcpy(Movies[auxIndex].titulo,auxTitulo);
                        strcpy(Movies[auxIndex].genero,auxGenero);
                        strcpy(Movies[auxIndex].descripcion,auxDescripcion);
                        strcpy(Movies[auxIndex].linkImagen,auxImagen);
                        Movies[auxIndex].duracion = auxDuracion;
                        Movies[auxIndex].status = 1;
                        Movies[auxIndex].puntaje = auxPuntaje;
                        }
                        else
                        {
                            printf("Error.\n");
                        }

                       break;


                                case 4:
                                    generarPaginaWeb(Movies,MAX);
                                    break;


                                    case 5:
                                    seguir = 'n';
                                    break;

        }
    }

    return 0;
}
