#include "TunnelDrivingSettingsPage.h"

TunnelDrivingSettingsPage::TunnelDrivingSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void TunnelDrivingSettingsPage::InitializeSettingsList()
{
	AddCommonListItems({ "车速范围5~10km/h", "驶入隧道时未减速", "驶入隧道时未开启前\n照灯", "驶入隧道后不按规定\n车道行驶、变道",
						 "驶入隧道出（入）口\n时未鸣喇叭", "驶出隧道后未关闭前\n照灯", "中途停车" });
}

void TunnelDrivingSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void TunnelDrivingSettingsPage::mousePressEvent(QMouseEvent *e)
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
