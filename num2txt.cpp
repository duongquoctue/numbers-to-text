#include <iostream>

#include "resource.h"
#include "num2txt.h"


// read group of 3 digits
const char *Num2Txt::read_group(int gr)
{
	static char buf[BUFSIZE];

	strcpy_s(buf, "");

	// read first digit
	strcat_s(buf, hundreds[gr / 100]);

	// special case for 2-digit numbers (11 = eleven, 12 = twelve, etc.)
	if (gr >= 10) {
		for (int i = 0; i < SIZE_OF_SPECIAL_NUMBERS_ARRAY; i++) {
			if (gr % 100 == special[i]) {
				strcat_s(buf, special_txt[i]);
				return buf;
			}
		}
	}

	// read second digit
	strcat_s(buf, tens[gr % 100 / 10]);

	// zero is the second digit (100-109, 200-209, ...), add the word "and"
	if (gr >= 100 && gr % 100 <= 9 && gr % 100 >= 1)
		strcat_s(buf, and_txt);

	// read last digit
	strcat_s(buf, units[gr % 10]);

	return buf;
}
static char text[BUFSIZE];
static char buf[BUFSIZE];
// read numbers by group of three, starting from the right
const char * Num2Txt::group_count( long int user_input) {
	int gr;
	int gr_count = 0;

	strcpy_s(text, "");
	while (user_input > 0L) {
		gr = user_input % 1000;

		// this group has some numbers other than 000
		if (gr > 0) {
			// read the whole group
			strcpy_s(buf, read_group(gr));

			// add name of group
			if (gr == 1)
				strcat_s(buf, groups[gr_count]);
			else
				strcat_s(buf, groups2[gr_count]); // with 's'

			  // add the text that we have read earlier
			strcat_s(buf, text);

			// put everything in result      
			strcpy_s(text, buf);
		}

		user_input /= 1000;
		gr_count++;
	}
	// add the word "minus" in front if number is less than zero
	if (is_negative == true) {
		strcpy_s(buf, "minus ");
	    strcat_s(buf, text);
		strcpy_s(text, buf);
		return text;
	} 
	else return text;
}
