#include "RightAngleTurnSettingsPage.h"

RightAngleTurnSettingsPage::RightAngleTurnSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void RightAngleTurnSettingsPage::InitializeSettingsList()
{
	AddCommonListItems({ "转弯前不使用或错误\n使用转向灯", "转弯后不关闭转向灯", "中途停车", "车轮触压道路边缘线" });
}

void RightAngleTurnSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void RightAngleTurnSettingsPage::mousePressEvent(QMouseEvent *e)
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
