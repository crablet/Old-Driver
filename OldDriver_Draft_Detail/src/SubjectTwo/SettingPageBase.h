#pragma execution_character_set("utf-8")

#ifndef SETTINGPAGEBASE_H
#define SETTINGPAGEBASE_H

#include <vector>
#include <utility>
#include <initializer_list>

#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <QSize>
#include <QComboBox>
#include <QCheckBox>
#include <QStringList>

#include "src/CommonUi/UiConstants.h"
#include "src/CommonUi/ListItemWidget.h"

#include "src/ConfigHelper.hpp"

// 所有科二详细设置页的基类，我们只需继承它然后重写InitializeSettingsList()函数即可，
// 记得在构造函数中调用Ui和connect的初始化函数
class SettingPageBase : public QWidget
{
    Q_OBJECT
public:
    explicit SettingPageBase(QWidget *parent = nullptr);
	virtual ~SettingPageBase() = default;

public:
	void SetBackground(const QPixmap &BackgroundPicture);

	auto& GetLabels() const noexcept
	{
		return Labels;
	}

	auto &GetComboxs() const noexcept
	{
		return Comboxs;
	}

	auto& GetCheckBoxs() const noexcept
	{
		return CheckBoxs;
	}

protected:
	void InitializeUi();
	virtual void InitializeConnect();
	virtual void InitializeSettingsList() = 0;

	void SetItemSize(const QSize &Size);
	void ResetItemSize();

	template <typename T>
	auto* CreateLabel(T &&Str)
	{
		auto *Label = new QLabel(std::forward<T>(Str));
		Labels.push_back(Label);

		return Label;
	}

	auto* CreateComboBox()
	{
		auto *Combox = new QComboBox;
		Combox->addItems({ "100", "10", "5" });
		Combox->setFixedWidth(96);
		Comboxs.push_back(Combox);

		return Combox;
	}

	auto* CreateCheckBox()
	{
		auto *CheckBox = new QCheckBox("此评测是否生效");
		CheckBox->setStyleSheet(ListItemCheckBoxStyle);
		CheckBox->setLayoutDirection(Qt::RightToLeft);	// 使得框在右边，文字在左边
		CheckBox->setChecked(true);
		CheckBoxs.push_back(CheckBox);

		return CheckBox;
	}

	auto* CreateListWidgetItem()	// 创建容纳列表项的容器
	{
		auto *ListItem = new QListWidgetItem(SettingsList);
		ListItem->setSizeHint(ItemSize);	// 不加这一行就显示不出列表项

		return ListItem;
	}

	template <typename T>
	void AddCommonListItems(std::initializer_list<T> &&List)	// 向列表中添加以List中的每一项开头的普通列表项
	{
		for (auto &&Str : List)
		{
			auto *Widget = new ListItemWidget;
			Widget->setStyleSheet(ListItemWidgetStyle);
			Widget->Insert(CreateLabel(std::move(Str)), CreateComboBox(), CreateCheckBox());

			auto *Item = CreateListWidgetItem();
			SettingsList->addItem(Item);
			SettingsList->setItemWidget(Item, Widget);
		}
	}

protected:
	QListWidget *SettingsList;
	QWidget *ListBackgroundWidget;
	QHBoxLayout *OuterLayout;
	QPushButton *ReturnButton;

	std::vector<QLabel*> Labels;
	std::vector<QComboBox*> Comboxs;
	std::vector<QCheckBox*> CheckBoxs;

	QSize ItemSize;
};

#endif // SETTINGPAGEBASE_H