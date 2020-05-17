#include "empleado.h"

int findEmployeeById(eEmployees list[],int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            return i;
        }
    }

    return -1;
}

int getInt(char mensaje[])
{
    int num;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &num);

    return num;
}

void initEmployees(eEmployees list[],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
        list[i].id = -1;
    }
}

void addEmployee(eEmployees list[],int len)
{
    int i;

    i=findEmployeeById(list,len);

    if(i!=-1)
    {
        list[i].id=i+1;

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(list[i].name);

        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(list[i].lastName);

        printf("Ingrese el sueldo: ");
        scanf("%f", &list[i].salary);

        printf("Ingrese el sector: ");
        scanf("%d", &list[i].sector);

        list[i].isEmpty=0;
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
}

void removeEmployee(eEmployees list[], int len)
{
    int i;
    int id;
    int flag=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty!=1)
        {
            id=getInt("Ingrese el legajo del empleado a dar de baja: ");

            for(i=0; i<len; i++)
            {
                if (id==list[i].id)
                {
                    printf("Se ha dado de baja al siguiente empleado:\n");
                    printEmployee(list[i]);
                    list[i].isEmpty = 1;
                    flag=1;
                }
            }

            if(flag==0)
            {
                printf("No ingreso un legajo valido\n");
            }
        }
        else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
        break;
    }


}

void modifyEmployee(eEmployees list[],int len)
{
    int i;
    int flag=0;
    int option;
    int id;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty!=1)
        {
            id=getInt("Ingrese el id del empleado a modificar: ");

            for(i=0; i<len; i++)
            {
                if (id==list[i].id && list[i].isEmpty==0)
                {
                    printf("Se modificara el siguiente empleado:\n");
                    printEmployee(list[i]);

                    option=getInt("Escoja lo que quiere modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\nElija una opcion: ");
                    switch(option)
                    {
                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(list[i].name);
                        flag=1;
                        break;
                    case 2:
                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(list[i].lastName);
                        flag=1;
                        break;
                    case 3:
                        printf("Ingrese nuevo salario: ");
                        scanf("%f", &list[i].salary);
                        flag=1;
                        break;
                    case 4:
                        printf("Ingrese nuevo sector: ");
                        scanf("%d", &list[i].sector);
                        flag=1;
                        break;
                    case 5:
                        flag=1;
                        break;
                    }
                }
            }

            if(flag==0)
            {
                printf("No ingreso un legajo valido\n");
            }
        }
        else
        {
            printf("En el sistema no figuran empleados cargados \n");
        }
        break;
    }
}

void orderEmployees(eEmployees list[], int len, eEmployees aux)
{
    int i;
    int j;

    for(i=0; i<len-1; i++)
    {
        if(list[i].isEmpty==0)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[j].isEmpty==0)
                {
                    if(list[i].sector>list[j].sector)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                    else if(list[i].sector==list[j].sector)
                    {
                        if(stricmp(list[i].lastName, list[j].lastName)>0)
                        {
                            aux=list[i];
                            list[i]=list[j];
                            list[j]=aux;
                        }
                        else if(stricmp(list[i].lastName, list[j].lastName)==0)
                        {
                            if(stricmp(list[i].name, list[i].name)>1)
                            {
                                aux=list[i];
                                list[i]=list[j];
                                list[j]=aux;
                            }
                        }
                    }
                }
            }
        }
    }
}

void printEmployee(eEmployees unEmpleado)
{
    printf("%d\t%s\t\t%s\t\t%.2f\t\t%d\n", unEmpleado.id,unEmpleado.name, unEmpleado.lastName, unEmpleado.salary,unEmpleado.sector);
}

void printListEmployees(eEmployees list[], int len)
{
    int i;
    eEmployees aux;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty!=1)
        {
            orderEmployees(list,len,aux);
            for(i=0; i<len; i++)
            {
                if(list[i].isEmpty!=1)
                {
                    printEmployee(list[i]);
                }
            }
        }
        else
        {
            printf("En el sistema no hay empleados cargados\n");
        }
        break;
    }
}
