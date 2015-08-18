// find all string permutations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *c1, char *c2){
	char tmp;
	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void permutation(char *str, int start, int end){
	if(start == end){
		printf("%s\n", str);
	}
	unsigned int i;
	for(i = start; i <= end; i++){
		swap(&str[start], &str[i]);
		permutation(str, start+1, end);
		swap(&str[start], &str[i]);
	}
}

int main(int argc, char *argv[]){
	int len = strlen(argv[1]);
	char str[len];
	strcpy(str, argv[1]);
	permutation(str, 0, len-1);
	printf("%s\n", str);
	return 0;
}
