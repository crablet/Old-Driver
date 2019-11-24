#ifndef TURNAROUNDSETTINGSPAGE_H
#define TURNAROUNDSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class TurnAroundSettingsPage final : public SettingsPageBase
{
    Q_OBJECT
public:
    explicit TurnAroundSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // TURNAROUNDSETTINGSPAGE_H