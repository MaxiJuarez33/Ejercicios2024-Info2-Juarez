#include <stdio.h>

int main()
{
    int cantNumeros = 0, suma = 0;

    while (1)
    {
        int ingreso = 0;

        printf("Ingrese un numero entero o 999 para terminar el bucle: ");
        scanf("%d", &ingreso);

        if (ingreso != 999)
        {
            cantNumeros++;
            suma += ingreso;
        }
        else
        {
            break;
        }
    }

    float average = suma / (float)cantNumeros;

    printf("\n\nEl promedio de los %d numeros ingresados, es de %.2f", cantNumeros, average);

    return 0;
}