#include "PictureDelegate.h"
#include<qpixmap.h>
#include<qpainter.h>
#include"Domain.h"



PictureDelegate::~PictureDelegate()
{
}



void PictureDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QString coat = index.model()->data(index, Qt::EditRole).toString();

	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() != 1 )
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	if (coat.contains("Pink"))
	{
		QPixmap pixMap("Pink.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (coat.contains("Yellow"))
	{
		QPixmap pixMap("Yellow.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (coat.contains("Black"))
	{
		QPixmap pixMap("Black.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (coat.contains("Red"))
	{
		QPixmap pixMap("Red.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (coat.contains("Green"))
	{
		QPixmap pixMap("Green.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() == 1)
	{
		return QSize(32, 100);
	}

	return QStyledItemDelegate::sizeHint(option, index);
}
