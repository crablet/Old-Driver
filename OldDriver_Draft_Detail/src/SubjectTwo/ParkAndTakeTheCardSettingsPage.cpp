#include "ParkAndTakeTheCardSettingsPage.h"

ParkAndTakeTheCardSettingsPage::ParkAndTakeTheCardSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void ParkAndTakeTheCardSettingsPage::InitializeSettingsList()
{
	AddCommonListItems({ "停车后未挂空档", "停车后未拉紧驻车制\n动器", 
						 "停车后，车身距道路\n边缘线大于50cm",
						 "停车后，倒车校正位\n置",
						 "车轮压道路边缘线",
						 "驶过停车取卡位置未\n停车"});
}

void ParkAndTakeTheCardSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void ParkAndTakeTheCardSettingsPage::mousePressEvent(QMouseEvent *e)
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

