#include <iostream>
#include <string>

#include "numbers.h"
#include "text.h"

#define BUFSIZE 256

#define SIZE_OF_SPECIAL_NUMBERS_ARRAY 9 // needs to be refactor..

using namespace std;

Numbers numbers_obj;
Text text_obj;

const char *readgroup(int x);
//long int check_user_input(long int input);

int main() {

	char buf[BUFSIZE] = {};
	char text[BUFSIZE] = {};

	long int user_input, user_input_pos;
	while (true) {
		cout << "Enter number you want to read out loud: ";
		cin >> user_input;

		if (!cin) {
		  cout << "Bad value! Type again.." << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	

	user_input_pos = user_input;

	bool is_negative = false; // assume that the number is larger than 0
	
	if (user_input < 0L) {
		is_negative = true;
		user_input_pos = -user_input;
	}

	int gr;
	int gr_count = 0;
	// read numbers by group of three, starting from the right
	strcpy_s(text, "");
	while (user_input_pos > 0L) {
		gr = user_input_pos % 1000;

		// this group has some numbers other than 000
		if (gr > 0) {
			// read the whole group
			strcpy_s(buf, readgroup(gr));

			// add name of group
			if (gr == 1)
				strcat_s(buf, text_obj.groups[gr_count]);
			else
				strcat_s(buf, text_obj.groups2[gr_count]); // with 's'

			  // add the text that we have read earlier
			strcat_s(buf, text);

			// put everything in result      
			strcpy_s(text, buf);
		}

		user_input_pos /= 1000;
		gr_count++;
	}

	// add the word "minus" in front if number is less than zero
	if (is_negative) {
		strcpy_s(buf, "minus ");
		strcat_s(buf, text);
		strcpy_s(text, buf);
	}

	cout << "Your number is: " << user_input << endl;
	cout << "The text is: " << text << endl;

	getchar();
	getchar();

	return 0;
}



// read group of 3 digits
const char *readgroup(int gr)
{
	static char buf[BUFSIZE];

	strcpy_s(buf, "");

	// read first digit
	strcat_s(buf, text_obj.hundreds[gr / 100]);

	// special case for 2-digit numbers (11 = eleven, 12 = twelve, etc.)
	if (gr >= 10) {
		for (int i = 0; i < SIZE_OF_SPECIAL_NUMBERS_ARRAY; i++) {
			if (gr % 100 == numbers_obj.special[i]) {
				strcat_s(buf, text_obj.specialTxt[i]);
				return buf;
			}
		}
	}

	// read second digit
	strcat_s(buf, text_obj.tens[gr % 100 / 10]);

	// zero is the second digit (100-109, 200-209, ...), add the word "and"
	if (gr >= 100 && gr % 100 <= 9 && gr % 100 >= 1)
		strcat_s(buf, text_obj.andTxt);

	// read last digit
	strcat_s(buf, text_obj.units[gr % 10]);

	return buf;
}
