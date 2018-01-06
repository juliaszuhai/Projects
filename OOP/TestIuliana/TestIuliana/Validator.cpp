#include "Validator.h"



Validator::Validator()
{
}


Validator::~Validator()
{
}

bool Validator::validString(std::string s)
{
	return (s == "");
}

bool Validator::validInteger(int n)
{
	return n > 0 && n<100000000;
}
bool Validator::validDouble(double n)
{
	return n > 0 && n<100000000;
}
