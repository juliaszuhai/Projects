#ifndef PRACTICALEXAM_H
#define PRACTICALEXAM_H

#include <QtWidgets/QMainWindow>
#include "ui_practicalexam.h"
#include"Controller.h"
#include"practicalexam.h"
#include<qtextedit.h>
class PracticalExam : public QMainWindow
{
	Q_OBJECT

public:
	PracticalExam(Controller& ctrl, std::string name, std::vector<PracticalExam*> &windows, std::vector<QTextEdit*> &texts,QWidget *parent = 0);
	~PracticalExam();
	void populateList();
	void add();
	int getIndex();
	void accept();
	void populateList2(PracticalExam* win);
	void developHandler();
	void saveHandler();
	void saveModifHandler();

private:
	Ui::PracticalExamClass ui;
	Controller& ctrl;
	std::string name;
	std::vector<PracticalExam*> &windows;
	std::vector<QTextEdit*> &texts;

};

#endif // PRACTICALEXAM_H
