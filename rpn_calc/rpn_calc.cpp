#include <iostream>
#include <cstdlib>
#include"stack.h"

bool is_operand (const char* token) {
  return ((token[0] >= '0') and (token[0] <= '9'));
}

bool is_operator(const char* token) {
    return ((token[0] == '!') or (token[0] == '+') or (token[0] == '-') or (token[0] == '*') or (token[0] == '/'));
}

int rpn_eval(int n, const char* tab[]) {
    //int stack[n]; // joue le rôle de la pile
    int* stack=init_stack(n);
    int i = 0; // i repère la première case vide
    for (int j = 0 ; j < n ; j++) {
        if (is_operand(tab[j])) {
            push(stack,i,atoi(tab[j]));
        }
        if (is_operator(tab[j])) {
            int a;
            int b;
            if (tab[j][0] == '!') {
                print_stack(stack,i);
                a=pop(stack,i);
                push(stack,i,-a);
            }  
            else {
                if (tab[j][0]=='+') {
                    print_stack(stack,i);
                    b=pop(stack,i);
                    a=pop(stack,i);
                    push(stack,i,a+b);
                }
                if (tab[j][0]=='-') {
                    print_stack(stack,i);
                    b=pop(stack,i);
                    a=pop(stack,i);
                    push(stack,i,a-b);
                }
                if (tab[j][0]=='x') {
                    print_stack(stack,i);
                    b=pop(stack,i);
                    a=pop(stack,i);
                    push(stack,i,a*b);
                }
                if (tab[j][0]=='/') {
                    print_stack(stack,i);
                    b=pop(stack,i);
                    a=pop(stack,i);
                    push(stack,i,a/b);
                }
            }
        }
    }
    int a = pop(stack,i) ;
    delete_stack(stack) ;
    return a ;
}