#include "GUI.h"
#include"Validator.h"

GUI::GUI(Controller & ctrl, QWidget * parent) :QWidget(parent), ctrl(ctrl)
{
	setWindow();
	this->populateList();
	try
	{
		connect(this->add, &QPushButton::clicked, this, &GUI::addButtonHandler);
	}
	catch (const std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Cannot remove trenchcoat. Quantity is not 0.", QMessageBox::Ok);
	}
	
	connect(this->remove, &QPushButton::clicked, this, &GUI::removeButtonHandler);
	connect(this->trenchCoatList, &QListWidget::itemClicked, this, &GUI::listHandler);
	connect(this->update, &QPushButton::clicked, this, &GUI::updateButtonHandler);
	connect(this->cbb, &QComboBox::currentTextChanged, this, &GUI::filterHandler);
}

GUI::~GUI()
{
}
QList<QListWidgetItem*> GUI::search_for_string(QString search_str)
{
	QList<QListWidgetItem*> my_found_items;

	for (int i = 0; i < this->trenchCoatList->count(); i++)
	{
		QListWidgetItem* current = this->trenchCoatList->item(i);
		if (current->text().contains(search_str))
		{
			my_found_items.append(current);
		}
	}
	return my_found_items;
}
void GUI::filterHandler()
{
	
	if (cbb->currentText() == "Short")
	{
		this->populateShortList();
	}
	else
	{
		this->populateList();
	}
	
}
void GUI::setWindow() {
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	this->cbb = new QComboBox{};
	//QComboBox* combo = new QComboBox{};
	QString s = "Detailed";
	QString p = "Short";
	cbb->addItem(s);
	cbb->addItem(p);
	mainLayout->addWidget(this->cbb);
	this->trenchCoatList = new QListWidget;
	mainLayout->addWidget(this->trenchCoatList);
	//QHBoxLayout* inputLayout = new QHBoxLayout;
	QFormLayout* formLayout = new QFormLayout{ };
	this->colourEdit = new QLineEdit{};
	this->sizeEdit = new QLineEdit{};
	this->priceEdit = new QLineEdit{};
	this->quantityEdit = new QLineEdit{};
	this->photoEdit = new QLineEdit{};
	QFont f{ "Verdana", 15 };
	QLabel* trenchCoatLabel0 = new QLabel{ "&size:" };
	trenchCoatLabel0->setBuddy(this->sizeEdit);
	trenchCoatLabel0->setFont(f);
	this->sizeEdit->setFont(f);
	//
	QLabel* trenchCoatLabel = new QLabel{ "&colour :" };
	trenchCoatLabel->setBuddy(this->colourEdit);
	trenchCoatLabel->setFont(f);
	this->colourEdit->setFont(f);
	//
	QLabel* trenchCoatLabel1 = new QLabel{ "&price :" };
	trenchCoatLabel1->setBuddy(this->priceEdit);
	trenchCoatLabel1->setFont(f);
	this->priceEdit->setFont(f);
	//
	QLabel* trenchCoatLabel2 = new QLabel{ "&quantity:" };
	trenchCoatLabel2->setBuddy(this->quantityEdit);
	trenchCoatLabel2->setFont(f);
	this->quantityEdit->setFont(f);
	//
	QLabel* trenchCoatLabel3 = new QLabel{ "&photo:" };
	trenchCoatLabel3->setBuddy(this->photoEdit);
	trenchCoatLabel3->setFont(f);
	this->photoEdit->setFont(f);

	formLayout->addRow(trenchCoatLabel0, this->sizeEdit);
	formLayout->addRow(trenchCoatLabel, this->colourEdit);
	formLayout->addRow(trenchCoatLabel1, this->priceEdit);
	formLayout->addRow(trenchCoatLabel2, this->quantityEdit);
	formLayout->addRow(trenchCoatLabel3, this->photoEdit);

	QHBoxLayout* buttonLayout = new QHBoxLayout;
	this->add = new QPushButton{ "Add" };
	this->remove = new QPushButton{ "Remove" };
	this->update = new QPushButton{ "Update " };
	buttonLayout->addWidget(add);
	buttonLayout->addWidget(remove);
	buttonLayout->addWidget(update);
	mainLayout->addLayout(buttonLayout);
	mainLayout->addLayout(formLayout);


}

void GUI::addButtonHandler()
{
	QString size = this->sizeEdit->text();
	std::string s = size.toStdString();
	if (valid.validString(s))
	{
		throw std::invalid_argument("Field cannot be empty.");
	}
	QString colour = this->colourEdit->text();
	std::string c = colour.toStdString();
	if (valid.validString(c))
	{
		throw std::invalid_argument("Field cannot be empty.");
	}
	QString price = this->priceEdit->text();
	double pr = price.toDouble();
	if (valid.validDouble(pr)==false)
	{
		throw std::invalid_argument("Field cannot be empty.");
	}
	QString quantity = this->quantityEdit->text();
	int q = quantity.toInt();
	if (valid.validInteger(q)==false)
	{
		throw std::invalid_argument("Field cannot be empty.");
	}
	QString photo = this->photoEdit->text();
	std::string p = photo.toStdString();
	if (valid.validString(p))
	{
		throw std::invalid_argument("Field cannot be empty.");
	}
	
		this->ctrl.addTrenchCoatCtrl(size.toStdString(), colour.toStdString(), price.toDouble(), quantity.toInt(), photo.toStdString());

	QMessageBox::information(nullptr, "Succes", "Hello, trench coat was added", QMessageBox::Ok);
	this->populateList();


}

void GUI::populateList()
{
	std::vector<TrenchCoat> trenchcoats = this->ctrl.getRepo().getTrenchCoats();
	this->trenchCoatList->clear();
	for (auto i : trenchcoats)
	{
		QString sizeStr = QString::fromStdString(i.getSize())+","+ QString::fromStdString(i.getColour())+ "," + QString::number(i.getPrice())+ "," + QString::number(i.getQuantity())+ "," + QString::fromStdString(i.getSource());
		this->trenchCoatList->addItem(sizeStr);
	}

}
void GUI::populateShortList()
{
	std::vector<TrenchCoat> trenchcoats = this->ctrl.getRepo().getTrenchCoats();
	this->trenchCoatList->clear();
	for (auto i : trenchcoats)
	{
		QString sizeStr = QString::fromStdString(i.getSize()) + "," + QString::fromStdString(i.getColour());
		this->trenchCoatList->addItem(sizeStr);
	}

}

int GUI::getIndex()
{
	if (this->trenchCoatList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->trenchCoatList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->sizeEdit->clear();
		this->colourEdit->clear();
		this->priceEdit->clear();
		this->quantityEdit->clear();
		this->photoEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void GUI::populateMiniBoxes()
{
	int i = this->getIndex();
	QString trenchCoat = this->trenchCoatList->item(i)->text();
	std::string trench = trenchCoat.toStdString();
	vector<string> tokens = tokenize(trench, ',');
	//QString string = QString::fromStdString(tokens[0]) + "," + QString::fromStdString(tokens[1]) + "," + QString::fromStdString(tokens[2]) + "," + QString::fromStdString(tokens[3]) + "," + QString::fromStdString(tokens[4]);
	this->sizeEdit->setText(QString::fromStdString(tokens[0]));
	this->colourEdit->setText(QString::fromStdString(tokens[1]));
	//this->sizeEdit->setText(QString::fromStdString(tokens[2]));
	//this->sizeEdit->setText(QString::fromStdString(tokens[3]));
	//this->sizeEdit->setText(QString::fromStdString(tokens[4]));

	
}

void GUI::removeButtonHandler()
{
	QString size = this->sizeEdit->text();
	QString colour = this->colourEdit->text();
	try {
		this->ctrl.removeTrenchCoatCtrl(size.toStdString(), colour.toStdString());
	}
	catch (const std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Cannot remove trenchcoat. Quantity is not 0.", QMessageBox::Ok);
	}
	//QMessageBox::critical(nullptr, "Error", "Hello, button was clicked", QMessageBox::Ok);
	this->populateList();
}

void GUI::listHandler()
{
	this->populateMiniBoxes();
}

void GUI::updateButtonHandler()
{
	QString size = this->sizeEdit->text();
	QString colour = this->colourEdit->text();
	QString price = this->priceEdit->text();
	QString quantity = this->quantityEdit->text();
	QString photo = this->photoEdit->text();
	try {
		this->ctrl.updateTrenchCoatCtrl(size.toStdString(), colour.toStdString(),price.toDouble(),quantity.toInt(),photo.toStdString());
	}
	catch (const std::invalid_argument& err)
	{
		QMessageBox::critical(nullptr, "Error", "Could not find trench coat.", QMessageBox::Ok);
	}
	//QMessageBox::critical(nullptr, "Error", "Hello, button was clicked", QMessageBox::Ok);
	this->populateList();
}
