#pragma once
#include <QPlainTextEdit>

class TTYTextEdit : public QPlainTextEdit
{
public:
    TTYTextEdit(QWidget* parent = 0);
    virtual QSize sizeHint() const;

signals:

public slots:
};
