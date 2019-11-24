#ifndef OVERTAKINGSETTINGS_PAGE_H
#define OVERTAKINGSETTINGS_PAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class OvertakingSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit OvertakingSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // OVERTAKINGSETTINGS_PAGE_H
