#pragma once
#include"Repository.h"
#include"Order.h"
#include<vector>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<exception>
#include"FileOrder.h"
#include"UndoAction.h"
#include<memory>
class Controller
{
public:
	Repository repo;
	FileOrder* order;
	std::vector<std::unique_ptr<UndoAction>> undoActions;

public:
	Controller(const Repository& r, FileOrder* o) {
		this->repo = r;
		this->order = o;
		this->setFilter(this->getRepo().getTrenchCoats());
	}
	Repository getRepo() const { return repo; }
	FileOrder* getOrder() const { return order; }
	~Controller();
	void addTrenchCoatCtrl(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo);
	int addTrenchCoatToOrder(const TrenchCoat& trenchcoat);
	int addCurrentCoat();
	void updateTrenchCoatCtrl(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo);
	void removeTrenchCoatCtrl(const std::string& size, const std::string& colour);
	void showOrder();
	void buy();
	void undo();
	void setFilter(vector<TrenchCoat>& t);
	void Controller::addTrenchCoatOrder(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo);
	vector<TrenchCoat> filtersize(const std::string& size);
	TrenchCoat Controller::findbyCtrl(const std::string size, const std::string colour);
	void nextItemOrder();
	bool Controller::pred(const TrenchCoat& t, const std::string size) { return t.getSize() == size; }
	void saveOrder(const std::string& filename);
	void openOrder() const;
};

