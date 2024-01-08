#include<bits/stdc++.h>
using namespace std;

class Computer{
	protected:
		string mamt;
		string hangsx;
		int namsx;
		float giaban;
	public:
		Computer(){
			cin.ignore();
			cout<<"Nhap ma mt: ";getline(cin,mamt);
			cout<<"Nhap hang sx: ";getline(cin,hangsx);
			cout<<"Nhap nam sx: ";cin>>namsx;
			cout<<"Gia ban: ";cin>>giaban;
		}
		void set_computer(string mamt,string hangsx,int namsx,float giaban){
			this->mamt=mamt;
			this->hangsx=hangsx;
			this->namsx=namsx;
			this->giaban=giaban;
		}
		string get_mamt(){
			return mamt;
		}
		string get_hangsx(){
			return hangsx;
		}
		int get_namsx(){
			return namsx;
		}
		float get_giaban(){
			return giaban;
		}
		void hienthi_computer(){
			cout<<"Ma mt: "<<mamt<<endl;
			cout<<"Hang sx: "<<hangsx<<endl;
			cout<<"Nam sx: "<<namsx<<endl;
			cout<<"Gia ban:"<<giaban<<endl;
		}
};
class Laptop : public Computer{
	protected:
		int doday;
		int cannang;
		int kichthuocmh;
		string hdh;
	public:
		Laptop() : Computer(){
			cout<<"Nhap do day: ";cin>>doday;
			cout<<"Nhap can nang: ";cin>>cannang;
			cout<<"Nhap kich thuoc mh: ";cin>>kichthuocmh;
			cin.ignore();
			cout<<"Nhap he dieu hanh: ";getline(cin,hdh);
		}
		void set_Laptop(int doday,int cannang,int kichthuocmh,string hdh){
			this->cannang=cannang;
			this->doday=doday;
			this->kichthuocmh=kichthuocmh;
			this->hdh=hdh;
		}
		int get_cannang(){
			return cannang;
		}
		int get_doday(){
			return doday;
		}
		int get_kichthuocmhh(){
			return kichthuocmh;
		}
		string get_hdh(){
			return hdh;
		}
		int sonamsd(){
			return 2024-get_namsx();
		}
		int tinh_gtcl(){
			double gtcl=0.0;
			if(get_hdh() == "Windows" || get_hdh() == "windows"){
				gtcl=get_giaban()-(sonamsd()*0.1*get_giaban());
			}else{
				gtcl =giaban-(sonamsd()*0.05*giaban);
			}return (gtcl<0) ? 0 : gtcl;
			cout<<gtcl<<endl;
		}
		void hienthi_laptop(){
			hienthi_computer();
			cout<<"Do day: "<<doday<<endl;
			cout<<"Can nang: "<<cannang<<endl;
			cout<<"Kich thuoc man hinh: "<<kichthuocmh<<endl;
			cout<<"hdh: "<<hdh<<endl;
			cout<<"So nam sd: "<<sonamsd()<<endl;
			cout<<"Gtcl: "<<tinh_gtcl()<<endl;
		}
		
		bool operator>(Laptop &other){
			return tinh_gtcl() > other.tinh_gtcl();
		}
};
int main(){
	vector<Laptop> Lt{};
	int control;
	string hdh;
	int cannang,doday,kichthuocmh;
	continue_menu:
		cout<<"0.Ket thuc"<<endl;
		cout<<"1.Them"<<endl;
		cout<<"2.Sap xep ds theo thu tu tang dan"<<endl;
		cout<<"3.Nhap chuoi hsx, xoa tat ca cac mt co hang san xuat la hsx"<<endl;
		cout<<"4.Hien thi"<<endl;
	nhap_menu:
		cout<<"Nhap chuc nang: ";
		cin>>control;
		switch(control){
			default:{
				break;
				goto nhap_menu;
			}
			case 1:{
				Laptop q;
				Lt.push_back(q);
				cout<<"--Them thanh cong--"<<endl;
				goto continue_menu;
			}
			case 2:{
				for(int i=0;i<Lt.size()-1;i++)
					for(int j=i+1;j<Lt.size();j++)
						if(Lt[i].tinh_gtcl()<Lt[j].tinh_gtcl())
							swap(Lt[i],Lt[j]);
				cout<<"--Da sap xep--"<<endl;		
				goto continue_menu;
			}
			case 3:{
				cin.ignore();
				string hsx;
				cout<<"Nhap hsx: ";
				getline(cin,hsx);
				for (auto it = Lt.begin(); it != Lt.end(); ) {
    				if (it->get_hangsx() == hsx) {
        				it = Lt.erase(it);
    				} else {
        				++it;
    				}		
				}
				cout<<"--Da xoa thanh cong--"<<endl;
			}
			case 4:{
				for(int i=0;i<Lt.size();i++){
					Lt[i].hienthi_laptop();
				}
				goto continue_menu;
			}
		}
}