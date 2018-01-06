#pragma once
#include<iostream>
#include"Writer.h"
class Idea
{private:
	std::string descr;
	std::string status;
	std::string name_creator;
	int act;
public:
	Idea(std::string descr,std::string status,std::string name_creator,int act);
	~Idea();

	std::string getDescr() { return this->descr; }
	std::string getStatus() { return this->status; }
	std::string getNameCreator() { return this->name_creator; }
	int getAct() { return this->act; }
	void modifyStatus();
};

