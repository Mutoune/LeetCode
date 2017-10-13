#include "stdio.h"
#include "stdlib.h"

int reverse(int x) {
	long res = 0;
	short modNum = 0;
	short flg = 0;
	if (x < 0) {
		flg = 1;
		x = x * -1;
	}
	while (x > 0) {
		modNum = x % 10;
		res = res * 10 + modNum;
		x = x / 10;
	}
	if (flg == 1)
		res = res * -1;
	if (res > 2147483647 || res < -2147483648)
		res = 0;
	return res;
}

//int main() {
//	int x;
//	scanf("%d", &x);
//	printf("%d\n", reverse(x));
//	return 0;
//}