#pragma execution_character_set("utf-8")

#ifndef PRACTICEITEMSGROUP_H
#define PRACTICEITEMSGROUP_H

#include <vector>

#include <QWidget>
#include <QGridLayout>
#include <QString>
#include <QLabel>

#include "src/CommonUi/UiConstants.h"

class PracticeItemsGroup : public QWidget
{
    Q_OBJECT
public:
    explicit PracticeItemsGroup(QWidget *parent = nullptr);
	PracticeItemsGroup(std::vector<QString> &&ItemsList, QWidget *Parent = nullptr);

signals:

public slots:

private:
	QGridLayout *Layout;
};

#endif // PRACTICEITEMSGROUP_H