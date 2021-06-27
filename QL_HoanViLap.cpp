#include <iostream>
using namespace std;

const int n = 3;

int save[n+1];

void proc() {
	for (int i=1; i<=n; i++) cout<<save[i];
	cout<<endl;
}

void TRY (int i) {
	for (int j=1; j<=n; j++) {
		save[i] = j;
		if (i == n) proc();
		else TRY(i+1);
	}
}

int main() {
	TRY(1);
}
