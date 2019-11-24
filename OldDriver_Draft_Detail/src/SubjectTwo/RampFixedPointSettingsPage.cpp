#include "RampFixedPointSettingsPage.h"

RampFixedPointSettingsPage::RampFixedPointSettingsPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void RampFixedPointSettingsPage::InitializeSettingsList()
{
	SetItemSize(QSize(0, 114));
	AddCommonListItems({ "车辆停止后，车身距\n离路边缘线超过30cm\n但未超过50cm", 
						 "车辆停止后，车身距\n离路边缘线超过50cm", "停车后，未拉紧驻车\n制动器",
						 "车辆停止后，车前保\n险杠未到停车线，前\n后超出50cm", 
						 "车辆停止后，车前保\n险杠未到停车线，前\n后未超出50cm",
						 "车辆后溜大于30cm", "车辆后溜小于30cm", "车辆停止后，起步时\n间规定15s" });
}

void RampFixedPointSettingsPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

void RampFixedPointSettingsPage::mousePressEvent(QMouseEvent *e)
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
