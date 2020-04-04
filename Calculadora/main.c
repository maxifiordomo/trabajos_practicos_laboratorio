
#include <stdio.h>

int main()
{
   char operador;
   float primerNumero, segundoNumero;

   printf("Ingrese el operador (puede ser +, -, , /) : ");
   scanf("%c", &operador);

   printf ("Ingrese los dos operandos: ");
   scanf ("%f %f", &primerNumero, &segundoNumero);

   switch (operador){
       case '+':
        printf("%f + %f = %f", primerNumero, segundoNumero, primerNumero + segundoNumero);
        break;
        case '-':
        printf("%f - %f = %f", primerNumero, segundoNumero, primerNumero - segundoNumero);
        break;
        case '*':
        printf("%f * %f = %f", primerNumero, segundoNumero, primerNumero * segundoNumero);
        break;
        case '/':
        printf("%f / %f = %f", primerNumero, segundoNumero, primerNumero / segundoNumero);
        break;
        default:
        printf("El operador no es correcto");
        break;
   }
}
