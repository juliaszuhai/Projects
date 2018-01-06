#include "Idea.h"




Idea::Idea(std::string descr, std::string status, std::string name_creator, int act)
{
	this->descr = descr;
	this->status = status;
	this->name_creator = name_creator;
	this->act = act;
}

Idea::~Idea()
{
}

void Idea::modifyStatus()
{
	this->status = "accepted";
}
