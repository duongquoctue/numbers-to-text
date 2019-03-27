#include <iostream>
#include "user.h"


using namespace std;

long int User::input() {
	long int user_input;
	while (true) {
		cout << "Enter number you want to read out loud: ";
		cin >> user_input;
		long int user_input_pos = check_for_negative(user_input);
		if (!cin) {
			cout << "Bad value! Type again.." << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else return user_input_pos;
	}
}


long int User::check_for_negative(long int user_input) {
	long int user_input_pos = user_input;

	if (user_input < 0L) {
		is_negative = true;
		user_input_pos = -user_input;
	}
	return user_input_pos;
}
