// **************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// **************************************************************************
// �ĵ�˵����SQL Server ���Ӧ��
// ==========================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------
// 2013.04.18   XChinux     ����
// 2013.06.04   XChinux     ����ODBCDSN()����
//
// ==========================================================================
/// @file MSSQL.h SQL Server ���Ӧ��
#ifndef TIANCHI_TCMSSQL_H
#define TIANCHI_TCMSSQL_H

#include <tianchi/tcglobal.h>
#include <QStringList>

/// @brief ��ȡ ODBC �����Ͱ汾��Ϣ
/// @author XChinux XChinux@163.com
/// @date 2013-04-18
class TIANCHI_API TcMSSQL
{
public:
    /// @brief ��ȡ ODBC �����Ͱ汾��Ϣ
    /// @date 2013-04-18
    /// @return  �� / �ָ��汾�ź���������:<br>
    ///     10.00/SQL Server Native Client 10.0<br>
    ///     09.00/SQL Native Client<br>
    ///     03.50/SQL Server<br>
    static QStringList availableODBCDrivers();
    /// @brief  ����ODBC DSN�ַ���
    /// @date 2013-06-04
    /// @param  driver  ����ODBC��������
    /// @param  server  host\instancename ��ʽ,���ΪĬ��ʵ������ֱ��Ϊhost
    /// @param  dbname  ���ݿ���
    /// @param  user    �����û���
    /// @param  pass    ��������
    /// @return ����DSN�ַ���
    static QString ODBCDSN(const QString &driver,
            const QString &server,
            const QString &dbname,
            const QString &user = QString(),
            const QString &pass = QString());
};

#endif
