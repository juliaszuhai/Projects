/********************************************************************************
** Form generated from reading UI file 'testiuliana.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTIULIANA_H
#define UI_TESTIULIANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestIulianaClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *RightLayout;
    QComboBox *comboBox;
    QHBoxLayout *adminButtons;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updateButton;
    QPushButton *undoButton;
    QListWidget *trenchCoatList;
    QLabel *sizeLabel;
    QLineEdit *sizeEdit;
    QLabel *colourLabel;
    QLineEdit *colourEdit;
    QLabel *priceLabel;
    QLineEdit *priceEdit;
    QLabel *quantityLabel;
    QLineEdit *quantityEdit;
    QLabel *photoLabel;
    QLineEdit *photoEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *goToAdmin;
    QPushButton *goToUser;
    QVBoxLayout *LeftLayout;
    QListWidget *seeCurrent;
    QComboBox *filterBySize;
    QPushButton *nextTrenchCoat;
    QVBoxLayout *verticalLayout;
    QPushButton *buyCart;
    QPushButton *addToCart;
    QListWidget *seeShoppingBag;
    QVBoxLayout *putFilename;
    QLabel *filenameLabel;
    QLineEdit *filename;
    QPushButton *saveOrder;
    QPushButton *openShopping;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestIulianaClass)
    {
        if (TestIulianaClass->objectName().isEmpty())
            TestIulianaClass->setObjectName(QStringLiteral("TestIulianaClass"));
        TestIulianaClass->resize(836, 545);
        centralWidget = new QWidget(TestIulianaClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 801, 491));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RightLayout = new QVBoxLayout();
        RightLayout->setSpacing(6);
        RightLayout->setObjectName(QStringLiteral("RightLayout"));
        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        RightLayout->addWidget(comboBox);

        adminButtons = new QHBoxLayout();
        adminButtons->setSpacing(6);
        adminButtons->setObjectName(QStringLiteral("adminButtons"));
        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        adminButtons->addWidget(addButton);

        removeButton = new QPushButton(horizontalLayoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        adminButtons->addWidget(removeButton);

        updateButton = new QPushButton(horizontalLayoutWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        adminButtons->addWidget(updateButton);


        RightLayout->addLayout(adminButtons);

        undoButton = new QPushButton(horizontalLayoutWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));

        RightLayout->addWidget(undoButton);

        trenchCoatList = new QListWidget(horizontalLayoutWidget);
        trenchCoatList->setObjectName(QStringLiteral("trenchCoatList"));

        RightLayout->addWidget(trenchCoatList);

        sizeLabel = new QLabel(horizontalLayoutWidget);
        sizeLabel->setObjectName(QStringLiteral("sizeLabel"));

        RightLayout->addWidget(sizeLabel);

        sizeEdit = new QLineEdit(horizontalLayoutWidget);
        sizeEdit->setObjectName(QStringLiteral("sizeEdit"));

        RightLayout->addWidget(sizeEdit);

        colourLabel = new QLabel(horizontalLayoutWidget);
        colourLabel->setObjectName(QStringLiteral("colourLabel"));

        RightLayout->addWidget(colourLabel);

        colourEdit = new QLineEdit(horizontalLayoutWidget);
        colourEdit->setObjectName(QStringLiteral("colourEdit"));

        RightLayout->addWidget(colourEdit);

        priceLabel = new QLabel(horizontalLayoutWidget);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));

        RightLayout->addWidget(priceLabel);

        priceEdit = new QLineEdit(horizontalLayoutWidget);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));

        RightLayout->addWidget(priceEdit);

        quantityLabel = new QLabel(horizontalLayoutWidget);
        quantityLabel->setObjectName(QStringLiteral("quantityLabel"));

        RightLayout->addWidget(quantityLabel);

        quantityEdit = new QLineEdit(horizontalLayoutWidget);
        quantityEdit->setObjectName(QStringLiteral("quantityEdit"));

        RightLayout->addWidget(quantityEdit);

        photoLabel = new QLabel(horizontalLayoutWidget);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));

        RightLayout->addWidget(photoLabel);

        photoEdit = new QLineEdit(horizontalLayoutWidget);
        photoEdit->setObjectName(QStringLiteral("photoEdit"));

        RightLayout->addWidget(photoEdit);


        horizontalLayout->addLayout(RightLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        goToAdmin = new QPushButton(horizontalLayoutWidget);
        goToAdmin->setObjectName(QStringLiteral("goToAdmin"));

        verticalLayout_2->addWidget(goToAdmin);

        goToUser = new QPushButton(horizontalLayoutWidget);
        goToUser->setObjectName(QStringLiteral("goToUser"));

        verticalLayout_2->addWidget(goToUser);


        horizontalLayout->addLayout(verticalLayout_2);

        LeftLayout = new QVBoxLayout();
        LeftLayout->setSpacing(6);
        LeftLayout->setObjectName(QStringLiteral("LeftLayout"));
        seeCurrent = new QListWidget(horizontalLayoutWidget);
        seeCurrent->setObjectName(QStringLiteral("seeCurrent"));

        LeftLayout->addWidget(seeCurrent);

        filterBySize = new QComboBox(horizontalLayoutWidget);
        filterBySize->setObjectName(QStringLiteral("filterBySize"));

        LeftLayout->addWidget(filterBySize);

        nextTrenchCoat = new QPushButton(horizontalLayoutWidget);
        nextTrenchCoat->setObjectName(QStringLiteral("nextTrenchCoat"));

        LeftLayout->addWidget(nextTrenchCoat);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        buyCart = new QPushButton(horizontalLayoutWidget);
        buyCart->setObjectName(QStringLiteral("buyCart"));

        verticalLayout->addWidget(buyCart);

        addToCart = new QPushButton(horizontalLayoutWidget);
        addToCart->setObjectName(QStringLiteral("addToCart"));

        verticalLayout->addWidget(addToCart);


        LeftLayout->addLayout(verticalLayout);

        seeShoppingBag = new QListWidget(horizontalLayoutWidget);
        seeShoppingBag->setObjectName(QStringLiteral("seeShoppingBag"));
        seeShoppingBag->setEnabled(true);

        LeftLayout->addWidget(seeShoppingBag);

        putFilename = new QVBoxLayout();
        putFilename->setSpacing(6);
        putFilename->setObjectName(QStringLiteral("putFilename"));
        filenameLabel = new QLabel(horizontalLayoutWidget);
        filenameLabel->setObjectName(QStringLiteral("filenameLabel"));

        putFilename->addWidget(filenameLabel);

        filename = new QLineEdit(horizontalLayoutWidget);
        filename->setObjectName(QStringLiteral("filename"));

        putFilename->addWidget(filename);

        saveOrder = new QPushButton(horizontalLayoutWidget);
        saveOrder->setObjectName(QStringLiteral("saveOrder"));

        putFilename->addWidget(saveOrder);

        openShopping = new QPushButton(horizontalLayoutWidget);
        openShopping->setObjectName(QStringLiteral("openShopping"));

        putFilename->addWidget(openShopping);


        LeftLayout->addLayout(putFilename);


        horizontalLayout->addLayout(LeftLayout);

        TestIulianaClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestIulianaClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 836, 21));
        TestIulianaClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestIulianaClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestIulianaClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestIulianaClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestIulianaClass->setStatusBar(statusBar);

        retranslateUi(TestIulianaClass);

        QMetaObject::connectSlotsByName(TestIulianaClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestIulianaClass)
    {
        TestIulianaClass->setWindowTitle(QApplication::translate("TestIulianaClass", "TestIuliana", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("TestIulianaClass", "Detailed", 0)
         << QApplication::translate("TestIulianaClass", "Simplified", 0)
        );
        addButton->setText(QApplication::translate("TestIulianaClass", "Add", 0));
        removeButton->setText(QApplication::translate("TestIulianaClass", "Remove", 0));
        updateButton->setText(QApplication::translate("TestIulianaClass", "Update", 0));
        undoButton->setText(QApplication::translate("TestIulianaClass", "Undo", 0));
        sizeLabel->setText(QApplication::translate("TestIulianaClass", "Size:", 0));
        colourLabel->setText(QApplication::translate("TestIulianaClass", "Colour:", 0));
        priceLabel->setText(QApplication::translate("TestIulianaClass", "Price:", 0));
        quantityLabel->setText(QApplication::translate("TestIulianaClass", "Quantity:", 0));
        photoLabel->setText(QApplication::translate("TestIulianaClass", "Photo:", 0));
        goToAdmin->setText(QApplication::translate("TestIulianaClass", "<", 0));
        goToUser->setText(QApplication::translate("TestIulianaClass", ">", 0));
        filterBySize->clear();
        filterBySize->insertItems(0, QStringList()
         << QApplication::translate("TestIulianaClass", "Size S", 0)
         << QApplication::translate("TestIulianaClass", "Size M", 0)
         << QApplication::translate("TestIulianaClass", "Size L", 0)
         << QApplication::translate("TestIulianaClass", "Size XL", 0)
         << QApplication::translate("TestIulianaClass", "Size XXL", 0)
        );
        nextTrenchCoat->setText(QApplication::translate("TestIulianaClass", "Next trench coat", 0));
        buyCart->setText(QApplication::translate("TestIulianaClass", "Buy shopping bag", 0));
        addToCart->setText(QApplication::translate("TestIulianaClass", "Add item to shopping bag", 0));
        filenameLabel->setText(QApplication::translate("TestIulianaClass", "Filename path:", 0));
        saveOrder->setText(QApplication::translate("TestIulianaClass", "Save shopping bag  to file", 0));
        openShopping->setText(QApplication::translate("TestIulianaClass", "Open File", 0));
    } // retranslateUi

};

namespace Ui {
    class TestIulianaClass: public Ui_TestIulianaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTIULIANA_H
