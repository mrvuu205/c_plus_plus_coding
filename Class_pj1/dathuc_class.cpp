#include <bits/stdc++.h>

 using namespace std;

 class DATHUC{
 private:
 	vector<double> heso;
 public:

 	friend istream& operator>>(istream& is, DATHUC& dt){
 		int n;
 		// cout << "nhap so bac: ";
 		is >> n;

 		dt.heso.resize(n + 1);

 		for( int i = 0; i < dt.heso.size(); i++){
 			is >> dt.heso[i];
 		}

 		return is;

 	}

 	friend ostream& operator<<(ostream& os, DATHUC& dt){
 		bool F = true;

 		for(int i = 0; i < dt.heso.size(); i ++){
 			//in dau
 			if(dt.heso[i]){
 				if (!F){
 					if(dt.heso[i] < 0) os << " - ";
 				 		else os << " + " ;
 				}
 				else{	
 					if (dt.heso[i] < 0) os << " - ";

 				}
 			// in heso
 				if( abs(dt.heso[i]) != 1 || i == dt.heso.size() - 1){
 					os << abs(dt.heso[i]);
 				}

 				if(i < dt.heso.size() - 1){
 					os << "x";
 					if(i < dt.heso.size() - 2) os << "^" << dt.heso.size() - i - 1;
 				}

 				F = false;
 			} 
 		}
 		if(F) os << "0";

 		return os;

 	}

 	DATHUC operator+(const DATHUC& other){
 		DATHUC result;

 		int bm = max(this->heso.size(), other.heso.size());	 	
 		result.heso.resize(bm, 0);
 		for(int i = 0; i < bm; i++){
 			double hs1 = (i < this->heso.size())?this->heso[this->heso.size() - i - 1] : 0;
 			double hs2 = (i < other.heso.size())?other.heso[other.heso.size() - i - 1] : 0;
 			result.heso[bm - 1 - i] = hs1 + hs2;
 		}

 		return result;
 	}


 	DATHUC operator-(const DATHUC& other){
 		DATHUC result;

 		int bm = max(this->heso.size(), other.heso.size());	 	
 		result.heso.resize(bm);
 		for(int i = 0; i < bm; i++){
 			double hs1 = (i < this->heso.size())?this->heso[this->heso.size() - i - 1] : 0;
 			double hs2 = (i < other.heso.size())?other.heso[other.heso.size() - i - 1] : 0;

 			result.heso[bm - 1 - i] = hs1 - hs2;
 		}

 		return result;
 	}

 	double tinhgiatritai(double x){
 		double result = 0;
 		for(int i = 0; i < heso.size() ; i++){
 			result += heso[i] * pow(x, heso.size() - 1 -i);
 		}

 		return result;
 	}

};

int main(){
	DATHUC dt1, dt2, dt3;
	cin >> dt1 >> dt2;
	cout << dt1 << endl;
	cout << dt2 << endl;

	dt3 = dt1 + dt2;
	cout << dt3 << endl;


	return 0;
}
