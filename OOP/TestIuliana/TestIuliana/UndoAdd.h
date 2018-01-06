#pragma once
#include"UndoAction.h "
#include"Domain.h"
#include"Repository.h"
class UndoAdd:public UndoAction
{
private:
	TrenchCoat coatAdded;
	Repository& repo;
public:
	~UndoAdd();
	UndoAdd(Repository& _repo, const TrenchCoat& s) : repo{ _repo }, coatAdded{ s } {}
	void executeUndo() override
	{
		this->repo.removeTrenchCoat(coatAdded.getSize(), coatAdded.getColour());
	}
};

