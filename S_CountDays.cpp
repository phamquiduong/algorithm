#include<iostream>
using namespace std;
int dim[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};		//Number Day in Month

struct date{
	int d,m,y;
};

date t,s;

istream&operator >> (istream&i, date &x){
	cout<<"Day Month Year = "; i>>x.d>>x.m>>x.y;
	return i;
}

ostream&operator >> (ostream&o, const date &x){
	o<<x.d<<'/'<<x.m<<'/'<<x.y<<endl;
	return o;
}

bool nhuan(int y){
	if (y%100==0) {if (y%400==0) return 1; else return 0;}
	if (y%4==0) return 1; else return 0;
}

bool checkdate(date x){
		//Check Month
	if (x.m<1 || x.m>12) return 0;
		//Check Day
	if (x.m==2){
		if (nhuan(x.y)){
			if (x.d>=1 && x.d<=29) return 1; else return 0;
		} else{
			if (x.d>=1 && x.d<=28) return 1; else return 0;
		}
	}
	if (x.d>=1 && x.d<=dim[x.m]) return 1; else return 0;
	
}

int checkinput(date &t, date &s){
		//Check Year
	if (t.y>s.y) return 0;
	if (t.y<s.y) return 1;
		//Check Month
	if (t.m>s.m) return 0;
	if (t.m<s.m) return 1;
		//Check Day
	if (t.d>s.d) return 0;
	if (t.d<s.d) return 1;
		//The same case
	return -1;
}

int main(){
		// Check date
	cout<<"First Time:\n  "; cin>>t;
	while (checkdate(t)==0){
		cout<<"     ~ Input False :( Please Input Again!\n  ";
		cin>>t;
	}
	cout<<"\nSecond Time:\n  "; cin>>s;
	while (checkdate(s)==0){
		cout<<"     ~ Input False :( Please Input Again!\n  ";
		cin>>s;
	}
		// Check input
	int check=checkinput(t,s);
	if (check==-1) {
		cout<<"\n--------------------------------\n     ==> The same day!";
		return 0;
	}
	if (check==0) {			//Neu ngay truoc lon hon ngay sau thi trao doi de tinh
		date temp=t;
		t=s;
		s=temp;
	}
	
		//Proc
	int pt=t.d;
	for (int i=1; i<t.m; i++){
		if (i==2){
			if (nhuan(t.y)) pt+=29; else pt+=28;
		} else pt+=dim[i];
	}
	
	int ps=s.d;
	for (int i=1; i<s.m; i++){
		if (i==2){
			if (nhuan(t.y)) ps+=29; else ps+=28;
		} else ps+=dim[i];
	}
	for (int i=t.y; i<s.y; i++)
		if (nhuan(i)) ps+=366; else ps+=365;
	cout<<"\n--------------------------------\n     ==> "<<ps-pt<<" days :)";		
}
