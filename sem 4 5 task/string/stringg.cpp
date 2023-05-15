#include <iostream>
#pragma once
#include <cassert>]
#include <cstring>
using namespace std;

class stringg
{
public:
    size_t capacity = 16;
    size_t sizze = 0;
    union
    {
        char* ptr;
        char stackbuf[16];
    }data;

    stringg() {}
    stringg(const char* str) {
        Copy(str);
    }
    stringg(const stringg& s) {
        if (s.capacity <= 16)
            Copy(s.data.stackbuf);
        else
            Copy(s.data.ptr);
    }

    ~stringg() {
        if (capacity > 16)
            delete[] data.ptr;
    }

    stringg& operator=(const stringg& s) {
        if (s.capacity <= 16)
            Copy(s.data.stackbuf);
        else
            Copy(s.data.ptr);
        return *this;
    }

    size_t Size()const {
        return sizze;
    }

    void Reserve(size_t cap) {
        cap *= 2;
        char* neww = new char[cap];
        if (capacity <= 16)
            copy(data.stackbuf, data.stackbuf + sizze, neww);
        else {
            copy(data.ptr, data.ptr + sizze, neww);
            delete[] data.ptr;
        }
        data.ptr = neww;
        capacity = cap;
    }

    size_t Capacity() const {
        return capacity;
    }

    void Append(const char* str) {
        sizze = strlen(str) + sizze + 1;
        if (not ((sizze <= capacity) || (sizze < 16)))
            Reserve(sizze);
        if (capacity <= 16)
            copy(str, str + sizze, data.stackbuf + strlen(str));
        else {
            copy(str, str + sizze, data.ptr + strlen(str));
        }
    }

    char& operator[](size_t i) {
        if (capacity <= 16) {
          return data.stackbuf[i];
        }
        else {
          return data.ptr[i];
        }
    }
    char& operator[](int i) {
        if (capacity <= 16) {
          return data.stackbuf[i];
        }
        else {
          return data.ptr[i];
        }
    }


    void Copy(const char* str) {
        size_t len = strlen(str) + 1;

        if (not ((len <= capacity) || (len < 16)))
            Reserve(len);
        if (capacity <= 16)
            copy(str, str + len, data.stackbuf);
        else {
            copy(str, str + len, data.ptr);
        }

        sizze = len;
    }


};

