#ifndef MEETINGCARSETTINGS_PAGE_H
#define MEETINGCARSETTINGS_PAGE_H

#include <QWidget>
#include <QMouseEvent>

#include "SettingsPageBase.h"

class MeetingCarSettingsPage final : public SettingsPageBase
{
	Q_OBJECT
public:
	explicit MeetingCarSettingsPage(QWidget *parent = nullptr);

signals:

public slots:

private:
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void InitializeConnect() override;
	virtual void AddSpecificItemToSettingsTable() override;
};

#endif // MEETINGCARSETTINGS_PAGE_H
