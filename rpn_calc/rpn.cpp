#include<iostream>
#include"calc.h"

int main(int argc, const char* argv[]) {
    std::cout << rpn_eval(argc,argv) << std::endl ;
    return 0;
}