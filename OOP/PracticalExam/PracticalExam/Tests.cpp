#include "Tests.h"

#include<assert.h>

void Tests::testRepo()
{
	Repository repo{ "ideas.txt", "writers.txt" };
	Idea i{ "tgbtb","proposed","Diana",2 };
	repo.addIdea(i);
	assert(repo.getIdeas().size() == 3);
	repo.ChangeStatus(2);
	assert(repo.getIdeas()[2].getStatus() == "accepted");
}

void Tests::testAll()
{
	testRepo();
	testController();
}

void Tests::testController()
{
	Repository repo{ "ideas.txt", "writers.txt" };
	Controller ctrl{ repo };
	Idea i{ "easy peasy","proposed","Diana",2 };
	ctrl.add("easy peasy", 1,"Iulia");
	assert(ctrl.getRepo().getIdeas().size() == 3);
	ctrl.acceptIdeas("Diana", 2);
	assert(ctrl.getRepo().getIdeas()[2].getStatus() == "accepted");
}
