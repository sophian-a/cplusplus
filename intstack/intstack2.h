class IntStack {
public:
    IntStack (int s) : size(s), top(0) {
        if (s > 0) {
            tab = new int [size] ;
        }
        else {
            std::cout << "La taille de la pile est négative." << std::endl;
            throw("Cannot create a stack with negative size.");
        }
    }

    IntStack (const IntStack& rst ) : size(rst.size), top(rst.top) {
        // tab = new int [size] ;
        // tab = rst.(*tab) ;
        tab = new int [size] ;
        for (int j=0 ; j<top ; j++) {
            tab[j] = rst.tab[j] ;
        }
    }

    void push (int e) {
        if (not is_full()) {
            tab[top]=e;
            top = top +1;
        }
        else {
            std::cout << "La pile est pleine." << std::endl;
            throw("Cannot push on a full stack.");
        }
    }

    int pop () {
        if (not is_empty()) {
            top = top -1;
            return tab[top];
        }
        else {
            std::cout << "La pile est vide." << std::endl ;
            throw("Cannot pop an empty stack.");
        }
    }

    bool is_empty () {
        return top == 0;
    }

    bool is_full() {
        return top == size;
    }

    void print() {
        std::cout << '[' ;
        for (int j=0 ; j<top ; j++) {
            std::cout << tab[j] << ' ';
        }
    std::cout << ']' << std::endl ;
    }

    ~IntStack () {
        delete [] tab ;
    }


private:
    int top;
    int size;
    int *tab;
};