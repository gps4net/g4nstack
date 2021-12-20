#ifndef G4NUTIL_H
#define G4NUTIL_H

typedef enum {
	HOME,
	ROAMING
} Network;

/**
 * Converts the string in hexa or decimal to int
 * returns 0 if not a number
 * int is 2 bytes, 4 hexa chars
 */
unsigned int parseInt(char* str, int base);

/**
 * Converts the string in hexa or decimal to long
 * returns 0 if not a number
 * long is 4 bytes, 8 hexa chars
 */
unsigned long parseLong(char* str, int base);

/**
 * Returns the substring from begin index to end index or the given string.
 * Return value must be freed from heap with free(return_value).
 */
char *substring(char *string, int beginIndex, int endIndex);

/**
 * Reverts the characters of the given string
 * String s must be initialized with char s[] = "string to Reverse". char * s = "string to Reverse" will give a segmentation fault.
 */
char* Reverse(char *s);

/**
 * Getting the first index of str in base
 */
int indexOf(char* base, char* str);

/**
 * Getting startIndex of str in base
 */
int indexOf_shift(char* base, char* str, int startIndex);

/**
 * Converts the number to a hexa string. Leading zeros are added in case the length of string is less than noOfChars.
 * The result is appended to hexaString.
 */
void toHexaString(char* hexaString, unsigned long number, int noOfChars);

/**
* Convert string to uppercase
*/
void toUpperCase(char* string);

#endif
