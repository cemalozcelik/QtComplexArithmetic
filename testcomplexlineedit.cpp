#include <QtTest/QtTest>
#include "complexlineedit.h"

class TestComplexLineEdit : public QObject
{
    Q_OBJECT

private slots:
    void testValidInput();
    void testInvalidInput();
};

void TestComplexLineEdit::testValidInput()
{
    ComplexLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "1");
    QCOMPARE(lineEdit.text(), QString("1"));
}

void TestComplexLineEdit::testInvalidInput()
{
    ComplexLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "a");
    QCOMPARE(lineEdit.text(), QString("")); // Expect an empty string for invalid input
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a test object to initialize the Qt Test framework
    TestComplexLineEdit testObject;

    // Run the tests
    int status = QTest::qExec(&testObject, argc, argv);

    return status;
}

#include "testcomplexlineedit.moc"
