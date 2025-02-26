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
		os << "( " << d.x << ", " << d.y << " )";
		return os;
	}

	static double khoangcach(DIEM &d1, DIEM &d2){
		return hypot(d1.x - d2.x, d1.y - d2.y);
	}
};

class HINHTRON{
private:
	DIEM O;
	double R;
	string mausac;
	double PI = 3.14;

public:

	static void nhapthongtin(HINHTRON &o){
		cin>>o.O;
		cin>> o.R;
		cin >> o.mausac;
	}
	static void inthongtin(HINHTRON &o){
		cout << "hinh tron tam O "<< o.O << " ban kinh bang " << o.R << " co mau " << o.mausac ;
	}
	static void chuvidientic(HINHTRON &o){
		double cv = 2*o.R*o.PI;
		double dt = pow(o.R, 2)*o.PI;

		cout<< "\nChu vi hinh tron la: " << cv << endl;
		cout << "Dien tich hinh tron la: " << dt << endl;
	}
};

int main(){
	HINHTRON o;
	HINHTRON::nhapthongtin(o);
	HINHTRON::inthongtin(o);
	HINHTRON::chuvidientic(o);

	return 0;
}