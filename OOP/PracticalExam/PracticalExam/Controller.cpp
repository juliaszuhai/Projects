#include "Controller.h"




Controller::~Controller()
{
}

void Controller::changeStatusCtrl(int i)
{
	this->repo.ChangeStatus(i);
}

Repository Controller::getRepo()
{
	return this->repo;
}

void Controller::add(std::string descr, int a,std::string name)
{
	std::string status = "porposed";
	Idea i{ descr,status,name,a };
	try {
		this->repo.addIdea(i);
	}
	catch (std::invalid_argument &err)
	{
		throw err;
	}
}

void Controller::acceptIdeas(std::string name, int i)
{
	bool ok = false;
	for (auto j : this->repo.getWriters())
	{
		if (j.getExpertise() == "Senior")
			if (this->repo.getIdeas()[i].getStatus() == "proposed")
			{
				this->changeStatusCtrl(i);
				ok = true;
			}
	}
	if (ok == false)
		throw std::invalid_argument("Cannot accept idea");
}

void Controller::writeToFileCtrl()
{
	this->repo.writeToFile();
}

void Controller::saveToFileCtrl(std::string s)
{
	this->repo.saveToFile(s);
}
