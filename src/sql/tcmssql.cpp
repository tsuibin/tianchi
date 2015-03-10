#include <tianchi/sql/tcmssql.h>
#include <QSettings>
#include <QStringListIterator>
#include <QtAlgorithms>

/**
 * get MSSQL ODBC drivers name and version, every item such as:
 * -------------------------------------------------------------
 *     10.00/SQL Server Native Client 10.0
 *     09.00/SQL Native Client
 *     03.50/SQL Server
 * -------------------------------------------------------------
 * @author  XChinux<XChinux@163.com>
 * @final   2013-04-18
 * @return  QStringList         desc sorted ver/drivername lists
 */
QStringList TcMSSQL::availableODBCDrivers()
{
    QStringList slDrivers;
#ifdef Q_OS_WIN
    QSettings  sts("HKEY_LOCAL_MACHINE\\SOFTWARE\\ODBC\\ODBCINST.INI"
            "\\ODBC Drivers", QSettings::NativeFormat);
    QStringList slKeys = sts.allKeys();

    QStringList slKeys2;
    slKeys2 << slKeys.filter("SQL Server") << slKeys.filter("Native Client");
    slKeys2.removeDuplicates();
    QStringListIterator it(slKeys2);

    while (it.hasNext())
    {
        QString strV = it.next();
        if (sts.value(strV).toString() == "Installed")
        {
            QSettings sts2("HKEY_LOCAL_MACHINE\\SOFTWARE\\ODBC\\ODBCINST.INI\\"
                + strV, QSettings::NativeFormat);
            strV.prepend(sts2.value("DriverODBCVer").toString() + "/");
            slDrivers << strV;
        }
    }
    qSort(slDrivers.begin(), slDrivers.end(), qGreater<QString>());
#endif
    return slDrivers;
}

/// @brief  ����ODBC DSN�ַ���
/// @author XChinux<XChinux@163.com>
/// @final  2013-06-04
/// @param  driver  ����ODBC��������
/// @param  server  host\instancename ��ʽ,���ΪĬ��ʵ������ֱ��Ϊhost
/// @param  dbname  ���ݿ���
/// @param  user    �����û���
/// @param  pass    ��������
/// @return ����DSN�ַ���
QString TcMSSQL::ODBCDSN(const QString &driver,
            const QString &server,
            const QString &dbname,
            const QString &user /*= QString() */,
            const QString &pass /*= QString()*/)
{
    QString strDSN = QString("DRIVER={%1};SERVER=%2;DATABASE=%3")
        .arg(driver).arg(server).arg(dbname);
    if (!user.isEmpty())
    {
        strDSN += ";UID=" + user;
    }
    if (!pass.isEmpty())
    {
        strDSN += ";PWD=" + pass;
    }
    return strDSN;
}
