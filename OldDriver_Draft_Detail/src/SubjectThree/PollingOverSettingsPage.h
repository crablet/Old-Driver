#ifndef POLLINGOVERSETTINGSPAGE_H
#define POLLINGOVERSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class PollingOverSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit PollingOverSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // POLLINGOVERSETTINGSPAGE_H
