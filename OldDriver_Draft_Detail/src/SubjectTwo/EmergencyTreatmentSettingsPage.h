#pragma execution_character_set("utf-8")

#ifndef EMERGENCYTREATMENTSETTINGSPAGE_H
#define EMERGENCYTREATMENTSETTINGSPAGE_H

#include <QWidget>

#include "SettingPageBase.h"

class EmergencyTreatmentSettingsPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit EmergencyTreatmentSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::PracticeSettings::EmergencyTreatment;
};

#endif // EMERGENCYTREATMENTSETTINGSPAGE_H
