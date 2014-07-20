#include "qt/element/QtButton.h"

QtButton::QtButton(QWidget *parent)
	: QPushButton(parent)
	, m_onClick(nullptr)
{
	connect(this, SIGNAL(clicked()), this, SLOT(slotOnClick()));
}

QtButton::~QtButton()
{
}

void QtButton::setCallbackOnClick(std::function<void(void)> callback)
{
	m_onClick = callback;
}

void QtButton::slotOnClick()
{
	if (m_onClick)
	{
		m_onClick();
	}
}
