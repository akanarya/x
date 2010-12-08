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
#define _LIC_MSG0   "Lisans dosyasý bulunamadý"
#define _LIC_MSG1   "Lisans geçersiz. Her bilgisayar için ayrý lisans alýnmalýdýr."
#define _LIC_MSG2   "Haberleþme için að kartý bulunamadý, program kapatýlacak."
#define _LIC_MSG3   "Donaným geçersiz"
#define _LIC_MSG4   "Lisans geçerli"

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
