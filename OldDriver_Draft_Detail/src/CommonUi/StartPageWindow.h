#pragma execution_character_set("utf-8")

#ifndef STARTPAGEWINDOW_H
#define STARTPAGEWINDOW_H

#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QLabel>
#include <QPushButton>

#include "src/CommonUi/UiConstants.h"
#include "src/SubjectTwo/SubjectTwoMainWindow.h"
#include "src/SubjectThree/SubjectThreeMainWindow.h"

class StartPageWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StartPageWindow(QWidget *parent = nullptr);

signals:

public slots:

private:
	void InitializeUi();
	void InitializeConnect();

private:
	QPushButton *SubjectTwoButton, *SubjectThreeButton;
	QLabel *StartPageLogoLabel;

	SubjectTwoMainWindow *SubjectTwoWindow;
	SubjectThreeMainWindow *SubjectThreeWindow;
};

#endif // STARTPAGEWINDOW_H