#include <iostream>
#include "intlist.h"

bool test_isempty() {
    IntList list ;
    bool test1 = list.is_empty() ;
    list.add_front(1) ;
    bool test2 = list.is_empty() ;
    return test1==true && test2==false ;
}

void test_add() {
    IntList list ;
    list.add_front(1) ;
    list.add_front(0) ;
    list.add_back(2) ;
    list.add_back(3) ;
    std::cout << "Test add fonctionne si retourne {0 1 2 3 }" << std::endl ;
    list.print() ;
}

void test_remove_front_back() {
    IntList list ;
    list.add_front(1) ;
    list.add_front(0) ;
    list.add_back(2) ;
    list.add_back(3) ;
    list.remove_front() ;
    list.remove_back() ;
    std::cout << "Test remove_front / remove_back fonctionne si retourne {1 2 }" << std::endl ;
    list.print() ;
}

bool test_size() {
    IntList list ;
    int size1 = list.size() ;
    list.add_front(1) ;
    list.add_front(0) ;
    list.add_back(2) ;
    list.add_back(3) ;
    int size2 = list.size() ;
    return size1==0 && size2==4 ;
}

bool test_search() {
    IntList list ;
    list.add_front(1) ;
    list.add_back(2) ;
    list.add_back(3) ;
    bool test1 = list.search(1) ;
    bool test2 = list.search(4) ;
    // std::cout << std::boolalpha << test1 << test2 << std::endl ;
    return test1==true && test2==false ;
}

void test_remove() {
    IntList new_list ;
    new_list.add_front(18) ;
    new_list.add_front(17) ;
    new_list.add_back(19) ;
    std::cout << "Test remove : on crée la liste : " ;
    new_list.print() ;
    std::cout << "On essaie d'enlever 1 :" << std::endl ;
    new_list.remove(9) ;
    new_list.print() ;
    std::cout << "On essaie d'enlever 19 :" << std::endl ;
    new_list.remove(19) ;
    new_list.print() ;
}

int main () {
    std::cout << "Test is_empty fonctionne si retourne true" << std::endl ;
    std::cout << std::boolalpha << test_isempty() << std::endl ;
    test_add() ;
    test_remove_front_back() ;
    std::cout << "Test size fonctionne si retourne true" << std::endl ;
    std::cout << std::boolalpha << test_size() << std::endl ;
    std::cout << "Test search fonctionne si retourne true" << std::endl ;
    std::cout << std::boolalpha << test_search() << std::endl ;
    test_remove() ;
    return 0 ;
}