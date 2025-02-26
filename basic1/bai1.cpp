#include <bits/stdc++.h>

using namespace std;

bool tamgiac(int a,int b,int c);


int main(){
	int a, b, c;
	cin>>a >>b >>c;
	if (tamgiac(a, b, c))
	{
		cout << "Co the tao thanh tam giac vuong." << endl;
	}else
	{
		cout << "Khong the tao thanh tam giac vuong." << endl;
	 }

	return 0;

}

bool tamgiac(int a,int b,int c)
{
	if((a + b > c) && (a + c > b) && (b + c > a))
	{
		if((a*a + b*b == c*c) || (b*b + c*c == a*a) || (a*a + c*c == b*b))
			return true;
	}
	return false;
}