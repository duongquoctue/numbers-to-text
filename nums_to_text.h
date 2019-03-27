#ifndef NUMS_TO_TEXT_H
#define NUMS_TO_TEXT_H

#include "user.h"

class User;

// Class NumsToText: convert the number to text representation.
class NumsToText : public User
{
  public:
	const char *read_group(int gr);
	const char *read_number(long int user_input);
};

#endif
