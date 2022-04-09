//
// Created by ASUS on 26.03.2022.
//

#include "vector.h"
#include <iostream>

using namespace std;

vectorR3::vectorR3() {
    x = 0;
    y = 0;
    z = 0;
}

vectorR3::vectorR3(float &a, float &b, float &c){
    x = a;
    y = b;
    z = c;
}

vectorR3::vectorR3(vector<float> &v) {
    x = v[0];
    y = v[1];
    z = v[2];
}


void vectorR3::setX(float &a) {
    x = a;
}

void vectorR3::setY(float &b) {
    y = b;
}

void vectorR3::setZ(float &c) {
    z = c;
}

void vectorR3::setXYZ(float &a, float &b, float &c) {
    x = a;
    y = b;
    z = c;
}


float vectorR3::getX() {
    return x;
}

float vectorR3::getY() {
    return y;
}

float vectorR3::getZ() {
    return z;
}


vectorR3 vectorR3::summary_vectors(vectorR3 &v1, vectorR3 &v2) {
    vectorR3 v_res;
    v_res.x = v1.x + v2.x;
    v_res.y = v1.y + v2.y;
    v_res.z = v1.z + v2.z;
    return v_res;
}

vectorR3 vectorR3::difference_vectors(vectorR3 &v1, vectorR3 &v2) {
    vectorR3 v_res;
    v_res.x = v1.x - v2.x;
    v_res.y = v1.y - v2.y;
    v_res.z = v1.z - v2.z;
    return v_res;
}

float vectorR3::length_vectors(vectorR3 &v1) {
    return sqrt(pow(v1.x,2) + pow(v1.y,2) + pow(v1.z,2));
}

float vectorR3::angle_vector(vectorR3 &v1, vectorR3 &v2) {
    float dot = v1.x * v2.x +v1.y * v2.y + v1.z * v2.z;
    return acos(dot/(length_vectors(v1)* length_vectors(v2))) * 57.3248;
}

void vectorR3::output(vectorR3 v1) {
    cout << "(" << v1.x << "," << v1.y << "," << v1.z << ")";

}
