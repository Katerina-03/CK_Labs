//
// Created by ASUS on 24.03.2022.
//

#include "menu.h"
#include <iostream>


menu::menu() {
    Number = 0;
    cout << "comand:\n";
    cout << "1 - summary\n";
    cout << "2 - difference\n";
    cout << "3 - size\n";
    cout << "4 - angle\n";
    cout << "\n";
    cin >> Number;
}

void menu::select( menu settings) {
    vectorR3 v1, v2;
    float x, y, z;

    switch(settings.Number){

        case 1:
            cout << "1\n";
            cin >> x >> y >> z;
            v1.setXYZ(x, y, z);

            cout << "2\n";
            cin >> x >> y >> z;
            v2.setXYZ(x, y, z);

            cout << "sum:\n";
            vectorR3::output(vectorR3::summary_vectors(v1, v2));
            break;


        case 2:
            cout << "1\n";
            cin >> x >> y >> z;
            v1.setXYZ(x, y, z);

            cout << "2\n";
            cin >> x >> y >> z;
            v2.setXYZ(x, y, z);

            cout << "difference:\n";
            vectorR3::output(vectorR3::difference_vectors(v1, v2));
            break;


        case 3:
            cout << "vector\n";
            cin >> x >> y >> z;
            v1.setXYZ(x, y, z);

            cout << "size=\n" << vectorR3::length_vectors(v1);
            break;


        case 4:
            cout << "1\n";
            cin >> x >> y >> z;
            v1.setXYZ(x, y, z);

            cout << "2\n";
            cin >> x >> y >> z;
            v2.setXYZ(x, y, z);

            cout << "angle = " << vectorR3::angle_vector(v1,v2);
            break;


        default:
            cout << "error\n";
            break;


    }

}
