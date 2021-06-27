#include<iostream>
using namespace std;

int dem=0;

void chuyen(int n, char a, char b, char c){
	if (n==1){
		cout<<a<<"-->"<<b<<endl;
		dem++;	
	}
	if (n>1){
		chuyen(n-1,a,c,b);
		chuyen(1,a,b,c);
		chuyen(n-1,c,b,a);
	}
	
}

int main(){
	chuyen(5,'a','b','c');
	cout<<"\n\n"<<dem;
}
