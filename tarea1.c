/**************************************************
*       Ingenieria Civil Informatica         	 *
*         Universidad de Concepcion 		     *
*                                                *
*                                                *
*               Tarea 1                          *
*    Arquitectura de Computadores                *
*              Grupo 001                         *
*                                                *
*                                                *
*    Vanessa Soledad Arriagada Pérez             *
*    César Andrés Bolívar Severino 	             *
*    Daniel Antonio Ortega Cárcamo 	 	         *
*    Carlos Ignacio Provoste Viveros  	         *
*    		                                     *
**************************************************/

#include <stdio.h>
#include <limits.h>

int isZero(int x);
int minusOne(void);
int bitNor(int x, int y);
int getByte(int x, int n);
int isNotEqual(int x, int y);
int negate(int x);
int isPositive(int x);
int isGreater(int x, int y);
int reverseBytes(int x);
int isPower2(int x);

int main(int argc, char const *argv[])
{
    printf("%d\n", isZero(5));
    printf("%d\n", isZero(0));
    printf("%d\n", minusOne());
    printf("%d\n", bitNor(4, 5));
    printf("%d\n", bitNor(0x6, 0x5));
    printf("%x\n", getByte(0x12345678, 1));
    printf("%d\n", isNotEqual(5, 5));
    printf("%d\n", isNotEqual(4, 5));
    printf("%d\n", negate(5));
    printf("%d\n", isPositive(5));
    printf("%d\n", isPositive(0));
    printf("%d\n", isPositive(-1));
    printf("isPositive %d: %d\n", -25434, isPositive(-25434));
    printf("isPositive %d: %d\n", 3453, isPositive(3453));
    printf("isPositive %d: %d\n", 2, isPositive(2));
    printf("isPositive %d: %d\n", -2, isPositive(-2));
    printf("isPositive %d: %d\n", -3, isPositive(-3));
    printf("%x\n", reverseBytes(0x01020304));
    printf("%d\n", isGreater(0, 0));
    printf("%d\n", isGreater(1, 2));
    printf("%d\n", isGreater(3, 3));
    printf("%d\n", isGreater(4, 1));
    printf("%d\n", isGreater(-1, -2));
    printf("%d\n", isGreater(-2, -1));
    printf("%d\n", isGreater(4, -2));
    printf("%d\n", isGreater(-4, 3));
    printf("%d\n", isGreater(-1, -1));
    printf("%d\n", isGreater(INT_MAX, INT_MAX));
    printf("%d\n", isGreater(INT_MAX, INT_MIN)); // falla
    printf("%d\n", isGreater(INT_MIN, INT_MAX));
    printf("%d\n", isGreater(INT_MIN, INT_MIN)); // falla
    printf("%d\n", isGreater(INT_MAX, INT_MAX - 1));
    printf("%d\n", isGreater(INT_MIN + 1, INT_MIN));
    printf("%d\n", isPower2(5));
    printf("%d\n", isPower2(8));
    printf("%d\n", isPower2(0));
    printf("%d\n", isPower2(1));
    printf("%d\n", isPower2(2));
    printf("%d\n", isPower2(-12));
    printf("%d\n", isPower2(-121));
    printf("%d\n", -2147483648);
    printf("%d\n", isPower2(-2147483648));

    return 0;
}

/*
Como el operador ""!"", corresponde a la negacion logica, por lo que
cualquier numero operado con el, dara un zero, a excepcion que este numero sea 0.
 */
int isZero(int x)
{
    return !x;
}
/*
La representacion en complemento 2 del (-1) corresponde a un string compuesto solamente de 1's,
por lo que su complemento es un string que consiste solamente en 0's, por lo que para obtener menos 1,
se opera el complemento con 0.
 */
int minusOne(void)
{
    return ~0;
}

/*
Se llego a la expresion correspondiente, usando los operadores logicos,
para obtener una expresion equivalente, cumpliendo el requisito de los operadores propuesto.

 */
int bitNor(int x, int y)
{
    return (~x) & (~y);
}

/*
Para obtener el ultimo byte de un entero, se hace un and byte con 0xff,
entonces para obtener el i-esimo byte, primero debemos desplazar, el valor(x)
y bytes(8*n), hacia la derecha.
 */
int getByte(int x, int n)
{
    int byte = 8;
    return x >> byte*n & 0xFF;
}

/*
Cualquier número operado consigo mismo con el operador ^ entrega solo 0s, por
lo que al negarlo dos veces queda 0, en caso contrario da 1.
 */
int isNotEqual(int x, int y)
{
    return !!(x ^ y);
}
/*
Primero se opera el entero ingresado invirtiendo sus Bytes con el operador
'Complemento 2', lo cual nos dará un número signed de la forma (-x-1), luego
sólo sumamos '1' y nos retorna '-x'.
 */
int negate(int x)
{
    return (~x) + 1;
}
/*
Tabla para referencia.

 CASO    || signo_x | es_cero | !signo_x | !es_cero | (!signo_x) & (!es_cero)
-----------------------------------------------------------------------------
positivo ||    0    |    0    |     1    |     1    |           1
cero     ||    0    |    1    |     1    |     0    |           0
negativo ||    1    |    0    |     0    |     1    |           0
 */
int isPositive(int x)
{
    int signo_x = (x >> 31) & 1;
    int es_cero = !x;
    return (!signo_x) & (!es_cero);
}
/*
Usamos lo aplicado en la función getByte para obtener individualmente los bytes,
luego los reordenamos usando Shift de modo que quede el número inicial quede
al revés y se unen usando |.
 */
int reverseBytes(int x)
{
    int b0 = x & 0xFF;
    int b1 = (x >> 8) & 0xFF;
    int b2 = (x >> 16) & 0xFF;
    int b3 = (x >> 24) & 0xFF;
    return (b0 << 24) | (b1 << 16) | (b2 << 8) | (b3);
}
/*
Para que un número sea mayor que otro, la diferencia debe ser positiva. Este
principio usamos para hacer la función, teniendo en cuenta el caso especial cuando x e y son iguales

CASO                || signo   | !signo  | es_cero  |!es_cero  | (!signo) & (!es_cero)
-------------------------------------------------------------------------------------
diferencia positiva ||    0    |    1    |     0    |     1    |           1
diferencia cero     ||    0    |    1    |     1    |     0    |           0
diferencia negativa ||    1    |    0    |     0    |     1    |           0
 */
int isGreater(int x, int y)
{
    int menos_y = (~y) + 1;
    int diferencia = x + menos_y;

    int signo_diferencia = (diferencia >> 31) & 1;
    int es_cero_la_diferencia = !diferencia;

    return (!signo_diferencia) & (!es_cero_la_diferencia);
}

/*
Tomamos x y su antecesor operandolos con un "&". Luego, si el resultado es cero
 el número es una potencia de 2 y en caso contrario no lo es.
 */
int isPower2(int x)
{
    int menos_uno = ~0;
    int x_menos_uno = x + menos_uno;
    int resultado_and = x & x_menos_uno;
    int no_es_cero = !!x;

    int signo = (x >> 31) & 1;
    int es_positivo_o_cero = !signo; // Caso particular para que no se considere que -2147483648 (o 10000000000000000000000000000000) como potencia de 2
    return (!(resultado_and ^ 0)) & no_es_cero & es_positivo_o_cero;
}
