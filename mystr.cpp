#include "mystr.hpp"

#include <cstring>

Mystr::Mystr(const char* rhs) {
    len = strlen(rhs);
    thestring = new char[len+1];
    strcpy(thestring, rhs);
}

Mystr::Mystr(const Mystr& rhs) {
    len = rhs.len;
    thestring = new char[len+1];
    strcpy(thestring, rhs.thestring);
}

Mystr& Mystr::operator= (const Mystr& rhs){
    if (this != &rhs) {
        len = rhs.len;
        delete[] thestring;
        thestring = new char[len+1];
        strcpy(thestring, rhs.thestring);
    }
    return *this;
}

Mystr& Mystr::operator= (const char* rhs) {
    delete[] thestring;
    len = strlen(rhs);
    thestring = new char[len+1];
    strcpy(thestring, rhs);
    return *this;
}

Mystr Mystr::operator+ (Mystr& rhs) {
    Mystr temp;
    temp.len = len + rhs.len;
    temp.thestring = new char[temp.len+1];
    strcpy(temp.thestring, thestring);
    strcat(temp.thestring, rhs.thestring);
    return temp;
}

Mystr& Mystr::operator+= (const Mystr& rhs) {
    char* temp = nullptr;
    if (len) {
        temp = new char[len+1];
        strcpy(temp, thestring);
    }
    delete[] thestring;
    thestring = new char[len+rhs.len+1];
    strcpy(thestring, temp);
    strcpy(thestring-1+len, rhs.thestring);
    len = len+rhs.len;
    return *this;
}

bool Mystr::operator== (const Mystr& rhs) {
    return (!strcmp(thestring, rhs.thestring));
}

bool Mystr::operator!= (const Mystr& rhs) {
    return (strcmp(thestring, rhs.thestring));
}

std::ostream& operator<< (std::ostream& os, const Mystr& rhs) {
    if (rhs.isEmpty())
        return os;
    os << rhs.thestring;
    return os;
}

std::istream& operator>> (std::istream& is, Mystr& rhs) {
    rhs.len = 10;
    rhs.thestring = new char[rhs.len+1];
    size_t i = 0;
    while (is.get(rhs.thestring[i])) {
        if (isspace(rhs.thestring[i])) {
            break;
        }
        ++i;
        if (i == rhs.len) {
            rhs.resize(rhs.len*2);
        }
    }
    rhs.thestring[i] = '\0';
    rhs.len = i;
    return is;
}

Mystr& Mystr::append(const Mystr& rhs) {
    *this += rhs;
    return *this;
}

bool Mystr::compare(const Mystr& rhs) const {
    return (thestring == rhs.thestring);
}

bool Mystr::isEmpty() const {
    if (len)
        return 0;
    return 1;
}

size_t Mystr::length() const {
    return len;
}

void Mystr::resize(size_t newlen) {
    len = newlen;
    char* temp = new char[len+1];
    strcpy(temp, thestring);
    delete[] thestring;
    thestring = temp;
}

void Mystr::clear() {
    len = 0;
    delete[] thestring;
    thestring = nullptr;
}

void Mystr::swap(Mystr& lhs, Mystr& rhs) {
    std::swap(lhs.len, rhs.len);
    std::swap(lhs.thestring, rhs.thestring);
}

int Mystr::substr(const Mystr& rhs) const {
    char* temp = strstr(thestring, rhs.thestring);
    if (temp) {
        return temp - thestring;
    }
    return -1;
}

void Mystr::insert(Mystr& rhs, int pos) {
    len = len + rhs.len;
    char* temp = new char[len+1];
    strncpy(temp, thestring, pos);
    strcat(temp, rhs.thestring);
    strcat(temp, thestring+pos);
    delete[] thestring;
    thestring = temp;
}

void Mystr::insert(char ch, int pos) {
    char* temp = new char[len+2];
    strncpy(temp, thestring, pos);
    temp[pos] = ch;
    strcat(temp, thestring+pos);
    delete[] thestring;
    thestring = temp;
}
