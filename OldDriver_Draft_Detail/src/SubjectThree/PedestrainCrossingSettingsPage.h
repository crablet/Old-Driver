#ifndef PEDESTRAINCROSSINGSETTINGSPAGE_H
#define PEDESTRAINCROSSINGSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class PedestrainCrossingSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit PedestrainCrossingSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // PEDESTRAINCROSSINGSETTINGSPAGE_H
