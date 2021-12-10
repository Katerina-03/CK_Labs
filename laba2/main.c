#include <stdio.h>
#include <math.h>
#define PI 3.14159265


int main()
{
    double z1, z2, grade, radian;
    radian = PI/180;
    scanf("%lf", &grade);

    z1=(sin(2*grade*radian)+sin(5*grade*radian)-sin(3*grade*radian))/(cos(grade*radian)-cos(3*grade*radian)+cos(5*grade*radian));
    z2=sin(3*grade*radian)/cos (3*grade*radian) ;
    printf("%lf %lf", z1, z2);

}
