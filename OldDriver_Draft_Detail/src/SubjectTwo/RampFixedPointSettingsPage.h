#pragma execution_character_set("utf-8")

#ifndef RAMPFIXEDPOINTSETTINGSPAGE_H
#define RAMPFIXEDPOINTSETTINGSPAGE_H

#include <QWidget>
#include <QSize>

#include "SettingPageBase.h"

// “坡道定点停车与起步”评分设置页
class RampFixedPointSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit RampFixedPointSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::RampFixedPoint;
};

#endif // RAMPFIXEDPOINTSETTINGSPAGE_H