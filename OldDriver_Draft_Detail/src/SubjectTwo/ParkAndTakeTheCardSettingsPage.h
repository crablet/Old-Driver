#pragma execution_character_set("utf-8")

#ifndef PARKANDTAKETHECARDSETTINGSPAGE_H
#define PARKANDTAKETHECARDSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

class ParkAndTakeTheCardSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit ParkAndTakeTheCardSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::ParkAndTakeTheCard;
};

#endif // PARKANDTAKETHECARDSETTINGSPAGE_H