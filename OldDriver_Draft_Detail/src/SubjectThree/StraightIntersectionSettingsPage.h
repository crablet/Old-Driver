#ifndef STRAIGHTINTERSECTIONSETTINGSPAGE_H
#define STRAIGHTINTERSECTIONSETTINGSPAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class StraightIntersectionSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit StraightIntersectionSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // STRAIGHTINTERSECTIONSETTINGSPAGE_H
