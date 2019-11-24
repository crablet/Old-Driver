#include "SubjectThreeMainWindow.h"

SubjectThreeMainWindow::SubjectThreeMainWindow(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void SubjectThreeMainWindow::InitializeUi()
{
	setFixedSize(DeviceW, DeviceH);
	setWindowTitle("驾培车载");	// 暂定是这个名字

	// 设置背景色
	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QColor(60, 65, 73));
	setPalette(Pal);

	// 中间的白色背景
	WhiteBackgroundLabel = new QLabel(this);
	WhiteBackgroundLabel->setFixedSize(WhiteBackgroundLabelW, WhiteBackgroundLabelH);
	WhiteBackgroundLabel->move(WhiteBackgroundLabelX, WhiteBackgroundLabelY);
	WhiteBackgroundLabel->setStyleSheet(WhiteBackgroundLabelStyle);

	// 表格与底部的黑色分割线
	CentralBlackSplitter = new QLabel(this);
	CentralBlackSplitter->setFixedSize(CentralBlackSplitterW, CentralBlackSplitterH);
	CentralBlackSplitter->move(CentralBlackSplitterX, CentralBlackSplitterY);
	CentralBlackSplitter->setStyleSheet(CentralBlackSplitterStyle);

	// “参数设置”按钮
	SettingsButton = new QPushButton(this);
	SettingsButton->setFixedSize(SettingsButtonW, SettingsButtonH);
	SettingsButton->move(SettingsButtonX, SettingsButtonY);
	SettingsButton->setStyleSheet(SettingsButtonStyle);
	SettingsButton->setText("参数设置");

	// “开始练习”按钮
	PractiseBeginButton = new QPushButton(this);
	PractiseBeginButton->setFixedSize(PractiseBeginButtonW, PractiseBeginButtonH);
	PractiseBeginButton->move(PractiseBeginButtonX, PractiseBeginButtonY);
	PractiseBeginButton->setStyleSheet(PractiseBeginButtonStyle);
	PractiseBeginButton->setText("开始练习");

	PracticeItems = new PracticeItemsGroup({ "掉头", "会车", "超车", "加减档", "路口右转", "路口左转", "人行横道", "公交车站", "通过学校", "直线行驶", "直行路口", "变更车道", "靠边停车" }, this);
	PracticeItems->move(PracticeItemsGroupX, PracticeItemsGroupY);

	ReturnButton = new QPushButton(this);
	ReturnButton->setFixedSize(ReturnButtonW, ReturnButtonH);
	ReturnButton->move(ReturnButtonX, ReturnButtonY);
	ReturnButton->setIconSize(ReturnButton->size());	// 要先手动设置图标大小，否则图标会很小
	ReturnButton->setIcon(QIcon(":/Pictures/ReturnButtonIcon.png"));	// 设置好大小以后才能放图标，否则图标会很小
	ReturnButton->setFlat(true);	// 去除背景，使背景透明

	DeductMarkTable = new QTableWidget(this);
	DeductMarkTable->setFixedSize(DeductMarkTableW, DeductMarkTableH);
	DeductMarkTable->move(DeductMarkTableX, DeductMarkTableY);
	DeductMarkTable->setColumnCount(4);
	DeductMarkTable->setHorizontalHeaderLabels({ "扣分", "扣分项目", "扣分原因", "时间" });
	DeductMarkTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	DeductMarkTable->horizontalHeader()->setStyleSheet(DeductMarkTableHeaderStyle);

	NameLabel = new QLabel(this);
	NameLabel->setFixedSize(NameLabelW, NameLabelH);
	NameLabel->move(NameLabelX, NameLabelY);
	NameLabel->setStyleSheet(TopLabelsStyle);
	NameLabel->setText("姓名：范冰冰");	// 这一行只是示例，以后要实时改变的

	IdNumerLabel = new QLabel(this);
	IdNumerLabel->setFixedSize(IdNumerLabelW, IdNumerLabelH);
	IdNumerLabel->move(IdNumerLabelX, IdNumerLabelY);
	IdNumerLabel->setStyleSheet(TopLabelsStyle);
	IdNumerLabel->setText("身份证：103543188311763821");	// 这一行只是示例，以后要实时改变的

	ScoreLabel = new QLabel(this);
	ScoreLabel->setFixedSize(ScoreLabelW, ScoreLabelH);
	ScoreLabel->move(ScoreLabelX, ScoreLabelY);
	ScoreLabel->setStyleSheet(TopLabelsStyle);
	ScoreLabel->setText("考试得分：100");	// 这一行只是示例，以后要实时改变的

	TotalTimeLabel = new QLabel(this);
	TotalTimeLabel->setFixedSize(TotalTimeLabelW, TotalTimeLabelH);
	TotalTimeLabel->move(TotalTimeLabelX, TotalTimeLabelY);
	TotalTimeLabel->setStyleSheet(TopLabelsStyle);
	TotalTimeLabel->setText("考试用时：56:10");	// 这一行只是示例，以后要实时改变的

	HeadPortraitLabel = new QLabel(this);
	HeadPortraitLabel->setFixedSize(HeadPortraitLabelW, HeadPortraitLabelH);
	HeadPortraitLabel->move(HeadPortraitLabelX, HeadPortraitLabelY);
	HeadPortraitLabel->setPixmap(QPixmap(":/Pictures/FanBingBing.png").scaled(HeadPortraitLabel->size()));	// 这一行只是示例，以后要实时改变的

	RouteChoosingButton = new QPushButton(this);
	RouteChoosingButton->setFixedSize(RouteChoosingButtonW, RouteChoosingButtonH);
	RouteChoosingButton->move(RouteChoosingButtonX, RouteChoosingButtonY);
	RouteChoosingButton->setStyleSheet(RouteChoosingButtonStyle);
	RouteChoosingButton->setText("路线一");

	LightsPracticeButton = new QPushButton(this);
	LightsPracticeButton->setFixedSize(LightsPracticeButtonW, LightsPracticeButtonH);
	LightsPracticeButton->move(LightsPracticeButtonX, LightsPracticeButtonY);
	LightsPracticeButton->setStyleSheet(LightsPracticeButtonStyle);
	LightsPracticeButton->setText("灯光模拟");
	LightsPracticeButton->setFlat(true);

	LightsPracticeSwitcher = new QCheckBox(this);
	LightsPracticeSwitcher->setFixedSize(LightsPracticeSwitcherW, LightsPracticeSwitcherH);
	LightsPracticeSwitcher->move(LightsPracticeSwitcherX, LightsPracticeSwitcherY);

	CarSpeedButton = new QPushButton(this);
	CarSpeedButton->setFixedSize(CarSpeedButtonW, CarSpeedButtonH);
	CarSpeedButton->move(CarSpeedButtonX, CarSpeedButtonY);
	CarSpeedButton->setStyleSheet(CarSpeedButtonStyle);
	CarSpeedButton->setText("车速：0");
	CarSpeedButton->setFlat(true);

	GearButton = new QPushButton(this);
	GearButton->setFixedSize(GearButtonW, GearButtonH);
	GearButton->move(GearButtonX, GearButtonY);
	GearButton->setStyleSheet(GearButtonStyle);
	GearButton->setText("挡位：0");
	GearButton->setFlat(true);

	EngineSpeedButton = new QPushButton(this);
	EngineSpeedButton->setFixedSize(EngineSpeedButtonW, EngineSpeedButtonH);
	EngineSpeedButton->move(EngineSpeedButtonX, EngineSpeedButtonY);
	EngineSpeedButton->setStyleSheet(EngineSpeedButtonStyle);
	EngineSpeedButton->setText("转速：0");
	EngineSpeedButton->setFlat(true);

	ObdSignalLabel = new QLabel("OBD信号：", this);
	ObdSignalLabel->setFixedSize(ObdSignalLabelW, ObdSignalLabelH);
	ObdSignalLabel->move(ObdSignalLabelX, ObdSignalLabelY);
	ObdSignalLabel->setStyleSheet(ObdSignalLabelStyle);

	// 点击“参数设置”后会展示的按钮组
	SettingsPage = new SubjectThreeSettingsPage(this);
	SettingsPage->hide();
	SettingsPage->setFixedSize(this->size());
	SettingsPage->move(QPoint(0, 0));
}

void SubjectThreeMainWindow::InitializeConnect()
{
	// 点击“参数设置”，然后展示中部设置界面
	connect(SettingsButton, &QPushButton::clicked, [this]()
	{
		// 模糊的背景图片，要先缩小，然后模糊，最后放大回去，这样效率才高
		auto Background = QPixmap
								(GaussianBlur(grab(QRect(QPoint(0, 0), size()))
											 .scaled(size() / 9)))
								.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		SettingsPage->SetBackground(Background);
		SettingsPage->show();
	});

	// 点击返回按钮，返回到首页（选择科目二和科目三的地方）
	connect(ReturnButton, &QPushButton::clicked, [this]()
	{
		emit BackToStartPage();
	});
}

// 重写鼠标按下的事件实现点击框外空白处时隐藏设置框
void SubjectThreeMainWindow::mousePressEvent(QMouseEvent *e)
{
	if (!SettingsPage->isHidden() && SettingsPage->IsAllPagesHidden())	// 当出现设置界面时才需要判断按下的位置
	{
		int x = e->pos().x();
		int y = e->pos().y();
		if (!(x >= SettingsWidgetX && x <= SettingsWidgetX + SettingsWidgetW
			&& y >= SettingsWidgetY && y <= SettingsWidgetY + SettingsWidgetH))
		{
			SettingsPage->hide();	// 当鼠标点击设置框外空白处时隐藏设置框
		}
	}
	else
	{
		QWidget::mousePressEvent(e);	// 注意要将剩余的事件传回给父类处理
	}
}
