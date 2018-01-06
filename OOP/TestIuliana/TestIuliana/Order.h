#pragma once
#include"Domain.h"
#include<vector>
#include"Repository.h"
class Order
{
public:
	vector<TrenchCoat> trenchcoats;
	vector<TrenchCoat> littlerepo;
	int current;
	int total;
public:
	Order();
	Order(const Repository& r);
	vector<TrenchCoat> getShoppingBasket() const { return this->trenchcoats; }
	int add(const TrenchCoat& trenchcoat);
	TrenchCoat Order::getCurrentTrenchCoat();
	TrenchCoat getOnPos(int pos);
	void setFilterOrder(vector<TrenchCoat>& t);
	void order();
	void next();
	bool isEmpty();
	virtual ~Order() {}
};