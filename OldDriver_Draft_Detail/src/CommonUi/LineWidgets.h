#ifndef LINEWIDGETS_H
#define LINEWIDGETS_H

#include <QWidget>
#include <QHBoxLayout>

class LineWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit LineWidgets(QWidget *parent = nullptr);

signals:

public slots:

public:
	template <typename Head, typename ...Tail>
	void InsertWidgets(Head &H, Tail &...T);
	void InsertWidgets();
	

private:
	QHBoxLayout *Layout;
};

#endif // LINEWIDGETS_H