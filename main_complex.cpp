#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    Complex num1(2, 4);
    Complex num2(3,6);

    Complex sum = num1 + num2;
    cout << "summery:" << endl;
    sum.display();

    cout << "product:" << endl;
    sum  = num1 * num2;
    sum.display();

    double v2 = (double)sum;
    cout << "value:" << v2 << endl;
    sum = num2 * 1.1;
    sum.display();
}
