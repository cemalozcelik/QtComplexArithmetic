// complexlineedit.h
#ifndef COMPLEXLINEEDIT_H
#define COMPLEXLINEEDIT_H

#include <QLineEdit>

class ComplexLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    ComplexLineEdit(QWidget *parent = nullptr);

protected:
    void focusInEvent(QFocusEvent* event) override;
    void focusOutEvent(QFocusEvent* event) override;

public slots:
    void setTextFormatted(const QString &text);

private:
    bool isValidComplexFormat(const QString &text);
};

#endif // COMPLEXLINEEDIT_H
