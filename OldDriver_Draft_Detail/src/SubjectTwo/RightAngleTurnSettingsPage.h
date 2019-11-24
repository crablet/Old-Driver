#pragma execution_character_set("utf-8")

#ifndef RIGHTANGLETURNSETTINGSPAGE_H
#define RIGHTANGLETURNSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

// “直角转弯”评分设置页
class RightAngleTurnSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit RightAngleTurnSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::RightAngleTurn;
};

#endif // RIGHTANGLETURNSETTINGSPAGE_H