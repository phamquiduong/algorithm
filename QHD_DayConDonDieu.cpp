// Chuong trinh day con don dieu dai nhat
// Su dung thuat toan Quy Hoach Dong

#include<iostream>
using namespace std;

int a[100] = { 0,1,2,3,8,9,4,5,6,20,9,10 };		//O day minh xet tu phan tu a[1] tro di.. khong xet phan tu a[0]
int kq[100] = { 0,1 };		//Voi truong hop mang A co 1 phan tu thi MAX day don dieu la 1.. Khoi tao co so QHD

int max(int a[], int kq[], int n) {		//Ham chua cong thuc QHD
	int t = 0;
	for (int i = 1; i < n; i++)
		if (a[i] < a[n] && kq[i] > t)
			t = kq[i];
	return t;
}

void truyhoi(int kq[], int vt) {
	if (kq[vt] == 1)
		cout << "  a[" << vt << "]= " << a[vt] << endl;
	else {
		int i=vt-1;
		while (kq[i] != kq[vt] - 1) i--;
		truyhoi(kq, i);
		cout << "  a[" << vt << "]= " << a[vt] << endl;
	}
}

int main() {
	int n = 11, vt = 1;
	for (int i = 2; i <= n; i++) kq[i] = max(a,kq,i) + 1;
	for (int i=1; i<=n; i++)
		if (kq[i] > kq[vt])
			vt = i;
	cout << "Do dai lon nhat: " << kq[vt] << endl;
	cout << "\nKet qua:\n";
	truyhoi(kq, vt);
}
