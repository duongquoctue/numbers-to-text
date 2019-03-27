#ifndef NUMS_TO_TEXT_H
#define NUMS_TO_TEXT_H_

#include "resource.h"
#include "user.h"

class User;

// Class NumsToText: convert the number to text representation.
class NumsToText : public User
{
  public:
	const char *read_group(int gr);
	const char *read_number(long int user_input);

  protected:
	// Special numbers: 11 -> 19
	static const int special[10];

	static const char *units[10];
	static const char *tens[10];
	static const char *hundreds[10];
	static const char *groups[10];
	static const char *groups_s[10];
	static const char *special_txt[10];
	static const char *and_txt;
};

#endif
