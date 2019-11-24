#include "SettingsPageBase.h"

SettingsPageBase::SettingsPageBase(QWidget *parent) : QWidget(parent)
{
}

void SettingsPageBase::InitializeUi()
{
	TableBackgroundWidget = new QWidget(this);
	TableBackgroundWidget->setFixedSize(TableBackgroundWidgetW, TableBackgroundWidgetH);
	TableBackgroundWidget->move(TableBackgroundWidgetX, TableBackgroundWidgetY);
	TableBackgroundWidget->setStyleSheet(TableBackgroundWidgetStyle);
	TableBackgroundWidget->setAttribute(Qt::WA_StyledBackground);

	InitializeSettingsTable();
	AddSpecificItemToSettingsTable();
	SettingsTable->resizeRowsToContents();	// 根据填充的控件重新计算表格每项的行高

	OuterLayout = new QHBoxLayout(this);
	OuterLayout->addWidget(TableBackgroundWidget);
	setLayout(OuterLayout);

	ReturnButton = new QPushButton(this);
	ReturnButton->setFixedSize(SettingsPageReturnButtonW, SettingsPageReturnButtonH);
	ReturnButton->move(SettingsPageReturnButtonX + 64, SettingsPageReturnButtonY);
	ReturnButton->setIconSize(ReturnButton->size());
	ReturnButton->setIcon(QIcon(":/Pictures/PracticeSettingReturnButton.png"));
	ReturnButton->setFlat(true);
}

void SettingsPageBase::InitializeConnect()
{
	connect(ReturnButton, &QPushButton::clicked, [this]()
	{
		this->hide();
	});
}

void SettingsPageBase::InitializeSettingsTable()
{
	SettingsTable = new QTableWidget(this);
	SettingsTable->setFixedSize(SettingsTableW, SettingsTableH);
	SettingsTable->move(SettingsTableX, SettingsTableY);
	SettingsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);	// 平滑滚动

	SettingsTable->setColumnCount(2);	// 两列
	SettingsTable->setRowCount(3);		// 三行

	SettingsTable->verticalHeader()->hide();	// 取消行号
	SettingsTable->horizontalHeader()->hide();	// 取消列号
	SettingsTable->horizontalHeader()->setStretchLastSection(true);		// 让最后一列填满整个宽度

	SettingsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);	// 禁止编辑
	SettingsTable->setSelectionMode(QAbstractItemView::NoSelection);	// 禁止选中（取消选中后的背景高亮）
	SettingsTable->setFocusPolicy(Qt::NoFocus);							// 取消选中后的虚线框（有待考虑）

	SettingsTable->setCellWidget(0, 0, CreateHeaderLabel("转向灯要求"));
	SettingsTable->setCellWidget(1, 0, CreateHeaderLabel("制动要求"));
	SettingsTable->setCellWidget(2, 0, CreateHeaderLabel("速度要求"));

	AddTurnLightItem();	// “转向灯要求”的设置页
	AddDeboostItem();	// “制动要求”的设置页
	AddSpeedItem();		// “速度要求”的设置页
}

// “转向灯要求”的设置页
void SettingsPageBase::AddTurnLightItem()
{
	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateCheckBox("左转灯"));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateCheckBox("右转灯"));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateCheckBox("双闪灯"));
	WidgetLayout1->addStretch();

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateLabel("灯光要求时间："));
	WidgetLayout2->addWidget(CreateComboBox({ "3S", "2S", "1S" }));	// BUG: 字体重叠
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateLabel("灯光不开启：扣"));
	WidgetLayout2->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout2->addWidget(CreateLabel("分"));

	auto *WidgetLine2 = CreateWidget();
	WidgetLine2->setLayout(WidgetLayout2);

	/////////////////////////////////////////

	auto *WidgetLayout3 = new QHBoxLayout;
	WidgetLayout3->addWidget(CreateLabel("灯光开启后时间未到且灯光归位："));
	WidgetLayout3->addStretch();
	WidgetLayout3->addWidget(CreateLabel("扣"));
	WidgetLayout3->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout3->addWidget(CreateLabel("分"));

	auto *WidgetLine3 = CreateWidget();
	WidgetLine3->setLayout(WidgetLayout3);

	/////////////////////////////////////////

	auto *WidgetLayout4 = new QHBoxLayout;
	WidgetLayout4->addWidget(CreateLabel("（1）灯光开启时间未到就打开灯光："));
	WidgetLayout4->addStretch();
	WidgetLayout4->addWidget(CreateLabel("扣"));
	WidgetLayout4->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout4->addWidget(CreateLabel("分"));

	auto *WidgetLine4 = CreateWidget();
	WidgetLine4->setLayout(WidgetLayout4);

	/////////////////////////////////////////

	auto *WidgetLayout5 = new QHBoxLayout;
	WidgetLayout5->addWidget(CreateLabel("（2）及时开启灯光时间："));
	WidgetLayout5->addWidget(CreateComboBox({ "3S", "2S", "1S" }));
	WidgetLayout5->addStretch();

	auto *WidgetLine5 = CreateWidget();
	WidgetLine5->setLayout(WidgetLayout5);

	/////////////////////////////////////////

	auto *WidgetLayout6 = new QHBoxLayout;
	WidgetLayout6->addWidget(CreateCheckBox("是否要求进入科目前打开灯光："));
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

	SettingsTable->setCellWidget(0, 1, OuterWidget);
}

// “制动要求”的设置页
void SettingsPageBase::AddDeboostItem()
{
	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("制动时间："));
	WidgetLayout1->addWidget(CreateComboBox({ "3S", "2S", "1S" }));
	WidgetLayout1->addStretch();
	WidgetLayout1->addWidget(CreateLabel("未制动：扣"));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout1->addWidget(CreateLabel("分"));

	auto *WidgetLine1 = CreateWidget();
	WidgetLine1->setLayout(WidgetLayout1);

	/////////////////////////////////////////

	auto *WidgetLayout2 = new QHBoxLayout;
	WidgetLayout2->addWidget(CreateLabel("制动后时间未到要求："));
	WidgetLayout2->addStretch();
	WidgetLayout2->addWidget(CreateLabel("扣"));
	WidgetLayout2->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout2->addWidget(CreateLabel("分"));

	auto *WidgetLine2 = CreateWidget();
	WidgetLine2->setLayout(WidgetLayout2);

	/////////////////////////////////////////

	auto *WidgetLayout3 = new QHBoxLayout;
	WidgetLayout3->addWidget(CreateLabel("（1）制动时间未到就离开："));
	WidgetLayout3->addStretch();
	WidgetLayout3->addWidget(CreateLabel("扣"));
	WidgetLayout3->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout3->addWidget(CreateLabel("分"));

	auto *WidgetLine3 = CreateWidget();
	WidgetLine3->setLayout(WidgetLayout3);

	/////////////////////////////////////////

	auto *WidgetLayout4 = new QHBoxLayout;
	WidgetLayout4->addWidget(CreateLabel("（2）及时踩下制动时间："));
	WidgetLayout4->addWidget(CreateComboBox({ "3S", "2S", "1S" }));
	WidgetLayout4->addStretch();

	auto *WidgetLine4 = CreateWidget();
	WidgetLine4->setLayout(WidgetLayout4);

	/////////////////////////////////////////

	auto *WidgetLayout5 = new QHBoxLayout;
	WidgetLayout5->addWidget(CreateCheckBox("是否要求进入科目前制动："));
	WidgetLayout5->addStretch();
	WidgetLayout5->addWidget(CreateLabel("扣"));
	WidgetLayout5->addWidget(CreateComboBox({ "100", "50" }));
	WidgetLayout5->addWidget(CreateLabel("分"));

	auto *WidgetLine5 = CreateWidget();
	WidgetLine5->setLayout(WidgetLayout5);

	/////////////////////////////////////////

	auto *OuterLayout = new QVBoxLayout;
	OuterLayout->addWidget(WidgetLine1);
	OuterLayout->addWidget(WidgetLine2);
	OuterLayout->addWidget(WidgetLine3);
	OuterLayout->addWidget(WidgetLine4);
	OuterLayout->addWidget(WidgetLine5);

	auto *OuterWidget = new QWidget;
	OuterWidget->setLayout(OuterLayout);

	SettingsTable->setCellWidget(1, 1, OuterWidget);
}

// “速度要求”的设置页
void SettingsPageBase::AddSpeedItem()
{
	auto *WidgetLayout1 = new QHBoxLayout;
	WidgetLayout1->addWidget(CreateLabel("踩下制动后速度范围："));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "90" }));
	WidgetLayout1->addWidget(CreateLabel("—"));
	WidgetLayout1->addWidget(CreateComboBox({ "100", "90" }));
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
	WidgetLayout2->addWidget(CreateComboBox({ "100", "90" }));
	WidgetLayout2->addWidget(CreateLabel("—"));
	WidgetLayout2->addWidget(CreateComboBox({ "100", "90" }));
	WidgetLayout2->addWidget(CreateLabel("1/min x1000"));
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

void SettingsPageBase::SetBackground(const QPixmap &BackgroundPicture)
{
	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), BackgroundPicture);
	setPalette(Pal);
}
