// complexlineedit.cpp
#include "complexlineedit.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

ComplexLineEdit::ComplexLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    // Create a regular expression pattern for a valid complex number format.
    QRegularExpression pattern("([-+]?(\\d+(\\.\\d*)?)?)?([-+])?(\\d+(\\.\\d*)?)?i");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(pattern, this);
    setValidator(validator);

    // Apply the style to format the text with a shadow effect.
    QString styleSheet = "QLineEdit {"
                         "    border: 2px solid gray;"
                         "    border-radius: 5px;"
                         "    padding: 2px 4px;"
                         "    background: white;"
                         "    color: black;"
                         "    font-weight: bold;"
                         "    text-align: center;"
                         "    text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.5);" // Shadow effect
                         "}";
    setStyleSheet(styleSheet);
}

bool ComplexLineEdit::isValidComplexFormat(const QString &text)
{
    QRegularExpression pattern("([-+]?(\\d+(\\.\\d*)?)?)?([-+])?(\\d+(\\.\\d*)?)?i");
    QRegularExpressionMatch match = pattern.match(text);
    return match.hasMatch();
}

void ComplexLineEdit::setTextFormatted(const QString &text)
{
    if (isValidComplexFormat(text))
    {
        // If the input is in a valid complex format, set it as is.
        setText(text);
    }
    else
    {
        // If not, try to format the text as "(1)+(-1i)".
        QRegularExpression complexPattern("(\\d+(\\.\\d*)?)");
        QRegularExpressionMatchIterator matchIterator = complexPattern.globalMatch(text);

        QString formattedText = "(";
        int i = 0;

        while (matchIterator.hasNext())
        {
            if (i > 0)
            {
                formattedText += (i % 2 == 0) ? "+" : ")+(";
            }

            formattedText += matchIterator.next().captured(0);
            i++;
        }

        if (i % 2 != 0)
        {
            formattedText += ")+";
        }
        else
        {
            formattedText += ")";
        }

        setText(formattedText);
    }
}

void ComplexLineEdit::focusInEvent(QFocusEvent* event)
{
    // When the widget receives focus, format the text to the simplified format.
    setTextFormatted(text());
    QLineEdit::focusInEvent(event);
}

void ComplexLineEdit::focusOutEvent(QFocusEvent* event)
{
    // When the widget loses focus, format the text to the displayed format.
    setTextFormatted(text());
    QLineEdit::focusOutEvent(event);
}
