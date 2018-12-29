#include "mystr.hpp"

int main() {
    Mystr one("one");
    Mystr two{"two"};
    Mystr n = " and ";
    Mystr three = "random string passing by";

    std::cout << "['one' plus ' and ' plus 'two']: " << one+n+two << '\n'
        << "[Is 'one' bigger than ' and '?]: " << one.compare(n) << '\n';
    one.resize(10);
    std::cout << "['two' length]: " << two.length() << '\n';

    Mystr four = "randomstring";
    std::cout << "[Four]: " << four << '\n';
    Mystr five;
    std::cout << "[Enter string]:\n";
    std::cin >> five;
    std::cout << "[FIVE]: " << five << '\n';
    four.insert(five, 3);
    std::cout << "[fifth string inserted in fourth]: " << four << '\n';
    //Mystr::swap(three, five);
    std::cout << "[position of ->" << five << "<- in] " << four << ": " << four.substr(five) << '\n';
    five.clear();
    std::cout << "[Cleared five]: " << five << '\n';
    return 0;
}
