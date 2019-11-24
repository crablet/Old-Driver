#include "NarrowRoadTurnAroundSettingsPage.h"

NarrowRoadTurnAroundSettingsPage::NarrowRoadTurnAroundSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void NarrowRoadTurnAroundSettingsPage::InitializeSettingsList()
{
	AddCommonListItems({ "车轮压边缘线", "三进二退未完成掉头", "项目完成时间" });
}

void NarrowRoadTurnAroundSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void NarrowRoadTurnAroundSettingsPage::mousePressEvent(QMouseEvent *e)
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
