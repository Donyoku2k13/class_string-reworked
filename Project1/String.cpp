#include "String_.h"

string_::string_()
{
	str = nullptr;
	length = 0;
}

string_::string_(const char * s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

void string_::setString(const char * s)
{
	if (str != nullptr)
	{
		delete[] str;
	}
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

const char * string_::getString()
{
	return str;
}

int string_::getLength()
{
	return length;
}

void string_::append(const char * s)
{
	if (str == nullptr)
	{
		setString(s);
		return;
	}
	length += strlen(s);
	char*tmp = new char[length + 1];
	strcpy_s(tmp, length + 1, str);
	strcat_s(tmp, length + 1, s);
	delete[]str;
	str = tmp;

}
bool string_::equal(const char *s) {
	if (strcmp(str, s) == 0)
		return true;
	else return false;
}
void string_::print()const
{
	cout << str << endl;
}

void string_::clear()
{
	if (str != nullptr)
	{
		delete[]str;
	}
	str = nullptr;
	length = 0;
}

string_::~string_()
{
	clear();
}

string_::string_(const string_ &obj) // copying costructor 
{
	length = obj.length;
	if (length == 0) {
		str = nullptr;
		return;
	}
	//çíà÷èò åñòü îòêóäà êîïèðîâàòü
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);

}
bool operator==(string_ &a, string_&b) {
	if (a.getLength()!=b.getLength())
	{
		return false;
	}
	for (size_t i = 0; i < a.getLength(); i++)
	{
		if (strcmp(a.getString(), b.getString())) {
			return false;
		}
	}
	return true;
}
bool operator!=(string_ &a, string_&b) {
	if (a.getLength() != b.getLength())
	{
		return true;
	}
	for (size_t i = 0; i < a.getLength(); i++)
	{
		if (strcmp(a.getString(), b.getString())) {
			return true;
		}
	}
	return false;
}
ostream & operator<<(ostream & os, const string_ & obj)
{
	obj.print();
	return os;
}
istream & operator>>(istream & is, string_ & obj)
{
	char f[100];
	cin.getline(f, 100);
	obj.setString(f);

	return is;
}