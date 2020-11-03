#include <iostream>

void push(int tab[], int &i, int x) { // &i pour modifier la variable i (et pas juste sa copie)
    tab[i]=x;
    i+=1;
}

int pop(int tab[], int &i) { // idem
    i=i-1;
    return tab[i];
}

int* init_stack(int n) {
    int* p = new int[n] ;
    return p ;
}

void delete_stack(int stack[]) {
    delete [] stack ;
}

void print_stack(int stack[], int i) {
    std::cout << '[' ;
    for (int j=0 ; j<i ; j++) {
        std::cout << stack[j] << ' ';
    }
    std::cout << '[' << std::endl ;
}


// void delete_stack (int stack []) {
//   delete [] stack;
// }