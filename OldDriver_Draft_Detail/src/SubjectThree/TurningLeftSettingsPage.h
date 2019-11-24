#ifndef TURNINGLEFTSETTINGSPAGE_H
#define TURNINGLEFTSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class TurningLeftSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit TurningLeftSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // TURNINGLEFTSETTINGSPAGE_H
