#pragma once
#include<iostream>
#include<string>
class Writer
{
private:
	std::string name;
	std::string expertise;
public:
	Writer(std::string name, std::string expertise);
	~Writer();
	std::string getName() { return this->name; }
	std::string getExpertise() { return this->expertise; }
};

