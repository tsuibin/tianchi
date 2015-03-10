// �ĵ�˵����ʵ���м�������Ǽ�ͷ��button
// ==========================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------
// 2013.10.14   younghz     ����
// 2013.10.15   XChinux     ��ʽ������
// ==========================================================================
/// @file tcarrowbutton.h ʵ���м�������Ǽ�ͷ��button
// ==========================================================================

#ifndef TIANCHI_TCARROWBUTTON_H
#define TIANCHI_TCARROWBUTTON_H

#include <tianchi/tcglobal.h>
#include <QPushButton>

QT_BEGIN_NAMESPACE
class QKeyEvent;
class QPaintEvent;
QT_END_NAMESPACE

class TcArrowButtonPrivate;

/// @brief ��ͷ��ť��
class TIANCHI_API TcArrowButton : public QPushButton
{
    Q_OBJECT
public:
    /// @brief ���캯��
    /// @param [in] num ��ť�м�ͷ������
    /// @param [in] arrowType ���Ƽ�ͷ�ķ���(Qt::UpArrow/Qt::DownArrow/Qt::LeftArrow/Qt::DownArrow)
    /// @param [in] *parent
    explicit TcArrowButton(int num, Qt::ArrowType, QWidget *parent = 0);
    virtual ~TcArrowButton();

    /// @brief ��ͷ����
    /// @return ��ͷ�ķ���
    Qt::ArrowType arrowType() const;

    /// @brief ��ť�ϼ�ͷ������
    /// @return ��ť�ϼ�ͷ������
    int num() const;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
private:
    Q_DISABLE_COPY(TcArrowButton)
    Q_DECLARE_PRIVATE(TcArrowButton)
    TcArrowButtonPrivate* const d_ptr;
};

#endif // TCARROWBUTTON_H
