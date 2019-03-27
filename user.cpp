#include <iostream>
#include "user.h"

using namespace std;

// Make the user type in the number.
long int User::input()
{
	long int user_input;
	while (true)
	{
		cout << "Enter number you want to read out loud: ";
		cin >> user_input;
		// See User::check_for_negative() below.
		long int user_input_pos = check_for_negative(user_input);
		// Handle bad value (eg. not long int type).
		if (!cin)
		{
			cout << "Bad value! Type again.."
				 << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			return user_input_pos;
	}
}

// If the number is negative, make it positive for easy processing.
long int User::check_for_negative(long int user_input)
{
	long int user_input_pos = user_input;

	if (user_input < 0L)
	{
		is_negative = true;
		user_input_pos = -user_input;
	}
	return user_input_pos;
}
