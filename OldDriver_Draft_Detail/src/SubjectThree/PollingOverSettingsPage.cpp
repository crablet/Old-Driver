#include "PollingOverSettingsPage.h"

PollingOverSettingsPage::PollingOverSettingsPage(QWidget *parent) : SettingsPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void PollingOverSettingsPage::mousePressEvent(QMouseEvent *e)
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

void PollingOverSettingsPage::InitializeConnect()
{
	SettingsPageBase::InitializeConnect();
}

void PollingOverSettingsPage::AddSpecificItemToSettingsTable()
{
	SettingsTable->removeRow(SettingsTable->rowCount() - 1);	// 先移除最后一行
	SettingsTable->insertRow(SettingsTable->rowCount());		// 再加上一行，相当于清空最后一行

	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 0, CreateHeaderLabel("速度要求"));

	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("速度范围："));
	WidgetLayout1->addWidget(CreateComboBox({ "15", "30" }));
	WidgetLayout1->addWidget(CreateLabel("—"));
	WidgetLayout1->addWidget(CreateComboBox({ "15", "30" }));
	WidgetLayout1->addWidget(CreateLabel("km/h"));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateLabel("扣"));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout1->addWidget(CreateLabel("分"));

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateLabel("转速范围："));
	WidgetLayout2->addWidget(CreateComboBox({ "15", "30" }));
	WidgetLayout2->addWidget(CreateLabel("—"));
	WidgetLayout2->addWidget(CreateComboBox({ "15", "30" }));
	WidgetLayout2->addWidget(CreateLabel("1/min x1000"));
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateLabel("扣"));
	WidgetLayout2->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout2->addWidget(CreateLabel("分"));

	auto *WidgetLine2 = CreateWidget();
	WidgetLine2->setLayout(WidgetLayout2);

	/////////////////////////////////////////

	auto *OuterLayout1 = new QVBoxLayout;
	OuterLayout1->addWidget(WidgetLine1);
	OuterLayout1->addWidget(WidgetLine2);

	auto *OuterWidget1 = new QWidget;
	OuterWidget1->setLayout(OuterLayout1);

	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 1, OuterWidget1);

	/////////////////////////////////////////
	//            “速度要求”^^^
	//         vvv“靠边停车评判”
	/////////////////////////////////////////

	SettingsTable->insertRow(SettingsTable->rowCount());
	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 0, CreateHeaderLabel("靠边停车\n评判"));

	auto *WidgetLayout3 = new QHBoxLayout;
	WidgetLayout3->addWidget(CreateLabel("停车后，车身超过道路右侧边缘线\n或者人行道边缘超出50CM"));
	WidgetLayout3->addStretch();
	WidgetLayout3->addWidget(CreateLabel("扣"));
	WidgetLayout3->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout3->addWidget(CreateLabel("分"));

	auto *WidgetLine3 = CreateWidget();
	WidgetLine3->setLayout(WidgetLayout3);

	/////////////////////////////////////////

	auto *WidgetLayout4 = new QHBoxLayout;
	WidgetLayout4->addWidget(CreateLabel("下车后不关闭车门"));
	WidgetLayout4->addStretch();
	WidgetLayout4->addWidget(CreateLabel("扣"));
	WidgetLayout4->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout4->addWidget(CreateLabel("分"));

	auto *WidgetLine4 = CreateWidget();
	WidgetLine4->setLayout(WidgetLayout4);

	/////////////////////////////////////////

	auto *WidgetLayout5 = new QHBoxLayout;
	WidgetLayout5->addWidget(CreateLabel("停车后，车身距离道路右侧边缘线\n或者人行道边缘大于30CM，\n未超出50CM"));
	WidgetLayout5->addStretch();
	WidgetLayout5->addWidget(CreateLabel("扣"));
	WidgetLayout5->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout5->addWidget(CreateLabel("分"));

	auto *WidgetLine5 = CreateWidget();
	WidgetLine5->setLayout(WidgetLayout5);

	/////////////////////////////////////////

	auto *WidgetLayout6 = new QHBoxLayout;
	WidgetLayout6->addWidget(CreateLabel("停车后，未拉紧驻车制动器"));
	WidgetLayout6->addStretch();
	WidgetLayout6->addWidget(CreateLabel("扣"));
	WidgetLayout6->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout6->addWidget(CreateLabel("分"));

	auto *WidgetLine6 = CreateWidget();
	WidgetLine6->setLayout(WidgetLayout6);

	/////////////////////////////////////////

	auto *WidgetLayout7 = new QHBoxLayout;
	WidgetLayout7->addWidget(CreateLabel("拉紧驻车制动器前放松行车制动踏板"));
	WidgetLayout7->addStretch();
	WidgetLayout7->addWidget(CreateLabel("扣"));
	WidgetLayout7->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout7->addWidget(CreateLabel("分"));

	auto *WidgetLine7 = CreateWidget();
	WidgetLine7->setLayout(WidgetLayout7);

	/////////////////////////////////////////

	auto *WidgetLayout8 = new QHBoxLayout;
	WidgetLayout8->addWidget(CreateLabel("下车前不将发动机熄火"));
	WidgetLayout8->addStretch();
	WidgetLayout8->addWidget(CreateLabel("扣"));
	WidgetLayout8->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout8->addWidget(CreateLabel("分"));

	auto *WidgetLine8 = CreateWidget();
	WidgetLine8->setLayout(WidgetLayout8);

	/////////////////////////////////////////

	auto *WidgetLayout9 = new QHBoxLayout;
	WidgetLayout9->addWidget(CreateLabel("未将档位置为空挡"));
	WidgetLayout9->addStretch();
	WidgetLayout9->addWidget(CreateLabel("扣"));
	WidgetLayout9->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout9->addWidget(CreateLabel("分"));

	auto *WidgetLine9 = CreateWidget();
	WidgetLine9->setLayout(WidgetLayout9);

	/////////////////////////////////////////

	auto *OuterLayout2 = new QVBoxLayout;
	OuterLayout2->addWidget(WidgetLine3);
	OuterLayout2->addWidget(WidgetLine4);
	OuterLayout2->addWidget(WidgetLine5);
	OuterLayout2->addWidget(WidgetLine6);
	OuterLayout2->addWidget(WidgetLine7);
	OuterLayout2->addWidget(WidgetLine8);
	OuterLayout2->addWidget(WidgetLine9);

	auto *OuterWidget2 = new QWidget;
	OuterWidget2->setLayout(OuterLayout2);

	SettingsTable->setCellWidget(SettingsTable->rowCount() - 1, 1, OuterWidget2);
}
