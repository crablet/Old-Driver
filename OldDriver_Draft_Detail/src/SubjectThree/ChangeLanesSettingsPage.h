#ifndef CHANGELANESSETTINGSPAGE_H
#define CHANGELANESSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class ChangeLanesSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit ChangeLanesSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // CHANGELANESSETTINGSPAGE_H
