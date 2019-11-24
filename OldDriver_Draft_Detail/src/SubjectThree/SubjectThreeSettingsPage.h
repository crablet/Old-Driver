#pragma execution_character_set("utf-8")

#ifndef SUBJECTTHREESETTINGSPAGE_H
#define SUBJECTTHREESETTINGSPAGE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPalette>

#include "src/CommonUi/UiConstants.h"
#include "src/CommonUi/ShadowButton.h"
#include "src/CommonUi/DeviceSettingDetailPage.h"
#include "src/SubjectThree/PracticeSettingsDetailPage.h"
#include "src/ConfigHelper.hpp"

class SubjectThreeSettingsPage : public QWidget
{
    Q_OBJECT
public:
    explicit SubjectThreeSettingsPage(QWidget *parent = nullptr);

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

	PracticeSettingsDetailPage *PracticeSettingsDetail;
	DeviceSettingDetailPage *DeviceSettingDetail;
};

#endif // SUBJECTTHREESETTINGSPAGE_H