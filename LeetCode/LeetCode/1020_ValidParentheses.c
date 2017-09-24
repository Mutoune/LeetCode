#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

bool isValid(char* s) {
	char* stack;
	stack = (char*)malloc(10000 * sizeof(char));
	int j = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			stack[j] = s[i];
			j++;
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			switch (s[i]) {
			case ')':
				if (j > 0 && stack[j - 1] == '(') {
					j--;
				}
				else {
					return false;
				}
				break;
			case ']':
				if (j > 0 && stack[j - 1] == '[') {
					j--;
				}
				else {
					return false;
				}
				break;
			case '}':
				if (j > 0 && stack[j - 1] == '{') {
					j--;
				}
				else {
					return false;
				}
				break;
			}
		}
	}
	if (j > 0) {
		return false;
	}
	free(stack);
	return true;
}

int main() {
	bool flg = isValid("()[]{}");
	//isValid("()");
	printf("%d\n", flg);
	return 0;
}
