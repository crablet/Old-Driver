#ifndef SHADOWBUTTON_H
#define SHADOWBUTTON_H

#include <QPushButton>
#include <QGraphicsDropShadowEffect>

class ShadowButton : public QPushButton
{
	Q_OBJECT
public:
	explicit ShadowButton(QWidget *parent = nullptr);

public slots:

private:
	QGraphicsDropShadowEffect *ShadowEffect;
};

#endif // SHADOWBUTTON_H