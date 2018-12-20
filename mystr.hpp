/*
 * =====================================================================================
 *
 *       Filename:  mystr.hpp
 *
 *    Description:  my implementation of string
 *
 *        Version:  1.0
 *        Created:  12/11/2018 07:41:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alex Klim
 *   Organization:  home
 *
 * =====================================================================================
 */
#include <iostream>

class Mystr {
public:
    Mystr() : thestring(nullptr), len(0) {};
    Mystr(const char*);
    Mystr(const Mystr&);
    ~Mystr() { delete[] thestring; };

    Mystr& operator= (const Mystr&);
    Mystr& operator= (const char*);
    Mystr operator+ (Mystr&);
    Mystr& operator+= (const Mystr&);
    bool operator== (const Mystr&);
    bool operator!= (const Mystr&);

    friend std::ostream& operator<< (std::ostream& os, const Mystr&);
    friend std::istream& operator>> (std::istream& is, Mystr&);

    Mystr& append(const Mystr&);
    bool compare(const Mystr&) const;
    size_t length() const;
    void resize(size_t);
    void clear();
    static void swap(Mystr&, Mystr&);
    int substr(const Mystr&) const;
    void insert(Mystr&, int);
    void insert(char, int);

private:
    char* thestring;
    size_t len;
};
