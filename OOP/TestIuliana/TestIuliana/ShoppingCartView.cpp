#include "ShoppingCartView.h"

ShoppingCartView::ShoppingCartView(FileOrder*u, QAbstractItemModel*model,QWidget *parent)
	: QWidget(parent),user{u},tableModel{model}
{
	ui.setupUi(this);
	this->ui.shoppingBasketListView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->ui.shoppingBasketListView->setModel(this->tableModel);
	this->setupPictureTableView();

}

ShoppingCartView::~ShoppingCartView()
{

}

void ShoppingCartView::setupPictureTableView()
{// set the model
	ui.shoppingBasketListView->setModel(this->tableModel);

	// set the custom delegate
	ui.shoppingBasketListView->setItemDelegate(new PictureDelegate{});

	// force the columns to resize, according to the size of their contents
	ui.shoppingBasketListView->resizeColumnsToContents();
	ui.shoppingBasketListView->resizeRowsToContents();
	// hide the vertical header
	ui.shoppingBasketListView->verticalHeader()->hide();
}
