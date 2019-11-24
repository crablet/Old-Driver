#pragma execution_character_set("utf-8")

#ifndef TUNNELDRIVINGSETTINGSPAGE_H
#define TUNNELDRIVINGSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

class TunnelDrivingSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit TunnelDrivingSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::TunnelDriving;
};

#endif // TUNNELDRIVINGSETTINGSPAGE_H
