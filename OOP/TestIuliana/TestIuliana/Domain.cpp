#include"Domain.h"
#include<Windows.h>
#include<ShellApi.h>
#include<vector>
#include<iostream>
#include"Utils.h"
#include<string>
#include<sstream>

using namespace std;
TrenchCoat::TrenchCoat() : size(""), colour(""), price{ 0 }, quantity{ 0 }, photo("") {}
int TrenchCoat::nrinstances = 0;
TrenchCoat::TrenchCoat(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo)
{
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
	nrinstances++;

}
TrenchCoat::TrenchCoat(const TrenchCoat& t)
{
	this->size = t.getSize();
	this->colour = t.getColour();
	this->price = t.getPrice();
	this->quantity = t.getQuantity();
	this->photo = t.getSource();
}
bool TrenchCoat::operator==(const TrenchCoat& v)
{
	return getSize() == v.getSize() && getColour() == v.getColour();
}
TrenchCoat TrenchCoat::operator=(const TrenchCoat& v)
{
	this->size = v.getSize();
	this->colour = v.getColour();
	this->price = v.getPrice();
	this->quantity = v.getQuantity();
	this->photo = v.getSource();
	return *this;

}
TrenchCoat::~TrenchCoat()
{
	//nrinstances--;
}
int TrenchCoat::getInstances()
{
	return nrinstances;
}

void TrenchCoat::order()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);

}

istream & operator >> (istream & is, TrenchCoat & s)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	s.size = tokens[0];
	s.colour = tokens[1];
	s.price = stod(tokens[2]);
	s.quantity = stod(tokens[3]);
	s.photo = tokens[4];
	return is;
}
ostream & operator<<(ostream & os, const TrenchCoat& s)
{
	os << s.size << "," << s.colour << "," << s.price << "," << s.quantity << "," << s.photo << "\n";
	return os;
}
