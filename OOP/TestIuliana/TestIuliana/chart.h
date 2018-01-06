#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include "ui_chart.h"

class Chart : public QWidget
{
	Q_OBJECT

public:
	Chart(QWidget *parent = 0);
	~Chart();

private:
	Ui::Chart ui;
};

#endif // CHART_H
