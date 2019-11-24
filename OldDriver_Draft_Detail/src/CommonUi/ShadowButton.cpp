#include "ShadowButton.h"

ShadowButton::ShadowButton(QWidget *parent) : QPushButton(parent)
{
	ShadowEffect = new QGraphicsDropShadowEffect(this);
	ShadowEffect->setOffset(3, 3);
	ShadowEffect->setColor(Qt::gray);
	ShadowEffect->setBlurRadius(4);
	setGraphicsEffect(ShadowEffect);
}
