#include <iostream>
using namespace std;
struct date{
	int ngay, thang, nam;
};
//xac dinh nam nhuan
bool nam_nhuan(int x)
{
	return (x%400 == 0 || ((x%4==0) && x % 100 != 0 ));
}
//so ngay trong tung thang
int day_of_month(int month, int year)
{
	int dom;
	switch(month){
	case 4: case 6: case 9: case 11: dom = 30;

		break;
	case 2:
		{
			if(nam_nhuan(year)) dom = 29;
			else dom = 28;
		}
		break;
	default: 
		dom = 31;
		break;
	}
	return dom;
}
void nhap(date &d)
{
	cout << "\nNhap nam: ";
	while(!(cin >> d.nam) || d.nam <= 0 )
	{
		cout << "\nNam khong hop le, vui long nhap lai: "; cin >> d.nam;
		cin.clear();             
    	cin.ignore(1000,'\n'); 
	}
	cout << "\nNhap thang: ";
	while(!( cin >> d.thang) || d.thang <= 0 || d.thang > 12)
	{
		cout << "\nThang khong hop le, vui long nhap lai: "; cin >> d.thang;
		cin.clear();             
    	cin.ignore(1000,'\n'); 
	}
	cout << "\nNhap ngay: "; 
	while(!(cin >> d.ngay) || d.ngay <= 0 || d.ngay > day_of_month(d.thang, d.nam))
	{
		cout << "Ngay khong hop le, vui long nhap lai: "; cin >> d.ngay;
		cin.clear();             
    	cin.ignore(1000,'\n'); 
	}
}
//tim ngay ke tiep
void nextDay(date &d)
{
	int maxDay = day_of_month(d.thang, d.nam);
	//nếu vẫn còn trong tháng
	if(d.ngay < maxDay)
	{
		d.ngay ++;
	}
		//qua tháng mới
	else {
		d.ngay = 1;
		if(d.thang == 12) //nếu qua năm mới
		{
			d.thang = 1;
			d.nam ++;
		}
		else d.thang++; // vẫn còn trong năm
	}
}
void xuat(date d)
{
	cout << "\nNgay ke tiep la: " << d.ngay << "/" << d.thang  << '/' << d.nam;
}
int main()
{
	date d;
	nhap(d);
	nextDay(d);
	xuat(d);
}
