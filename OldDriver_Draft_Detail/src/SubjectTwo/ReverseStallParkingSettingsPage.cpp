#include "ReverseStallParkingSettingsPage.h"

ReverseStallParkingSettingsPage::ReverseStallParkingSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void ReverseStallParkingSettingsPage::InitializeSettingsList()
{
	AddCommonListItems({ "中途停车", "车身出线", "倒库不入", "不按规定路线行驶", "停车前，两个前轮未\n过库区控制线", "全程限时210s" });
}

void ReverseStallParkingSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void ReverseStallParkingSettingsPage::mousePressEvent(QMouseEvent *e)
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
