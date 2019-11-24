#pragma execution_character_set("utf-8")

#ifndef REVERSESTALLPARKINGSETTINGSPAGE_H
#define REVERSESTALLPARKINGSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

// “倒车入库”评分设置页
class ReverseStallParkingSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit ReverseStallParkingSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::ReverseStallParking;
};

#endif // REVERSESTALLPARKINGSETTINGSPAGE_H