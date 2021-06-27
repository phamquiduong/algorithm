#include<iostream>
using namespace std;

int min(int a[],int x,int y){
	if (x==y) return a[x];
	int min1=min(a,x,(x+y)/2);
	int min2=min(a,(x+y)/2+1,y);
	if (min1<min2) return min1; else return min2;
}

int main(){
	int a[]={9,3,6,2,8};
	cout<<"Min = "<<min(a,0,4);
}
