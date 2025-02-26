#include <bits/stdc++.h>

using namespace std;

const float PI = 3.14;

struct Circle
{
    float r;

    friend istream& operator>> (istream &is, Circle &circle)
    {
        is >> circle.r;

        return is;

    }

    float chu_vi()
    {
        return r * 2 * PI;
    }

    float dien_tich()
    {
        return r*r*PI;

    }
};


int main(){

    Circle circle;
    cin >> circle;

    cout << "Chu vi hinh tron" << circle.chu_vi() << endl;
    cout << "Dien tich hinh tron" << circle.dien_tich() << endl;



    return 0;
}