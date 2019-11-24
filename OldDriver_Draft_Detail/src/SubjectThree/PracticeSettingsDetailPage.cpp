#include "PracticeSettingsDetailPage.h"

PracticeSettingsDetailPage::PracticeSettingsDetailPage(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void PracticeSettingsDetailPage::InitializeUi()
{
	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QColor(60, 65, 73));
	setPalette(Pal);

	setFixedSize(DeviceW, DeviceH);

	InnerWidget = new QWidget(this);
	InnerWidget->setStyleSheet(PracticeSettingDetailPageWidgetStyle);
	InnerWidget->setFixedSize(DeviceW - 14, DeviceH - 14);	// 左右留够距离
	InnerWidget->move(7, 7);	// 左右留够距离
	InnerLayout = new QGridLayout(InnerWidget);

	// 设置返回按钮，注意控件叠放次序，这个返回按钮应该在最底层的
	ReturnButton = new QPushButton(this);
	ReturnButton->setFixedSize(PracticeSettingReturnButtonW, PracticeSettingReturnButtonH);
	ReturnButton->move(PracticeSettingReturnButtonX, PracticeSettingReturnButtonY);
	ReturnButton->setIconSize(ReturnButton->size());
	ReturnButton->setIcon(QIcon(":/Pictures/PracticeSettingReturnButton.png"));
	ReturnButton->setFlat(true);

	InitializeSettingsPages();

	auto SlotsFunctions
		= { ShowPageOf< TurnAroundSettingsPage >,
			ShowPageOf< MeetingCarSettingsPage >,
			ShowPageOf< OvertakingSettingsPage >,
			ShowPageOf< AddAndSubtractSpeedSettingsPage >,
			ShowPageOf< TurningRightSettingsPage >,
			ShowPageOf< TurningLeftSettingsPage >,
			ShowPageOf< PedestrainCrossingSettingsPage >,
			ShowPageOf< BusStopSettingsPage >,
			ShowPageOf< SchoolSettingsPage >,
			ShowPageOf< StraightDrivingSettingsPage >,
			ShowPageOf< StraightIntersectionSettingsPage >,
			ShowPageOf< ChangeLanesSettingsPage >,
			ShowPageOf< PollingOverSettingsPage > };
	for (const auto &f : SlotsFunctions)
	{
		Slots.emplace_back(f);
	}

	// 设置中间项目选项按钮
	std::vector<QString> Vec
	{ "掉头", "会车", "超车", "加减挡", "路口右转", "路口左转", "人行横道", 
	  "公交车站", "通过学校", "直线行驶", "直行路口", "变更车道", "靠边停车", 
	  "通用设置", "上车准备", "起步" };
	for (int i = 0; i < static_cast<int>(Vec.size()); ++i)
	{
		auto *Btn = new ShadowButton(this);
		Btn->setText(Vec[i]);
		Btn->setFixedSize(PracticeSettingDetailPageButtonW, PracticeSettingDetailPageButtonH);
		Btn->setStyleSheet(PracticeSettingDetailPageButtonStyle);

		// 这里到时候要完善函数
		if (i < SlotsFunctions.size())
		{
			connect(Btn, &QPushButton::clicked, this, Slots[i]);
		}

		InnerLayout->addWidget(Btn, i / 4, i % 4);
	}
	InnerWidget->setLayout(InnerLayout);
	InnerWidget->show();
}

void PracticeSettingsDetailPage::InitializeConnect()
{
	// 点击返回按钮后应该返回到上一页面
	connect(ReturnButton, &QPushButton::clicked, [this]()
	{
		this->hide();
	});
}

void PracticeSettingsDetailPage::InitializeSettingsPages()
{
	TurnAroundSettingsPage_ = new TurnAroundSettingsPage(this);
	TurnAroundSettingsPage_->setFixedSize(this->size());
	TurnAroundSettingsPage_->hide();

	MeetingCarSettingsPage_ = new MeetingCarSettingsPage(this);
	MeetingCarSettingsPage_->setFixedSize(this->size());
	MeetingCarSettingsPage_->hide();

	OvertakingSettingsPage_ = new OvertakingSettingsPage(this);
	OvertakingSettingsPage_->setFixedSize(this->size());
	OvertakingSettingsPage_->hide();

	AddAndSubtractSpeedSettingsPage_ = new AddAndSubtractSpeedSettingsPage(this);
	AddAndSubtractSpeedSettingsPage_->setFixedSize(this->size());
	AddAndSubtractSpeedSettingsPage_->hide();

	TurningRightSettingsPage_ = new TurningRightSettingsPage(this);
	TurningRightSettingsPage_->setFixedSize(this->size());
	TurningRightSettingsPage_->hide();

	TurningLeftSettingsPage_ = new TurningLeftSettingsPage(this);
	TurningLeftSettingsPage_->setFixedSize(this->size());
	TurningLeftSettingsPage_->hide();

	PedestrainCrossingSettingsPage_ = new PedestrainCrossingSettingsPage(this);
	PedestrainCrossingSettingsPage_->setFixedSize(this->size());
	PedestrainCrossingSettingsPage_->hide();

	BusStopSettingsPage_ = new BusStopSettingsPage(this);
	BusStopSettingsPage_->setFixedSize(this->size());
	BusStopSettingsPage_->hide();

	SchoolSettingsPage_ = new SchoolSettingsPage(this);
	SchoolSettingsPage_->setFixedSize(this->size());
	SchoolSettingsPage_->hide();

	StraightDrivingSettingsPage_ = new StraightDrivingSettingsPage(this);
	StraightDrivingSettingsPage_->setFixedSize(this->size());
	StraightDrivingSettingsPage_->hide();

	StraightIntersectionSettingsPage_ = new StraightIntersectionSettingsPage(this);
	StraightIntersectionSettingsPage_->setFixedSize(this->size());
	StraightIntersectionSettingsPage_->hide();

	ChangeLanesSettingsPage_ = new ChangeLanesSettingsPage(this);
	ChangeLanesSettingsPage_->setFixedSize(this->size());
	ChangeLanesSettingsPage_->hide();

	PollingOverSettingsPage_ = new PollingOverSettingsPage(this);
	PollingOverSettingsPage_->setFixedSize(this->size());
	PollingOverSettingsPage_->hide();
}
