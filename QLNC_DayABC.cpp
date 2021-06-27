#include <iostream>
using namespace std;

const int n=10;

char save[n], minV[n];
int minC = 9999;

void proc(int current_C){
	minC=current_C;
	for (int i=0; i<n; i++) minV[i]=save[i];
}

bool same(int start, int numElement) {
	for (int i=start; i<start+numElement; i++) 
		if (save[i] != save[i+numElement]) return false;
	return true;
}

bool check(int n) {
	for (int i=1; i<=(n/2); i++) {		// Number element to compare
		for (int j=0; j<(n/i)-1; j++)	// Number subsequence to compare
			if (same(j,i)) return false;
	}
	return true;
}

void TRY (int i, int current_C) {
	for (char j = 'A'; j<='C'; j++) {
		save[i] = j;
		if (j=='C') current_C++;
		if (!check(i+1) || current_C>=minC || current_C<(i+1)/4) continue;
		if (i==n-1) proc(current_C);
		else TRY(i+1, current_C);
	}
}

int main() {
	TRY(0,0);
	cout<<"Min of char 'C': "<<minC<<"\n\n-> ";
	for (int i=0; i<n; i++) cout<<minV[i]<<" ";
}
