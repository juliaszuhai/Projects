#ifndef SHOPPINGCARTVIEW_H
#define SHOPPINGCARTVIEW_H

#include <QWidget>
#include "ui_ShoppingCartView.h"
#include "FileOrder.h"
#include "PictureDelegate.h"
class ShoppingCartView : public QWidget
{
	Q_OBJECT

public:
	ShoppingCartView(FileOrder*u, QAbstractItemModel*model, QWidget *parent = 0);
	~ShoppingCartView();
	void setupPictureTableView();

private:
	Ui::ShoppingCartView ui;
	QAbstractItemModel * tableModel;
	FileOrder* user;
};

#endif // SHOPPINGCARTVIEW_H
