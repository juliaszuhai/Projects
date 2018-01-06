#include "initialization.h"
#include<qpushbutton.h>

Initialization::Initialization(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &Initialization::buttonHandler);
}

Initialization::~Initialization()
{

}

int Initialization::getChoice()
{
	return choice;
}

void Initialization::buttonHandler()
{
	if (ui.CSVRadioButton->isChecked() == true)
	{
		choice = 1;
	}
	else
		if (ui.radioButton_2->isChecked() == true)
		{
			choice = 0;
		}

	this->close();
}
