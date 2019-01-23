#pragma once

#include <QWidget>
#include <obs.hpp>

#define GREY_COLOR_BACKGROUND 0xFF4C4C4C

class OBSQTDisplay : public QWidget {
	Q_OBJECT
	Q_PROPERTY(QColor displayBackgroundColor MEMBER backgroundColor
			WRITE SetDisplayBackgroundColor)

	OBSDisplay display;

	void CreateDisplay();

	void resizeEvent(QResizeEvent *event) override;
	void paintEvent(QPaintEvent *event) override;

signals:
	void DisplayCreated(OBSQTDisplay *window);
	void DisplayResized();

public:
	OBSQTDisplay(QWidget *parent = nullptr,
			Qt::WindowFlags flags = nullptr);

	virtual QPaintEngine *paintEngine() const override;

	inline obs_display_t *GetDisplay() const {return display;}

	uint32_t backgroundColor = GREY_COLOR_BACKGROUND;

private slots:
	void SetDisplayBackgroundColor(const QColor &color);
};
