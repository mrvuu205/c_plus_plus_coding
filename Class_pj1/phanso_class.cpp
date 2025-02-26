#include <bits/stdc++.h>

using namespace std;

class PS{
private:
	int tu, mau;
public:

	PS(): tu(0), mau(1) {}

	PS(int t, int m): tu(t), mau(m) {}

	void rutgon(){
		int uc = __gcd(tu, mau);
		tu /= uc;
		mau /= uc;

		if(mau < 0){
			tu, mau = -tu, -mau;
		}

	}

	friend istream& operator>>(istream& is, PS& ps){
		is >> ps.tu >> ps.mau;
		while(ps.mau == 0){
			cout << "Nhap lai mau so di thang lol: ";
			is >> ps.mau;
		}

		ps.rutgon();

		return is;
	}

	friend ostream& operator<<(ostream& os, PS& ps){
		os << ps.tu << "/" << ps.mau;
		return os;
	}

	PS operator+(const PS& other ){
		PS result;
		result.tu = this->tu* other.mau + this->mau* other.tu;
		result.mau = this->mau * other.mau;

		result.rutgon();

		return result;

	}

	PS operator-(const PS& other ){
		PS result;
		result.tu = this->tu* other.mau - this->mau* other.tu;
		result.mau = this->mau * other.mau;

		result.rutgon();

		return result;

	}

	PS operator*(const PS& other ){
		PS result;
		result.tu = this->tu* other.tu;
		result.mau = this->mau * other.mau;

		result.rutgon();

		return result;

	}

	PS operator/(const PS& other ){
		PS result;
		result.tu = this->tu* other.mau;
		result.mau = this->mau * other.tu;

		result.rutgon();

		return result;

	}

	PS operator-(){
		PS result;

		result.tu = -(this->tu);
		result.mau = this->mau;

		return result;

	}


	bool operator==(const PS &other){
		if(this->tu == other.tu && this->mau == other.mau){
			return true;
		}
		return false;
	}

	bool operator!=(const PS &other){
		if(this->tu == other.tu && this->mau == other.mau){
			return false;
		}
		return true;
	}



};


int main(){
	PS ps1, ps2, ps3;
	cin >> ps1 >> ps2;
	cout << ps1 << "\n" << ps2 << endl;

	ps3 = ps1 * ps2;
	
	cout << ps3;


}