#-------------------------------------------------
#
# Project created by QtCreator 2019-07-27T16:17:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OldDriver_Draft_Detail
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

unix:LIBS += -lstdc++fs

SOURCES += \
    src/SubjectThree/BusStopSettingsPage.cpp \
    src/SubjectThree/ChangeLanesSettingsPage.cpp \
    src/SubjectThree/PedestrainCrossingSettingsPage.cpp \
    src/SubjectThree/PollingOverSettingsPage.cpp \
    src/SubjectThree/SchoolSettingsPage.cpp \
    src/SubjectThree/StraightDrivingSettingsPage.cpp \
    src/SubjectThree/StraightIntersectionSettingsPage.cpp \
    src/SubjectThree/TurningLeftSettingsPage.cpp \
    src/SubjectThree/TurningRightSettingsPage.cpp \
    src/main.cpp \
    src/CommonUi/LineWidgets.cpp \
    src/CommonUi/StartPageWindow.cpp \
    src/SubjectTwo/SubjectTwoMainWindow.cpp \
    src/SubjectThree/SubjectThreeMainWindow.cpp \
    src/CommonUi/ShadowButton.cpp \
    src/SubjectTwo/SubjectTwoSettingsPage.cpp \
    src/CommonUi/PracticeItemsGroup.cpp \
    src/CommonUi/GaussianBlur.cpp \
    src/CommonUi/ListItemWidget.cpp \
    src/SubjectTwo/ReverseStallParkingSettingsPage.cpp \
    src/SubjectTwo/PracticeSettingDetailPage.cpp \
    src/SubjectTwo/StartingActionsSettingsPage.cpp \
    src/SubjectTwo/RampFixedPointSettingsPage.cpp \
    src/SubjectTwo/CurveDrivingSettingsPage.cpp \
    src/SubjectTwo/RightAngleTurnSettingsPage.cpp \
    src/SubjectTwo/SideParkingSettingsPage.cpp \
    src/SubjectTwo/NarrowRoadTurnAroundSettingsPage.cpp \
    src/SubjectTwo/ParkAndTakeTheCardSettingsPage.cpp \
    src/SubjectTwo/TunnelDrivingSettingsPage.cpp \
    src/SubjectTwo/EmergencyTreatmentSettingsPage.cpp \
    src/CommonUi/DeviceSettingDetailPage.cpp \
    src/SubjectThree/SubjectThreeSettingsPage.cpp \
    src/SubjectThree/PracticeSettingsDetailPage.cpp \
    src/SubjectTwo/SettingPageBase.cpp \
    src/SubjectThree/SettingsPageBase.cpp \
    src/SubjectThree/TurnAroundSettingsPage.cpp \
    src/SubjectThree/MeetingCarSettingsPage.cpp \
    src/SubjectThree/OvertakingSettingsPage.cpp \
    src/SubjectThree/AddAndSubtractSpeedSettingsPage.cpp

HEADERS += \
    src/CommonUi/LineWidgets.h \
    src/CommonUi/StartPageWindow.h \
    src/SubjectThree/BusStopSettingsPage.h \
    src/SubjectThree/ChangeLanesSettingsPage.h \
    src/SubjectThree/PedestrainCrossingSettingsPage.h \
    src/SubjectThree/PollingOverSettingsPage.h \
    src/SubjectThree/SchoolSettingsPage.h \
    src/SubjectThree/StraightDrivingSettingsPage.h \
    src/SubjectThree/StraightIntersectionSettingsPage.h \
    src/SubjectThree/TurningLeftSettingsPage.h \
    src/SubjectThree/TurningRightSettingsPage.h \
    src/SubjectTwo/SubjectTwoMainWindow.h \
    src/CommonUi/UiConstants.h \
    src/SubjectThree/SubjectThreeMainWindow.h \
    src/CommonUi/ShadowButton.h \
    src/SubjectTwo/SubjectTwoSettingsPage.h \
    src/CommonUi/PracticeItemsGroup.h \
    src/CommonUi/GaussianBlur.h \
    src/CommonUi/ListItemWidget.h \
    src/SubjectTwo/ReverseStallParkingSettingsPage.h \
    src/SubjectTwo/PracticeSettingDetailPage.h \
    src/SubjectTwo/StartingActionsSettingsPage.h \
    src/SubjectTwo/RampFixedPointSettingsPage.h \
    src/SubjectTwo/CurveDrivingSettingsPage.h \
    src/SubjectTwo/RightAngleTurnSettingsPage.h \
    src/SubjectTwo/SideParkingSettingsPage.h \
    src/SubjectTwo/NarrowRoadTurnAroundSettingsPage.h \
    src/SubjectTwo/ParkAndTakeTheCardSettingsPage.h \
    src/SubjectTwo/TunnelDrivingSettingsPage.h \
    src/SubjectTwo/EmergencyTreatmentSettingsPage.h \
    src/CommonUi/ConfigHelper.hpp \
    src/CommonUi/DeviceSettingDetailPage.h \
    src/SubjectThree/SubjectThreeSettingsPage.h \
    src/SubjectThree/PracticeSettingsDetailPage.h \
    src/SubjectTwo/SettingPageBase.h \
    src/SubjectThree/SettingsPageBase.h \
    src/SubjectThree/TurnAroundSettingsPage.h \
    src/SubjectThree/MeetingCarSettingsPage.h \
    src/SubjectThree/OvertakingSettingsPage.h \
    src/SubjectThree/AddAndSubtractSpeedSettingsPage.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
