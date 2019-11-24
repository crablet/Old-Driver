#include "SideParkingSettingsPage.h"

SideParkingSettingsPage::SideParkingSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void SideParkingSettingsPage::InitializeSettingsList()
{
	AddCommonListItems({ "行驶中车轮触压车道\n边缘线（每次）", "行驶中车身触碰库区\n边线（每次）",
						 "车辆入库停止后，车\n身出线", "中途停车", "全程限时90s" });
}

void SideParkingSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void SideParkingSettingsPage::mousePressEvent(QMouseEvent *e)
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
