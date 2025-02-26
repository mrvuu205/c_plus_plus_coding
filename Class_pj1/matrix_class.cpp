#include <bits/stdc++.h>

using namespace std;

class MATRIX{
private:
	int rows, cols;
	int **data;
public:

	MATRIX(int r = 0, int c = 0) : rows(r), cols(c), data(nullptr) {}

	~MATRIX() {
		clear();
	}

	void clear(){
		if (data){
			for(int i = 0; i < rows; i++){
					delete[] data[i];
				}
			delete[] data;
			data = nullptr;
			}
	}

	friend istream& operator>>(istream& is, MATRIX& mx){
		mx.clear();
		is >> mx.rows >> mx.cols;
		if(mx.rows <= 0 || mx.cols <= 0){
			throw invalid_argument("sai roi nhap lai");
		}
		mx.data = new int*[mx.rows];
		for(int i = 0; i < mx.rows; i++){
			mx.data[i] = new int[mx.cols];
			for(int j = 0; j < mx.cols; j++){
				is >> mx.data[i][j]; 
			}
		}
		return is;
	}

	friend ostream& operator<<(ostream& os,const MATRIX& mx){
		if(!mx.data){
			throw invalid_argument("lam choa co gi ma in");
		}
		for(int i = 0; i < mx.rows; i ++){
			os << "[ ";
			for(int j = 0; j < mx.cols; j++){
				os << mx.data[i][j] << " ";
			}
			os << "] \n";
		}

		return os;
	}

	MATRIX operator+(const MATRIX& other){
		MATRIX result(this->rows, this->cols);
		result.data = new int*[this->rows];
		for (int i = 0; i < this->rows; i++){
			result.data[i] = new int[this->cols];
			for(int j = 0; j < this->cols; j++){
				result.data[i][j] = this->data[i][j] + other.data[i][j]; 
			}
		}

		return result;
	}

	MATRIX operator-(const MATRIX& other){
		MATRIX result(this->rows, this->cols);
		result.data = new int*[this->rows];
		for (int i = 0; i < this->rows; i++){
			result.data[i] = new int[this->cols];
			for(int j = 0; j < this->cols; j++){
				result.data[i][j] = this->data[i][j] - other.data[i][j]; 
			}
		}

		return result;
	}

	MATRIX operator*(const MATRIX& other){
		if (this ->cols != other.rows){
			throw invalid_argument("khong nhan duoc");
		}

		MATRIX result(this->rows, other.cols);
		result.data = new int*[this->rows];
		for(int i = 0; i < this->rows; i++){
			result.data[i] = new int[other.cols];
			for(int j = 0; j < other.cols; j++){
				result.data[i][j] = 0;
				for(int k = 0; k < this->cols; k++)
					result.data[i][j] += this->data[i][k] * other.data[k][j];
			}
		}

		return result;
	}

};



int main(){
	MATRIX mx1, mx2;
	cin >> mx1 >> mx2;
	cout << mx1 << "\n" << mx2 << endl;
	MATRIX mx3 = mx1 * mx2;
	cout << mx3;

}