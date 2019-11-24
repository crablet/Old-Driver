#pragma execution_character_set("utf-8")

#ifndef PRACTICESETTINGSDETAILPAGE_H
#define PRACTICESETTINGSDETAILPAGE_H

#include <vector>
#include <type_traits>

#include <QWidget>
#include <QGridLayout>
#include <QPalette>
#include <QString>
#include <QPushButton>

#include "src/CommonUi/ShadowButton.h"
#include "src/CommonUi/UiConstants.h"
#include "src/CommonUi/GaussianBlur.h"

#include "TurnAroundSettingsPage.h"
#include "MeetingCarSettingsPage.h"
#include "OvertakingSettingsPage.h"
#include "AddAndSubtractSpeedSettingsPage.h"
#include "TurningRightSettingsPage.h"
#include "TurningLeftSettingsPage.h"
#include "PedestrainCrossingSettingsPage.h"
#include "BusStopSettingsPage.h"
#include "SchoolSettingsPage.h"
#include "StraightDrivingSettingsPage.h"
#include "StraightIntersectionSettingsPage.h"
#include "ChangeLanesSettingsPage.h"
#include "PollingOverSettingsPage.h"

#include "src/ConfigHelper.hpp"

class PracticeSettingsDetailPage : public QWidget
{
    Q_OBJECT
public:
    explicit PracticeSettingsDetailPage(QWidget *parent = nullptr);

private:
	void InitializeUi();
	void InitializeConnect();
	void InitializeSettingsPages();

	template <typename PageName>
	constexpr SettingsPageBase* GetPageOf() noexcept
	{
		if constexpr (std::is_same_v<PageName, TurnAroundSettingsPage>)
		{
			return TurnAroundSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, MeetingCarSettingsPage>)
		{
			return MeetingCarSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, OvertakingSettingsPage>)
		{
			return OvertakingSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, AddAndSubtractSpeedSettingsPage>)
		{
			return AddAndSubtractSpeedSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, TurningRightSettingsPage>)
		{
			return TurningRightSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, TurningLeftSettingsPage>)
		{
			return TurningLeftSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, PedestrainCrossingSettingsPage>)
		{
			return PedestrainCrossingSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, BusStopSettingsPage>)
		{
			return BusStopSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, SchoolSettingsPage>)
		{
			return SchoolSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, StraightDrivingSettingsPage>)
		{
			return StraightDrivingSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, StraightIntersectionSettingsPage>)
		{
			return StraightIntersectionSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, ChangeLanesSettingsPage>)
		{
			return ChangeLanesSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, PollingOverSettingsPage>)
		{
			return PollingOverSettingsPage_;
		}
		else
		{
			static_assert(AlwaysFalse<true>, "给GetPageOf传入的页面名称不存在");

			return nullptr;
		}
	}

	// 根据传入的模板参数自动生成展示该项目的设置页的页面的函数的辅助函数
	template <typename PageName>
	void ShowPageOfHelper() noexcept
	{
		auto Background = QPixmap
								(GaussianBlur(grab(QRect(QPoint(0, 0), size()))
											 .scaled(size() / 9)))
								.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

		auto *PagePtr = GetPageOf<PageName>();
		PagePtr->SetBackground(Background);
		PagePtr->show();
	}

	// 根据传入的模板参数自动生成展示该项目的设置页的页面的函数的实用变量，返回该函数的函数指针
	template <typename PageName>
	static inline auto ShowPageOf = &PracticeSettingsDetailPage::ShowPageOfHelper<PageName>;

private:
	QGridLayout *InnerLayout;
	QWidget *InnerWidget;	// 中间白色的载体
	QPushButton *ReturnButton;

	TurnAroundSettingsPage *TurnAroundSettingsPage_;
	MeetingCarSettingsPage *MeetingCarSettingsPage_;
	OvertakingSettingsPage *OvertakingSettingsPage_;
	AddAndSubtractSpeedSettingsPage *AddAndSubtractSpeedSettingsPage_;
	TurningRightSettingsPage *TurningRightSettingsPage_;
	TurningLeftSettingsPage *TurningLeftSettingsPage_;
	PedestrainCrossingSettingsPage *PedestrainCrossingSettingsPage_;
	BusStopSettingsPage *BusStopSettingsPage_;
	SchoolSettingsPage *SchoolSettingsPage_;
	StraightDrivingSettingsPage *StraightDrivingSettingsPage_;
	StraightIntersectionSettingsPage *StraightIntersectionSettingsPage_;
	ChangeLanesSettingsPage *ChangeLanesSettingsPage_;
	PollingOverSettingsPage *PollingOverSettingsPage_;

	std::vector<void(PracticeSettingsDetailPage::*)()> Slots;
};

#endif // PRACTICESETTINGSDETAILPAGE_H