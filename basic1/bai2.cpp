#include <bits/stdc++.h>

using namespace std;

void Chuyendoi(string s);

int main(){

	string s;
	getline(cin, s);
	Chuyendoi(s);

	return 0;
}

void Chuyendoi(string s){
	for(char c: s){
		c = toupper(c);
		cout<< c;
	}
}