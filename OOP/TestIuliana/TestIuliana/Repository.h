#pragma once
#include"Domain.h"
#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<exception>
using namespace std;
class Repository
{
private:
	vector<TrenchCoat> trenchcoats;
	std::string filename;
public:
	Repository() { }
	Repository(std::string file);
	~Repository();
	void addTrenchCoat(const TrenchCoat& s);
	void updateTrenchCoat(const TrenchCoat& s);
	int removeTrenchCoat(const std::string size, const std::string colour);
	vector<TrenchCoat> getTrenchCoats() const { return trenchcoats; }
	int getRepoLength();
	TrenchCoat getTrenchCoatRepo(int poz);
	TrenchCoat findby(const std::string size, const std::string colour);
	void readFromFile();
	void storeToFile();
};
