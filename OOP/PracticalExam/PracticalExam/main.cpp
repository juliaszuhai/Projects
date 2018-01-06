#include "practicalexam.h"
#include <QtWidgets/QApplication>
#include"Controller.h"
#include"Repository.h"
#include"Idea.h"
#include"Writer.h"
#include"Tests.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tests::testAll();
	Repository repo{ "ideas.txt", "writers.txt" };
	Controller ctrl{ repo };
	std::vector<PracticalExam*> windows;
	std::vector<QTextEdit*> texts;
	for (int i = 0; i < repo.getWriters().size(); i++)
	{
		PracticalExam * w = new PracticalExam{ ctrl,repo.getWriters()[i].getName(),windows,texts };
		windows.push_back(w);
		windows[windows.size() - 1]->setWindowTitle(QString::fromStdString(repo.getWriters()[i].getName()));

	}
	for (auto w : windows)
	{
		w->show();
	}

	return a.exec();
}
