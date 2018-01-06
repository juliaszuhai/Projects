#include "MyTableModel.h"
#include<qfont.h>
#include<algorithm>
#include<qdebug.h>
#include<qmessagebox.h>
#include <qbrush.h>
#include <qcolor.h>



int MyTableModel::rowCount(const QModelIndex & parent) const
{
	return this->user->getShoppingBasket().size();
}

int MyTableModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant MyTableModel::data(const QModelIndex & index, int role) const
{
	TrenchCoat currentCoat = this->user->getShoppingBasket()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		// first column - name
			return QString::fromStdString(currentCoat.getSize());
		case 1:		// second column - group
			return QString::fromStdString(currentCoat.getColour());
		case 2:		// third column - lab grade
			return QString::number(currentCoat.getPrice());
		case 3:		// third column - lab grade
			return QString::number(currentCoat.getQuantity());
		case 4:		// fourth column - seminar grade
			return QString::fromStdString(currentCoat.getSource());
		default:
			break;
		}
	}

	return QVariant();
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Size" };
			case 1:
				return QString{ "Colour" };
			case 2:
				return QString{ "Price" };
			case 3:
				return QString{ "Quantity" };
			case 4:
				return QString{ "Source" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool MyTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();

	TrenchCoat& currentCoat = this->user->getShoppingBasket()[index.row()];

	if (role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
		{
			std::string labGrade{ value.toString().toStdString() };
			//currentDog.setLabGrade(std::stod(labGrade));
			break;
		}
		case 3:
		{
			std::string seminarGrade{ value.toString().toStdString() };
			//currentStudent.setSeminarGrade(std::stod(seminarGrade));
		}
		}
	}

	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0 || col == 1)
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}



MyTableModel::~MyTableModel()
{
}
