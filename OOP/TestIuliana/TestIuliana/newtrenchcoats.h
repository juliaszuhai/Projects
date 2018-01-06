#ifndef NEWTRENCHCOATS_H
#define NEWTRENCHCOATS_H

#include <QtWidgets/QMainWindow>

class NewTrenchCoats : public QMainWindow
{
	Q_OBJECT

public:
	NewTrenchCoats(QWidget *parent = 0);
	~NewTrenchCoats();

private:
	Ui::NewTrenchCoatsClass ui;
};

#endif // NEWTRENCHCOATS_H
