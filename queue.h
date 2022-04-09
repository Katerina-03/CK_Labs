
#ifndef INC_3LABAPROGA1_QUEUE_H
#define INC_3LABAPROGA1_QUEUE_H
#include <queue>
using namespace std;
class Queue {
private:
    queue <int> values;
public:
    int size = 100;
    Queue& operator<<(Queue& data, int a);
    Queue& operator>>(Queue& data, int b);
};

#endif //INC_3LABAPROGA1_QUEUE_H
