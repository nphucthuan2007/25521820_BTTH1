#include <iostream>
using namespace std;
struct Sinhvien{
	string hoten;
	double diemtoan, diemvan, dtb;
};
void nhap(Sinhvien &sv)
{
	cout << "Nhap ho va ten sinh vien: ";
	getline(cin, sv.hoten);
	cout << "Nhap diem toan: "; cin >> sv.diemtoan;
	while(sv.diemtoan < 0 || sv.diemtoan > 10)
	{
		cout << "Diem toan khong hop le, vui long nhap lai: ";
		cin >> sv.diemtoan;
	}
	cout << "Nhap diem van: "; cin >> sv.diemvan;
	while(sv.diemvan < 0 || sv.diemvan > 10) //đảm bảo đầu vào hợp lệ
	{
		cout << "Diem van khong hop le, vui long nhap lai: ";
		cin >> sv.diemvan;
	}
	sv.dtb = (sv.diemtoan+sv.diemvan)/2.0; //tính đtb
}
void xuat(Sinhvien sv)
{
	cout << sv.hoten << " " << sv.diemtoan << " " << sv.diemvan << " dtb: " << sv.dtb;
}
int main()
{
	Sinhvien sv;
	nhap(sv);
	xuat(sv);
	
	return 0;
}
