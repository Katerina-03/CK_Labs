#include "Vector.h"

using namespace std;

teamplate <typename T>
class Vector
{
private:
    {
        T*arr_; // ��������� ������
        size_t size_ {}; // �����������
        size_t capacity_{}; // max ������
    }
public:
    {
        Vector () //����������� ������
        {
            arr_ = new T [1];
            capacity_ = 1;
        }

        Vector (conts vector <T> v) // ����������� �����������
        {
            size_ = v.size;
            arr = new int;
            for ( int = i; i < size_; i++)
            {
                *arr = *v.arr;
                cout << "Copy-Constructor" << endl;
            }
        }
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
