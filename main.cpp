#include <iostream>
#include "fun.h"


using namespace std;

int main()
{
    int a, inc, tmp;

    cout << "values: \n";
    cin >> a >> inc;
    tmp = a;
    inc_num_point(&a, &inc);
    cout << "point + inc = " << a << endl;
    inc_num_link(tmp, inc);
    cout << "link + inc = " << tmp << endl;

    cout << "number to reverse: \n";
    cin >> a;
    tmp = a;
    reverse_num_point(&a);
    cout << "point = " << a << endl;
    reverse_num_link(tmp);
    cout << "link = " << tmp << endl;

    complexNumber complex_num, complex_tmp;
    cout << "complex value: \n";
    cin >> complex_num.x;
    cin >> complex_num.ar;
    cin >> complex_num.y;
    complex_tmp = complex_num;
    conjugate_num_point(&complex_num);
    cout << "point num: " << complex_num.x << complex_num.ar << complex_num.y << 'i'<<endl;
    conjugate_num_link(complex_tmp);
    cout << "link num: " << complex_tmp.x << complex_tmp.ar << complex_tmp.y << 'i'<<endl;

    int n, input, scal;
    cout << "size of your matrix: \n";
    cin >> n;
    cout << "scalar to multiply: \n";
    cin >> scal;
    int **arr;
    arr = (int **) malloc(n * sizeof(int*));
    int tmp_arr[256][256];

    cout << "enter matrix: \n";
    for(int i=0; i<n; i++) {
        arr[i] = (int *) malloc(n * sizeof(int));


        for(int j=0; j<n; j++) {
            cin >> input;
            arr[i][j] = input;
            tmp_arr[i][j] = input;
        }
    }
    multiply_array_point(arr, &n, &scal);
    cout << "multiply\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
    multiply_array_link(tmp_arr, n, scal);
    cout << "multiply \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << tmp_arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
