#include "testiuliana.h"
#include <QtWidgets/QApplication>
#include"Controller.h"
#include"Repository.h"
#include"GUI.h"
#include "SVOrder.h"
#include"HTMLOrderFile.h"
#include"initialization.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "Text.txt" };
	FileOrder* o{};
	Initialization i{};
	i.exec();
	int c = i.getChoice();
	if (c == 1)
	{
		o = new CSVOrder{};
	}
	else
	{
		o = new HTMLOrderFile{};
	}
	Controller ctrl{ repo,o };
	//GUI g{ ctrl };
	TestIuliana g{ctrl};
	g.show();
	return a.exec();
}
