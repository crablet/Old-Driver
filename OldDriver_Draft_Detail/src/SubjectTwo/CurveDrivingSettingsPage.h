#pragma execution_character_set("utf-8")

#ifndef CURVEDRIVINGSETTINGSPAGE_H
#define CURVEDRIVINGSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

class CurveDrivingSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit CurveDrivingSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::CurveDriving;
};

#endif // CURVEDRIVINGSETTINGSPAGE_H