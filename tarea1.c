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

int isZero(int x)
{
    return !x;
}

int minusOne(void)
{
    return ~0;
}

int bitNor(int x, int y)
{
    return (~x) & (~y);
}

int getByte(int x, int n)
{
    int byte = 8;
    return x >> byte*n & 0xFF;
}

int isNotEqual(int x, int y)
{
    return !!(x ^ y);
}

int negate(int x)
{
    return (~x) + 1;
}

int isPositive(int x)
{
    //  CASO    || signo_x | es_cero | !signo_x | !es_cero | (!signo_x) & (!es_cero)
    // -----------------------------------------------------------------------------
    // positivo ||    0    |    0    |     1    |     1    |           1
    // cero     ||    0    |    1    |     1    |     0    |           0
    // negativo ||    1    |    0    |     0    |     1    |           0
    //
    int signo_x = (x >> 31) & 1;
    int es_cero = !x;
    return (!signo_x) & (!es_cero);
}

int reverseBytes(int x)
{
    int b0 = x & 0xFF;
    int b1 = (x >> 8) & 0xFF;
    int b2 = (x >> 16) & 0xFF;
    int b3 = (x >> 24) & 0xFF;
    return (b0 << 24) | (b1 << 16) | (b2 << 8) | (b3);
}

int isGreater(int x, int y)
{
    int menos_y = (~y) + 1;
    int diferencia = x + menos_y;

    int signo_diferencia = (diferencia >> 31) & 1;
    int es_cero_la_diferencia = !diferencia;

    return (!signo_diferencia) & (!es_cero_la_diferencia);
}

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
