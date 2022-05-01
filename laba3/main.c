#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%o", &a);
    printf("%x \n",a );
    printf("%o\n", a<<4);
    printf("%o\n", ~a);
    int b;
    scanf("%x", &b);
    printf("%x\n",(a|b));


    return 0;
}

