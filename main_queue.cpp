#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    Queue my;
    my << 10 << 7 << 6 << 8;
    my >> 2;
    return 0;
}
