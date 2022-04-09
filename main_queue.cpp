#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    Queue manager;
    manager << 10 << 7 << 6 << 8;
    manager >> 2;
    return 0;
}
