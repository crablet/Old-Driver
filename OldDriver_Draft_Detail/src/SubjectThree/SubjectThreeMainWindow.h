#ifndef SUBJECTTHREEMAINWINDOW_H
#define SUBJECTTHREEMAINWINDOW_H

#include <QPalette>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QTableWidget>
#include <QHeaderView>
#include <QPixmap>
#include <QCheckBox>

#include "src/CommonUi/UiConstants.h"
#include "src/CommonUi/PracticeItemsGroup.h"
#include "SubjectThreeSettingsPage.h"

class SubjectThreeMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SubjectThreeMainWindow(QWidget *parent = nullptr);

signals:
	void BackToStartPage();	// 触发该信号时，返回首页

private:
	void InitializeUi();
	void InitializeConnect();
	virtual void mousePressEvent(QMouseEvent *e) override;

private:
	QPushButton *SettingsButton;		// “参数设置”按钮
	QPushButton *PractiseBeginButton;	// “开始练习”按钮
	QPushButton *ReturnButton;			// 点击该按钮返回到首页
	QPushButton *RouteChoosingButton;	// 选择科目三行驶路线的按钮
	QPushButton *LightsPracticeButton;	// “灯光模拟”按钮
	QPushButton *CarSpeedButton;		// “车速”按钮
	QPushButton *GearButton;			// “挡位”按钮
	QPushButton *EngineSpeedButton;		// “转速”按钮

	SubjectThreeSettingsPage *SettingsPage;	// 点击“参数设置”后会展示的按钮组

	QLabel *CentralBlackSplitter;	// 表格与底部的黑色分割线
	QLabel *WhiteBackgroundLabel;	// 中间的白色背景
	QLabel *NameLabel;				// 显示姓名的标签
	QLabel *IdNumerLabel;			// 显示身份证号的标签
	QLabel *ScoreLabel;				// 显示考试得分的标签
	QLabel *TotalTimeLabel;			// 显示考试用时的标签
	QLabel *HeadPortraitLabel;		// 显示头像的标签
	QLabel *ObdSignalLabel;			// 显示“OBD信号”的标签

	PracticeItemsGroup *PracticeItems;

	QTableWidget *DeductMarkTable;	// 正中间的扣分详情表

	QCheckBox *LightsPracticeSwitcher;	// “灯光模拟”的复选框
};

#endif // SUBJECTTHREEMAINWINDOW_H