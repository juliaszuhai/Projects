#pragma once
#include"UndoAction.h"
#include"Repository.h"
#include"Domain.h"
class UndoRemove:public UndoAction
{
private:
	Repository repo;
	TrenchCoat coatRemoved;
public:
	UndoRemove(Repository& _repo, const TrenchCoat& s) : repo{ _repo }, coatRemoved{ s } {}
	~UndoRemove();
	void executeUndo() override
	{
		this->repo.addTrenchCoat(coatRemoved);
	}
};

