#include <stdio.h>
#include <stdlib.h>
#include "bioinformatics.h"

int main(int argc, char** argv) {
	if(argc < 4) {
		puts("Needs 3 args: <func number> <arg1> <arg2>");
		return 1;
	}
	switch(atoi(argv[1])) {
		case 1:
			putchar('0' + getHammingDistance(argv[2], argv[3]));
			break;
		case 2:
			putchar('0' + countSubstrPattern(argv[2], argv[3]));
			break;
		case 3: 
			putchar('0' + isValidString(argv[2], argv[3]));
			break;
		case 4: 
			printf("%d", getSkew(argv[2], atoi(argv[3])));
			break;
		case 5: 
			printf("%d", getMaxSkewN(argv[2], atoi(argv[3])));
			break;
		case 6: 
			printf("%d", getMinSkewN(argv[2], atoi(argv[3])));
			break;
	}
	putchar('\n');
	return 0;
}
