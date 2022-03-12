#include <iostream>
#include "fun.h"

using namespace std;

void inc_num_point(int *a, int *inc) {
    *a += *inc;
}

void inc_num_link(int &a, int &inc) {
    a += inc;
}

void reverse_num_point(int *a) {
    *a = ~(*a) + 1;
}

void reverse_num_link(int &a) {
    a = ~a + 1;
}

void conjugate_num_point(complexNumber *complex_num) {
    (*complex_num).ar = ((*complex_num).ar == '+') ? '-': '+';
}


void conjugate_num_link(complexNumber &complex_num) {
    complex_num.ar = (complex_num.ar == '+') ? '-': '+';
}

void multiply_array_point(int **arr, int *n, int *scal) {
    for(int i=0; i<*n; i++) {
        for(int j=0; j<*n; j++) {
            cout << arr[i][j] << " ";
            arr[i][j] *= *scal;
        }
        cout << endl;
    }
}

void multiply_array_link(int arr[][256], int n, int scal) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
            arr[i][j] = scal;
        }
        cout << endl;
    }
}
