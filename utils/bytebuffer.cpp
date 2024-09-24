#include "bytebuffer.h"

ByteBuffer::ByteBuffer()
{
    this->mData = new byte[bufferSize];
    this->rPos = 0;
    this->wPos = 0;
    this->leng = bufferSize;
}

ByteBuffer::~ByteBuffer()
{
    delete[] mData;
    rPos = 0;
    wPos = 0;
    leng = 0;
    mData = nullptr;
}

void ByteBuffer::putInt8(const int8_t& p)
{
    if(availableLength() >= 1)
    {
        memcpy(this->mData + wPos, (byte*) &p, 1);
        wPos += 1;
    }else
    {
        shrink();
        if(availableLength() >= 1)
        {
            memcpy(this->mData + wPos, (byte*) &p, 1);
            wPos += 1;
        }else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & p, 1);
            this->wPos += 1;
        }
    }
}

void ByteBuffer::putUInt8(const uint8_t& p)
{
    if (availableLength() >= 1)
    {
        memcpy(this->mData + wPos, (byte*) & p, 1);
        this->wPos += 1;
    }
    else
    {
        shrink();

        if (availableLength() >= 1)
        {
            memcpy(this->mData + wPos, (byte*) & p, 1);
            this->wPos += 1;
        }
        else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & p, 1);
            this->wPos += 1;
        }
    }
}

void ByteBuffer::putInt16(const int16_t& p, bool bigEndian)
{
    int16_t temp = 0;
    if(bigEndian)
    {
        temp = htobe16(p);
    }else
    {
        temp = htole16(p);
    }

    if (availableLength() >= 2)
    {
        memcpy(this->mData + wPos, (byte*) & temp, 2);
        this->wPos += 2;
    }
    else
    {
        shrink();

        if (availableLength() >= 2)
        {
            memcpy(this->mData + wPos, (byte*) & temp, 2);
            this->wPos += 2;
        }
        else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & temp, 2);
            this->wPos += 2;
        }
    }
}

void ByteBuffer::putUInt16(const uint16_t& p, bool bigEndian)
{
    uint16_t temp = 0;

    if (bigEndian)
    {
        temp = htobe16(p);
    }
    else
    {
        temp = htole16(p);
    }

    if (availableLength() >= 2)
    {
        memcpy(this->mData + wPos, (byte*) & temp, 2);
        this->wPos += 2;
    }
    else
    {
        shrink();

        if (availableLength() >= 2)
        {
            memcpy(this->mData + wPos, (byte*) & temp, 2);
            this->wPos += 2;
        }
        else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & temp, 2);
            this->wPos += 2;
        }
    }
}

void ByteBuffer::putInt32(const int32_t& p, bool bigEndian)
{
    int32_t temp = 0;

    if (bigEndian)
    {
        temp = htobe32(p);
    }
    else
    {
        temp = htole32(p);
    }

    if (availableLength() >= 4)
    {
        memcpy(this->mData + wPos, (byte*) & temp, 4);
        wPos += 4;
    }
    else
    {
        shrink();

        if (availableLength() >= 4)
        {
            memcpy(this->mData + wPos, (byte*) & temp, 4);
            this->wPos += 4;
        }
        else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & temp, 4);
            this->wPos += 4;
        }
    }
}

void ByteBuffer::putUInt32(const uint32_t& p, bool bigEndian)
{
    uint32_t temp = 0;

    if (bigEndian)
    {
        temp = htobe32(p);
    }
    else
    {
        temp = htole32(p);
    }

    if (availableLength() >= 4)
    {
        memcpy(this->mData + wPos, (byte*) & temp, 4);
        wPos += 4;
    }
    else
    {
        shrink();

        if (availableLength() >= 4)
        {
            memcpy(this->mData + wPos, (byte*) & temp, 4);
            this->wPos += 4;
        }
        else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & temp, 4);
            this->wPos += 4;
        }
    }
}

void ByteBuffer::putInt64(const int64_t& p, bool bigEndian)
{
    int64_t temp = 0;

    if (bigEndian)
    {
        temp = htobe64(p);
    }
    else
    {
        temp = htole64(p);
    }

    if (availableLength() >= 8)
    {
        memcpy(this->mData + wPos, (byte*) & temp, 8);
        wPos += 8;
    }
    else
    {
        shrink();

        if (availableLength() >= 8)
        {
            memcpy(this->mData + wPos, (byte*) & temp, 8);
            this->wPos += 8;
        }
        else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & temp, 8);
            this->wPos += 8;
        }
    }
}

void ByteBuffer::putUInt64(const uint64_t& p, bool bigEndian)
{
    uint64_t temp = 0;

    if (bigEndian)
    {
        temp = htobe64(p);
    }
    else
    {
        temp = htole64(p);
    }

    if (availableLength() >= 8)
    {
        memcpy(this->mData + wPos, (byte*) & temp, 8);
        wPos += 8;
    }
    else
    {
        shrink();

        if (availableLength() >= 8)
        {
            memcpy(this->mData + wPos, (byte*) & temp, 8);
            this->wPos += 8;
        }
        else
        {
            adjust(bufferSize + leng);
            memcpy(this->mData + wPos, (byte*) & temp, 8);
            this->wPos += 8;
        }
    }
}

void ByteBuffer::putFloat(const float &p, bool bigEndian)
{
    uint32_t temp = bitwise_cast<uint32_t>(p);
    if (bigEndian)
    {
        temp = htobe32(temp);
    }
    else
    {
        temp = htole32(temp);
    }

    this->putBytes((byte*) & temp, 4);
}

void ByteBuffer::putDouble(const double &p, bool bigEndian)
{
    uint64_t temp = bitwise_cast<uint64_t>(p);

    if (bigEndian)
    {
        temp = htobe64(temp);
    }
    else
    {
        temp = htole64(temp);
    }

    this->putBytes((byte*) & temp, 8);
}

void ByteBuffer::putBytes(const byte *data, int length)
{
    if(availableLength() >= length)
    {
        memcpy(mData + wPos, data, length);
        wPos += length;
    }else
    {
        shrink();
        if(availableLength() >= length)
        {
            memcpy(mData, data, length);
            wPos += length;
        }else
        {
            adjust(bufferSize + leng);
            memcpy(mData,data,length);
            wPos += length;
        }
    }
}

bool ByteBuffer::getInt8(int8_t &p)
{
    if(rPos < wPos)
    {
        memcpy(&p,mData+rPos,1);
        rPos++;
        return true;
    }

    return false;
}

bool ByteBuffer::getUInt8(uint8_t &p)
{
    if (rPos < wPos)
    {
        memcpy(&p, mData + rPos, 1);
        rPos++;
        return true;
    }

    return false;
}

bool ByteBuffer::getInt16(int16_t &p, bool bigEndian)
{
    int16_t temp;

    if (rPos <= (wPos - 2))
    {
        memcpy(&temp, mData + rPos, 2);
        rPos += 2;

        if (bigEndian)
        {
            p = be16toh(temp);
        }
        else
        {
            p = le16toh(temp);
        }

        return true;
    }

    return false;
}

bool ByteBuffer::getUInt16(uint16_t &p, bool bigEndian)
{
    uint16_t temp;

    if (rPos <= (wPos - 2))
    {
        memcpy(&temp, mData + rPos, 2);
        rPos += 2;

        if (bigEndian)
        {
            p = be16toh(temp);
        }
        else
        {
            p = le16toh(temp);
        }

        return true;
    }

    return false;
}

bool ByteBuffer::getInt32(int32_t &p, bool bigEndian)
{
    int32_t temp;

    if (rPos <= (wPos - 4))
    {
        memcpy(&temp, this->mData + rPos, 4);
        rPos += 4;

        if (bigEndian)
        {
            p = be32toh(temp);
        }
        else
        {
            p = le32toh(temp);
        }

        return true;
    }

    return false;
}

bool ByteBuffer::getUInt32(uint32_t &p, bool bigEndian)
{
    uint32_t temp;

    if (rPos <= (wPos - 4))
    {
        memcpy(&temp, this->mData + rPos, 4);
        rPos += 4;

        if (bigEndian)
        {
            p = be32toh(temp);
        }
        else
        {
            p = le32toh(temp);
        }

        return true;
    }

    return false;
}

bool ByteBuffer::getInt64(int64_t &p, bool bigEndian)
{
    int64_t temp;

    if (rPos <= (wPos - 8))
    {
        memcpy(&temp, this->mData + rPos, 8);
        rPos += 8;

        if (bigEndian)
        {
            p = be64toh(temp);
        }
        else
        {
            p = le64toh(temp);
        }

        return true;
    }

    return false;
}

bool ByteBuffer::getUInt64(uint64_t &p, bool bigEndian)
{
    uint64_t temp;

    if (rPos <= (wPos - 8))
    {
        memcpy(&temp, this->mData + rPos, 8);
        rPos += 8;

        if (bigEndian)
        {
            p = be64toh(temp);
        }
        else
        {
            p = le64toh(temp);
        }

        return true;
    }

    return false;
}

bool ByteBuffer::getFloat(float &p, bool bigEndian)
{
    uint32_t temp;

    if (rPos <= (wPos - 4))
    {
        memcpy((byte*) & temp, this->mData + rPos, 4);
        rPos += 4;

        if (bigEndian)
        {
            temp = be32toh(temp);
        }
        else
        {
            temp = le32toh(temp);
        }

        p = bitwise_cast<float>(temp);
        return true;
    }

    return false;
}

bool ByteBuffer::getDouble(double &p, bool bigEndian)
{
    uint64_t temp;

    if (rPos <= (wPos - 8))
    {
        memcpy((byte*) & temp, this->mData + rPos, 8);
        rPos += 8;

        if (bigEndian)
        {
            temp = be64toh(temp);
        }
        else
        {
            temp = le64toh(temp);
        }

        p = bitwise_cast<double>(temp);
        return true;
    }

    return false;
}

bool ByteBuffer::getBytes(byte *data, int length)
{
    if (rPos >= wPos)
    {
        return false;
    }

    if (rPos <= (wPos - length))
    {
        memcpy(data, this->mData + rPos, length);
        rPos += length;
        return true;
    }
    return false;
}

bool ByteBuffer::copyBytes(byte *data, int length)
{
    if (rPos >= wPos)
    {
        return false;
    }

    if (rPos <= (wPos - length))
    {
        memcpy(data, this->mData + rPos, length);
        return true;
    }
    return false;
}

int ByteBuffer::getTotalLength()
{
    return (wPos - rPos);
}

void ByteBuffer::shrink()
{
    removeHead(rPos);
    rPos = 0;
}

void ByteBuffer::rewindRead(int numberByte)
{
    if (numberByte <= 0)
    {
        return;
    }

    if (numberByte >= rPos)
    {
        rPos = 0;
    }
    else
    {
        rPos -= numberByte;
    }
}

void ByteBuffer::removeHead(int pos)
{
    if (pos <= rPos)
    {
        rPos -= pos;
        wPos -= pos;
        memmove(this->mData, this->mData + pos, wPos - rPos);
    }
    else if ((rPos < pos) && (pos <= wPos))
    {
        rPos = 0;
        wPos -= pos;
        memmove(this->mData, this->mData + pos, wPos - rPos);
    }
    else
    {
        this->clear();
    }
}

int ByteBuffer::getCurrentPositionRead()
{
    return rPos;
}

int ByteBuffer::length()
{
    return leng;
}

void ByteBuffer::clear()
{
    rPos = 0;
    wPos = 0;
    memset(mData,0,leng);
}

void ByteBuffer::adjust(int length)
{
    byte* tempData = (byte*) realloc(this->mData, length);

    if (tempData == NULL) // error in reallocating memory
    {
        byte* temp = new byte[length];
        memcpy(temp, this->mData, this->leng);
        delete[] this->mData;
        this->mData = temp;
        this->leng = length;
    }
    else
    {
        this->mData = tempData;
        this->leng = length;
    }
}

int ByteBuffer::availableLength()
{
    return leng - wPos;
}

int ByteBuffer::readableLength()
{
    return wPos - rPos;
}

byte *ByteBuffer::data() const
{
    return this->mData;
}
