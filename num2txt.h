#ifndef NUM2TXT_H
#define NUM2TXT_H

#include "user.h"


class User;

class Num2Txt : public User {
public:
	const char * read_group(int gr);
	const char * group_count(long int user_input);
};
#endif
