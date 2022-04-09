//
// Created by ASUS on 26.03.2022.
//

#ifndef INC_2_2_VECTOR_H
#define INC_2_2_VECTOR_H
#include <cmath>
#include <vector>
using namespace std;



class vectorR3 {
private:
    float x;
    float y;
    float z;

public:
    vectorR3(); // конструктор по умолчанию
    vectorR3(float &a , float &b, float &c); // конструтор 3 вещественных чисел
    vectorR3(vector<float> &v); // конструктор вектора

    void setX(float &a);
    void setY(float &b);
    void setZ(float &c);
    void setXYZ(float &a, float &, float &c);

    float getX();
    float getY();
    float getZ();

    vectorR3 summary_vectors(vectorR3 &v1, vectorR3 &v2);
    vectorR3 difference_vectors(vectorR3 &v1, vectorR3 &v2);
    float length_vectors(vectorR3 &v1);
    float angle_vector(vectorR3 &v1, vectorR3 &v2);
    void output(vectorR3 v1);

};


#endif //INC_2_2_VECTOR_H
