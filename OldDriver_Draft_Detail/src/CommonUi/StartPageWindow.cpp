#include "StartPageWindow.h"

StartPageWindow::StartPageWindow(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void StartPageWindow::InitializeUi()
{
	setFixedSize(DeviceW, DeviceH);
	setWindowTitle("驾培车载");	// 暂定是这个名字

	// 设置背景色
	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QColor(60, 65, 73));
	setPalette(Pal);

	StartPageLogoLabel = new QLabel(this);
	StartPageLogoLabel->setFixedSize(StartPageLogoLabelW, StartPageLogoLabelH);
	StartPageLogoLabel->move(StartPageLogoLabelX, StartPageLogoLabelY);
	StartPageLogoLabel->setPixmap(QPixmap(":/Pictures/StartPageLogo.png").scaled(StartPageLogoLabel->size()));

	SubjectTwoWindow = new SubjectTwoMainWindow;

	// 设置跳转到科目二界面的按钮
	SubjectTwoButton = new QPushButton(this);
	SubjectTwoButton->setStyleSheet(StartPageButtonStyle);
	SubjectTwoButton->setFixedSize(SubjectTwoButtonW, SubjectTwoButtonH);
	SubjectTwoButton->move(SubjectTwoButtonX, SubjectTwoButtonY);
	SubjectTwoButton->setText("科目二");

	SubjectThreeWindow = new SubjectThreeMainWindow;

	// 设置跳转到科目三界面的按钮
	SubjectThreeButton = new QPushButton(this);
	SubjectThreeButton->setFixedSize(SubjectThreeButtonW, SubjectThreeButtonH);
	SubjectThreeButton->move(SubjectThreeButtonX, SubjectThreeButtonY);
	SubjectThreeButton->setText("科目三");
	SubjectThreeButton->setStyleSheet(StartPageButtonStyle);
}

void StartPageWindow::InitializeConnect()
{
	connect(SubjectTwoButton, &QPushButton::clicked, [this]()	// 点击“科目二”按钮，进入科目二界面
	{
		this->hide();
		SubjectTwoWindow->show();
	});
	connect(SubjectThreeButton, &QPushButton::clicked, [this]()	// 点击“科目三”按钮，进入科目三界面
	{
		this->hide();
		SubjectThreeWindow->show();
	});

	connect(SubjectTwoWindow, &SubjectTwoMainWindow::BackToStartPage, [this]()	// 收到信号，从科目二界面返回
	{
		SubjectTwoWindow->hide();
		this->show();
	});
	connect(SubjectThreeWindow, &SubjectThreeMainWindow::BackToStartPage, [this]()	// 收到信号，从科目三界面返回
	{
		SubjectThreeWindow->hide();
		this->show();
	});
}
