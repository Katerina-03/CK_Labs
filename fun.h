#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct complexNumber {
    int x;
    int y;
    char ar;
};

void inc_num_point(int *a, int *inc);
void inc_num_link(int &a, int &inc);
void reverse_num_point(int *a);
void reverse_num_link(int &a);
void conjugate_num_point(complexNumber *complex_num);
void conjugate_num_link(complexNumber &complex_num);
void multiply_array_point(int **arr, int *n, int *scal);
void multiply_array_link(int arr[256][256], int n, int scal);
#endif
