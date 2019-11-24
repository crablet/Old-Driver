#pragma execution_character_set("utf-8")

#ifndef STARTINGACTIONSSETTINGSPAGE_H
#define STARTINGACTIONSSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

// “起步动作”评分设置页
class StartingActionsSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit StartingActionsSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::StartingActions;
};

#endif // STARTINGACTIONSSETTINGSPAGE_H