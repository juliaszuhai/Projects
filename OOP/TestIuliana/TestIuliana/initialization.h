#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <QWidget>
#include<QDialog>
#include "ui_initialization.h"

class Initialization : public QDialog
{
	Q_OBJECT
private:
	int choice;

public:
	Initialization(QWidget *parent = 0);
	~Initialization();
	int getChoice();
	void buttonHandler();
	

private:
	Ui::Initialization ui;
};

#endif // INITIALIZATION_H
