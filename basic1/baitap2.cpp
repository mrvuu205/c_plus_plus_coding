#include <bits/stdc++.h>

using namespace std;

 struct Product
 {
 	string name;
 	int price;
 	int quantity;

 	friend istream& operator>>(istream &is, Product &product)
 	{
 		getline(is, product.name);
 		is >> product.price;
 		is >> product.quantity;

 		return is;

 	}

 	friend ostream& operator<<(ostream &os, Product product)
 	{
 		os << "Ten: " << product.name;
 		os << ", don gia: " << product.price;
 		os << ", so luong: " << product.quantity;

 		return os;

 	}
 };

int show_menu();


int main(){
	while(true)
	{
		int chose = show_menu();

		switch(chose)
		{
		case 1:
			break; 
		case 2:
			break;
		case 3:
			break;
		case 0:
			cout << "Bye bye";
			return 0;
		default:
			cout << "Lua chon khong hop le." << endl;
		}

		cout << " Ban co muon tiep tuc khong? (1/0)";
		bool is_continue;

		if (!is_continue){
			cout <<"Bye bye";
			break; 
		}
	}
	return 0;
}

int show_menu()
{
	system("cls");
	int chose;
	cout << "=====MENU===="<< endl;
	cout << "1. Xem danh sach san pham"<< endl;
	cout << "2. Them san pham moi " << endl;
	cout << "3. xoa san pham" << endl;
	cout << "0. Thoat chuong trinh" << endl;

	cout << " Lua chon cua ban la: ";
	cin >> chose;

	return chose;

}