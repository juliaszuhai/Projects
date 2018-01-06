#include "HTMLOrderFile.h"
#include<fstream>
#include<Windows.h>
#include<exception>
#include"Order.h"
#include"Domain.h"

using namespace std;
void HTMLOrderFile::writeToFile()
{
	ofstream f(this->filename);
	if (!f.is_open())
		throw std::invalid_argument("Could not open file.");
	f << "<!DOCTYPE html><head><title>Order</title></head><body><table border = 1><tr><td>Size</td><td>Colour</td><td>Price</td><td>Quantity</td><td>Photo</td></tr>";
	for (auto s : this->trenchcoats)
	{
		f << "<tr>";
		std::string afis;
		afis = "<td>" + s.getSize() + "</td>" + "<td>" + s.getColour() + "</td>" + "<td>" + std::to_string(s.getPrice()) + "</td>" + "<td>" + std::to_string(s.getQuantity()) + "</td>" + "<td>" + "<a href=" + s.getSource() + "</a>" + "</td>";
		f << afis.c_str();
		f << "</tr>";
	}
	f << "</table></body></html>";
	f.close();
}

void HTMLOrderFile::displayOrder() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
