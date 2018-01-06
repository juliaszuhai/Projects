#pragma once
#include"FileOrder.h"
class HTMLOrderFile :public FileOrder
{
public:
	void writeToFile()override;
	void displayOrder() const override;
};

