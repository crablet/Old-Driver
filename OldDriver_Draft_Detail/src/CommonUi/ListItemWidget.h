#ifndef LISTITEMWIDGET_H
#define LISTITEMWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

class ListItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListItemWidget(QWidget *parent = nullptr);

signals:

public slots:

public:
	template <typename Head, typename ...Tail>
	void Insert(Head HeadWidget, Tail... TailWidgets)
	{
		Layout->addWidget(HeadWidget);
		Insert(TailWidgets...);
	}

	void Insert()
	{
	}

private:
	QHBoxLayout *Layout;
};

#endif // LISTITEMWIDGET_H
