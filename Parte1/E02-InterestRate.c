/**
 * @file E02-InteresetRate.c
 * @brief Programa hecho para calcular el interes compuesto de una inversion, con una tasa variable del 5, 6, 8, 9 y 10% de interes, en un plazo de 10 años con un monto inicial de $1000.00
 */

#include <stdio.h>
#include <math.h> /** @brief Esta libreria es incluida para poder utilizar la funcion de la potencia, pow() */

/**
 * @brief La funcion main() contiene todo el programa, contiene dos fors en cadena donde uno tiene la funcion de contar años y el otro en cambiar el indice del array de interes
 */

int main()
{
    double interes[] = {.05, .06, .08, .1}, montoAcumuladoVariable, montoInicial = 1000.00; /** @brief Todas las variables  del programa declaradas */

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            montoAcumuladoVariable = montoInicial * pow((1 + interes[j]), i); /** @brief En esta operacion se realiza el calculo del interes @param j, correspondiente al año @param i, asignando el resultado a la variable de @param montoAcumuladoVariable */

            printf("\n\nEl monto acumulado en el año %d y de interes %.2lf es de $%.2lf\n", i, interes[j], montoAcumuladoVariable);
            printf("Presione Enter para continuar...");
            getchar(); /** @brief Esta funcion permite esperar a que el usuario presione una tecla para continuar, asi evitar que el programa se ejecute completo en segundos */
        }
    }

    return 0;
}