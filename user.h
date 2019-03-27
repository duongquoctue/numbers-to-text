#ifndef USER_H
#define USER_H


class User {
public:
	long int input();
	long int check_for_negative(long int input);
protected:
	bool is_negative = false; // assume that the number is larger than 0
};

#endif
