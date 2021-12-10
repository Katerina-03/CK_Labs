#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    printf((a>=23 && a<=45)? "true":"false");
    int b;
    scanf("%o", &b);
    printf("%d\n", (b&(1<<3)==0? 0:1));


    return 0;

}
