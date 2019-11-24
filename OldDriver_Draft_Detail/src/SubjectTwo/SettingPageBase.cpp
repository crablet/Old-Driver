#include "SettingPageBase.h"

SettingPageBase::SettingPageBase(QWidget *parent)
	: QWidget(parent), ItemSize(QSize(0, 72))
{
}

void SettingPageBase::InitializeUi()
{
	ListBackgroundWidget = new QWidget(this);
	ListBackgroundWidget->setFixedSize(ListBackgroundWidgetW, ListBackgroundWidgetH);
	ListBackgroundWidget->move(ListBackgroundWidgetX, ListBackgroundWidgetY);
	ListBackgroundWidget->setStyleSheet(ListBackgroundWidgetStyle);
	ListBackgroundWidget->setAttribute(Qt::WA_StyledBackground);

	SettingsList = new QListWidget(this);
	SettingsList->setFixedSize(SettingsListW, SettingsListH);
	SettingsList->move(SettingsListX, SettingsListY);

	InitializeSettingsList();

	OuterLayout = new QHBoxLayout(this);
	OuterLayout->addWidget(ListBackgroundWidget);
	setLayout(OuterLayout);

	ReturnButton = new QPushButton(this);
	ReturnButton->setFixedSize(SettingsPageReturnButtonW, SettingsPageReturnButtonH);
	ReturnButton->move(SettingsPageReturnButtonX, SettingsPageReturnButtonY);
	ReturnButton->setIconSize(ReturnButton->size());
	ReturnButton->setIcon(QIcon(":/Pictures/PracticeSettingReturnButton.png"));
	ReturnButton->setFlat(true);
}

void SettingPageBase::InitializeConnect()
{
	connect(ReturnButton, &QPushButton::clicked, [this]()
	{
		this->hide();
	});
}

void SettingPageBase::SetItemSize(const QSize &Size)
{
	ItemSize = Size;
}

void SettingPageBase::ResetItemSize()
{
	ItemSize = QSize(0, 72);
}

void SettingPageBase::SetBackground(const QPixmap &BackgroundPicture)
{
	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), BackgroundPicture);
	setPalette(Pal);
}
