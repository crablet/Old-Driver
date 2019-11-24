#include "SchoolSettingsPage.h"

SchoolSettingsPage::SchoolSettingsPage(QWidget *parent) : SettingsPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void SchoolSettingsPage::mousePressEvent(QMouseEvent *e)
{
	// 点击旁边空白处隐藏设置页面
	if (!this->isHidden())
	{
		int x = e->pos().x();
		int y = e->pos().y();
		if (!(x >= TableBackgroundWidgetX && x <= TableBackgroundWidgetX + TableBackgroundWidgetW
			&& y >= TableBackgroundWidgetY && y <= TableBackgroundWidgetY + TableBackgroundWidgetH))
		{
			this->hide();

			//Config::Save<Type>(this);
		}
	}

	QWidget::mousePressEvent(e);
}

void SchoolSettingsPage::InitializeConnect()
{
	SettingsPageBase::InitializeConnect();
}

void SchoolSettingsPage::AddSpecificItemToSettingsTable()
{
	SettingsTable->insertRow(SettingsTable->rowCount());
	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 0, CreateHeaderLabel("通过学校\n评判"));

	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("不观察左、右方交通情况"));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateLabel("扣"));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout1->addWidget(CreateLabel("分"));

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateLabel("未停车礼让行人"));
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateLabel("扣"));
	WidgetLayout2->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout2->addWidget(CreateLabel("分"));

	auto *WidgetLine2 = CreateWidget();
	WidgetLine2->setLayout(WidgetLayout2);

	/////////////////////////////////////////

	auto *OuterLayout = new QVBoxLayout;
	OuterLayout->addWidget(WidgetLine1);
	OuterLayout->addWidget(WidgetLine2);

	auto *OuterWidget = new QWidget;
	OuterWidget->setLayout(OuterLayout);

	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 1, OuterWidget);
}
