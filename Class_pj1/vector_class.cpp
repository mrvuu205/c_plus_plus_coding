#include <bits/stdc++.h>

using namespace std;

class VECTOR{
private:
	vector <double> data;
	int n;

public:
	VECTOR(int size = 0): n(size), data(size, 0.0) {}

	friend istream& operator>>(istream& is, VECTOR& v){
		for( int i = 0; i < v.n; i++) {
			is >> v.data[i];
		}

		return is;
	}

	friend ostream& operator<<(ostream& os, VECTOR& v){
		os << "{ ";
		for (int i = 0; i < v.n; i++)
		{
			os << v.data[i] << " ";
		}

		os << "}";
		return os;
	}

	VECTOR operator+(const VECTOR& other){
		if(n != other.n){
			throw invalid_argument("Hai vector khong cung so chieu ");
		}
		VECTOR result(n);
		for (int i = 0; i < n; i++)
		{
			result.data[i] = this->data[i] + other.data[i];
		}
		
		return result;

	}

	VECTOR operator-(const VECTOR& other){
		if(n != other.n){
			throw invalid_argument("Hai vector khong cung so chieu ");
		}
		VECTOR result(n);
		for (int i = 0; i < n; i++)
		{
			result.data[i] = this->data[i] - other.data[i];
		}

		return result;
	}

	double operator*(const VECTOR& other){
		if(n != other.n){
			throw invalid_argument("Hai vector khong cung so chieu ");
		}
		double dot_product = 0.0;

		for (int i = 0; i < n; i++)
		{
			dot_product += data[i] * other.data[i];
		}

		return dot_product;
	}


};


int main(){

	int n;
	cin >> n;
	VECTOR v1(n), v2(n), v3, v4;
	cin >> v1 >> v2;
	v3 = v1 + v2;
	v4 = v1 - v2;

	double x = v1 * v2;
	cout <<"Tich vo huong 2 vector bang: " << x << endl;
	cout << "Hieu 2 vector bang: " << v4 << endl;
	cout << "Tong 2 vector bang: " << v3;
	return 0;



}