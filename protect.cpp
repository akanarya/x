#include "protect.h"

void protect::getIfList(){
    ifList = QNetworkInterface::allInterfaces();

    if (ifList.size() != 0) {
        hardwareAdress = ifList[0].hardwareAddress();
    } else {
        statusMessage = _LIC_MSG2;
        licenseState = _LIC3;
    }
}

bool protect::checkLicenceFile(QString path){
    QFile file(path + _LIC_FILE);
    bool fileExist = file.open(QIODevice::ReadOnly | QIODevice::Text);

    if (fileExist){
        QTextStream in(&file);
        fileKey = in.readLine();
    }
    return fileExist;
}

void protect::genPrivateKey(){
    privateKey = "";

    if (hardwareAdress.length() == 17){

        // unicode (ascii) values of each char seperated by "-"
        for (int segmentNo = 0; segmentNo <= 12; segmentNo += 3){
            privateKey += QString::number(hardwareAdress[segmentNo].unicode()) + "-";
            privateKey += QString::number(hardwareAdress[segmentNo + 1].unicode()) + "-";
        }
        privateKey += QString::number(hardwareAdress[15].unicode()) + "-";
        privateKey += QString::number(hardwareAdress[16].unicode());
    } else {
        statusMessage = _LIC_MSG3;
        licenseState = _LIC3;
    }
}

void protect::genKeysLists(){
    privateKeyList.clear();

    for (int i = 0; i < ifList.size(); i++){
        hardwareAdress = ifList[i].hardwareAddress();
        genPrivateKey();
        if (licenseState != _LIC3){
            privateKeyList.append(privateKey);

            genKey();
            keyList.append(key);
        }
    }
}

QString protect::reconHardwareAdress(){
    QString hwa = "";

    if (privateKey != ""){
        int index = -1, prevIndex;
        int count = 0;

        do{
            index++;
            prevIndex = index;
            index = privateKey.indexOf("-", index);
            QChar ch(privateKey.mid(prevIndex, (index - prevIndex)).toInt());
            hwa.append(ch);
            count++;
        } while(index != -1);
    }
    return hwa;
}

void protect::genKey(){
    key = "";

    int index = -1, prevIndex;
    int count = -1;

    do{
        index++;
        prevIndex = index;
        index = privateKey.indexOf("-", index);

        count++;

        // key is even chars of mac addr. char ascii values + 1
        if ( (count + 1) % 2 == 0){
            QChar ch(privateKey.mid(prevIndex, (index - prevIndex)).toInt()+1);
            key.append(ch);
        }

    } while(index != -1);
}

bool protect::checkKey(){
    bool valid = false;

    for (int i = 0; i < keyList.size(); i++)
        if (keyList[i] == fileKey){
            valid = true;
            break;
        }

    return valid;
}

void protect::checkLicence(){

    getIfList();    // check hardware

    if (licenseState != _LIC3){
        genKeysLists();                         // generate private key list

        if (keyList.size() != 0){
            //genKeys();                          // generate keys from private keys

            if (!checkLicenceFile()){           // check license file
                statusMessage = _LIC_MSG0;
                licenseState = _LIC0;
            } else {
                if (fileKey.length() != 6){     // check key length in file
                    statusMessage = _LIC_MSG1;
                    licenseState = _LIC1;
                } else {
                    if (checkKey()) {             // compare keys
                        statusMessage = _LIC_MSG4;
                        licenseState = _LIC2;
                    } else {
                        statusMessage = _LIC_MSG1;
                        licenseState = _LIC1;
                    }
                }
            }
        } else {
            statusMessage = _LIC_MSG3;
            licenseState = _LIC3;
        }
    }
}

void protect::genUUID(){
    UUID = QUuid::createUuid().toString();
}

QString protect::makeReport(){
    report = "";
    report += "------------------------------------------------\n";
    report += "list size: " + QString::number(ifList.size()) + "\n";
    //report += "name: " + ifList[0].name() + "," + ifList[0].humanReadableName()+ "," + ifList[0].hardwareAddress() + "\n";
    report += "hw addr of 0: " + ifList[0].hardwareAddress() + "\n";

    for (int i = 0; i < privateKeyList.size(); i++)
        report += "key " + QString::number(i) + " : " +  privateKeyList[i] + "\n";

    for (int i = 0; i < keyList.size(); i++)
        report += "key " + QString::number(i) + " : " +  keyList[i] + "\n";

    report += "status: " + statusMessage + "\n";
    report += "state: " + QString::number(licenseState) + "\n";
    report += "------------------------------------------------";

    return report;
}
