#pragma once

#include <assert.h>
#include <string.h>
#include <sstream>
#include <iomanip>

typedef unsigned char byte;
const int bufferSize = 4096;

template <typename To, typename From>
static inline To bitwise_cast(From from)
{
    assert(sizeof(From) == sizeof(To));
    union
    {
        From f;
        To t;
    } u;
    u.f = from;
    return u.t;
}

class ByteBuffer
{
    public:
        ByteBuffer();
        ~ByteBuffer();

        //put
        void putInt8(const int8_t& p);
        void putUInt8(const uint8_t& p);
        void putInt16(const int16_t& p, bool bigEndian = true);
        void putUInt16(const uint16_t& p, bool bigEndian = true);
        void putInt32(const int32_t& p, bool bigEndian = true);
        void putUInt32(const uint32_t& p, bool bigEndian = true);
        void putInt64(const int64_t& p, bool bigEndian = true);
        void putUInt64(const uint64_t& p, bool bigEndian = true);
        void putFloat(const float& p, bool bigEndian = true);
        void putDouble(const double& p, bool bigEndian = true);
        void putBytes(const byte* data, int length);

        // get
        bool getInt8(int8_t& p);
        bool getUInt8(uint8_t& p);
        bool getInt16(int16_t& p, bool bigEndian = true);
        bool getUInt16(uint16_t& p, bool bigEndian = true);
        bool getInt32(int32_t& p, bool bigEndian = true);
        bool getUInt32(uint32_t& p, bool bigEndian = true);
        bool getInt64(int64_t& p, bool bigEndian = true);
        bool getUInt64(uint64_t& p, bool bigEndian = true);
        bool getFloat(float& p, bool bigEndian = true);
        bool getDouble(double& p, bool bigEndian = true);
        bool getBytes(byte* data, int length);

        bool copyBytes(byte* data, int length);
        int getTotalLength();
        void shrink();
        void rewindRead(int numberByte);
        void removeHead(int pos);
        int getCurrentPositionRead();
        int length();
        void clear();
        void adjust(int length);
        int availableLength();
        int readableLength();
        byte *data() const;

    private:
        byte* mData;
        int leng;
        int rPos;
        int wPos;
};

