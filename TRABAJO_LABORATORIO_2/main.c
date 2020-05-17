#include <stdlib.h>
#include "empleado.h"

#define X 1000

int main()
{
    int option;

    eEmployees list[X];

    initEmployees(list,X);

    do
    {
        option=getInt("1.Alta\n2.Modificacion\n3.Baja\n4.Informar la lista de empleados\n5.Salir del programa\nElija una opcion: ");
        switch(option)
        {
        case 1:
            addEmployee(list,X);
            break;
        case 2:
            modifyEmployee(list,X);
            break;
        case 3:
            removeEmployee(list,X);
            break;
        case 4:
            printListEmployees(list,X);
            break;
        }

        system("pause");
        system("cls");
    }
    while(option!=5);

    return 0;
}
