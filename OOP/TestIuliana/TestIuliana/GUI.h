#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include<qmessagebox.h>
#include"Controller.h"
#include"Utils.h"
#include"Validator.h"
#include<QComboBox>
class GUI : public QWidget
{
	Q_OBJECT
private:
	Controller & ctrl;
	Validator valid;
public:
	GUI(Controller& ctrl, QWidget *parent = 0);
	~GUI();
	void setWindow();
	void addButtonHandler();
	void populateList();
	void populateShortList();
	int getIndex();
	void populateMiniBoxes();
	void removeButtonHandler();
	void listHandler();
	void updateButtonHandler();
	QList<QListWidgetItem*> search_for_string(QString search_str);
	void filterHandler();
private:
	QListWidget* trenchCoatList;
	QPushButton* add;
	QPushButton* remove;
	QPushButton* update;
	QLineEdit* sizeEdit;
	QLineEdit* colourEdit;
	QLineEdit* priceEdit;
	QLineEdit* quantityEdit;
	QLineEdit* photoEdit;
	//QLineEdit* substring;
	QComboBox* cbb;
};

