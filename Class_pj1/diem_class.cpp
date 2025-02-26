#include <bits/stdc++.h>

using namespace std;

class DIEM
{

private:
	double x, y;

public:

	DIEM() : x(0), y(0) {}
	DIEM(double x, double y) : x(x), y(y) {}

	double getX() const { return x; }
	double getY() const { return y; }

	static double khoangcach(const DIEM& d1, const DIEM& d2){
		return hypot(d1.x - d2.x, d1.y - d2.y);
	}
	friend istream& operator>>(istream& is, DIEM &d){
		// cout << " toa do diem: ";
		is >> d.x >> d.y;
		return is;
	}
	friend ostream& operator<<(ostream& os, const DIEM &d){
		os <<"(" << d.x << " , " << d.y << ")";
		return os;
	}

	static void dainhat(const DIEM d[], int n){
        const DIEM* dau = &d[0];
        const DIEM* cuoi = &d[1];
        double max = khoangcach(*dau,*cuoi);

		for(int i = 0; i < n - 1; i++ ){
			for( int j = i + 1; j < n; j++){
				if( max < khoangcach(d[i], d[j])){
					max = khoangcach(d[i], d[j]);
					dau = &d[i];
					cuoi = &d[j];
				}
			}
		}
		cout << "doan thang dai nhat tu " << *dau << " den " << *cuoi << " co do dai la: " << max ;
	}
};



class DOANTHANG{
private:
	DIEM d1, d2;
public:

	friend istream& operator>>(istream& is, DOANTHANG &dt){
		// cout << "nhap diem:  ";
		is >> dt.d1 >> dt.d2;
		return is;
	}

	friend ostream& operator<<(ostream& os, DOANTHANG &dt){
		os << "Do dai doan thang tu diem "<< dt.d1 << " den diem "<< dt.d2 << " la: "<< endl;
		return os;
	}

	// friend double dodai(DOANTHANG &dt){
	// 	return hypot(dt.d1.x - dt.d2.x, dt.d1.y - dt.d2.y);
	// }

};



int main(){
	int n; 
	cin >> n;
	DIEM * d = new DIEM[n];

	for (int i = 0; i < n; i++){
		cin >> d[i];
	}

	DIEM::dainhat(d, n);

	delete[] d;
	return 0;
}