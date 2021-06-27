#include<stdio.h>

void output(long long n, int cs) {
	if (n > 0) output(n / cs, cs); else return;
	char t = n % cs;
	if (t < 10) t += 48; else t += 55;
	printf("%c", t);
}

int main() {
	int cs; printf("	Co_so_vao: "); scanf("%d", &cs);
	long long n = 0;
	printf("		=> Gia_tri: ");
	fflush(stdin);
	while (1) {
		char t;
		scanf("%c", &t);
		if (t == '\n') break;
		if (t <= '9') t -= 48;
		else t -= 55;
		n = n * cs + t;
	}
	printf("\n	-----------------------\n\n	Co_so_ra: ");  scanf("%d", &cs);
	printf("		=>Ket_qua: ");
	if (cs == 10) printf("%lld",n);
	else output(n, cs);
}
