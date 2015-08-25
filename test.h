#ifndef TEST_H
#define TEST_H
#include<iostream>
#include<string>
namespace myspace{

class Test {
public:
    Test() {}
    void print(std::string s) { std::cout << s << std::endl; }
};

}

#endif
