#include <iostream>
#include"rpn_calc.h"

void TestRpnCalc () {
    std::cout << "Pour l'addition, utiliser : +" << std::endl ;
    std::cout << "Pour la soustraction : -" << std::endl ;
    std::cout << "Pour la multiplication : x" << std::endl ;
    std::cout << "Pour la division : /" << std::endl ;
    std::cout << "Pour l'opposé : !" << std::endl ;
    std::cout << "Aucun autre opérateur n'est autorisé. Ne pas accoler les opérateurs." << std::endl ;
    std::cout << "Ne pas diviser par 0." << std::endl ;
    std::cout << "N'utiliser que des entiers." << std::endl ;
    //const char* alpha = "abc"
    std::cout << "Dans les instructions suivantes, il faut bien sûr mettre des guillemets autour des chaînes de caractère." << std::endl ;
    std::cout << std::boolalpha << "is_operand(abc)  retourne " << is_operand("abc") << std::endl;
    std::cout << std::boolalpha << "is_operand(123)  retourne " << is_operand("123") << std::endl;
    std::cout << std::boolalpha << "is_operator(abc)  retourne " << is_operator("abc") << std::endl;
    std::cout << std::boolalpha << "is_operator(123)  retourne " << is_operator("123") << std::endl;
    std::cout << std::boolalpha << "is_operator(+)  retourne " << is_operator("+") << std::endl;
    std::cout << std::boolalpha << "is_operator(-)  retourne " << is_operator("-") << std::endl;
    std::cout << std::boolalpha << "is_operator(x)  retourne " << is_operator("x") << std::endl;
    std::cout << std::boolalpha << "is_operator(/)  retourne " << is_operator("/") << std::endl;
    std::cout << std::boolalpha << "is_operator(!)  retourne " << is_operator("!") << std::endl;
    // const char* expr [] = {"3", "2", "+"};
    // std::cout << "rpn_calc(3, ["2", "3", "+"])  retourne " << rpn_calc(3, expr) << std::endl;
    // const char* expr2 [] = {"18", "1", "!", "x", "3", "/"};
    // std::cout << "rpn_calc(6, ["18", "1", "!", "x", "3", "/"])  retourne " << rpn_calc(6, expr2) << std::endl;
}