// **************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// **************************************************************************
// �ĵ�˵������QVariantMap��Ϊ�����е�model,ֻ��׷�Ӻ����,���ɲ�����ɾ��
// ==========================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------
// 2013.07.04   XChinux     ����
// 2014.01.02   XChinux     add currencyText() function
// ==========================================================================
/// @file tcmath.cpp
// ==========================================================================
#include <tianchi/core/tcmath.h>
#include <QStringList>
#include "../3rdparty/bcmath/bcmath.h"

std::string TcMath::bcadd(const std::string &left, const std::string &right, 
        int scale /*= -1*/)
{
    return ::bcadd(left, right, scale);
}

std::string TcMath::bcsub(const std::string &left, const std::string &right, 
        int scale /*= -1*/)
{
    return ::bcsub(left, right, scale);
}

std::string TcMath::bcmul(const std::string &left, const std::string &right, 
        int scale /*= -1*/)
{
    return ::bcmul(left, right, scale);
}

std::string TcMath::bcdiv(const std::string &left, const std::string &right, 
        int scale /*= -1*/)
{
    return ::bcdiv(left, right, scale);
}

std::string TcMath::bcmod(const std::string &left, const std::string &right)
{
    return ::bcmod(left, right);
}

std::string TcMath::bcpowmod(const std::string &left, const std::string &right, 
        const std::string &mod, int scale /*= -1*/)
{
    return ::bcpowmod(left, right, mod, scale);
}

std::string TcMath::bcpow(const std::string &left, const std::string &right, 
        int scale /*= -1*/)
{
    return ::bcpow(left, right, scale);
}

std::string TcMath::bcsqrt(const std::string &left, int scale /*= -1*/)
{
    return ::bcsqrt(left, scale);
}

int TcMath::bccomp(const std::string &left, const std::string &right, 
        int scale /*= -1*/)
{
    return ::bccomp(left, right, scale);
}

bool TcMath::bcscale(int scale)
{
    return ::bcscale(scale);
}

//--------------------------------------------------------------------------

QString TcMath::bcadd(const QString &left, const QString &right, 
        int scale /*= -1*/)
{
    return QString::fromStdString(
            ::bcadd(left.toStdString(), right.toStdString(), scale));
}

QString TcMath::bcsub(const QString &left, const QString &right, 
        int scale /*= -1*/)
{
    return QString::fromStdString(
            ::bcsub(left.toStdString(), right.toStdString(), scale));
}

QString TcMath::bcmul(const QString &left, const QString &right, 
        int scale /*= -1*/)
{
    return QString::fromStdString(
            ::bcmul(left.toStdString(), right.toStdString(), scale));
}

QString TcMath::bcdiv(const QString &left, const QString &right, 
        int scale /*= -1*/)
{
    return QString::fromStdString(
            ::bcdiv(left.toStdString(), right.toStdString(),scale));
}

QString TcMath::bcmod(const QString &left, const QString &right)
{
    return QString::fromStdString(
            ::bcmod(left.toStdString(), right.toStdString()));
}

QString TcMath::bcpowmod(const QString &left, const QString &right, 
        const QString &mod, int scale /*= -1*/)
{
    return QString::fromStdString(
            ::bcpowmod(left.toStdString(), right.toStdString(), 
                mod.toStdString(), scale));
}

QString TcMath::bcpow(const QString &left, const QString &right, 
        int scale /*= -1*/)
{
    return QString::fromStdString(
            ::bcpow(left.toStdString(), right.toStdString(), scale));
}

QString TcMath::bcsqrt(const QString &left, int scale /*= -1*/)
{
    return QString::fromStdString(::bcsqrt(left.toStdString(), scale));
}

int TcMath::bccomp(const QString &left, const QString &right, 
            int scale /*= -1*/)
{
    return ::bccomp(left.toStdString(), right.toStdString(), scale);
}

QString TcMath::currencyText(const QString &number)
{
    //static QString str2 = C("Ǫ��ʰ��Ǫ��ʰ��Ǫ��ʰ��Ǫ��ʰԪ");
    static const QString str2 = QString::fromUtf8("\344\273\237\344\275\260\346\213\276\344\270\207\344\273\237\344\275\260\346\213\276\344\272\277\344\273\237\344\275\260\346\213\276\344\270\207\344\273\237\344\275\260\346\213\276\345\205\203");
    //static QString str3 = C("��Ҽ��������½��ƾ�");
    static const QString str3 = QString::fromUtf8("\351\233\266\345\243\271\350\264\260\345\217\201\350\202\206\344\274\215\351\231\206\346\237\222\346\215\214\347\216\226");
    static const QString strYiWan = QString::fromUtf8("\344\272\277\344\270\207");//= C("����");
    static const QString strZero = QString::fromUtf8("\351\233\266");// = C("��");
    static const QString strZero2 = QString::fromUtf8("\351\233\266\351\233\266");// = C("����");
    static const QString strYuan = QString::fromUtf8("\345\205\203");// = C("Ԫ");
    static const QString strZheng = QString::fromUtf8("\346\225\264");// = C("��");
    static const QString strJiao = QString::fromUtf8("\350\247\222");// = C("��");
    static const QString strFen = QString::fromUtf8("\345\210\206");// = C("��");
    static const QString strJiaoZheng = QString::fromUtf8("\350\247\222\346\225\264");// = C("����");

    QString str = bcadd(number, QString("0.00"), 2);
    str.replace("-", "");

    int cnt = str3.size();
    QStringList str3arr;
    for (int i = 0; i < cnt; i++)
    {
        str3arr << str3.mid(i, 1);
    }
    int len2 = str.size() - 3;
    QString str22 = str2.mid(str2.size() - len2);

    QString str4 = "";
    for (int i = 0; i < len2; i++)
    {
        int j = str.mid(i, 1).toInt();
        QString word_unit = str22.mid(i, 1);
        if (strYiWan.indexOf(word_unit) > -1)
        {
            if (j == 0)
            {
                str4 += word_unit;
            }
            else
            {
                str4 += str3arr[j] + word_unit;
            }
        }
        else
        {
            if (j == 0)
            {
                str4 += strZero;//C("��");
            }
            else
            {
                str4 += str3arr[j] + word_unit;
            }
        }
    }
    int pos;
    while ((pos = str4.indexOf(strZero2)) > -1)
    {
        str4 = str4.mid(0, pos) + str4.mid(pos + 1);
    }
    if (str4.right(1) == strZero)
    {
        if (str4.size() > 1)
        {
            str4 = str4.mid(0, str4.size() - 1) + strYuan;//C("Ԫ");
        }
        else
        {
            str4 += strYuan;//C("Ԫ");
        }
    }

    if (str.right(2) == "00")
    {
        str4 += strZheng;//C("��");
    }
    else if (str.right(1) == "0")
    {
        // ���
        int j = str.right(2).left(1).toInt();
        str4 += str3arr[j] + strJiaoZheng;
    }
    else if (str.right(2).left(1) == "0")
    {
        // ���
        int j = str.right(1).toInt();
        str4 += strZero + str3arr[j] + strFen;
    }
    else
    {
        int j = str.right(2).left(1).toInt();
        str4 += str3arr[j] + strJiao;
        j = str.right(1).toInt();
        str4 += str3arr[j] + strFen;
    }
    return str4;
}

std::string TcMath::currencyText(const std::string &number)
{
    return currencyText(QString::fromStdString(number)).toStdString();
}
