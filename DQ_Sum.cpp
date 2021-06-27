#include <iostream>
using namespace std;

int sum (int i) {
    if (i<1) return 0;
    else return sum(i-1)+i;
}

int main() {
    cout<<sum(1);
}