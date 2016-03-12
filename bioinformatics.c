int getHammingDistance(char* str1, char* str2) {
	int distance = 0;
	while (*str1 != '\0' && *str2 != '\0') {
		if (*(str1++) != *(str2++)) {
			distance++;
		}
	}
	if(*str1 != *str2) {
		return -1;
	}
	return distance;
}

int countSubstrPattern(char* original, char* pattern) {
	char *patternFind = original;
	char *patternStart = pattern;
	int patternOccurence = 0;
	while(*original != 0) {
		while (*pattern != '\0' && *original != 0 && *(pattern++) == *(original)++);

		if (*pattern == '\0') {
			patternOccurence++;
		}
		pattern = patternStart;
		original = ++patternFind;
	}

	return patternOccurence;
}

int containsChar(char *str, char ch) {
	while(*str != '\0') {
		if (*(str++) == ch) {
			return 1;
		}
	}
	return 0;
}

int isValidString(char* str, char* alphabet) {
	while(*str != '\0') {
		if(!containsChar(alphabet, *(str++))) {
			return 0;
		}
	}
	
	return 1;
}

int getSkew(char* str, int index) {
	int count;
	for(count = 0; *str != '\0' && index > 0; index--, str++) {
		if ( *str == 'G') {
			count++;
		} else if (*str == 'C') {
			count--;
		}
	}
	return count;
}

int getMaxSkewN(char* str, int index) {
	int maxSkew = 0;
	int count;
	for(count = 0; *str != '\0' && index > 0; index--, str++) {
		if ( *str == 'G') {
			count++;
		} else if (*str == 'C') {
			count--;
		}

		if(count > maxSkew) {
			maxSkew = count;
		};
	}
	return maxSkew;
}
