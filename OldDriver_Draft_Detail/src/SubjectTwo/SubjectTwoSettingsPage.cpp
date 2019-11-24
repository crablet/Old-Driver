#include "SubjectTwoSettingsPage.h"

SubjectTwoSettingsPage::SubjectTwoSettingsPage(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

bool SubjectTwoSettingsPage::IsAllPagesHidden() const
{
	return PracticeSettingsDetail->isHidden() && DeviceSettingDetail->isHidden();
}

void SubjectTwoSettingsPage::InitializeUi()
{	
	SettingsLayout = new QHBoxLayout(this);
	SettingsLayout->setMargin(0);

	SettingsWidget = new QWidget(this);
	SettingsWidget->setAttribute(Qt::WA_StyledBackground);	// 当子控件（自己）是QWidget时，需要有这一行，不然样式表无效，会和父控件的样式一
	SettingsWidget->setStyleSheet(SettingsWidgetStyle);
	SettingsWidget->setLayout(SettingsLayout);
	SettingsWidget->setFixedSize(SettingsWidgetW, SettingsWidgetH);
	SettingsWidget->move(SettingsWidgetX, SettingsWidgetY);

	PracticeSettingButton = new ShadowButton(this);
	PracticeSettingButton->setFixedSize(PracticeSettingButtonW, PracticeSettingButtonH);
	PracticeSettingButton->move(PracticeSettingButtonX, PracticeSettingButtonY);
	PracticeSettingButton->setStyleSheet(SubjectTwoSettingsButtonStyle);
	PracticeSettingButton->setText("练习设置");

	DeviceSettingButton = new ShadowButton(this);
	DeviceSettingButton->setFixedSize(DeviceSettingButtonW, DeviceSettingButtonH);
	DeviceSettingButton->move(DeviceSettingButtonX, DeviceSettingButtonY);
	DeviceSettingButton->setStyleSheet(SubjectTwoSettingsButtonStyle);
	DeviceSettingButton->setText("配件设置");

	VoiceSettingButton = new ShadowButton(this);
	VoiceSettingButton->setFixedSize(VoiceSettingButtonW, VoiceSettingButtonH);
	VoiceSettingButton->move(VoiceSettingButtonX, VoiceSettingButtonY);
	VoiceSettingButton->setStyleSheet(SubjectTwoSettingsButtonStyle);
	VoiceSettingButton->setText("语音设置");

	SettingsLayout->addWidget(PracticeSettingButton);
	SettingsLayout->addWidget(DeviceSettingButton);
	SettingsLayout->addWidget(VoiceSettingButton);

	OuterLayout = new QHBoxLayout(this);
	OuterLayout->setMargin(0);
	OuterLayout->addWidget(SettingsWidget);
	setLayout(OuterLayout);

	PracticeSettingsDetail = new PracticeSettingDetailPage(this);
	PracticeSettingsDetail->hide();

	DeviceSettingDetail = new DeviceSettingDetailPage(this);
	DeviceSettingDetail->setFixedSize(DeviceW, DeviceH);	// 奇奇怪怪的问题，必须加上这一行
	DeviceSettingDetail->hide();
}

void SubjectTwoSettingsPage::InitializeConnect()
{
	// 点击“练习设置”按钮出现设置页
	connect(PracticeSettingButton, &QPushButton::clicked, [this]()
	{
		PracticeSettingsDetail->show();
	});

	// 点击“配件设置”按钮出现设置页
	connect(DeviceSettingButton, &QPushButton::clicked, [this]()
	{
		auto Background = QPixmap
								(GaussianBlur(grab(QRect(QPoint(0, 0), size()))
											 .scaled(size() / 9)))
								.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

		DeviceSettingDetail->SetBackground(Background);
		DeviceSettingDetail->show();
	});
}

void SubjectTwoSettingsPage::SetBackground(const QPixmap &BackgroundPicture)
{
	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), BackgroundPicture);
	setPalette(Pal);
}
