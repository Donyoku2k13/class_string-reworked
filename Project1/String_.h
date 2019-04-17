#pragma once
#include <iostream>
using namespace std;

class string_
{
public:
	string_();
	string_(const char*s);
	void setString(const char *s);

	const char* getString();
	int getLength();
	void append(const char*s);
	void print()const;
	void clear();
	bool equal(const char *s);
	~string_();
	string_(const string_ &obj);

private:
	char *str;
	int length;
};
bool operator==(string_ &a, string_&b);
bool operator!=(string_ &a, string_&b);
ostream & operator<<(ostream & os, const string_ & obj);
istream & operator>>(istream & is, string_ & obj);