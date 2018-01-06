#pragma once
#include"Idea.h"
#include"Writer.h"
#include<iostream>
#include<vector>
class Repository
{
private:
	std::vector<Idea> ideas;
	std::vector<Writer> writers;
	std::string filename_i;
	std::string filename_w;
public:
	Repository(std::string filename_i,std::string filename_w);
	~Repository();
	void ChangeStatus(int i);
	/*Description: the function changes the status of an idea which has been proposed
	Input: integer i
	Output: the status has changed to accepted
	*/
	std::vector<Idea> getIdeas();
	std::vector<Writer> getWriters() { return this->writers; }
	void readFromFile_i();
	void readFromFile_w();
	void writeToFile();
	void saveToFile(std::string s);
	void addIdea(Idea i);
	/*Description: the function adds a new idea
	Input:idea i
	Output: if the idea is not a duplicate and doesn't have certain fildes empty,then the idea is added
	*/

};

