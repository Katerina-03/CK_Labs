
#include "queue.h"
#include <iostream>
#include <queue>
using namespace std;

Queue& operator<<(Queue& data, int a) {
    if (data.values.size() < data.size) {
        data.values.push(a);
        cout << a << endl;
        cout << "push" << endl;
        return data;
    }

}
Queue& operator>>(Queue& data, int b) {
    if (!data.values.empty()) {
        cout << data.values.front() << endl;
        cout << "pop" << endl;
        data.values.pop();
        return data;
    }
    return data;
}
