#pragma execution_character_set("utf-8")

#ifndef PRACTICESETTINGDETAILPAGE_H
#define PRACTICESETTINGDETAILPAGE_H

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

#include "ReverseStallParkingSettingsPage.h"
#include "StartingActionsSettingsPage.h"
#include "SideParkingSettingsPage.h"
#include "RampFixedPointSettingsPage.h"
#include "RightAngleTurnSettingsPage.h"
#include "CurveDrivingSettingsPage.h"
#include "NarrowRoadTurnAroundSettingsPage.h"
#include "ParkAndTakeTheCardSettingsPage.h"
#include "EmergencyTreatmentSettingsPage.h"
#include "TunnelDrivingSettingsPage.h"

#include "src/ConfigHelper.hpp"

class PracticeSettingDetailPage : public QWidget
{
    Q_OBJECT
public:
    explicit PracticeSettingDetailPage(QWidget *parent = nullptr);

private:
	void InitializeUi();
	void InitializeConnect();
	void InitializeSettingsPages();

	// 根据传入的模板参数在编译期返回该模板参数在本类中对应的指针实例
	template <typename PageName>
	constexpr SettingPageBase* GetPageOf() noexcept
	{
		if constexpr (std::is_same_v<PageName, StartingActionsSettingsPage>)
		{
			return StartingActionsSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, ReverseStallParkingSettingsPage>)
		{
			return ReverseStallParkingSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, SideParkingSettingsPage>)
		{
			return SideParkingSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, RampFixedPointSettingsPage>)
		{
			return RampFixedPointSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, RightAngleTurnSettingsPage>)
		{
			return RightAngleTurnSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, CurveDrivingSettingsPage>)
		{
			return CurveDrivingSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, NarrowRoadTurnAroundSettingsPage>)
		{
			return NarrowRoadTurnAroundSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, ParkAndTakeTheCardSettingsPage>)
		{
			return ParkAndTakeTheCardSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, EmergencyTreatmentSettingsPage>)
		{
			return EmergencyTreatmentSettingsPage_;
		}
		else if constexpr (std::is_same_v<PageName, TunnelDrivingSettingsPage>)
		{
			return TunnelDrivingSettingsPage_;
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
	static inline auto ShowPageOf = &PracticeSettingDetailPage::ShowPageOfHelper<PageName>;

private:
	QGridLayout *InnerLayout;
	QWidget *InnerWidget;	// 中间白色的载体
	QPushButton *ReturnButton;

	StartingActionsSettingsPage *StartingActionsSettingsPage_;
	ReverseStallParkingSettingsPage *ReverseStallParkingSettingsPage_;
	SideParkingSettingsPage *SideParkingSettingsPage_;
	RampFixedPointSettingsPage *RampFixedPointSettingsPage_;
	RightAngleTurnSettingsPage *RightAngleTurnSettingsPage_;
	CurveDrivingSettingsPage *CurveDrivingSettingsPage_;
	NarrowRoadTurnAroundSettingsPage *NarrowRoadTurnAroundSettingsPage_;
	ParkAndTakeTheCardSettingsPage *ParkAndTakeTheCardSettingsPage_;
	EmergencyTreatmentSettingsPage *EmergencyTreatmentSettingsPage_;
	TunnelDrivingSettingsPage *TunnelDrivingSettingsPage_;

	std::vector<void(PracticeSettingDetailPage::*)()> Slots;
};

#endif // PRACTICESETTINGDETAILPAGE_H