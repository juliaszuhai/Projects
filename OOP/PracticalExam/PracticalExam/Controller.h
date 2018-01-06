#pragma once
#include"Repository.h"
#include<iostream>
class Controller
{
private:
	Repository& repo;
public:
	Controller(Repository& r) :repo{ r } {}
	~Controller();
	void changeStatusCtrl(int i);
	
	Repository getRepo();
	void add(std::string descr, int a,std::string name);
	/*Description: the function adds a new idea
	Input:idea i
	Output: if the idea is not a duplicate and doesn't have certain fildes empty,then the idea is added
	*/
	void acceptIdeas(std::string name, int i);
	/*Description: the function vreifies if the writer is a senior and if the status is proposed and it changes if so
	Input: integer i, string name
	Output: the status has changed to accepted or not
	*/
	void writeToFileCtrl();
	void saveToFileCtrl(std::string s);
};

