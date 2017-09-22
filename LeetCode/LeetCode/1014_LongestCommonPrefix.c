#include "stdio.h"
#include "stdlib.h"

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0) return "";
	char* str = (char*) malloc (255 * sizeof(char));
	strcpy(str, strs[0]);
	for (int i = 1; i < strsSize; i++) {
		int j = 0;
		while (str[j] && strs[i][j] && str[j] == strs[i][j]) j++;
		str[j] = 0;
	}
	return str;
}

int main() {
	char* arrays [] = { "abcdeff", "ccd", "efe", "kes" };
	char** strs = arrays;
	//for (int i = 0; i < 4; i++) strs[i] = (char*)malloc(100 * sizeof(char));
	//strcpy(strs[0], "abcdeff");
	//strcpy(strs[1], "abccd");
	//strcpy(strs[2], "abefe");
	//strcpy(strs[3], "abkes");
	//for (int i = 0; i < 4; i++) free(strs[i]);
	//free(strs);
	printf("%s\n", longestCommonPrefix(strs, 4));
	return 0;
}