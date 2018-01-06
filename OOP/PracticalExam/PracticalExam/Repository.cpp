#include "Repository.h"

#include<iostream>
#include<fstream>
#include"Utils.h"
#include<algorithm>
using namespace std;

Repository::Repository(std::string filename_i, std::string filename_w)
{
	this->filename_i = filename_i;
	this->filename_w = filename_w;
	this->readFromFile_i();
	this->readFromFile_w();
}

Repository::~Repository()
{
}

void Repository::ChangeStatus(int i)
{
	this->ideas[i].modifyStatus();
}

std::vector<Idea> Repository::getIdeas()
{std::sort(this->ideas.begin(), this->ideas.end(), [](Idea& c1, Idea& c2) {return c1.getAct() < c2.getAct(); });
return this->ideas;
}

void Repository::readFromFile_i()
{
	ifstream f;
	f.open(this->filename_i);
	while (!f.eof())
	{
		string line;
		getline(f, line);
		vector<string> tokens = tokenize(line, ';');
		if (tokens.size() == 4)
		{
			int r;
			r = stoi(tokens[3]);
			Idea i{ tokens[0],tokens[1],tokens[2],r };
			this->ideas.push_back(i);
		}
	}
	f.close();}

void Repository::readFromFile_w()
{
	ifstream f;
	f.open(this->filename_w);
	while (!f.eof())
	{
		string line;
		getline(f, line);
		vector<string> tokens = tokenize(line, ';');
		if (tokens.size() == 2)
		{
		Writer w{ tokens[0],tokens[1] };
			this->writers.push_back(w);
		}
	}
	f.close();
}

void Repository::writeToFile()
{
	ofstream myfile;
	myfile.open("Act1.txt");
	for (auto q : this->ideas)
	{
		if (q.getAct() == 1)
		{
			myfile << q.getDescr() << ";" << q.getStatus() << ";" << q.getNameCreator() << ";" << q.getAct();
		}


	}
	myfile.close();

	ofstream myfile2;
	myfile2.open("Act2.txt");
	for (auto q : this->ideas)
	{
		if (q.getAct() == 2)
		{
			myfile2 << q.getDescr() << ";" << q.getStatus() << ";" << q.getNameCreator() << ";" << q.getAct();
		}


	}
	myfile2.close();

	ofstream myfile3;
	myfile3.open("Act3.txt");
	for (auto q : this->ideas)
	{
		if (q.getAct() == 3)
		{
			myfile3 << q.getDescr() << ";" << q.getStatus() << ";" << q.getNameCreator() << ";" << q.getAct();
		}


	}
	myfile3.close();
}

void Repository::saveToFile(std::string s)
{

	ofstream myfile3;
	myfile3.open("ceva.txt");
	for (auto q : this->ideas)
	{
		
		{
			myfile3 << s;
		}


	}
	myfile3.close();
}



void Repository::addIdea(Idea i)
{
	if (i.getDescr() == "")
		throw std::invalid_argument("Description cannot be empty");
	if (i.getAct() != 1 && i.getAct() != 2 && i.getAct() != 3)
		throw std::invalid_argument("Act must be 1 or 2 or 3");
	for (auto a : this->ideas)
	{
		if (i.getDescr() == a.getDescr() && i.getAct() == a.getAct())
		{
			throw std::invalid_argument("Duplicate idea!");
		}
	}
	this->ideas.push_back(i);
}
