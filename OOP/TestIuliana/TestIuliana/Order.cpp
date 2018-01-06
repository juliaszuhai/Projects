#include "Order.h"

Order::Order()
{
	this->current = 0;
	this->total = 0;
}
Order::Order(const Repository& r)
{
	this->current = 0;
	this->littlerepo = r.getTrenchCoats();

}
void Order::setFilterOrder(vector<TrenchCoat>& t)
{
	this->littlerepo = t;
}
int Order::add(const TrenchCoat& trenchcoat)
{

	this->trenchcoats.push_back(trenchcoat);
	this->total = this->total + trenchcoat.getPrice();
	return this->total;
}
TrenchCoat Order::getCurrentTrenchCoat()
{
	if (this->current == this->littlerepo.size())
		this->current = 0;
	vector<TrenchCoat> elems = this->littlerepo;
	if (!this->isEmpty())
		return elems[this->current];
	TrenchCoat t{};
	return t;
}
void Order::order()
{
	if (this->trenchcoats.size() == 0)
		return;
	this->current = 0;
	TrenchCoat currentCoat = this->getCurrentTrenchCoat();
	currentCoat.order();
}
void Order::next()
{
	this->current++;
	TrenchCoat currentCoat = this->getCurrentTrenchCoat();
	//currentCoat.order();
}
TrenchCoat Order::getOnPos(int pos)
{
	return this->trenchcoats[pos];
}
bool Order::isEmpty()
{
	return this->littlerepo.size() == 0;
}
