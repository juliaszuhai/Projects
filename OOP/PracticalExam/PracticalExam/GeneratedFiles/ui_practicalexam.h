/********************************************************************************
** Form generated from reading UI file 'practicalexam.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTICALEXAM_H
#define UI_PRACTICALEXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PracticalExamClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *ideasList;
    QLabel *descriptionLabel;
    QLineEdit *descriprtionEdit;
    QLabel *actLabel;
    QLineEdit *actEdit;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer;
    QPushButton *saveToFileButton;
    QPushButton *saveButton;
    QPushButton *developButton;
    QPushButton *acceptButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PracticalExamClass)
    {
        if (PracticalExamClass->objectName().isEmpty())
            PracticalExamClass->setObjectName(QStringLiteral("PracticalExamClass"));
        PracticalExamClass->resize(601, 406);
        centralWidget = new QWidget(PracticalExamClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 581, 341));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ideasList = new QListWidget(horizontalLayoutWidget);
        ideasList->setObjectName(QStringLiteral("ideasList"));

        verticalLayout->addWidget(ideasList);

        descriptionLabel = new QLabel(horizontalLayoutWidget);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        verticalLayout->addWidget(descriptionLabel);

        descriprtionEdit = new QLineEdit(horizontalLayoutWidget);
        descriprtionEdit->setObjectName(QStringLiteral("descriprtionEdit"));

        verticalLayout->addWidget(descriprtionEdit);

        actLabel = new QLabel(horizontalLayoutWidget);
        actLabel->setObjectName(QStringLiteral("actLabel"));

        verticalLayout->addWidget(actLabel);

        actEdit = new QLineEdit(horizontalLayoutWidget);
        actEdit->setObjectName(QStringLiteral("actEdit"));

        verticalLayout->addWidget(actEdit);

        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout->addWidget(addButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        saveToFileButton = new QPushButton(horizontalLayoutWidget);
        saveToFileButton->setObjectName(QStringLiteral("saveToFileButton"));

        horizontalLayout->addWidget(saveToFileButton);

        saveButton = new QPushButton(horizontalLayoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        developButton = new QPushButton(horizontalLayoutWidget);
        developButton->setObjectName(QStringLiteral("developButton"));

        horizontalLayout->addWidget(developButton);

        acceptButton = new QPushButton(horizontalLayoutWidget);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));

        horizontalLayout->addWidget(acceptButton);

        PracticalExamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PracticalExamClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 21));
        PracticalExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PracticalExamClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PracticalExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PracticalExamClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PracticalExamClass->setStatusBar(statusBar);

        retranslateUi(PracticalExamClass);

        QMetaObject::connectSlotsByName(PracticalExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *PracticalExamClass)
    {
        PracticalExamClass->setWindowTitle(QApplication::translate("PracticalExamClass", "PracticalExam", 0));
        descriptionLabel->setText(QApplication::translate("PracticalExamClass", "Description:", 0));
        actLabel->setText(QApplication::translate("PracticalExamClass", "Act:", 0));
        addButton->setText(QApplication::translate("PracticalExamClass", "Add a new idea!", 0));
        saveToFileButton->setText(QApplication::translate("PracticalExamClass", "Save to file", 0));
        saveButton->setText(QApplication::translate("PracticalExamClass", "Save!", 0));
        developButton->setText(QApplication::translate("PracticalExamClass", "Develop!", 0));
        acceptButton->setText(QApplication::translate("PracticalExamClass", "Accept this idea!", 0));
    } // retranslateUi

};

namespace Ui {
    class PracticalExamClass: public Ui_PracticalExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTICALEXAM_H
