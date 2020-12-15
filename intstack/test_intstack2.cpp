#include <iostream>
#include "intstack2.h"

// La fonction suivante permet de vérifier que l'implémentation fonctionne
void verif(IntStack st) {
    st.print();
    std::cout << "Pile vide ? " << st.is_empty() << std::endl ;
    std::cout << "Pile pleine ? " << st.is_full() << std::endl ;
    while (not st.is_full()) {
        st.push(1);
    }
    st.print();
    std::cout << "Pile vide ? " << st.is_empty() << std::endl ;
    std::cout << "Pile pleine ? " << st.is_full() << std::endl ;
}

void error_pop() {
    IntStack st(1);
    std::cout << "Test d'erreur de pop :" << std::endl ;
    st.print();
    st.pop();
}

void error_push() {
    IntStack st(3);
    st.push(20);
    st.push(30);
    st.push(1);
    std::cout << st.is_full() << std::endl ;
    st.push(4);
}

int main () {
    IntStack st (3);
    verif(st);
    // error_pop(); // On doit avoir une erreur (pile vide)
    // error_push(); // On doit obtenir une erreur (pile pleine)
    // IntStack st2(-1); // On doit obtenir une erreur (taille négative)
    st.push(10) ;
    IntStack st2(st) ;
    verif(st2) ;
}

// N'exécutez que l'erreur que vous souhaitez vérfier.