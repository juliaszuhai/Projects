#pragma once
#include <iostream>
class TrenchCoat
{
private:
	std::string size;
	std::string colour;
	double price;
	int quantity;
	std::string photo;
	static int nrinstances;
public:
	//int TrenchCoat::i = 0;
	TrenchCoat();
	TrenchCoat(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo);
	TrenchCoat(const TrenchCoat& t);
	~TrenchCoat();
	std::string getSize() const { return size; }
	std::string getColour() const { return colour; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }
	void decQuantity() { this->quantity = this->quantity - 1; }
	void incQuantity() { this->quantity = this->quantity + 1; }
	void setQuantity(int cant) { this->quantity = cant; }
	bool TrenchCoat::operator==(const TrenchCoat& v);
	TrenchCoat TrenchCoat::operator=(const TrenchCoat& v);
	std::string getSource() const { return photo; }
	static int getInstances();

	void order();
	friend std::istream& operator >> (std::istream& is, TrenchCoat& s);
	friend std::ostream& operator<<(std::ostream& os, const TrenchCoat& s);

};
