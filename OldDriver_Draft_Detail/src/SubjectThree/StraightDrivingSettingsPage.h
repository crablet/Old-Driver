#ifndef STRAIGHTDRIVINGSETTINGSPAGE_H
#define STRAIGHTDRIVINGSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class StraightDrivingSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit StraightDrivingSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // STRAIGHTDRIVINGSETTINGSPAGE_H
