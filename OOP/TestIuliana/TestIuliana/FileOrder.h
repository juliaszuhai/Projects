#pragma once
#include"Order.h"
class FileOrder : public Order
{
public:
	std::string filename;
public:
	FileOrder();
	virtual ~FileOrder() {}
	void setFilename(const std::string& filename);
	virtual void writeToFile() = 0;
	virtual void displayOrder() const = 0;

};