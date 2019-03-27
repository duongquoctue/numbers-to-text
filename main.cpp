#include <iostream>
#include <string>
#include "nums_to_text.h"

using namespace std;

// Initialize the object.
NumsToText nums_to_text;

int main()
{
	// Require the user input and store it for later use.
	long int user_input = nums_to_text.input();
	// Store the result for displaying on the screen.
	const char *result = nums_to_text.read_number(user_input);
	// Display the result
	cout << "The text representation is: " << result << endl;

	getchar();
	getchar();
	return 0;
}
