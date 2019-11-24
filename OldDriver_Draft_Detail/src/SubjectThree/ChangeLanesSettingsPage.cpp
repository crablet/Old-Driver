#include "ChangeLanesSettingsPage.h"

ChangeLanesSettingsPage::ChangeLanesSettingsPage(QWidget *parent) : SettingsPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void ChangeLanesSettingsPage::mousePressEvent(QMouseEvent * e)
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

void ChangeLanesSettingsPage::InitializeConnect()
{
	SettingsPageBase::InitializeConnect();
}

void ChangeLanesSettingsPage::AddSpecificItemToSettingsTable()
{
	SettingsTable->insertRow(SettingsTable->rowCount());
	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 0, CreateHeaderLabel("变更车道\n评判"));

	/////////////////////////////////////////

	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("变更车道前，未通过内、外后视镜\n观察后方道路交通情况"));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateLabel("扣"));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout1->addWidget(CreateLabel("分"));

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateLabel("变更车道时，判断车辆安全距离不合理，\n妨碍正常行驶车辆"));
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateLabel("扣"));
	WidgetLayout2->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout2->addWidget(CreateLabel("分"));

	auto *WidgetLine2 = CreateWidget();
	WidgetLine2->setLayout(WidgetLayout2);

	/////////////////////////////////////////

	auto *WidgetLayout3 = new QHBoxLayout;
	WidgetLayout3->addWidget(CreateLabel("控制行驶速度不合理，妨碍其他车辆\n正常行驶"));
	WidgetLayout3->addStretch();
	WidgetLayout3->addWidget(CreateLabel("扣"));
	WidgetLayout3->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout3->addWidget(CreateLabel("分"));

	auto *WidgetLine3 = CreateWidget();
	WidgetLine3->setLayout(WidgetLayout3);

	/////////////////////////////////////////

	auto *OuterLayout = new QVBoxLayout;
	OuterLayout->addWidget(WidgetLine1);
	OuterLayout->addWidget(WidgetLine2);
	OuterLayout->addWidget(WidgetLine3);

	auto *OuterWidget = new QWidget;
	OuterWidget->setLayout(OuterLayout);

	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 1, OuterWidget);
}
