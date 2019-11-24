#pragma execution_character_set("utf-8")

#ifndef SETTINGSPAGEBASE_H
#define SETTINGSPAGEBASE_H

#include <QHeaderView>
#include <QWidget>
#include <QTableWidget>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QString>
#include <QSizePolicy>
#include <QSpacerItem>
#include <QStringList>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "src/CommonUi/UiConstants.h"

class SettingsPageBase : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsPageBase(QWidget *parent = nullptr);
	virtual ~SettingsPageBase() = default;

signals:

public slots:

public:
	void SetBackground(const QPixmap &BackgroundPicture);

private:
	void AddTurnLightItem();	// “转向灯要求”的设置页
	void AddDeboostItem();		// “制动要求”的设置页
	void AddSpeedItem();		// “速度要求”的设置页

protected:
	void InitializeUi();
	virtual void InitializeConnect();
	virtual void InitializeSettingsTable();
	virtual void AddSpecificItemToSettingsTable() = 0;

	auto* CreateCheckBox(const QString &Str)
	{
		auto *CheckBox = new QCheckBox(Str);
		CheckBox->setLayoutDirection(Qt::RightToLeft);
		CheckBox->setStyleSheet(TableItemCheckBoxStyle);

		return CheckBox;
	}

	auto* CreateLabel(const QString &Str)
	{
		auto *Label = new QLabel(Str);
		Label->setStyleSheet(TableItemLabelStyle);

		return Label;
	}

	auto* CreateHeaderLabel(const QString& Str)
	{
		auto* Label = new QLabel(Str);
		Label->setStyleSheet("QLabel {font-size: 24px; font-family: SimHei; color: rgba(16, 16, 16, 1)}");
		Label->setAlignment(Qt::AlignCenter);
		Label->adjustSize();	// 根据QLabel内中包含的文字换行情况自适应大小

		return Label;
	}

	auto* CreateComboBox(const QStringList &List, int Width = 64)
	{
		auto *ComboBox = new QComboBox;
		ComboBox->setStyleSheet(ListItemWidgetStyle);
		ComboBox->setFixedWidth(Width);
		ComboBox->addItems(List);

		return ComboBox;
	}

	auto* CreateWidget()
	{
		auto *Widget = new QWidget;
		Widget->setMaximumWidth(700);

		return Widget;
	}

protected:
	QWidget *TableBackgroundWidget;
	QTableWidget *SettingsTable;
	QHBoxLayout *OuterLayout;
	QPushButton *ReturnButton;
};

#endif // SETTINGSPAGEBASE_H