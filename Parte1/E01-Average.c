/**
 * @file E01-Average.c
 * @brief El programa 1 de la guia de ejercicios pide el calculo de el promedio de X numeros enteros, siendo X la cantidad que el usuario quiera ingresar, sin pedirle explicitamente que ingrese la cantidad deseada
 * @author Maximiliano Juarez
 */

#include <stdio.h>

/**
 * @brief La siguiente funcion main() contiene todo el funcionamiento del programa
 * @param cantNumeros es la variable que funciona como contador de la cantidad que numeros ingresados, cada vez que se ingrese uno se suma 1 a esta variable
 * @param suma es la variable que contiene el resultado de la suma de todos los numeros ingresados
 * @param ingreso funciona en conjunto con la variable suma, contiene el ultimo numero ingresado por el usuario
 * @param averge es lo que pide el programa, el promedio, que se obtiene dividiendo la suma de todos los numeros ingresados sobre la cantidad de numeros ingresados
 */

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