#pragma execution_character_set("utf-8")

#ifndef SIDEPARKINGSETTINGSPAGE_H
#define SIDEPARKINGSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

class SideParkingSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit SideParkingSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::SideParking;
};

#endif // SIDEPARKINGSETTINGSPAGE_H
