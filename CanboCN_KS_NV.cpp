#include<bits/sdtc++.h>
using namespace std;

class Canbo{
	protected:
		string hoten;
		int tuoi;
		string gioitinh;
		string diachi;
	public:
		Canbo(){
			cout<<"Nhap ho ten: ";getline(cin,hoten);
			cout<<"Nhap tuoi: ";cin>>tuoi;
			cout<<"Nhp gioi tinh: ";getline(cin,gioitinh);
			cout<<"Nhap dia chi: ";getline(cin,diachi);
		}
		void set_Canbo(string hoten,int tuoi,string gioitinh,string diachi){
			this->hoten=hoten;
			this->tuoi=tuoi;
			this->gioitinh=gioitinh;
			this->diachi=diachi;
		}
		string get_hoten(){
			return hoten;
		}
		int get_tuoi(){
			return tuoi;
		}
		string get_gioitinh(){
			return gioitinh;
		}
		string get_diachi(){
			return diachi;
		}
		void hienthi_canbo(){
			cout<<"Ho ten: "<<hoten<<endl;
			cout<<"Tuoi: "<<tuoi<<endl;
			cout<<"Gioi tinh: "<<gioitinh<<endl;
			cout<<"Dia chi: "<<diachi<<endl;
		}
};
class Congnhan : public Canbo{
	protected:
		int bac;
	public:
		Congnhan() : Canbo(){
			cout<<"Nhap bac (1-10): ";cin>>bac;
		}
		void set_congnhan(int bac){
			this->bac=bac;
		}
		int get_bac(){
			return bac;
		}
		void hienthi_congnhan(){
			cout<<"Bac (1-10): "<<bac<<endl;
		}
};
class Kysu : public Canbo{
	protected:
		string nghanhdt;
	public:
		Kysu() : Canbo(){
			cout<<"Nhap nganh dao tao: ";getline(cin,nganhdt);
		}
		void set_kysu(string nghanhdt){
			this->nghanhdt=nghanhdt;
		}
		string get_nghanhdt(){
			return nghanhdt;
		}
		void hienthi_kisu(){
			cout<<"Nghanh dao tao: "<<nghanhdt<<endl;
		}
};
class Nhanvien : public Canbo{
	protected:
		string congviec;
	public:
		Nhanvien() : Canbo(){
			cout<<"Nhap cong viec: ";getline(cin,congviec);
		}
		void set_nhanvien(string congviec){
			this->congviec=congviec;
		}
		string get_congviec(){
			return congviec;
		}
		void hienthi_nhanvien(){
			cout<<"Cong viec: "<<congviec<<endl;
		}
};
class qlcb{
	
};
