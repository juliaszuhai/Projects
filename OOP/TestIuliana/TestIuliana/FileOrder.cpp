#include "FileOrder.h"
#include"Order.h"
#include"Repository.h"

FileOrder::FileOrder() :Order(), filename{ "" }
{
}

void FileOrder::setFilename(const std::string & filename)
{
	this->filename = filename;
}
