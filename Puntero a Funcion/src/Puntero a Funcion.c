/*
 ============================================================================
 Name        : Puntero.c
 Author      : Miguel Ángel Gil
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);

int calcular(int a, int b, int (*operacion)(int, int));

int main()
{
	setbuf(stdout, NULL);

    printf("%d\n", calcular(3, 18, sumar));

    printf("%d\n", calcular(3, 18, restar));

    printf("%d\n", calcular(3, 18, multiplicar));

    return 0;
}

int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}
int multiplicar(int a, int b)
{
    return a * b;
}

int calcular(int a, int b, int (*operacion)(int, int))
{

   return operacion(a, b);
}
