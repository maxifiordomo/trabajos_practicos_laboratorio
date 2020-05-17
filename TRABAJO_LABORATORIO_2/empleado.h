#include <stdio.h>
#include "string.h"

typedef struct
{

 int id;
 char name[61];
 char lastName[61];
 float salary;
 int sector;
 int isEmpty;

} eEmployees;

typedef struct
{
    int idSector;
    int nameSector;

} eSector;

int findEmployeeById(eEmployees[],int);
int getInt(char[]);
void initEmployees(eEmployees[],int);
void addEmployee(eEmployees[],int);
void removeEmployee(eEmployees[],int);
void modifyEmployee(eEmployees[],int);
void orderEmployees(eEmployees[],int,eEmployees);
void printEmployee(eEmployees);
void printListEmployees(eEmployees[],int);

