#pragma execution_character_set("utf-8")

#ifndef NARROWROADTURNAROUNDSETTINGSPAGE_H
#define NARROWROADTURNAROUNDSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

class NarrowRoadTurnAroundSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit NarrowRoadTurnAroundSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::NarrowRoadTurnAround;
};

#endif // NARROWROADTURNAROUNDSETTINGSPAGE_H