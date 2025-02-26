#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x,y;

};

double khoangcach(Point A, Point B);
Point diemxanhat(Point point[], int n);
void diemgannhaunhat(Point point[], int n, Point &A, Point &B );
void findBoundingBox(Point point[], int n, Point &Day, Point &Dinh);



int main(){
	int n;
	cin >> n;
	Point point[n];
	for(int i = 0; i < n; i++){
		cin>> point[i].x >> point[i].y;
	}
	Point farthest = diemxanhat(point, n);
	cout << "cau a" << endl;
    cout << "(" << farthest.x << "," << farthest.y << ")" << endl;

	cout << "cau b" << endl;
	Point A, B;
	diemgannhaunhat(point, n, A, B);
    cout << "(" << A.x << "," << A.y << ")" << endl;
    cout << "(" << B.x << "," << B.y << ")" << endl;

	Point Day, Dinh;
    findBoundingBox(point, n, Day, Dinh);
   	cout << "cau c" << endl;
    cout << "(" << Day.x << "," << Day.y << ")" << endl;
    cout << "(" << Dinh.x << "," << Dinh.y << ")" << endl;

    return 0;
}



double khoangcach(Point A, Point B){
	double h = sqrt(pow(A.x - B.x,2) + pow(A.y - B.y,2));
	return h;

}

Point diemxanhat(Point point[], int n){
	double max = 0;
	Point farthest = point[0];

	
	for(int  i = 0; i < n; i ++)
	{
		double kc =	khoangcach({0,0}, point[i]);
		if(max <= kc){
			max = kc;
			farthest = point[i];
		}
	}
	return farthest;
}	

void diemgannhaunhat(Point point[], int n, Point &A, Point &B ){
	double minS = numeric_limits<double>::max();

	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j ){
			double kc = khoangcach(point[i], point[j]);
			if(kc < minS){
			minS = kc;
			A = point[i];
			B = point[j];
			}
		}
	}
}

void findBoundingBox(Point point[], int n, Point &Day, Point &Dinh){
	
	if (n < 1) return;

	Day = Dinh = point[0];

	for(int i = 1; i < n; i++){
		if( point[i].x < Day.x )
			Day = point[i];
		if(  point[i].y > Dinh.y)
			Dinh = point[i];
	}
}