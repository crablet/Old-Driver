#pragma execution_character_set("utf-8")

#ifndef SUBJECTTWOMAINWINDOW_H
#define SUBJECTTWOMAINWINDOW_H

#include <QPalette>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QTableWidget>
#include <QHeaderView>
#include <QPixmap>

#include "src/CommonUi/UiConstants.h"
#include "SubjectTwoSettingsPage.h"
#include "src/CommonUi/PracticeItemsGroup.h"
#include "src/CommonUi/GaussianBlur.h"

class SubjectTwoMainWindow : public QWidget
{
    Q_OBJECT

public:
    SubjectTwoMainWindow(QWidget *parent = 0);

signals:
	void BackToStartPage();	// 触发该信号时，返回首页

private:
	void InitializeUi();
	void InitializeConnect();
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	QPushButton *SettingsButton;	// “参数设置”按钮
	QPushButton *PractiseBeginButton;	// “开始练习”按钮
	QPushButton *ReturnButton;	// 点击该按钮返回到首页

	SubjectTwoSettingsPage *SettingsPage;	// 点击“参数设置”后会展示的按钮组

	QLabel *CentralBlackSplitter;	// 表格与底部的黑色分割线
	QLabel *WhiteBackgroundLabel;	// 中间的白色背景
	QLabel *SatelliteStatusLabel;	// 显示卫星状态的标签，位于大黑条上
	QLabel *DirectonStatusLabel;	// 显示目前车辆朝向的标签，位于大黑条上
	QLabel *NameLabel;				// 显示姓名的标签
	QLabel *IdNumerLabel;			// 显示身份证号的标签
	QLabel *ScoreLabel;				// 显示考试得分的标签
	QLabel *TotalTimeLabel;			// 显示考试用时的标签
	QLabel *HeadPortraitLabel;		// 显示头像的标签

	PracticeItemsGroup *PracticeItems;

	QTableWidget *DeductMarkTable;	// 正中间的扣分详情表
};

#endif // SUBJECTTWOMAINWINDOW_H
