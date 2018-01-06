#include "SVOrder.h"
#include<fstream>
#include<Windows.h>
#include<exception>
#include"Order.h"

using namespace std;

void CSVOrder::writeToFile()
{
	ofstream f(this->filename);
	if (!f.is_open())
		throw std::invalid_argument("Could not open file.");
	for (auto s : this->trenchcoats)
		f << s;
	f.close();
}

void CSVOrder::displayOrder() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Users\\User\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Accessories\\Notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);

}
