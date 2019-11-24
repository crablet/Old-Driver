#include "PracticeItemsGroup.h"

PracticeItemsGroup::PracticeItemsGroup(QWidget *parent) : QWidget(parent)
{
}

PracticeItemsGroup::PracticeItemsGroup(std::vector<QString> &&ItemsList, QWidget *Parent) 
	: PracticeItemsGroup(Parent)
{
	setFixedSize(PracticeItemsGroupW, PracticeItemsGroupH);

	Layout = new QGridLayout(this);
	for (int i = 0; i < static_cast<int>(ItemsList.size()); ++i)
	{
		auto *Label = new QLabel(std::move(ItemsList[i]), this);
		Label->setStyleSheet(PracticeItemsGroupLabelStyle);

		Layout->addWidget(Label, i / 4, i % 4);
	}
	setLayout(Layout);
}
