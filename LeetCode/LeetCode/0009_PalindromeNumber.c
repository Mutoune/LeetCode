#include <stdio.h>
#include <stdlib.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

bool isPalindrome(int x) {
	if (x != 0 && x % 10 == 0) return false;
	int y = 0;
	while (x > y) {
		y = y * 10 + x % 10;
		x = x / 10;
	}
	if (x == y || x == y / 10) return true;
	else return false;
}