#include "OvertakingSettingsPage.h"

OvertakingSettingsPage::OvertakingSettingsPage(QWidget *parent) : SettingsPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void OvertakingSettingsPage::mousePressEvent(QMouseEvent *e)
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

void OvertakingSettingsPage::InitializeConnect()
{
	SettingsPageBase::InitializeConnect();
}

void OvertakingSettingsPage::AddSpecificItemToSettingsTable()
{
	SettingsTable->insertRow(SettingsTable->rowCount());
	SettingsTable->setCellWidget(3, 0, CreateHeaderLabel("超车评判"));

	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("超车前不通过内、外后视镜观察后方和\n左侧交通情况"));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateLabel("扣"));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout1->addWidget(CreateLabel("分"));

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateLabel("超车时机选择不合理，影响其他\n车辆正常行驶"));
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateLabel("扣"));
	WidgetLayout2->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout2->addWidget(CreateLabel("分"));

	auto *WidgetLine2 = CreateWidget();
	WidgetLine2->setLayout(WidgetLayout2);

	/////////////////////////////////////////

	auto *WidgetLayout3 = new QHBoxLayout;
	WidgetLayout3->addWidget(CreateLabel("超车时，未侧头观察被超越车辆动态"));
	WidgetLayout3->addStretch();
	WidgetLayout3->addWidget(CreateLabel("扣"));
	WidgetLayout3->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout3->addWidget(CreateLabel("分"));

	auto *WidgetLine3 = CreateWidget();
	WidgetLine3->setLayout(WidgetLayout3);

	/////////////////////////////////////////

	auto *WidgetLayout4 = new QHBoxLayout;
	WidgetLayout4->addWidget(CreateLabel("超车时未与被超越车辆保持安全距离"));
	WidgetLayout4->addStretch();
	WidgetLayout4->addWidget(CreateLabel("扣"));
	WidgetLayout4->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout4->addWidget(CreateLabel("分"));

	auto *WidgetLine4 = CreateWidget();
	WidgetLine4->setLayout(WidgetLayout4);

	/////////////////////////////////////////

	auto *WidgetLayout5 = new QHBoxLayout;
	WidgetLayout5->addWidget(CreateLabel("在没有中心线或同方向只有一条行\n车道的道路上从右侧超车"));
	WidgetLayout5->addStretch();
	WidgetLayout5->addWidget(CreateLabel("扣"));
	WidgetLayout5->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout5->addWidget(CreateLabel("分"));

	auto *WidgetLine5 = CreateWidget();
	WidgetLine5->setLayout(WidgetLayout5);

	/////////////////////////////////////////

	auto *WidgetLayout6 = new QHBoxLayout;
	WidgetLayout6->addWidget(CreateLabel("当后车发出超车信号时，具备让车条件\n不减速靠右让行"));
	WidgetLayout6->addStretch();
	WidgetLayout6->addWidget(CreateLabel("扣"));
	WidgetLayout6->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout6->addWidget(CreateLabel("分"));

	auto *WidgetLine6 = CreateWidget();
	WidgetLine6->setLayout(WidgetLayout6);

	/////////////////////////////////////////

	auto *OuterLayout = new QVBoxLayout;
	OuterLayout->addWidget(WidgetLine1);
	OuterLayout->addWidget(WidgetLine2);
	OuterLayout->addWidget(WidgetLine3);
	OuterLayout->addWidget(WidgetLine4);
	OuterLayout->addWidget(WidgetLine5);
	OuterLayout->addWidget(WidgetLine6);

	auto *OuterWidget = new QWidget;
	OuterWidget->setLayout(OuterLayout);

	SettingsTable->setCellWidget(3, 1, OuterWidget);
}
