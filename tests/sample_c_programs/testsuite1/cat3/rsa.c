/* C program for the Implementation Of RSA Algorithm */

#include <stdio.h>

int phi, M, n, e, d, C, FLAG;

int check()
{
    int i;
    for (i = 3; e % i == 0 && phi % i == 0; i + 2)
    {
        FLAG = 1;
        return;
    }
    FLAG = 0;
}

void encrypt()
{
    int i;
    C = 1;
    for (i = 0; i < e; i++)
        C = C * M % n;
    C = C % n;
    printf("\n\tEncrypted keyword : %d", C);
}

void decrypt()
{
    int i;
    M = 1;
    for (i = 0; i < d; i++)
        M = M * C % n;
    M = M % n;
    printf("\n\tDecrypted keyword : %d", M);
}

void main()
{
    int p, q, s;
    printf("Enter Two Relatively Prime Numbers\t: ");
    scanf("%d%d", &p, &q);
    n = p * q;
    printf("\n\tn\t= %d", n);
    phi = (p - 1) * (q - 1);
    printf("\n\tF(n)\t= %d", phi);
    do
    {
        printf("\n\nEnter e\t: ");
        scanf("%d", &e);
        check();
    } while (FLAG == 1);
    d = 1;
    do
    {
        s = (d * e) % phi;
        d++;
    } while (s != 1);
    d = d - 1;
    printf("\n\td\t= %d", d);
    printf("\n\te\t= %d", e);
    printf("\n\tPublic Key\t: {%d,%d}", e, n);
    printf("\n\tPrivate Key\t: {%d,%d}", d, n);
    printf("\n\nEnter The Plain Text\t: ");
    scanf("%d\n", &M);
    encrypt();
    printf("\n\nEnter the Cipher text\t: ");
    scanf("%d\n", &C);
    decrypt();
}

