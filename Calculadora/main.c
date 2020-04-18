#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ingresoEnteros.h"
#include "operaciones.h"

int main()
{
    int flagA ,flagB ,flagCalculo ,factorialA ,factorailB;
    float  numeroA, numeroB, resultadoSuma, resultadoResta, ResultadoMultiplicacion, resultadoDivision;
    char opcion;

    flagA=0;
    flagB=0;
    flagCalculo=0;
    numeroA=0;
    numeroB=0;

    do
    {
        if(flagA==0)
        {
            printf("1.Ingresar 1er operando (A=X)");
        }else//notificacion de variable A
        {
            printf("1.Ingresar 1er operando (A=%.2f)",numeroA);
        }
        if(flagB==0)
        {
            printf("\n2.Ingresar 2do operando (B=y)");
        }else//notificacion de variable B
        {
            printf("\n2.Ingresar 2do operando (B=%.2f)",numeroB);
        }
        if(flagCalculo==0)//confirmacion de calculo
        {
            printf("\n3.Calcular");
        }else
        {
            printf("\n3.Calcular  OK!!!!");
        }


        printf("\n4.Informar resultados\n5.salir\nElija una opcion:");
        fflush(stdin);
        scanf("%c",&opcion);

        system("cls");

        switch(opcion)
        {
            case '1':
                numeroA=pedirEntero("Numero A: ");
                flagA=1;
                if(flagA==1)
                {
                    flagCalculo=0;
                }
                break;
            case '2':
                numeroB=pedirEntero("Numero B: ");
                flagB=1;
                if(flagB==1)
                {
                    flagCalculo=0;
                }

                break;
            case '3':
                resultadoSuma=calculoSuma(numeroA ,numeroB);
                resultadoResta=calculoResta(numeroA ,numeroB);
                ResultadoMultiplicacion=calculaMultiplicacion(numeroA ,numeroB);
                if(numeroB!=0)//verificacion de division por 0
                {
                    resultadoDivision=calculoDivision(numeroA ,numeroB);

                }
                if(!(numeroB<0 || numeroA<0))//verificacion de factoriales negativos
                {
                    factorialA=factorial(numeroA);
                    factorailB=factorial(numeroB);

                }
                flagCalculo=1;

                break;
            case '4':
                printf("El resultado de %.2f + %.2f es: %.2f\n",numeroA ,numeroB ,resultadoSuma);
                printf("El resultado de %.2f - %.2f es: %.2f\n",numeroA ,numeroB ,resultadoResta);
                printf("El resultado de %.2f * %.2f es: %.2f\n",numeroA ,numeroB ,ResultadoMultiplicacion);
                if(numeroB!=0)//verificacion en caso que se quiera dividir por 0
                {
                    printf("El resultado de %.2f / %.2f es: %.2f\n",numeroA ,numeroB ,resultadoDivision);
                }else
                {
                    printf("No es posible dividir por cero\n");
                }
                if(numeroB<0 || numeroA<0)//verificacion de factoriales negativos
                {
                    printf("No existen los factoriales negativos\n");
                }else
                {
                    printf("El factorial de %.0f es: %d y El factorial de %.0f es: %d\n",numeroA ,factorialA ,numeroB ,factorailB);

                }
                system("pause");

                break;
            case '5':
                printf("Que tenga un buen dia!!!\n");
                system("pause");

                break;
            default:
                printf("no ingreso una opcion valida\n");
                system("pause");

                break;
        }
        system("cls");

    }while(opcion!='5');


    return 0;
}
