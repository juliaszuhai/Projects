#pragma once
#include<string>
class Validator
{
public:
	Validator();
	~Validator();
	bool validString(std::string s);
	bool validInteger(int n);
	bool validDouble(double n);
};

