#include "Repository.h"
#include<vector>
#include<string>
#include <algorithm> 
Repository::Repository(std::string file)
{

	this->filename = file;
	this->readFromFile();

}
Repository::~Repository()
{

}
void Repository::addTrenchCoat(const TrenchCoat& s)
{
	int poz = -1;
	for (int i = 0; i < trenchcoats.size(); i++)
	{
		if (this->trenchcoats[i] == s)
		{
			poz = i;
			break;
		}
	}

	if (poz != -1)
	{
		this->trenchcoats[poz] = s;
		this->storeToFile();
	}
	else
	{
		this->trenchcoats.push_back(s);
		this->storeToFile();
	}
}
void Repository::updateTrenchCoat(const TrenchCoat& s)
{
	int poz = -1;
	for (int i = 0; i < trenchcoats.size(); i++)
	{
		if (this->trenchcoats[i] == s)
		{
			poz = i;
			break;
		}
	}
	if (poz != -1)
	{
		this->trenchcoats[poz] = s;
		this->storeToFile();
	}
	else
	{
		throw std::invalid_argument("Could not find trench coat.");
	}
}

int Repository::removeTrenchCoat(std::string size, std::string colour)
{
	int poz = -1;

	TrenchCoat t = TrenchCoat(size, colour, 0, 0, "");
	for (int i = 0; i < trenchcoats.size(); i++)
	{
		if (this->trenchcoats[i] == t)
		{
			t = this->trenchcoats[i];
			poz = i;
			break;
		}
	}

	if (t.getQuantity() > 1)
	{
		throw std::invalid_argument("Cannot remove this. Quantity is not 0.");
	}
	if (poz >= 0)
	{
		this->trenchcoats.erase(this->trenchcoats.begin() + poz);
		this->storeToFile();
		return poz;
	}
	if (poz<0)
	{
		throw std::invalid_argument("Could not find trench coat");
	}
}
int Repository::getRepoLength()
{
	return this->trenchcoats.size();
}
TrenchCoat Repository::getTrenchCoatRepo(int poz)
{
	return this->trenchcoats[poz];
}
TrenchCoat Repository::findby(std::string size, std::string colour)
{

	TrenchCoat t = TrenchCoat(size, colour, 0, 0, "");
	for (int i = 0; i < trenchcoats.size(); i++)
	{
		if (this->trenchcoats[i] == t)
		{
			t = this->trenchcoats[i];
			return t;
		}
	}
}

void Repository::readFromFile()
{
	string size;
	string colour;
	double price;
	int quantity;
	string photo;
	ifstream infile;
	infile.open(this->filename);
	while (!infile.eof()) // To get you all the lines.
	{
		getline(infile, size); // Saves the line in STRING.
		getline(infile, colour);
		getline(infile, photo);
		infile >> price >> ws;
		infile >> quantity >> ws;
		TrenchCoat t{ size,colour,price,quantity,photo };
		this->addTrenchCoat(t);
	}
	infile.close();
}

void Repository::storeToFile()
{
	ofstream myfile;
	myfile.open(this->filename);
	for (int i = 0; i < trenchcoats.size(); i++)
	{
		myfile << this->trenchcoats[i].getSize() << endl;
		myfile << this->trenchcoats[i].getColour() << endl;
		myfile << this->trenchcoats[i].getSource() << endl;
		myfile << this->trenchcoats[i].getPrice() << endl;
		myfile << this->trenchcoats[i].getQuantity() << endl;
	}

	myfile.close();
}
