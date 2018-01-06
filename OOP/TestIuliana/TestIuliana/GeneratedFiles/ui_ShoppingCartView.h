/********************************************************************************
** Form generated from reading UI file 'ShoppingCartView.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCARTVIEW_H
#define UI_SHOPPINGCARTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShoppingCartView
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTableView *shoppingBasketListView;

    void setupUi(QWidget *ShoppingCartView)
    {
        if (ShoppingCartView->objectName().isEmpty())
            ShoppingCartView->setObjectName(QStringLiteral("ShoppingCartView"));
        ShoppingCartView->resize(578, 463);
        horizontalLayoutWidget = new QWidget(ShoppingCartView);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 561, 441));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        shoppingBasketListView = new QTableView(horizontalLayoutWidget);
        shoppingBasketListView->setObjectName(QStringLiteral("shoppingBasketListView"));

        horizontalLayout->addWidget(shoppingBasketListView);


        retranslateUi(ShoppingCartView);

        QMetaObject::connectSlotsByName(ShoppingCartView);
    } // setupUi

    void retranslateUi(QWidget *ShoppingCartView)
    {
        ShoppingCartView->setWindowTitle(QApplication::translate("ShoppingCartView", "ShoppingCartView", 0));
    } // retranslateUi

};

namespace Ui {
    class ShoppingCartView: public Ui_ShoppingCartView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCARTVIEW_H
