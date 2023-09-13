#include<bits/stdc++.h>
using namespace std;

int f(int a=3, int b=5)
	{return a+b;}

int main(){
	int m=4, n=6;
	cout << f()<< endl;
	cout << f(n)<< endl;
	cout << f(m,n);
}
