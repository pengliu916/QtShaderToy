#include "TTYTextEdit.h"

TTYTextEdit::TTYTextEdit(QWidget* parent): QPlainTextEdit(parent)
{
    //this->setWordWrapMode(QTextOption::NoWrap);
	this->setLineWrapMode( QPlainTextEdit::NoWrap );
}

QSize TTYTextEdit::sizeHint() const
{
    return QSize(800,100);
}
