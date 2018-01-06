#include"Controller.h"
#include <algorithm>
#include"UndoAction.h"
#include"UndoAdd.h"
#include"UndoRemove.h"
#include"UndoUpdate.h"
Controller::~Controller()
{

}
void Controller::addTrenchCoatCtrl(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo)
{

	TrenchCoat t = TrenchCoat(size, colour, price, quantity, photo);
	this->repo.addTrenchCoat(t);
	this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, t));
}
int Controller::addTrenchCoatToOrder(const TrenchCoat& trenchcoat)
{
return this->order->add(trenchcoat);
}
int Controller::addCurrentCoat()
{
TrenchCoat t = this->order->getCurrentTrenchCoat();
t.setQuantity(1);
return this->order->add(t);
}
void Controller::setFilter(vector<TrenchCoat>& t)
{
this->order->setFilterOrder(t);
this->order->current = 0;
}
void Controller::updateTrenchCoatCtrl(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo)
{
	for (int i = 0; i < this->repo.getTrenchCoats().size(); i++)
	{
		if (this->repo.getTrenchCoatRepo(i).getColour() == colour && this->repo.getTrenchCoatRepo(i).getSize() == size)
		{
			this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repo, this->repo.getTrenchCoatRepo(i)));
		}
	}
	TrenchCoat t = TrenchCoat(size, colour, price, quantity, photo);
	try {
		//TrenchCoat t = TrenchCoat(size, colour, price, quantity, photo);
		this->repo.updateTrenchCoat(t);
	}
	catch (const std::invalid_argument& err)
	{
		throw err;
	}
	
}
void Controller::removeTrenchCoatCtrl(const std::string& size, const std::string& colour)
{
	try {
		for (int i = 0; i < this->repo.getTrenchCoats().size(); i++)
		{
			if (this->repo.getTrenchCoatRepo(i).getColour() == colour && this->repo.getTrenchCoatRepo(i).getSize() == size)
			{
				this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, this->repo.getTrenchCoatRepo(i)));
			}
		}
		this->repo.removeTrenchCoat(size, colour);
	}
	catch (const std::invalid_argument& err)
	{
		throw err;
	}
	
	
}

void Controller::showOrder()
{
this->order->order();
}

vector <TrenchCoat> Controller::filtersize(const std::string& size)
{
vector<TrenchCoat> v;

for (int i = 0; i < this->repo.getRepoLength(); i++)
{
	if (this->repo.getTrenchCoatRepo(i).getSize() == size)
	{
		v.push_back(this->repo.getTrenchCoatRepo(i));
	}
}

return v;
}


void Controller::buy()
{
for (int cont = 0; cont < this->order->getShoppingBasket().size(); cont++)
{
for (int i = 0; i < this->repo.getRepoLength(); i++)
{
if (this->repo.getTrenchCoatRepo(i) == this->order->getOnPos(cont))
{
TrenchCoat trench = TrenchCoat(this->repo.getTrenchCoatRepo(i).getSize(), this->repo.getTrenchCoatRepo(i).getColour(), this->repo.getTrenchCoatRepo(i).getPrice(), this->repo.getTrenchCoatRepo(i).getQuantity() - 1, this->repo.getTrenchCoatRepo(i).getSource());
this->repo.updateTrenchCoat(trench);
}
}
}
this->order->trenchcoats.clear();
}

void Controller::undo()
{
	if (undoActions.empty())
	{
		throw std::invalid_argument{ "There are no more actions to undo." };
	}


	undoActions.back()->executeUndo();
	//std::unique_ptr<UndoAction> last = std::move(undoActions.back());
	//last->executeUndo();

	undoActions.pop_back();
}


TrenchCoat Controller::findbyCtrl(const std::string size, const std::string colour)
{
	return this->repo.findby(size, colour);
}

void Controller::nextItemOrder()
{
if (this->order == nullptr)
return;
this->order->next();
}

void Controller::saveOrder(const std::string& filename)
{
if (this->order == nullptr)
return;
this->order->setFilename(filename);
this->order->writeToFile();
}
void Controller::openOrder() const
{
if (this->order == nullptr)
return;
this->order->displayOrder();
}