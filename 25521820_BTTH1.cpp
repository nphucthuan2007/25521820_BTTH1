#include <bits/stdc++.h>
using namespace std;
struct Phanso{
	int tu, mau;
};
//ham nhap phan so
void nhap(Phanso &ps)
{
	cout << "Nhap tu so: "; cin >> ps.tu;
	//kiem tra tu so co phai la 1 con so hay khong
	while(isdigit(ps.tu)){
		cout << "Tu so phai la 1 con so.";
		cout << "Nhap lai tu so: "; 
		cin >> ps.tu; // nhap lai tu so
	}
	cout << "Nhap mau so: "; cin >> ps.mau;
	while(ps.mau == 0 || isdigit(ps.mau))
	{
		cout << "Mau so phai la 1 con so khac 0";
		cout << "Nhap lai mau so: ";
		// nhap lai mau so
		cin >> ps.mau;
	}
}
void xuat(Phanso ps)
{
	if(ps.tu % ps.mau != 0) // kiem tra phan so co the rut gon thanh 1 so nguyen hay khong
		cout << ps.tu << "/" << ps.mau;
	else cout << ps.tu/ps.mau; // rut gon thanh so nguyen
}
//ham tim uoc chung lon nhat
int gcd(int a, int b)
{
	while(a*b != 0)
	{
		if(a>b) a%=b;
		else b%=a;
	}
	return a+b;
}
void rutgon(Phanso &ps1)
{
	int x = gcd(ps1.tu, ps1.mau);
	ps1.tu /= x;
	ps1.mau /= x;
}
bool Phanso_lonhon(Phanso ps1, Phanso ps2)
{
	//kiem tra phan so 1 co lon hon phan so 2 hay khong
	return ps1.tu*ps2.mau > ps2.tu*ps1.mau;
}
Phanso tong(Phanso ps1, Phanso ps2)
{
	Phanso tong;
	tong.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
	tong.mau = ps1.mau*ps2.mau;
	rutgon(tong);
	return tong;
}
Phanso hieu(Phanso ps1, Phanso ps2)
{
	Phanso hieu;
	hieu.tu = ps1.tu*ps2.mau - ps2.tu*ps1.mau;
	hieu.mau = ps1.mau * ps2.mau;
	rutgon(hieu);
	return hieu;
}
Phanso tich(Phanso ps1, Phanso ps2)
{
	Phanso tich;
	tich.tu = ps1.tu * ps2.tu;
	tich.mau = ps1.mau * ps2.mau;
	rutgon(tich);
	return tich;
}
Phanso thuong(Phanso ps1, Phanso ps2)
{
	Phanso thuong;
	if(ps2.tu == 0){
    	cout << "\nKhong the chia cho phan so 0\n";
    	thuong.tu = 0;
	}
	else {
		thuong.tu = ps1.tu  * ps2.mau;
		thuong.mau = ps1.mau * ps2.tu;
		rutgon(thuong);
	}
	return thuong;
}
int main()
{
	Phanso ps1, ps2;
	nhap(ps1);
	nhap(ps2);
	rutgon(ps1); rutgon(ps2);
	if(Phanso_lonhon(ps1,ps2))
	{
		cout << "\nPhan so lon nhat la: "; xuat(ps1);
	}
	else {
		cout << "\nPhan so lon nhat la: "; xuat(ps2);
	}
	Phanso tong_ps = tong(ps1,ps2);
	cout << "\nTong hai pha so la: "; xuat(tong_ps);
	Phanso hieu_ps = hieu(ps1,ps2);
	cout << "\nHieu hai phan so la: "; xuat(hieu_ps);
	Phanso tich_ps = tich(ps1,ps2);
	cout << "\nTich hai phan so la: "; xuat(tich_ps);
	Phanso thuong_ps = thuong(ps1,ps2);
	cout << "\nThuong hai phan so la: "; xuat(thuong_ps);
	return 0;
}
