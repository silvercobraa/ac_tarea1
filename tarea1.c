#include <stdio.h>

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
    printf("%d\n", isPositive(-25434));
    printf("%d\n", isPositive(3453));
    printf("%x\n", reverseBytes(0x01020304));
    printf("%d\n", isPower2(5));
    printf("%d\n", isPower2(8));
    printf("%d\n", isPower2(0));
    printf("%d\n", isPower2(1));
    printf("%d\n", isPower2(2));
    printf("%d\n", isPower2(-12));
    printf("%d\n", isPower2(-121));

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
    return (((~x) >> 31) & 1) & (x);
}

int reverseBytes(int x)
{
    int b0 = x & 0xFF;
    int b1 = (x >> 8) & 0xFF;
    int b2 = (x >> 16) & 0xFF;
    int b3 = (x >> 24) & 0xFF;
    // printf("%x\n", b0);
    // printf("%x\n", b1);
    // printf("%x\n", b2);
    // printf("%x\n", b3);
    return (b0 << 24) | (b1 << 16) | (b2 << 8) | (b3);
}

int isGreater(int x, int y)
{

}

int isPower2(int x)
{
    int menos_uno = ~0;
    int x_menos_uno = x + menos_uno;
    int resultado_and = x & x_menos_uno;
    int no_es_cero = !!x;
    return (!(resultado_and ^ 0)) & no_es_cero;
}
