#ifndef TURNINGRIGHTSETTINGSPAGE_H
#define TURNINGRIGHTSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class TurningRightSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit TurningRightSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // TURNINGRIGHTSETTINGSPAGE_H
