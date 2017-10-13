#include "stdio.h"
#include "stdlib.h"

int romanToInt(char* s) {
	int res = 0, temp = 0;
	while (*s) {
		switch (*s)
		{
			case 'I': res += 1; temp = 1; break;
			case 'V': res += temp == 1 ? 3 : 5; break;
			case 'X': res += temp == 1 ? 8 : 10; temp = 10; break;
			case 'L': res += temp == 10 ? 30 : 50; break;
			case 'C': res += temp == 10 ? 80 : 100; temp = 100; break;
			case 'D': res += temp == 100 ? 300 : 500; break;
			case 'M': res += temp == 100 ? 800 : 1000; break;
		}
		s++;
	}
	return res;
}

//int main() {
//	printf("%d\n", romanToInt("IX"));
//	return 0;
//}