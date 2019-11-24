#ifndef DEVICESETTINGDETAILPAGE_H
#define DEVICESETTINGDETAILPAGE_H

#include <QWidget>

#include "src/SubjectTwo/SettingPageBase.h"

class DeviceSettingDetailPage final : public SettingPageBase
{
    Q_OBJECT
public:
    explicit DeviceSettingDetailPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void InitializeSettingsList() override;
	virtual void InitializeConnect() override;
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	static constexpr auto Type = Subject::Two::DeviceSettings;
};

#endif // DEVICESETTINGDETAILPAGE_H