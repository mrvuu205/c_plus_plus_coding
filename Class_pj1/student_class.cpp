#include <bits/stdc++.h>

using namespace std;

class STUDENT{
	private:
		string hoten;
		int tuoi;
		double diem_tb;
	public:

		friend istream& operator>>(istream& is, STUDENT& hs){
			is >> hs.hoten;
			is >> hs.tuoi;
			is >> hs.diem_tb;

			return is;
		}

		friend ostream& operator<<(ostream& os, STUDENT& hs){
			os << "ho tem: " << hs.hoten << endl;
			os << "tuoi: : " << hs.tuoi << endl;
			os << "diem trung binh: " << hs.diem_tb << endl;
			hs.pass_or_fail();

			return os;
		}

		void pass_or_fail(){
			if(diem_tb >= 5){
				cout <<"PASS"<< endl;
			}
			else cout <<"FAIL"<< endl;
		}
};

int main(){
	int n;
	cin >> n;
	STUDENT* hs = new STUDENT[n];

	for(int i = 0; i < n; i++){
		cin >> hs[i];
	}

	for(int i = 0; i < n; i++){
		cout << hs[i];
	}

	delete[] hs;

	return 0;

}