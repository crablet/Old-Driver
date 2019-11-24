#pragma execution_character_set("utf-8")

#ifndef SUBJECTTWOSETTINGSPAGE_H
#define SUBJECTTWOSETTINGSPAGE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPalette>

#include "src/CommonUi/UiConstants.h"
#include "src/CommonUi/ShadowButton.h"
#include "PracticeSettingDetailPage.h"
#include "src/CommonUi/DeviceSettingDetailPage.h"
#include "src/ConfigHelper.hpp"

class SubjectTwoSettingsPage : public QWidget
{
    Q_OBJECT
public:
    explicit SubjectTwoSettingsPage(QWidget *parent = nullptr);

signals:

public:
	void SetBackground(const QPixmap &Background);
	bool IsAllPagesHidden() const;

private:
	void InitializeUi();
	void InitializeConnect();

private:
	ShadowButton *PracticeSettingButton, *DeviceSettingButton, *VoiceSettingButton;
	QHBoxLayout *OuterLayout, *SettingsLayout;	// 没有这个就显示不出来
	QWidget *SettingsWidget;

	PracticeSettingDetailPage *PracticeSettingsDetail;
	DeviceSettingDetailPage *DeviceSettingDetail;
};

#endif // SUBJECTTWOSETTINGSPAGE_H