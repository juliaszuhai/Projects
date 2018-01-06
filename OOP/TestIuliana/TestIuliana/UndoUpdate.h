#pragma once
#include"Repository.h"
#include"Domain.h"
#include"UndoAction.h"
class UndoUpdate:public UndoAction
{
private:
	Repository& repo;
	TrenchCoat oldCoat;
public:
	UndoUpdate(Repository& _repo, const TrenchCoat& o) : repo{ _repo }, oldCoat{o} {}
	~UndoUpdate();
	void executeUndo() override
	{
		this->repo.updateTrenchCoat(oldCoat);
	}
};

