#ifndef BUSSTOPSETTINGSPAGE_H
#define BUSSTOPSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class BusStopSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit BusStopSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // BUSSTOPSETTINGSPAGE_H
