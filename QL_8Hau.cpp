#include <iostream>
using namespace std;

int save[9];
bool sum[17], sub[14], ed[9];

void print(){
	for (int i=1; i<=8; i++) {
		for (int j=1; j<=8; j++) {
			if (j==save[i]) cout<<" "<<i<<" ";
			else cout<<" . ";
		}
		cout<<endl;
	}
	cout<<"\n\n-----------------------\n\n";
	char c = getchar();
}

void TRY(int i){
	for (int j=1; j<=8; j++) {
		if (ed[j] && sum[i+j] && sub[i-j+7]) {
			save[i] = j;
			ed[j] = sum[i+j] = sub[i-j+7] = false;
			if (i==8) print();
			else TRY (i+1);
			ed[j] = sum[i+j] = sub[i-j+7] = true;
		}
	}
}

int main(){
	//Sum start from 2 to 16 | sub start from -7 to 7 or from 0 to 14 | ed start from 1 to 8
	
	for (int i=2; i<=16; i++) sum[i]=true;	//cheo 1
	for (int i=0; i<=14; i++) sub[i]=true;	//cheo 2
	for (int i=1; i<=8; i++) ed[i]=true;	//doc
	
	TRY(1);
}
