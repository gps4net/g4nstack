#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "g4nutil.h"

unsigned int parseInt(char* str, int base) {
	if (base == 16) {
		char prefix[] = "0x";
		strcat(prefix, str);
		return (int)strtol(prefix, NULL, base);
	}
	return (int)strtol(str, NULL, base);
}

unsigned long parseLong(char* str, int base) {
	if (base == 16) {
		char s[] = "0x";
		strcat(s, str);
		return strtol(s, NULL, base);
	}
	return strtol(str, NULL, base);
}

char *substring(char *string, int beginIndex, int endIndex) {
	int position = beginIndex, length = endIndex - beginIndex;
	char *p;
	int c;

	p = malloc(length+1);

	if (p == NULL) {
		printf("Unable to allocate memory.\n");
		exit(1);
	}

	for (c = 0; c < length; c++) {
		*(p+c) = *(string+position);
		string++;
	}

	*(p+c) = '\0';

	return p;
}

char* Reverse(char* s) {
	char* beg = s, *end = s, tmp1, tmp2;
	while (*end) end++;
	while ((end = end - 2) > beg)
	{
		tmp1 = *beg;
		beg++;
		tmp2 = *beg;
		beg--;
		*beg++ = *end;
		end++;
		*beg = *end;
		beg++;
		end--;
		*end =  tmp1;
		end++;
		*end = tmp2;
		end--;
	}
	return s;
}

/**
 * Getting the first index of str in base
 */
int indexOf (char* base, char* str) {
	return indexOf_shift(base, str, 0);
}

int indexOf_shift (char* base, char* str, int startIndex) {
	int result;
	int baselen = strlen(base);
	/* str should not longer than base */
	if (strlen(str) > baselen || startIndex > baselen) {
		result = -1;
	} else {
		if (startIndex < 0 ) {
			startIndex = 0;
		}
		char* pos = strstr(base+startIndex, str);
		if (pos == NULL) {
			result = -1;
		} else {
			result = pos - base;
		}
	}
	return result;
}

void toHexaString(char* hexaString, unsigned long number, int noOfChars) {
	char result[20] = "";
	sprintf(result, "%lx", number);
	int i = noOfChars - strlen(result);
	while(i > 0) {
		strcat(hexaString, "0");
		i--;
	}
	toUpperCase(result);
	strcat(hexaString, result);
	return;
}

void toUpperCase(char* string) {
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] = string[i] - 32;
		}
	}
}
