#include <iostream>
using namespace std;
class NhanVien{
	protected:
		string hoten;  	//ho ten nguoi lam viec
		int ns;			//nam sinh
		float lcb;		//he so luong
	public:	
		NhanVien(string ht,int nam,float hs){
			hoten=ht;ns=nam;lcb=hs;
		}
		string getHoTen(){
			return hoten;
		}
		virtual void xuat(){
			cout<<"hoten "<<hoten<<", nam sinh "<<ns<<", he so luong "<<lcb<<endl;
		}
		virtual float tinhluong(){
			return 0;
		};
};
class VanPhong:public NhanVien{
	int songay;
	int trocap;
	public:
		VanPhong(int sn,int tc,string ht,int nam,float hs):NhanVien(ht,nam,hs){
			songay=sn;trocap=tc;
		}
		float tinhluong(){
			return lcb+songay*200+trocap;
		}
		void xuat(){
			cout<<"Van phong:  ";
			NhanVien::xuat();
			cout<<"So ngay: "<<songay<<", tro cap: "<<trocap<<endl;
		}		
};
class SanXuat:public NhanVien{
	int sosanpham;
	public:
		SanXuat(int sl,string ht,int nam,float hs):NhanVien(ht,nam,hs){
			sosanpham=sl;
		}
		float tinhluong(){
			return lcb+sosanpham*2000;
		}
		void xuat(){
			cout<<"San Xuat:  ";
			NhanVien::xuat();
			cout<<"So san pham: "<<sosanpham<<endl;
		}
};
class QuanLy:public NhanVien{
	int phucap;
	int thuong;
	public:
		QuanLy(int pc,int t,string ht,int nam,float hs):NhanVien(ht,nam,hs){
			phucap=pc;thuong=t;
		}
		float tinhluong(){
			return lcb*phucap+thuong;
		}
		void xuat(){
			cout<<"Quan ly:  ";
			NhanVien::xuat();
			cout<<"Phu cap: "<<phucap<<", thuong: "<<thuong<<endl;
		}
};
class QLNhanVien{
	NhanVien * nv[100];
	int n;
	public:
		QLNhanVien(){
			n=0;
		}
		void nhap(){
		int chon;
		do{
			cout<<"Ban nhap gi? Van phong: 1; Lam viec: 2: Quan ly: 3; Khac ket thuc nhap ";
			cin>>chon;
			switch (chon){
				case 1:{
					int sn;int tc;string ht;int nam;float hs;
					cout<<"Nhap so ngay: ";cin>>sn;
					cout<<"Nhap tro cap: ";cin>>tc;cin.ignore(1);
					cout<<"Nhap ho ten : ";getline(cin,ht);
					cout<<"Nhap Nam sinh: ";cin>>nam;
					cout<<"Nhap Luong co ban: ";cin>>hs;
					nv[n]=new VanPhong( sn,tc, ht, nam, hs);
					n++;
					break;
				}
				case 2:{
					int sl;string ht;int nam;float hs;
					cout<<"Nhap so luong: ";cin>>sl;cin.ignore(1);
					cout<<"Nhap ho ten : ";getline(cin,ht);
					cout<<"Nhap Nam sinh: ";cin>>nam;
					cout<<"Nhap Luong co ban: ";cin>>hs;
					nv[n]=new SanXuat( sl, ht, nam, hs);
					n++;
					break;					
				}
				case 3:{
					int pc;int t;string ht;int nam;float hs;
					cout<<"Nhap phu cap: ";cin>>pc;
					cout<<"Nhap tien thuong: ";cin>>t;cin.ignore(1);
					cout<<"Nhap ho ten : ";getline(cin,ht);
					cout<<"Nhap Nam sinh: ";cin>>nam;
					cout<<"Nhap Luong co ban: ";cin>>hs;
					nv[n]=new QuanLy( pc,t, ht, nam, hs);
					n++;
					break;					
				}
			}
		} while (chon==1 ||chon==2||chon==3);
	}
	void xuat()	{
		for(int i=0;i<n;i++){
			nv[i]->xuat();
			cout<<"Luong: "<<nv[i]->tinhluong()<<endl;
		}
	}
	float tongLuong(){
		float tong=0;
		for (int i=0;i<n;i++){
			tong+=nv[i]->tinhluong();
		}
	}
	int timHoTen(string ht){
		int i=0;
		while (i<n && ht!=nv[i]->getHoTen())
			i++;
		if (i==n) return -1;
		else return i;
	}
};
int main(){
	QLNhanVien d;
	d.nhap();
	d.xuat();
	cout<<"Tong luong nhan vien="<<d.tongLuong()<<endl;
	cout<<d.timHoTen("le nam");
}
