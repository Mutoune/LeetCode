#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

char* tryBraces(char* string, int index) {
	int i = index + 1;
	int flg = 0;
	int length = strlen(string);
	while (i < length) {
		if (string[i] == '}') {
			int j = index;
			while (j <= i - 2) {
				string[j] = string[j + 1];
				j++;
			}
			j = i - 1;
			while (j < length - 2) {
				string[j] = string[j + 2];
				j++;
			}
			string[length - 2] = 0;
			flg = 1;
			break;
		}
		i++;
	}
	printf("%s\n", string);
	if (flg == 0) return "0";
	else return string;
}
char* tryBrackets(char* string, int index) {
	int i = index + 1;
	int flg = 0;
	int length = strlen(string);
	while (i < length) {
		if (string[i] == ']') {
			int j = index;
			while (j <= i - 2) {
				string[j] = string[j + 1];
				j++;
			}
			j = i - 1;
			while (j < length - 2) {
				string[j] = string[j + 2];
				j++;
			}
			string[length - 2] = 0;
			flg = 1;
			break;
		} else if (string[i] == '}' || string[i] == '{') return "0";
		i++;
	}
	printf("%s\n", string);
	if (flg == 0) return "0";
	else return string;
}
char* tryParentheses(char* string, int index) {
	int i = index + 1;
	int flg = 0;
	int length = strlen(string);
	while (i < length) {
		if (string[i] == ')') {
			int j = index;
			while (j < i - 2) {
				string[j] = string[j + 1];
				j++;
			}
			j = i - 1;
			while (j < length - 2) {
				string[j] = string[j + 2];
				j++;
			}
			string[length - 2] = 0;
			flg = 1;
			break;
		}
		else if (string[i] == ']' || string[i] == '}'|| string[i] == '[' || string[i] == '{') return "0";
		i++;
	}
	//printf("%s\n", string);
	if (flg == 0) return "0";
	else return string;
}
bool isValid(char* s) {
	char* string;
	string = (char*)malloc(10000 * sizeof(char));
	strcpy(string, s);
	int len = strlen(string);
	while (len >= 0) {
		if (string[len] == '(') string = tryParentheses(string, len);
		if (string == "0") return false;
		len--;
	}
	len = strlen(string);
	while (len >= 0) {
		if (string[len] == '[') string = tryBrackets(string, len);
		if (string == "0") return false;
		len--;
	}
	len = strlen(string);
	while (len >= 0) {
		if (string[len] == '{') string = tryBraces(string, len);
		if (string == "0") return false;
		len--;
	}
	for (len = 0; len < strlen(string); len++)
		if (string[len] == ')' || string[len] == ']' || string[len] == '}') return false;
	free(string);
	return true;
}

int main() {
	bool flg = isValid("]");
	//isValid("()");
	printf("%d\n", flg);
	return 0;
}
