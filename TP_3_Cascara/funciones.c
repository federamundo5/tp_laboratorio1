#include "funciones.h"
#define  MAX 5




void iniciar(EMovie* movies, int longitud)
{ int i;
    if(movies!= NULL )
    {
        for (i=0; i<longitud; i++)
        {
            movies[i].status=-1;
        }
    }
}



void OpenArchivo(EMovie *movies, int longitud)
{
    FILE *f;
    f = fopen("bin.dat", "rb");

    if(f == NULL)
    {
        printf("No se pudo abrir el fichero");
        //exit(1)
    }


    fread(movies, sizeof(EMovie), longitud, f);
    system("pause");

    fclose(f);
}


void setMovie(EMovie* Movies,char auxTitulo[],char auxGenero[],int auxDuracion,char auxDescripcion[],int auxPuntaje,char auxImagen[])
{ int i=0;

    for (i=0; i<MAX; i++)
    {
        if (Movies[i].status==-1)
        {
        strcpy(Movies[i].titulo,auxTitulo);
        strcpy(Movies[i].genero,auxGenero);
        strcpy(Movies[i].descripcion,auxDescripcion);
        strcpy(Movies[i].linkImagen,auxImagen);
        Movies[i].duracion = auxDuracion;
        Movies[i].status = 1;
        Movies[i].puntaje = auxPuntaje;
        }

        if(i==MAX&&Movies[i].status!=-1)
        {
            printf("No Hay Espacio");
        }
    }
}



void generarPaginaWeb(EMovie Movies[], int longitud)
{
    int i;
FILE *f;
f=fopen("pagina.html", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

  for(i=0;i<longitud;i++)
    {
        if(Movies[i].status==1)
        {
         fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", Movies[i].linkImagen);
         fprintf(f,"</a><h3><a href='#'>%s</a></h3><ul>",Movies[i].titulo);
         fprintf(f,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", Movies[i].genero, Movies[i].puntaje,Movies[i].duracion);
         fprintf(f,"<p>%s</p></article>",Movies[i].descripcion);
        }
    }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
    printf("\n\n archivo escrito con exito\n\n");

}




void GuardarBinario(EMovie *Movies, int longitud)
{
    FILE *f;
    f = fopen("bin.dat", "wb");
    if(f == NULL)
    {
        printf("No se pudo abrir el fichero");
        exit(1);
    }

    fwrite(Movies, sizeof(EMovie), longitud, f);

    printf("\nFichero guardado con exito\n");

    fclose(f);
}


