#include "AddAndSubtractSpeedSettingsPage.h"

AddAndSubtractSpeedSettingsPage::AddAndSubtractSpeedSettingsPage(QWidget *parent) : SettingsPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void AddAndSubtractSpeedSettingsPage::mousePressEvent(QMouseEvent *e)
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

void AddAndSubtractSpeedSettingsPage::InitializeConnect()
{
	SettingsPageBase::InitializeConnect();
}

void AddAndSubtractSpeedSettingsPage::AddSpecificItemToSettingsTable()
{
	SettingsTable->removeRow(SettingsTable->rowCount() - 1);	// 先删去原有的最后一行
	SettingsTable->insertRow(SettingsTable->rowCount());		// 然后加上一行，相当于把最后一行清空

	SettingsTable->setCellWidget(2, 0, CreateLabel("速度与挡位"));

	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("加减挡顺序："));
	WidgetLayout1->addWidget(CreateComboBox({ "23432" }, 96));
	WidgetLayout1->addStretch();

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateCheckBox("预报挡位"));
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateCheckBox("当前挡位"));
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateCheckBox("不播报挡位"));

	auto *WidgetLine2 = CreateWidget();
	WidgetLine2->setLayout(WidgetLayout2);

	/////////////////////////////////////////

	auto *WidgetLayout3 = new QHBoxLayout;
	WidgetLayout3->addWidget(CreateLabel("加挡："));

	auto *WidgetLine3 = CreateWidget();
	WidgetLine3->setLayout(WidgetLayout3);

	/////////////////////////////////////////

	auto *WidgetLayout4 = new QHBoxLayout;
	WidgetLayout4->addStretch();

	WidgetLayout4->addWidget(CreateLabel("1挡加2挡"));
	WidgetLayout4->addWidget(CreateComboBox({ "1", "2" }));	// 以后加多很多个选项
	WidgetLayout4->addWidget(CreateLabel("-"));
	WidgetLayout4->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout4->addStretch();

	WidgetLayout4->addWidget(CreateLabel("2挡加3挡"));
	WidgetLayout4->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout4->addWidget(CreateLabel("-"));
	WidgetLayout4->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout4->addStretch();

	auto *WidgetLine4 = CreateWidget();
	WidgetLine4->setLayout(WidgetLayout4);

	/////////////////////////////////////////

	auto *WidgetLayout5 = new QHBoxLayout;
	WidgetLayout5->addStretch();

	WidgetLayout5->addWidget(CreateLabel("3挡加4挡"));
	WidgetLayout5->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout5->addWidget(CreateLabel("-"));
	WidgetLayout5->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout5->addStretch();

	WidgetLayout5->addWidget(CreateLabel("4挡加5挡"));
	WidgetLayout5->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout5->addWidget(CreateLabel("-"));
	WidgetLayout5->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout5->addStretch();

	auto *WidgetLine5 = CreateWidget();
	WidgetLine5->setLayout(WidgetLayout5);

	/////////////////////////////////////////

	auto *WidgetLayout6 = new QHBoxLayout;
	WidgetLayout6->addWidget(CreateLabel("减挡："));

	auto *WidgetLine6 = CreateWidget();
	WidgetLine6->setLayout(WidgetLayout6);

	/////////////////////////////////////////

	auto *WidgetLayout7 = new QHBoxLayout;
	WidgetLayout7->addStretch();

	WidgetLayout7->addWidget(CreateLabel("5挡减4挡"));
	WidgetLayout7->addWidget(CreateComboBox({ "1", "2" }));	// 以后加多很多个选项
	WidgetLayout7->addWidget(CreateLabel("-"));
	WidgetLayout7->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout7->addStretch();

	WidgetLayout7->addWidget(CreateLabel("4挡减3挡"));
	WidgetLayout7->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout7->addWidget(CreateLabel("-"));
	WidgetLayout7->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout7->addStretch();

	auto *WidgetLine7 = CreateWidget();
	WidgetLine7->setLayout(WidgetLayout7);

	/////////////////////////////////////////

	auto *WidgetLayout8 = new QHBoxLayout;
	WidgetLayout8->addStretch();

	WidgetLayout8->addWidget(CreateLabel("3挡减2挡"));
	WidgetLayout8->addWidget(CreateComboBox({ "1", "2" }));	// 以后加多很多个选项
	WidgetLayout8->addWidget(CreateLabel("-"));
	WidgetLayout8->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout8->addStretch();

	WidgetLayout8->addWidget(CreateLabel("2挡减1挡"));
	WidgetLayout8->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout8->addWidget(CreateLabel("-"));
	WidgetLayout8->addWidget(CreateComboBox({ "1", "2" }));
	WidgetLayout8->addStretch();

	auto *WidgetLine8 = CreateWidget();
	WidgetLine8->setLayout(WidgetLayout8);

	/////////////////////////////////////////

	auto *OuterLayout = new QVBoxLayout;
	OuterLayout->addWidget(WidgetLine1);
	OuterLayout->addWidget(WidgetLine2);
	OuterLayout->addWidget(WidgetLine3);
	OuterLayout->addWidget(WidgetLine4);
	OuterLayout->addWidget(WidgetLine5);
	OuterLayout->addWidget(WidgetLine6);
	OuterLayout->addWidget(WidgetLine7);
	OuterLayout->addWidget(WidgetLine8);

	auto *OuterWidget = new QWidget;
	OuterWidget->setLayout(OuterLayout);

	SettingsTable->setCellWidget(2, 1, OuterWidget);
}
