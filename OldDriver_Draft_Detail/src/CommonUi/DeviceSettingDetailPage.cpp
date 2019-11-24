#include "DeviceSettingDetailPage.h"

DeviceSettingDetailPage::DeviceSettingDetailPage(QWidget *parent) : SettingPageBase(parent)
{
	InitializeUi();
	InitializeConnect();
}

void DeviceSettingDetailPage::InitializeConnect()
{
	SettingPageBase::InitializeConnect();
	connect(ReturnButton, &QPushButton::clicked, this, [this]()
	{
		Config::Save<Type>(this);
	});
}

// 看情况要不要弄成循环的形式
void DeviceSettingDetailPage::InitializeSettingsList()
{
	/**********************************************************/

	auto *Widget = new ListItemWidget;
	Widget->setStyleSheet(ListItemWidgetStyle);
	Widget->Insert(CreateLabel("指纹仪"), CreateCheckBox());

	auto *Item = CreateListWidgetItem();
	SettingsList->addItem(Item);
	SettingsList->setItemWidget(Item, Widget);

	/**********************************************************/

	Widget = new ListItemWidget;
	Widget->setStyleSheet(ListItemWidgetStyle);
	Widget->Insert(CreateLabel("身份识别器"), CreateCheckBox());

	Item = CreateListWidgetItem();
	SettingsList->addItem(Item);
	SettingsList->setItemWidget(Item, Widget);

	/**********************************************************/
	
	Widget = new ListItemWidget;
	Widget->setStyleSheet(ListItemWidgetStyle);
	Widget->Insert(CreateLabel("人脸识别摄像头"), CreateCheckBox());

	Item = CreateListWidgetItem();
	SettingsList->addItem(Item);
	SettingsList->setItemWidget(Item, Widget);

	/**********************************************************/

	// 如果不是第一次启动，则读取配置然后顺便初始化了选项
	if (Config::IsFirstRun())
	{
		Config::CreateInitialConfigFile();
	}
	else
	{
		Config::Load<Type>(this);
	}
}

void DeviceSettingDetailPage::mousePressEvent(QMouseEvent *e)
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

			return;
		}
	}

	QWidget::mousePressEvent(e);
}
