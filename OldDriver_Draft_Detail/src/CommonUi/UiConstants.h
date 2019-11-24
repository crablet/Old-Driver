#ifndef UICONSTANTS_H
#define UICONSTANTS_H

#include <QString>

inline constexpr int DeviceW = 1024;
inline constexpr int DeviceH = 600;

inline constexpr int SubjectTwoButtonX = 108;
inline constexpr int SubjectTwoButtonY = 371;
inline constexpr int SubjectTwoButtonW = 283;
inline constexpr int SubjectTwoButtonH = 165;

inline constexpr int SubjectThreeButtonX = 611;
inline constexpr int SubjectThreeButtonY = 371;
inline constexpr int SubjectThreeButtonW = 283;
inline constexpr int SubjectThreeButtonH = 165;

inline constexpr int StartPageLogoLabelX = 243;
inline constexpr int StartPageLogoLabelY = 39;
inline constexpr int StartPageLogoLabelW = 781;
inline constexpr int StartPageLogoLabelH = 196;

inline const QString StartPageButtonStyle 
	= "QPushButton {border-radius: 4px; background-color: rgba(255, 255, 255, 0); color: rgba(245, 245, 245, 1); font-size: 50px; font-family: SimHei; border: 3px solid rgba(187, 187, 187, 1)}";

inline constexpr int SettingsWidgetX = 33;
inline constexpr int SettingsWidgetY = 179;
inline constexpr int SettingsWidgetW = 943;
inline constexpr int SettingsWidgetH = 190;
inline const QString SettingsWidgetStyle 
	= "QWidget {background-color: rgba(255, 255, 255, 1); border: 1px solid rgba(187, 187, 187, 1); border-radius: 4px}";

inline const QString SubjectTwoSettingsButtonStyle 
	= "QPushButton {border-radius: 4px; background-color: rgba(68, 136, 169, 1); color: rgba(255, 255, 255, 1); font-size: 36px; font-family: SimHei; border: 1px solid rgba(187, 187, 187, 1); }";

inline constexpr int PracticeSettingButtonX = 68;
inline constexpr int PracticeSettingButtonY = 224;
inline constexpr int PracticeSettingButtonW = 223;
inline constexpr int PracticeSettingButtonH = 107;

inline constexpr int DeviceSettingButtonX = 396;
inline constexpr int DeviceSettingButtonY = 224;
inline constexpr int DeviceSettingButtonW = 223;
inline constexpr int DeviceSettingButtonH = 107;

inline constexpr int VoiceSettingButtonX = 709;
inline constexpr int VoiceSettingButtonY = 224;
inline constexpr int VoiceSettingButtonW = 223;
inline constexpr int VoiceSettingButtonH = 107;

inline constexpr int CentralBlackSplitterX = 4;
inline constexpr int CentralBlackSplitterY = 391;
inline constexpr int CentralBlackSplitterW = 1017;
inline constexpr int CentralBlackSplitterH = 48;
inline const QString CentralBlackSplitterStyle 
	= "QLabel {background-color: rgb(60, 65, 73)}";

inline constexpr int WhiteBackgroundLabelX = 4;
inline constexpr int WhiteBackgroundLabelY = 111;
inline constexpr int WhiteBackgroundLabelW = 1016;
inline constexpr int WhiteBackgroundLabelH = 484;
inline const QString WhiteBackgroundLabelStyle 
	= "QLabel {background-color: rgb(255, 255, 255)}";

inline constexpr int SettingsButtonX = 666;
inline constexpr int SettingsButtonY = 438;
inline constexpr int SettingsButtonW = 176;
inline constexpr int SettingsButtonH = 157;
inline const QString SettingsButtonStyle 
	= "QPushButton {background-color: rgba(68, 136, 169, 1); border: 1px solid rgba(60, 64, 73, 1); font-size: 28px; font-family: SimHei; color: rgba(245, 245, 245, 1)}";

inline constexpr int PractiseBeginButtonX = SettingsButtonX + 2 + SettingsButtonW;
inline constexpr int PractiseBeginButtonY = SettingsButtonY;
inline constexpr int PractiseBeginButtonW = SettingsButtonW;
inline constexpr int PractiseBeginButtonH = SettingsButtonH;
inline const QString PractiseBeginButtonStyle 
	= "QPushButton {background-color: rgba(68, 136, 169, 1); border: 1px solid rgba(60, 64, 73, 1); font-size: 28px; font-family: SimHei; color: rgba(245, 245, 245, 1)}";

inline constexpr int PracticeItemsGroupX = WhiteBackgroundLabelX + 32;
inline constexpr int PracticeItemsGroupY = SettingsButtonY;
inline constexpr int PracticeItemsGroupW = WhiteBackgroundLabelW - SettingsButtonW - PractiseBeginButtonW - 2;
inline constexpr int PracticeItemsGroupH = SettingsButtonH;

inline const QString PracticeItemsGroupLabelStyle 
	= "QLabel {font-size: 22px; font-family: SimHei}";

inline constexpr int ReturnButtonX = 940;
inline constexpr int ReturnButtonY = 25;
inline constexpr int ReturnButtonW = 59;
inline constexpr int ReturnButtonH = 59;

inline constexpr int SatelliteStatusLabelX = WhiteBackgroundLabelX + 45;
inline constexpr int SatelliteStatusLabelY = CentralBlackSplitterY;
inline constexpr int SatelliteStatusLabelW = 178;
inline constexpr int SatelliteStatusLabelH = CentralBlackSplitterH;
inline const QString SatelliteStatusLabelStyle 
	= "QLabel {font-size: 22px; font-family: SimHei; color: rgba(245, 245, 245, 1)}";

inline constexpr int DirectonStatusLabelX = SatelliteStatusLabelX + SatelliteStatusLabelW + 69;
inline constexpr int DirectonStatusLabelY = SatelliteStatusLabelY;
inline constexpr int DirectonStatusLabelW = 166;
inline constexpr int DirectonStatusLabelH = SatelliteStatusLabelH;
inline const QString DirectonStatusLabelStyle = SatelliteStatusLabelStyle;

inline constexpr int DeductMarkTableX = 4;
inline constexpr int DeductMarkTableY = 111;
inline constexpr int DeductMarkTableW = 1017;
inline constexpr int DeductMarkTableH = 485 - PracticeItemsGroupH - CentralBlackSplitterH;
inline const QString DeductMarkTableHeaderStyle 
	= "QHeaderView::section {font-size: 24px; font-family: SimHei; color: rgba(245, 245, 245, 1); background-color: rgba(68, 136, 169, 1)}";

inline constexpr int NameLabelX = 146;
inline constexpr int NameLabelY = 6;
inline constexpr int NameLabelW = 344;
inline constexpr int NameLabelH = 39;

inline constexpr int IdNumerLabelX = NameLabelX;
inline constexpr int IdNumerLabelY = NameLabelY + NameLabelH + 18;
inline constexpr int IdNumerLabelW = NameLabelW;
inline constexpr int IdNumerLabelH = NameLabelH;

inline const QString TopLabelsStyle 
	= "QLabel {font-size: 24px; font-family: SimHei; color: rgba(245, 245, 245, 1)}";

inline constexpr int ScoreLabelX = NameLabelX + NameLabelW + 96;
inline constexpr int ScoreLabelY = NameLabelY;
inline constexpr int ScoreLabelW = NameLabelW;
inline constexpr int ScoreLabelH = NameLabelH;

inline constexpr int TotalTimeLabelX = ScoreLabelX;
inline constexpr int TotalTimeLabelY = IdNumerLabelY;
inline constexpr int TotalTimeLabelW = NameLabelW;
inline constexpr int TotalTimeLabelH = NameLabelH;

inline constexpr int HeadPortraitLabelX = WhiteBackgroundLabelX;
inline constexpr int HeadPortraitLabelY = 6;
inline constexpr int HeadPortraitLabelW = WhiteBackgroundLabelY - HeadPortraitLabelY;
inline constexpr int HeadPortraitLabelH = HeadPortraitLabelW;

inline constexpr int PracticeSettingReturnButtonX = 980;
inline constexpr int PracticeSettingReturnButtonY = 14;
inline constexpr int PracticeSettingReturnButtonW = 30;
inline constexpr int PracticeSettingReturnButtonH = 30;

inline const QString PracticeSettingDetailPageWidgetStyle 
	= "QWidget {background-color: rgb(255, 255, 255); border: 1px solid rgba(187, 187, 187, 1)}";

inline constexpr int PracticeSettingDetailPageButtonW = 163;
inline constexpr int PracticeSettingDetailPageButtonH = 120;
inline const QString PracticeSettingDetailPageButtonStyle
	= "QPushButton {border-radius: 4px; background-color: rgba(60, 65, 73, 1); color: rgba(245, 245, 245, 1); font-size: 24px; font-family: SimHei; border: 1px solid rgba(187, 187, 187, 1)}";

inline constexpr int ListBackgroundWidgetX = 144;
inline constexpr int ListBackgroundWidgetY = 7;
inline constexpr int ListBackgroundWidgetW = 727;
inline constexpr int ListBackgroundWidgetH = 586;
inline const QString ListBackgroundWidgetStyle
	= "QWidget {line-height: 20px; color: rgba(16, 16, 16, 1); background-color: rgba(255, 255, 255, 1); font-size: 14px; font-family: SimHei; border: 1px solid rgba(187, 187, 187, 1)}";

inline constexpr int SettingsPageReturnButtonX = 833;
inline constexpr int SettingsPageReturnButtonY = 16;
inline constexpr int SettingsPageReturnButtonW = 30;
inline constexpr int SettingsPageReturnButtonH = 30;

inline constexpr int SettingsListX = 171;
inline constexpr int SettingsListY = 64;
inline constexpr int SettingsListW = 673;
inline constexpr int SettingsListH = 480;

inline const QString ListItemWidgetStyle 
	= "QWidget {color: rgba(16, 16, 16, 1); font-size: 24px; font-family: SimHei}";

inline const QString ListItemCheckBoxStyle 
	= R"(QCheckBox {spacing: 9px} 
		 QCheckBox::indicator {width: 24px; height: 24px} 
		 QCheckBox::indicator:unchecked {image: url(:/Pictures/CheckBoxUnchecked.png)} 
		 QCheckBox::indicator:checked {image: url(:/Pictures/CheckBoxChecked.png)})";

inline constexpr int RouteChoosingButtonX = WhiteBackgroundLabelX + 45;
inline constexpr int RouteChoosingButtonY = CentralBlackSplitterY + 6;
inline constexpr int RouteChoosingButtonW = 91;
inline constexpr int RouteChoosingButtonH = CentralBlackSplitterH - 12;
inline const QString RouteChoosingButtonStyle 
	= "QPushButton {border-radius: 5px; background-color: rgba(68, 136, 169, 1); color: rgba(255, 255, 255, 1); font-size: 20px; text-align: center; font-family: SimHei; border: 1px solid rgba(187, 187, 187, 1)}";

inline constexpr int LightsPracticeButtonX = RouteChoosingButtonX + RouteChoosingButtonW + 32;
inline constexpr int LightsPracticeButtonY = RouteChoosingButtonY;
inline constexpr int LightsPracticeButtonW = 108;
inline constexpr int LightsPracticeButtonH = RouteChoosingButtonH;
inline const QString LightsPracticeButtonStyle 
	= "QPushButton {font-size: 22px; font-family: SimHei; color: rgba(245, 245, 245, 1)}";

inline constexpr int LightsPracticeSwitcherX = LightsPracticeButtonX + LightsPracticeButtonW + 3;
inline constexpr int LightsPracticeSwitcherY = LightsPracticeButtonY + 8;
inline constexpr int LightsPracticeSwitcherW = 20;
inline constexpr int LightsPracticeSwitcherH = 20;

inline constexpr int CarSpeedButtonX = LightsPracticeSwitcherX + LightsPracticeSwitcherW + 96;
inline constexpr int CarSpeedButtonY = LightsPracticeButtonY;
inline constexpr int CarSpeedButtonW = LightsPracticeButtonW;
inline constexpr int CarSpeedButtonH = LightsPracticeButtonH;
inline const QString CarSpeedButtonStyle = LightsPracticeButtonStyle;

inline constexpr int GearButtonX = CarSpeedButtonX + CarSpeedButtonW + 20;
inline constexpr int GearButtonY = CarSpeedButtonY;
inline constexpr int GearButtonW = CarSpeedButtonW;
inline constexpr int GearButtonH = CarSpeedButtonH;
inline const QString GearButtonStyle = CarSpeedButtonStyle;

inline constexpr int EngineSpeedButtonX = GearButtonX + GearButtonW + 20;
inline constexpr int EngineSpeedButtonY = GearButtonY;
inline constexpr int EngineSpeedButtonW = GearButtonW;
inline constexpr int EngineSpeedButtonH = GearButtonH;
inline const QString EngineSpeedButtonStyle = GearButtonStyle;

inline constexpr int ObdSignalLabelX = EngineSpeedButtonX + EngineSpeedButtonW + 96;
inline constexpr int ObdSignalLabelY = EngineSpeedButtonY;
inline constexpr int ObdSignalLabelW = EngineSpeedButtonW;
inline constexpr int ObdSignalLabelH = EngineSpeedButtonH;
inline const QString ObdSignalLabelStyle 
	= "QLabel {font-size: 22px; font-family: SimHei; color: rgba(245, 245, 245, 1)}";

inline constexpr int SettingsTableX = SettingsListX - 64;
inline constexpr int SettingsTableY = SettingsListY;
inline constexpr int SettingsTableW = SettingsListW + 128;
inline constexpr int SettingsTableH = SettingsListH;

inline constexpr int TableBackgroundWidgetX = ListBackgroundWidgetX - 64;
inline constexpr int TableBackgroundWidgetY = ListBackgroundWidgetY;
inline constexpr int TableBackgroundWidgetW = ListBackgroundWidgetW + 128;
inline constexpr int TableBackgroundWidgetH = ListBackgroundWidgetH;
inline const QString TableBackgroundWidgetStyle = ListBackgroundWidgetStyle;

inline const QString TableItemCheckBoxStyle
	= R"(QCheckBox {spacing: 9px; font-size: 24px; font-family: SimHei} 
		 QCheckBox::indicator {width: 24px; height: 24px} 
		 QCheckBox::indicator:unchecked {image: url(:/Pictures/CheckBoxUnchecked.png)} 
		 QCheckBox::indicator:checked {image: url(:/Pictures/CheckBoxChecked.png)})";

inline const QString TableItemLabelStyle 
	= "QLabel {color: rgba(16, 16, 16, 1); font-size: 24px; font-family: SimHei}";

inline const QString TableItemComboxStyle 
	= "QComboBox {color: rgba(16, 16, 16, 1); font-size: 18px; font-family: SimHei}";

#endif // UICONSTANTS_H
