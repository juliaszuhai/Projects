#ifndef TESTIULIANA_H
#define TESTIULIANA_H

#include <QtWidgets/QMainWindow>
#include "ui_testiuliana.h"
#include"Controller.h"
#include"MyTableModel.h"
class TestIuliana : public QMainWindow
{
	Q_OBJECT

public:
	TestIuliana(Controller& c, QWidget *parent = 0);
	~TestIuliana();
	void addButtonHandler();
	void populateList();
	void populateShortList();
	int getIndex();
	void populateMiniBoxes();
	void removeButtonHandler();
	void listHandler();
	void updateButtonHandler();
	void filterHandler();
	void goToUserMode();
	void populateCurrentCoat();
	void nextCoat();
	void buyShopping();
	void addToBag();
	void populateShoppingBag();
	void saveBagToFile();
	void openFile();
	void userFilterHandler();
	void undoUI();
	void setupTableView();

private:
	Ui::TestIulianaClass ui;
	Controller& ctrl;
	//MyTableModel* tablemodel;
};

#endif // TESTIULIANA_H
