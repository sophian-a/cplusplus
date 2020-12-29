#include <iostream>
#include "intlist.h"

int main () {
    IntList new_list ;
    new_list.add_front(18) ;
    new_list.add_front(17) ;
    new_list.add_back(19) ;
    new_list.print() ;
    new_list.remove(9) ;
    new_list.print() ;
    return 0 ;
}