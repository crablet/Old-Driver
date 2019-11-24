#ifndef SCHOOLSETTINGSPAGE_H
#define SCHOOLSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class SchoolSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit SchoolSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // SCHOOLSETTINGSPAGE_H
