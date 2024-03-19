/**
 * @file E02-InterestRate.c
 * @brief Este programa permite calcular el interes compuesto, con distintos niveles de intereses, de una base de monto inicial de $1000
 * @author Maximiliano Juarez
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief El programa entero se encuentra en esta funcion, la cual se ocupa de la declaracion de variables, los bucles for para repetir y cambiar de tasa y el operador para calcular el interes
 */

int main()
{
    double interes[] = {.05, .06, .08, .1}, montoAcumuladoVariable, montoInicial = 1000.00;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            montoAcumuladoVariable = montoInicial * pow((1 + interes[j]), i);

            printf("\n\nEl monto acumulado en el año %d y de interes %.2lf es de $%.2lf\n", i, interes[j], montoAcumuladoVariable);
            printf("Presione Enter para continuar...");
            getchar();
        }
    }

    return 0;
}