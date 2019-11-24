#include "TurningLeftSettingsPage.h"

TurningLeftSettingsPage::TurningLeftSettingsPage(QWidget *parent) : SettingsPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void TurningLeftSettingsPage::mousePressEvent(QMouseEvent *e)
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

void TurningLeftSettingsPage::InitializeConnect()
{
	SettingsPageBase::InitializeConnect();
}

void TurningLeftSettingsPage::AddSpecificItemToSettingsTable()
{
	SettingsTable->removeRow(SettingsTable->rowCount() - 1);	// 先删去原有的最后一行
	SettingsTable->insertRow(SettingsTable->rowCount());		// 然后加上一行，相当于把最后一行清空

	SettingsTable->setCellWidget(2, 0, CreateHeaderLabel("路口左转弯\n评判"));

	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("不观察左、右方交通情况，转弯通过\n路口时，未观察侧前方交通情况"));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateLabel("扣"));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout1->addWidget(CreateLabel("分"));

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateLabel("遇有路口交通阻塞时进入路口，将\n车辆停在路口内等候"));
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

	SettingsTable->setCellWidget(2, 1, OuterWidget);
}
