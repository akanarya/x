#ifndef PROTECT_H
#define PROTECT_H
#include <QtNetwork/QNetworkInterface>
#include <QFile>
#include <QUuid>

#define _LIC0   0   // license file not found
#define _LIC1   1   // license invalid
#define _LIC2   2   // license valid
#define _LIC3   3   // not valid hardware

#define _LIC_FILE   "author.lic"
#define _LIC_MSG0   "Lisans dosyas� bulunamad�"
#define _LIC_MSG1   "Lisans ge�ersiz. Her bilgisayar i�in ayr� lisans al�nmal�d�r."
#define _LIC_MSG2   "Haberle�me i�in a� kart� bulunamad�, program kapat�lacak."
#define _LIC_MSG3   "Donan�m ge�ersiz"
#define _LIC_MSG4   "Lisans ge�erli"

class protect{

public:

    QList<QNetworkInterface> ifList;
    int licenseMode;
    int licenseState;

    QString UUID;
    QString fileName;
    QString fileKey;

    QString hardwareAdress;

    QString privateKey;
    QList<QString> privateKeyList;

    QString key;
    QList<QString> keyList;

    QString statusMessage, report;

    protect(int mode = 0) : licenseMode(mode){
        // mode 0   ;   network interface address
        if (mode != 0)  licenseMode = 0;

        licenseState = _LIC0;

        hardwareAdress = "";
        privateKey = "";

        key = "";
    }

    void getIfList();
    bool checkLicenceFile(QString path = "");
    void genPrivateKey();
    void genKeysLists();
    QString reconHardwareAdress();
    void genKey();
    bool checkKey();
    void checkLicence();
    void genUUID();

    QString makeReport();
};

#endif // PROTECT_H
