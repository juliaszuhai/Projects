#include "practicalexam.h"
#include<qmessagebox.h>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>
#include"Utils.h"
PracticalExam::PracticalExam(Controller& ctrl, std::string name, std::vector<PracticalExam*> &windows, std::vector<QTextEdit*> &texts, QWidget *parent)
	:ctrl{ ctrl }, name{ name }, windows{ windows }, texts{texts}, QMainWindow(parent)
{
	ui.setupUi(this);
	this->populateList();
	connect(ui.addButton, &QPushButton::clicked, this, &PracticalExam::add);
	connect(ui.acceptButton, &QPushButton::clicked, this, &PracticalExam::accept);
	connect(ui.developButton, &QPushButton::clicked, this, &PracticalExam::developHandler);
	connect(ui.saveToFileButton, &QPushButton::clicked, this, &PracticalExam::saveHandler);
	connect(ui.saveButton, &QPushButton::clicked, this, &PracticalExam::saveModifHandler);
	
	
}

PracticalExam::~PracticalExam()
{

}

void PracticalExam::populateList()
{
	ui.ideasList->clear();
	std::vector<Idea> v = this->ctrl.getRepo().getIdeas();
	for (auto i : v)
	{
		if (i.getStatus() == "accepted" && i.getNameCreator()==this->name)
		{
			QString s;
			s = QString::fromStdString(i.getDescr()) + ";" + QString::fromStdString(i.getStatus()) + ";" + QString::fromStdString(i.getNameCreator()) + ";" + QString::number(i.getAct());
			QColor colour = QString::fromStdString("green");
			QListWidgetItem* item = new QListWidgetItem{ s };
			item->setForeground(colour);
			ui.ideasList->addItem(item);

		}
		else {
			QString s;
			s = QString::fromStdString(i.getDescr()) + ";" + QString::fromStdString(i.getStatus()) + ";" + QString::fromStdString(i.getNameCreator()) + ";" + QString::number(i.getAct());
			ui.ideasList->addItem(s);
		}
	
	}

}

void PracticalExam::add()
{
	QString descr = ui.descriprtionEdit->text();
	QString act = ui.actEdit->text();
	try {
		this->ctrl.add(descr.toStdString(), act.toInt(), this->name);
	}
	catch (std::invalid_argument& err)
	{
		std::string s = err.what();
		QMessageBox::information(nullptr, "Error", QString::fromStdString(s), QMessageBox::Ok);
	}
	for (auto w : this->windows)
	{
		this->populateList2(w);
	}
}

int PracticalExam::getIndex()
{
	if (ui.ideasList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = ui.ideasList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void PracticalExam::accept()
{
	int i = this->getIndex();
	try {
		this->ctrl.acceptIdeas(this->name, i);

	}
	catch (std::invalid_argument& err)
	{
		std::string s = err.what();
		QMessageBox::information(nullptr, "Error", QString::fromStdString(s), QMessageBox::Ok);
	}
	for (auto w : this->windows)
	{
		this->populateList2(w);
	}
}

void PracticalExam::populateList2(PracticalExam* win)
{
		win->populateList();
	
}

void PracticalExam::developHandler()
{
	for(int i=0;i<this->ctrl.getRepo().getIdeas().size();i++)

	{
		if (this->ctrl.getRepo().getIdeas()[i].getStatus() == "accepted")
		{
			
			QTextEdit* dev = new QTextEdit(ui.horizontalLayoutWidget);
			dev->setObjectName(QStringLiteral("devEdit"));
			ui.horizontalLayout->addWidget(dev);
			QString s;
			s = QString::fromStdString(this->ctrl.getRepo().getIdeas()[i].getDescr()) + ";" + QString::fromStdString(this->ctrl.getRepo().getIdeas()[i].getStatus()) + ";" + QString::fromStdString(this->ctrl.getRepo().getIdeas()[i].getNameCreator()) + ";" + QString::number(this->ctrl.getRepo().getIdeas()[i].getAct());
			dev->setText(s);
			this->texts.push_back(dev);
			


		}
	}

}

void PracticalExam::saveHandler()
{
	this->ctrl.writeToFileCtrl();
}

void PracticalExam::saveModifHandler()
{
	for (auto a : this->texts)
	{
		QString s = a->toPlainText();
		std::string ceva = s.toStdString();
		this->ctrl.saveToFileCtrl(ceva);
		

	}
}


