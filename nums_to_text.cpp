#include <iostream>

#include "resource.h"
#include "nums_to_text.h"

// Read the group of 3 digits.
const char *NumsToText::read_group(int gr)
{
	// The buffer for the text representation of the group.
	static char buf[256];
	// Initialize the buffer.
	strcpy_s(buf, "");

	// Read the first digit.
	strcat_s(buf, hundreds[gr / 100]);

	// For 2 digits number, add the special case (11,12,13..)
	if (gr >= 10)
	{
		for (int i = 0; i < 9; i++)
		{
			if (gr % 100 == special[i])
			{
				strcat_s(buf, special_txt[i]);
				return buf;
			}
		}
	}

	// Read the second digit.
	strcat_s(buf, tens[gr % 100 / 10]);

	// If zero is the second digit, add the word "and"
	// (100-109, 200-209, ...)
	if (gr >= 100 && gr % 100 <= 9 && gr % 100 >= 1)
		strcat_s(buf, and_txt);

	// Read the last digit.
	strcat_s(buf, units[gr % 10]);

	// Return the buffer.
	return buf;
}

// Read the number by the group of 3 digits.
const char *NumsToText::read_number(long int user_input)
{
	// The buffer for storing the whole number.
	static char text[256];
	// The buffer for storing the group of 3 digits.
	static char buf[256];

	// The number of 3 digits itself.
	int gr;
	// Count the group of 3 digits.
	int gr_count = 0;

	// Initialize the buffer.
	strcpy_s(text, "");

	while (user_input > 0L)
	{
		// Take the group of 3 digits.
		gr = user_input % 1000;

		// If the group of 3 digits is not 000
		if (gr > 0)
		{
			// Read the whole group.
			strcpy_s(buf, read_group(gr));

			// Add the name of group, see the file resource.h
			if (gr == 1)
				strcat_s(buf, groups[gr_count]);
			else
				strcat_s(buf, groups2[gr_count]);

			// Add to the buffer
			strcat_s(buf, text);

			// Add to the buffer
			strcpy_s(text, buf);
		}

		user_input /= 1000;
		gr_count++;
	}

	// If number is less than zero,
	// add the word "minus" in front of the text representation
	if (is_negative == true)
	{
		strcpy_s(buf, "minus ");
		strcat_s(buf, text);
		strcpy_s(text, buf);
		return text;
	}
	else
		return text;
}
