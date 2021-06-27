#include <iostream>
using namespace std;

const int n = 3;

int save[n+1];
bool b[n+1];

void proc() {
	for (int i=1; i<=n; i++) cout<<save[i];
	cout<<endl;
}

void TRY (int i) {
	for (int j=1; j<=n; j++) {
		if (b[j]) {
			b[j] = false;
			save[i] = j;
			if (i == n) proc();
			else TRY(i+1);
			b[j] = true;
		}
	}
}

int main() {
	for (int i=1; i<=n; i++) b[i] = true;
	TRY(1);
}
