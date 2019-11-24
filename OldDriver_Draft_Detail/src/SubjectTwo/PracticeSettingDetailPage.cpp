#include "PracticeSettingDetailPage.h"

PracticeSettingDetailPage::PracticeSettingDetailPage(QWidget *parent) 
	: QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void PracticeSettingDetailPage::InitializeUi()
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

	// 存储各个按钮单击后展示详细设置界面的函数的变量
	auto SlotsFunctions
		= { ShowPageOf<StartingActionsSettingsPage>,
			ShowPageOf<ReverseStallParkingSettingsPage>,
			ShowPageOf<SideParkingSettingsPage>,
			ShowPageOf<RampFixedPointSettingsPage>,
			ShowPageOf<RightAngleTurnSettingsPage>,
			ShowPageOf<CurveDrivingSettingsPage>,
			ShowPageOf<NarrowRoadTurnAroundSettingsPage>,
			ShowPageOf<ParkAndTakeTheCardSettingsPage>,
			ShowPageOf<EmergencyTreatmentSettingsPage>,
			ShowPageOf<TunnelDrivingSettingsPage> };
	for (const auto &f : SlotsFunctions)
	{
		Slots.emplace_back(f);
	}

	// 设置中间项目选项按钮
	std::vector<QString> Vec
	{ "起步动作", "倒车入库", "侧方停车", "坡道定点", "直角转弯", "曲线行驶", "窄路掉头", "停车取卡", "紧急处置", "隧道行驶" };
	for (int i = 0; i < static_cast<int>(Vec.size()); ++i)
	{
		auto *Btn = new ShadowButton(this);
		Btn->setText(Vec[i]);
		Btn->setFixedSize(PracticeSettingDetailPageButtonW, PracticeSettingDetailPageButtonH);
		Btn->setStyleSheet(PracticeSettingDetailPageButtonStyle);

		connect(Btn, &QPushButton::clicked, this, Slots[i]);

		InnerLayout->addWidget(Btn, i / 4, i % 4);
	}
	InnerWidget->setLayout(InnerLayout);
	InnerWidget->show();
}

void PracticeSettingDetailPage::InitializeConnect()
{
	// 点击返回按钮后应该返回到上一页面
	connect(ReturnButton, &QPushButton::clicked, [this]()
	{
		this->hide();
	});
}

void PracticeSettingDetailPage::InitializeSettingsPages()
{
	StartingActionsSettingsPage_ = new StartingActionsSettingsPage(this);
	StartingActionsSettingsPage_->setFixedSize(this->size());
	StartingActionsSettingsPage_->hide();

	ReverseStallParkingSettingsPage_ = new ReverseStallParkingSettingsPage(this);
	ReverseStallParkingSettingsPage_->setFixedSize(this->size());
	ReverseStallParkingSettingsPage_->hide();

	SideParkingSettingsPage_ = new SideParkingSettingsPage(this);
	SideParkingSettingsPage_->setFixedSize(this->size());
	SideParkingSettingsPage_->hide();

	RampFixedPointSettingsPage_ = new RampFixedPointSettingsPage(this);
	RampFixedPointSettingsPage_->setFixedSize(this->size());
	RampFixedPointSettingsPage_->hide();

	RightAngleTurnSettingsPage_ = new RightAngleTurnSettingsPage(this);
	RightAngleTurnSettingsPage_->setFixedSize(this->size());
	RightAngleTurnSettingsPage_->hide();

	CurveDrivingSettingsPage_ = new CurveDrivingSettingsPage(this);
	CurveDrivingSettingsPage_->setFixedSize(this->size());
	CurveDrivingSettingsPage_->hide();

	NarrowRoadTurnAroundSettingsPage_ = new NarrowRoadTurnAroundSettingsPage(this);
	NarrowRoadTurnAroundSettingsPage_->setFixedSize(this->size());
	NarrowRoadTurnAroundSettingsPage_->hide();

	ParkAndTakeTheCardSettingsPage_ = new ParkAndTakeTheCardSettingsPage(this);
	ParkAndTakeTheCardSettingsPage_->setFixedSize(this->size());
	ParkAndTakeTheCardSettingsPage_->hide();

	EmergencyTreatmentSettingsPage_ = new EmergencyTreatmentSettingsPage(this);
	EmergencyTreatmentSettingsPage_->setFixedSize(this->size());
	EmergencyTreatmentSettingsPage_->hide();

	TunnelDrivingSettingsPage_ = new TunnelDrivingSettingsPage(this);
	TunnelDrivingSettingsPage_->setFixedSize(this->size());
	TunnelDrivingSettingsPage_->hide();

	if (Config::IsFirstRun())	// 如果是第一次运行，则生成默认的设置项Json文件
	{
		Config::CreateInitialConfigFile();
	}
	else	// 否则直接读取上一次的Json文件获取设置
	{
		Config::Load<Subject::Two::PracticeSettings::StartingActions>(StartingActionsSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::ReverseStallParking>(ReverseStallParkingSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::SideParking>(SideParkingSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::RampFixedPoint>(RampFixedPointSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::RightAngleTurn>(RightAngleTurnSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::CurveDriving>(CurveDrivingSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::NarrowRoadTurnAround>(NarrowRoadTurnAroundSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::ParkAndTakeTheCard>(ParkAndTakeTheCardSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::EmergencyTreatment>(EmergencyTreatmentSettingsPage_);
		Config::Load<Subject::Two::PracticeSettings::TunnelDriving>(TunnelDrivingSettingsPage_);
	}
}
