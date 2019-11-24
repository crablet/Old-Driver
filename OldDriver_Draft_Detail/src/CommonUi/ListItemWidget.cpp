#include "ListItemWidget.h"

ListItemWidget::ListItemWidget(QWidget *parent) : QWidget(parent)
{
	Layout = new QHBoxLayout(this);
	setLayout(Layout);
}
