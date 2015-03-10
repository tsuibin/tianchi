// �ĵ�˵����ʵ�ֿ������߰�ť���ڴ�С��counter
// ==========================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------
// 2013.10.31   younghz     ����
// ==========================================================================
/// @file tccounter.h ʵ�ֿ������߰�ť���ڴ�С��counter
// ==========================================================================

#ifndef TIANCHI_TCCOUNTER_H
#define TIANCHI_TCCOUNTER_H

#include <tianchi/tcglobal.h>
#include <QWidget>

/// @brief counter widget
/// ���widget����һ����ʾ���ֵ�lineedit��һ�����߶�������������Ӻͼ�С��ʾ
/// �����ֵ�ֵ��arrowbutton����ť����ʱ���ӻ��Ǽ�С����ֵ������setIncSteps()
/// �����趨��lineedit���ߵ�arrowbutton�ĸ���������setNumButtons()�����趨��

/// Example:
/// @code
/// #include "TcCounter.h"
///
/// TcCounter *myCounter = new TcCounter(parent);
///
/// myCounter->setRange(0.0, 10.0);
/// myCounter->setSingleStep(1.0);
/// myCounter->setButtonNum(2);
/// ...

QT_BEGIN_NAMESPACE
class QKeyEvent;
QT_END_NAMESPACE

class TcCounterPrivate;

/// @brief TcCounter��
class TIANCHI_API TcCounter : public QWidget
{
    Q_OBJECT
public:
    /// @brief ���캯��
    explicit TcCounter(QWidget *parent = 0);
    virtual ~TcCounter();

    /// @brief ���ð�ť����
    /// @param [in] ��ť����ֵ
    void setButtonNum(int n);

    /// @brief ����valueEdit��ʾ���ķ�Χ
    /// @param [in] minnum ��Сֵ
    /// @param [in] maxnum ���ֵ
    void setRange(double minnum, double maxnum);

    /// @brief ���ò���
    /// @param [in] ����ֵ
    void setSingleStep(double step);

    /// @return ������С
    double singleStep() const;

    /// @brief ����counter��״̬����Ч����Ч��
    ///        ������Ϊ��Чʱ��lineEdit�в�����ʾ���ֲ������ߵ�arrowButton������
    /// @param [in] on Ϊtrueʱ״̬����Ч��������Ч
    void setValid(bool on);

    /// @brief �����Ƿ���Ч״̬
    bool isValid() const;

    /// @brief ����lineEdit��ֻ������
    void setReadOnly(bool on);
    bool isReadOnly() const;

    /// @brief ����lineEdit��ʾ����Сֵ
    void setMinimum(double min);
    double minimum() const;

    /// @brief ����lineEdit�����ֵ
    void setMaximum(double max);
    double maximum() const;

    /// @brief lineEdit��ֵ
    double value() const;

    /// @brief �����ť���ӵĲ���
    void setStepButton1(int nSteps);
    int stepButton1() const;

    void setStepButton2(int nSteps);
    int stepButton2() const;

    void setStepButton3(int nSteps);
    int stepButton3() const;
Q_SIGNALS:

    /// @brief ���ؼ���ֵ�ı�ʱ����
    /// @param value �µ�ֵ
    void valueChanged(double value);

    void buttonReleased( double value);

public Q_SLOTS:
    void setValue(double value);

private Q_SLOTS:
    void btnRelease();
    void btnClick();


private:
    Q_DISABLE_COPY(TcCounter)
    Q_DECLARE_PRIVATE(TcCounter)

    TcCounterPrivate* const d_ptr;

protected:
    virtual void keyPressEvent(QKeyEvent *);
};

#endif // TIANCHI_TCCOUNTER_H
