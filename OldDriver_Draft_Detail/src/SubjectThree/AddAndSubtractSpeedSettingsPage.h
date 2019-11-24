#ifndef ADDANDSUBTRACTSETTINGS_PAGE_H
#define ADDANDSUBTRACTSETTINGS_PAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class AddAndSubtractSpeedSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit AddAndSubtractSpeedSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // ADDANDSUBTRACTSETTINGS_PAGE_H
