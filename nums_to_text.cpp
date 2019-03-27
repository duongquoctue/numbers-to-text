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

	// For 2 digits number, add the special case (11,12,13..).
	if (gr >= 10)
	{
		// See resource.h.
		for (int i = 0; i < IDS_NUMS_OF_SPECIAL_NUM; i++)
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
	// (100-109, 200-209, ...).
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

		// If the group of 3 digits is not 000.
		if (gr > 0)
		{
			// Read the whole group.
			strcpy_s(buf, read_group(gr));

			// Add the name of group.
			if (gr == 1)
				strcat_s(buf, groups[gr_count]);
			else
				strcat_s(buf, groups_s[gr_count]);

			// Add to the buffer.
			strcat_s(buf, text);

			// Add to the buffer.
			strcpy_s(text, buf);
		}

		user_input /= 1000;
		gr_count++;
	}

	// If the number is less than zero,
	// add the word "minus" in front of the text representation.
	if (is_negative == true)
	{
		strcpy_s(buf, STR_TEXT_MINUS);
		strcat_s(buf, text);
		strcpy_s(text, buf);
		return text;
	}
	else
		return text;
}

// See resource.h.
const int NumsToText::special[10] = {
	IDS_SPECIAL_NUM_1,
	IDS_SPECIAL_NUM_2,
	IDS_SPECIAL_NUM_3,
	IDS_SPECIAL_NUM_4,
	IDS_SPECIAL_NUM_5,
	IDS_SPECIAL_NUM_6,
	IDS_SPECIAL_NUM_7,
	IDS_SPECIAL_NUM_8,
	IDS_SPECIAL_NUM_9};
const char *NumsToText::units[10] = {
	STR_UNITS_,
	STR_UNITS_1,
	STR_UNITS_2,
	STR_UNITS_3,
	STR_UNITS_4,
	STR_UNITS_5,
	STR_UNITS_6,
	STR_UNITS_7,
	STR_UNITS_8,
	STR_UNITS_9};
const char *NumsToText::tens[10] = {
	STR_TENS_,
	STR_TENS_1,
	STR_TENS_2,
	STR_TENS_3,
	STR_TENS_4,
	STR_TENS_5,
	STR_TENS_6,
	STR_TENS_7,
	STR_TENS_8,
	STR_TENS_9};
const char *NumsToText::hundreds[10] = {
	STR_HUNDREDS_,
	STR_HUNDREDS_1,
	STR_HUNDREDS_2,
	STR_HUNDREDS_3,
	STR_HUNDREDS_4,
	STR_HUNDREDS_5,
	STR_HUNDREDS_6,
	STR_HUNDREDS_7,
	STR_HUNDREDS_8,
	STR_HUNDREDS_9};
const char *NumsToText::groups[10] = {
	STR_GROUPS_,
	STR_GROUPS_1,
	STR_GROUPS_2,
	STR_GROUPS_3};
const char *NumsToText::groups_s[10] = {
	STF_GROUPS_S_,
	STF_GROUPS_S_1,
	STF_GROUPS_S_2,
	STF_GROUPS_S_3};
const char *NumsToText::special_txt[10] = {
	STR_SPECIAL_TEXT_,
	STR_SPECIAL_TEXT_1,
	STR_SPECIAL_TEXT_2,
	STR_SPECIAL_TEXT_3,
	STR_SPECIAL_TEXT_4,
	STR_SPECIAL_TEXT_5,
	STR_SPECIAL_TEXT_6,
	STR_SPECIAL_TEXT_7,
	STR_SPECIAL_TEXT_8,
	STR_SPECIAL_TEXT_9};
const char *NumsToText::and_txt = STR_TEXT_AND;
