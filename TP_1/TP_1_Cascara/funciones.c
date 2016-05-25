#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



/** \brief retorna  resultado de la suma de dos n�meros

 * \param   primer numero
 * \param   segundo numero
 * \return resultado de la suma.
 *
 */
int suma(int numero1, int numero2)
{ int resultado;
    resultado=numero1+numero2;
    return resultado;
}

/** \brief  retorna resultado de la resta dos n�meros
 *
 * \param int a es el primer numero
 * \param int b es el segundo numero
 * \return returna resultado resta.
 *
 */
int  resta (int numero1, int numero2)
{
    int resultado;
    resultado=numero1-numero2;
    return resultado;
}

/** \brief retorna el resultado de una divisi�n
 *         Se utiliza la variable float resultado para guardar
 * \param numero1 es el dividendo
 * \param numero2 es el divisor
 * \return el resultado.
 *
 */
int division(int numero1, int numero2)
{
    float resultado;
    if(numero2!=0)
    {
        resultado=(float)numero1/numero2;
        return resultado;
    }else
    {
        printf("No se puede dividir con 0\n");
    }
}

/** \brief retorna el resultado de la multiplicacion
 * \param numero1
 * \param numero2
 * \return retorna resultado.
 *
 */
int multiplicacion (int numero1, int numero2)
{  int resultado;
    resultado=(numero1*numero2);
    return resultado;
}


/** \brief retorna el resultado de un factorial
 * \param numero1
 * \param numero2
 * \return retorna resultado.
 *
 */
int factorial(int numero)
{
    int resultado;
    if (numero>1)
    {
        resultado = numero*factorial(numero-1);
    }
    else
    {
        resultado=1;
    }

    return resultado;
}

/** \brief pide el ingreso de un n�mero y valida que sea un valor num�rico
 *
 * \return Retorna el valor del n�mero
 *
 */
int ingresoNumero(void)
{
    int numero;
    int validacion=0;

    printf("\nIngrese numero: ");
    validacion=scanf("%d",&numero);
    while(validacion==0)
    {
        printf("\nCaracter incorrecto, ingrese un numero: ");
        fflush(stdin);
        validacion=scanf("%d",&numero);
    }

    return numero;
}


