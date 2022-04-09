

#ifndef INC_3LABAPROGA2_HEADER_H
#define INC_3LABAPROGA2_HEADER_H

class Complex
{
private:
    int material;
    int fake;
public:
    Complex(int material, int fake);
    Complex();

    Complex operator + (Complex data);
    Complex operator * (Complex data);
    Complex operator * (double v);
    operator double() const;
    void display();

};


#endif //INC_3LABAPROGA2_HEADER_H
