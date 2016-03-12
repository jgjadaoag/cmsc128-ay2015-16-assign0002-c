/**
 * Gets the hamming distance of two strings.
 *
 * @param string to compare
 * @param string to compare
 *
 * @returns the hamming distance
 *
 * Returns the number of inversions per character to transform string 1 to string 2
 */
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

/**
 * Counts the occurences of substring in a string
 *
 * @param The string to look for the substring
 * @param The substring to look for
 *
 * @returns the number of substrings in the string
 */
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

/**
 * Tells if the string contains a specific character
 *
 * @param The string to look for the character
 * @param The character to look for
 *
 * @returns 1 if found, else 0
 */
int containsChar(char *str, char ch) {
	while(*str != '\0') {
		if (*(str++) == ch) {
			return 1;
		}
	}
	return 0;
}

/**
 * Tells if the string contains only letters from the given alphabet
 *
 * @param The string to validate
 * @param The alphabet to use
 *
 * @returns 1 if valid, else 0
 */
int isValidString(char* str, char* alphabet) {
	while(*str != '\0') {
		if(!containsChar(alphabet, *(str++))) {
			return 0;
		}
	}
	
	return 1;
}

/**
 * Gets the skew of a genome string
 *
 * @param The genome string
 * @param The number of nucleotides to look into
 *
 * @returns The number of G minus C
 */
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

/**
 * Gets the maximum skew from a genome string
 *
 * @param The genome string
 * @param The number of nucleotides to look into
 *
 * @returns The maximum Skew
 *
 * Returns the maximum skew for each skew in each number of nucleotides
 */
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

/**
 * Gets the minimum skew from a genome string
 *
 * @param The genome string
 * @param The number of nucleotides to look into
 *
 * @returns The minimum Skew
 *
 * Returns the minimum skew for each skew in each number of nucleotides
 */
int getMinSkewN(char* str, int index) {
	int minSkew = (*str == 'G')? 1: 0;
	int count;
	for(count = 0; *str != '\0' && index > 0; index--, str++) {
		if ( *str == 'G') {
			count++;
		} else if (*str == 'C') {
			count--;
		}

		if(count < minSkew) {
			minSkew = count;
		};
	}
	return minSkew;
}
