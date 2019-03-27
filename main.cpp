#include <iostream>
#include <string>
#include "num2txt.h"


using namespace std;

Num2Txt num2txt;

int main() {

	long int user_input = num2txt.input();
	const char * result = num2txt.group_count(user_input);

	cout << "The text representation is: " << result << endl;

	getchar();
	getchar();
	return 0;
}
