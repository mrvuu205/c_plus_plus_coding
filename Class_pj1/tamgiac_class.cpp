#include <bits/stdc++.h>

using namespace std;

class DIEM{
private:
    double x,y;

public:
    DIEM(): x(0), y(0) {}

    DIEM(double x, double y): x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    friend istream& operator>>(istream& is, DIEM &d){
        is >> d.x >> d.y;
        return is;
    }

    friend ostream& operator<<(ostream& os, DIEM &d){
        os << "(" << d.x << ", " << d.y << ")" ;
        return os;
    }

    static double khoangcach(DIEM &d1, DIEM &d2){
        return hypot(d1.x - d2.x, d1.y - d2.y);
    }


};

class TAMGIAC{
private:
    DIEM d1, d2, d3;
public:

    DIEM getd1() const { return d1; }
    DIEM getd2() const { return d2; }
    DIEM getd3() const { return d3; }

    static void nhapdinh(TAMGIAC &tg){
        cin >> tg.d1 >> tg.d2 >> tg.d3;
        cout << "cac dinh vua nhap la: " << tg.d1 << " , " << tg.d2 << " , " <<  tg.d3 << endl;
    }

    static void chuvi(TAMGIAC &tg){
        double AB = DIEM::khoangcach(tg.d1, tg.d2);
        double BC = DIEM::khoangcach(tg.d2, tg.d3);
        double AC = DIEM::khoangcach(tg.d1, tg.d3);

        double cv = AB + BC + AC;

        cout << "Chu vi tam giac la: " << cv << endl;
    }

    static void dientich(TAMGIAC &tg){
        double dt = 0.5*abs(tg.d1.getX()*(tg.d2.getY() - tg.d3.getY()) + tg.d2.getX()*(tg.d3.getY() - tg.d1.getY()) + tg.d3.getX()*(tg.d1.getY() - tg.d2.getY()));

        cout <<"Dien tich cua tam giac la: "<< dt;
    }

};

int main(){
    TAMGIAC tg;

    TAMGIAC::nhapdinh(tg);
    TAMGIAC::chuvi(tg);
    TAMGIAC::dientich(tg);

}