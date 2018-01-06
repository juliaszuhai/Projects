#pragma once
#include"FileOrder.h"
#include<string>
class CSVOrder :public FileOrder
{
public:
	void writeToFile()override;
	void displayOrder() const override;
};

