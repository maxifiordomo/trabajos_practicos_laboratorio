#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operaciones.h"

float calculoSuma(float numeroX ,float numeroY)
{
    float suma;

    suma=numeroX+numeroY;

    return suma;
}

float calculoResta(float numeroX ,float numeroY)
{
    float resta;

    resta=numeroX-numeroY;

    return resta;
}
float calculaMultiplicacion(float numeroX ,float numeroY)
{
    float multiplicacion;

    multiplicacion=numeroX*numeroY;

    return multiplicacion;
}

float calculoDivision(float numeroX ,float numeroY)
{
    float division;

    division=numeroX/numeroY;

    return division;
}

int factorial(int numero)
{
    int resultado;

    if(numero==0 || numero==1)
    {
        resultado=1;
    }else
    {
        resultado=numero*factorial(numero-1);
    }

    return resultado;
}
