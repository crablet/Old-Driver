#include "EmergencyTreatmentSettingsPage.h"

EmergencyTreatmentSettingsPage::EmergencyTreatmentSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void EmergencyTreatmentSettingsPage::InitializeSettingsList()
{
	AddCommonListItems({ "停车后未开启危险报\n警闪光灯", "未及时制动" });
}

void EmergencyTreatmentSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void EmergencyTreatmentSettingsPage::mousePressEvent(QMouseEvent *e)
{
	// 点击旁边空白处隐藏设置页面
	if (!this->isHidden())
	{
		int x = e->pos().x();
		int y = e->pos().y();
		if (!(x >= ListBackgroundWidgetX && x <= ListBackgroundWidgetX + ListBackgroundWidgetW
			&& y >= ListBackgroundWidgetY && y <= ListBackgroundWidgetY + ListBackgroundWidgetH))
		{
			this->hide();

			Config::Save<Type>(this);
		}
	}

	QWidget::mousePressEvent(e);
}
