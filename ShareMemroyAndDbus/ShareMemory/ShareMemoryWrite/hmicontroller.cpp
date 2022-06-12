#include "hmicontroller.h"

HMIController::HMIController(QObject *parent)
    : QObject{parent}
    ,m_testCount(0)
{
    m_shareMemWrite.setKey("TestShareMemKey");
    if(m_shareMemWrite.attach()){
        qDebug() << "attach share memory";
    }
    if(m_shareMemWrite.create(sizeof(SHARE_INFO))){
        qDebug() << "create share memory with struct SHARE_INFO";
    }
}

bool HMIController::writeShareMemory()
{
    if(!m_shareMemWrite.isAttached()){
        qDebug() << "attach failure";
        return false;
    }
    if(!m_shareMemWrite.lock()){
        qDebug() << "Lock failure";
    }
    char *buffer = (char*)m_shareMemWrite.data();
    if(buffer == nullptr){
        m_shareMemWrite.unlock();
        qDebug() << "Data failure";
        return false;
    }
    // create data needed share
    SHARE_INFO info;
    info.id = m_testCount;
    strcpy(info.message, "Test message");

    //copy data to shared mem
    memcpy(buffer, &info, sizeof(SHARE_INFO));
    //unlock
    m_shareMemWrite.unlock();
    //increase test count
    m_testCount++;
    return true;
}
// not use in this project
void HMIController::readShareMemory()
{
    int count = 0;
    bool isAttachSuccess = m_shareMemRead.attach();
    while(!isAttachSuccess && (count++ < 2)){
        QThread::usleep(10000);
        isAttachSuccess = m_shareMemRead.attach();
    }
    if(isAttachSuccess){
        if(!m_shareMemRead.lock()){
            qDebug() << "Lock failure";
        }else{
            SHARE_INFO info = {};
            memcpy(&info,m_shareMemRead.constData(), sizeof(SHARE_INFO));
            //unlock
            m_shareMemRead.unlock();
            //print out x
            qDebug() << "Read mem id: " << info.id;
            qDebug() << "Read mem message: " << QString::fromUtf8(info.message);
        }
        m_shareMemRead.detach();
    }else{
        qDebug() << "Cannot attach";
    }

}
