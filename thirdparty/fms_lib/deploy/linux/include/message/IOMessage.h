#pragma once

#include <string>
#include "constant.h"
#include "FmsApi_global.h"
#include <QObject>
//2 byte for message length
//1 byte for message type
//remain bytes for value
class MessageBuffer
{
public:
    explicit MessageBuffer(int size = 0);
    explicit MessageBuffer(const MessageBuffer& src);
    MessageBuffer& operator=(const MessageBuffer& src);

    ~MessageBuffer();
    char* initData(int size);
    void releaseData();
    char* getData() { return m_msgData;}
    int getLength() {return m_msgLen;}

    char* m_msgData = nullptr;
    int m_msgLen  = 0;
private:
    int m_size = 0;
};

class FMSAPI_EXPORT IOMessage: public QObject
{
    Q_OBJECT
public:
    IOMessage(void);
    virtual ~IOMessage(void);
    static int defaultSize() { return 4;}
    static QString messgeTypeToString(uint8 msgType);
	uint16 getLeng();
	uint8 getType();
	void setLeng(uint16 leng);
	void setType(uint8 type); 
    int packToData(MessageBuffer &dest); // serial length, type, and private data member, return number of byte
    virtual int serialToData(char *dest, int max_length) = 0; // serial length, type, and private data member, return number of byte
	virtual int parseFromData(char *mes_data, int mes_leng) = 0; // parse private data member, return INT_SUCCESS if success and INT_FAIL if fail
    uint8 getPriority() const;
    void setPriority(const uint8 &value);
protected:
    virtual QString toString(){return QString();}

protected:
    uint16 leng = 0;
    uint8 type = 0;
    uint8 priority = 0;
	
};

