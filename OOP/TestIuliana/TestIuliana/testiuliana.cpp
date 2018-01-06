#include "testiuliana.h"
#include<qmessagebox.h>
#include "Utils.h"
#include"shoppingcartview.h"

TestIuliana::TestIuliana(Controller& c,QWidget *parent)
	: QMainWindow(parent),ctrl{c}
{
	
	ui.setupUi(this);
	populateList();
	
	connect(ui.addButton, &QPushButton::clicked, this, &TestIuliana::addButtonHandler);

	connect(ui.removeButton, &QPushButton::clicked, this, &TestIuliana::removeButtonHandler);
	connect(ui.trenchCoatList, &QListWidget::itemClicked, this, &TestIuliana::listHandler);
	connect(ui.updateButton, &QPushButton::clicked, this, &TestIuliana::updateButtonHandler);
	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &TestIuliana::filterHandler);
	connect(ui.goToUser, &QPushButton::clicked, this, &TestIuliana::goToUserMode);
	connect(ui.nextTrenchCoat, &QPushButton::clicked, this, &TestIuliana::nextCoat);
	connect(ui.buyCart, &QPushButton::clicked, this, &TestIuliana::buyShopping);
	connect(ui.addToCart, &QPushButton::clicked, this, &TestIuliana::addToBag);
	connect(ui.saveOrder, &QPushButton::clicked, this, &TestIuliana::saveBagToFile);
	connect(ui.openShopping, &QPushButton::clicked, this, &TestIuliana::openFile);
	connect(ui.filterBySize, &QComboBox::currentTextChanged, this, &TestIuliana::userFilterHandler);
	connect(ui.undoButton, &QPushButton::clicked, this, &TestIuliana::undoUI);
	connect(ui.goToAdmin, &QPushButton::clicked, this, &TestIuliana::setupTableView);
}

TestIuliana::~TestIuliana()
{

}

void TestIuliana::addButtonHandler()
{
	QString size = ui.sizeEdit->text();
	
	QString colour = ui.colourEdit->text();
	
	QString price = ui.priceEdit->text();
	
	QString quantity = ui.quantityEdit->text();
	
	QString photo = ui.photoEdit->text();
	ctrl.addTrenchCoatCtrl(size.toStdString(), colour.toStdString(), price.toDouble(), quantity.toInt(), photo.toStdString());
	QMessageBox::information(nullptr, "Succes", "Hello, trench coat was added", QMessageBox::Ok);
	populateList();
}

void TestIuliana::populateList()
{
	std::vector<TrenchCoat> trenchcoats = ctrl.getRepo().getTrenchCoats();
	ui.trenchCoatList->clear();
	for (auto i : trenchcoats)
	{
		QString sizeStr = QString::fromStdString(i.getSize()) + "," + QString::fromStdString(i.getColour()) + "," + QString::number(i.getPrice()) + "," + QString::number(i.getQuantity()) + "," + QString::fromStdString(i.getSource());
		ui.trenchCoatList->addItem(sizeStr);
	}
}

void TestIuliana::populateShortList()
{
	std::vector<TrenchCoat> trenchcoats = this->ctrl.getRepo().getTrenchCoats();
	ui.trenchCoatList->clear();
	for (auto i : trenchcoats)
	{
		QString sizeStr = QString::fromStdString(i.getSize()) + "," + QString::fromStdString(i.getColour());
		ui.trenchCoatList->addItem(sizeStr);
	}
}

int TestIuliana::getIndex()
{
	if (ui.trenchCoatList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = ui.trenchCoatList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		ui.sizeEdit->clear();
		ui.colourEdit->clear();
		ui.priceEdit->clear();
		ui.quantityEdit->clear();
		ui.photoEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void TestIuliana::populateMiniBoxes()
{
	ui.sizeEdit->clear();
	ui.colourEdit->clear();
	ui.priceEdit->clear();
	ui.quantityEdit->clear();
	ui.photoEdit->clear();
	int i = getIndex();
	QString trenchCoat = ui.trenchCoatList->item(i)->text();
	std::string trench = trenchCoat.toStdString();
	vector<string> tokens = tokenize(trench, ',');
	ui.sizeEdit->setText(QString::fromStdString(tokens[0]));
	ui.colourEdit->setText(QString::fromStdString(tokens[1]));
	
}

void TestIuliana::removeButtonHandler()
{
	QString size = ui.sizeEdit->text();
	QString colour = ui.colourEdit->text();
	try {
		ctrl.removeTrenchCoatCtrl(size.toStdString(), colour.toStdString());
	}
	catch (const std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Cannot remove trenchcoat. Quantity is not 0.", QMessageBox::Ok);
	}
	populateList();
}

void TestIuliana::listHandler()
{
	populateMiniBoxes();
}

void TestIuliana::updateButtonHandler()
{
	QString size = ui.sizeEdit->text();
	QString colour = ui.colourEdit->text();
	QString price = ui.priceEdit->text();
	QString quantity = ui.quantityEdit->text();
	QString photo = ui.photoEdit->text();
	try {
		ctrl.updateTrenchCoatCtrl(size.toStdString(), colour.toStdString(), price.toDouble(), quantity.toInt(), photo.toStdString());
	}
	catch (const std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Could not find trench coat.", QMessageBox::Ok);
	}
	//QMessageBox::critical(nullptr, "Error", "Hello, button was clicked", QMessageBox::Ok);
	this->populateList();
}

void TestIuliana::filterHandler()
{
	if (ui.comboBox->currentText() == "Simplified")
	{
		populateShortList();
	}
	else
	{
		populateList();
	}
}

void TestIuliana::userFilterHandler()
{
	vector<TrenchCoat>v;
	if (ui.filterBySize->currentText() == "Size S")
	{
		
		v=ctrl.filtersize("S");
		ctrl.setFilter(v);
	}
	if (ui.filterBySize->currentText() == "Size M")
	{

		v=ctrl.filtersize("M");
		ctrl.setFilter(v);
	}
	if(ui.filterBySize->currentText() == "Size L")
	{

		v=ctrl.filtersize("L");
		ctrl.setFilter(v);
	}
	if(ui.filterBySize->currentText() == "Size XL")
	{

		v=ctrl.filtersize("XL");
		ctrl.setFilter(v);
	}
	if(ui.filterBySize->currentText() == "Size XXL")
	{

		v=ctrl.filtersize("XXL");
		ctrl.setFilter(v);
	}
}

void TestIuliana::undoUI()
{
	try {
		ctrl.undo();
	}
	catch (const std::invalid_argument& err)
	{
	QMessageBox::critical(nullptr, "Error", "Could not do undo.", QMessageBox::Ok);
	}
	populateList();
}

void TestIuliana::setupTableView()
{
	MyTableModel* tableModel = new MyTableModel{ ctrl.getOrder() };
	ShoppingCartView* newShoppingView = new ShoppingCartView { this->ctrl.getOrder(),tableModel,this };
	newShoppingView->show();
}




void TestIuliana::goToUserMode()
{
	
	populateCurrentCoat();
}

void TestIuliana::populateCurrentCoat()
{
	TrenchCoat i = ctrl.getOrder()->getCurrentTrenchCoat();
	ui.seeCurrent->clear();

	QString sizeStr = QString::fromStdString(i.getSize()) + "," + QString::fromStdString(i.getColour()) + "," + QString::number(i.getPrice()) + "," + QString::number(i.getQuantity()) + "," + QString::fromStdString(i.getSource());
	ui.seeCurrent->addItem(sizeStr);
	
}

void TestIuliana::nextCoat()
{
	ctrl.getOrder()->next();
	populateCurrentCoat();
}

void TestIuliana::buyShopping()
{
	int i;
	double price = 0;
	for (i = 0; i < ctrl.getOrder()->trenchcoats.size(); i++)
	{
		price = price + ctrl.getOrder()->trenchcoats[i].getPrice();

	}
	ctrl.buy();
	QString status = QString("The items have been succesfully bought! The price of your shopping bag %1 ").arg(price);
	QMessageBox::information(nullptr, "Succes", status, QMessageBox::Ok);
	populateList();
	populateShortList();
	populateShoppingBag();
}

void TestIuliana::addToBag()
{
	ctrl.addCurrentCoat();
	populateShoppingBag();
}

void TestIuliana::populateShoppingBag()
{
	int i;
	ui.seeShoppingBag->clear();
	vector<TrenchCoat> v = ctrl.getOrder()->trenchcoats;
	for (i = 0; i < v.size(); i++)
	{
		QString sizeStr = QString::fromStdString(v[i].getSize()) + "," + QString::fromStdString(v[i].getColour()) + "," + QString::number(v[i].getPrice()) + "," + QString::number(v[i].getQuantity()) + "," + QString::fromStdString(v[i].getSource());
		ui.seeShoppingBag->addItem(sizeStr);
	}
}

void TestIuliana::saveBagToFile()
{
	QString filename = ui.filename->text();
	string filenameS = filename.toStdString();
	ctrl.saveOrder(filenameS);
}

void TestIuliana::openFile()
{

	ctrl.openOrder();
}
