/********************************************************************************
** Form generated from reading UI file 'initialization.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIALIZATION_H
#define UI_INITIALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Initialization
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *CSVRadioButton;
    QPushButton *pushButton;

    void setupUi(QWidget *Initialization)
    {
        if (Initialization->objectName().isEmpty())
            Initialization->setObjectName(QStringLiteral("Initialization"));
        Initialization->resize(400, 300);
        verticalLayoutWidget = new QWidget(Initialization);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 391, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        CSVRadioButton = new QRadioButton(verticalLayoutWidget);
        CSVRadioButton->setObjectName(QStringLiteral("CSVRadioButton"));

        horizontalLayout->addWidget(CSVRadioButton);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Initialization);

        QMetaObject::connectSlotsByName(Initialization);
    } // setupUi

    void retranslateUi(QWidget *Initialization)
    {
        Initialization->setWindowTitle(QApplication::translate("Initialization", "Initialization", 0));
        label->setText(QApplication::translate("Initialization", "What kind of initialization would you like?", 0));
        radioButton_2->setText(QApplication::translate("Initialization", "HTML File", 0));
        CSVRadioButton->setText(QApplication::translate("Initialization", "CSV File", 0));
        pushButton->setText(QApplication::translate("Initialization", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class Initialization: public Ui_Initialization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALIZATION_H
