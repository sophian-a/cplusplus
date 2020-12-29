class IntCell { 
    friend class IntList;
private:
    // tout le code de la IntCell en private
    // le constructeur et ses 3 attributs
    // il n'y a aucune autre méthode en dehors du constructeur

    // Attributs :
    int content ;
    IntCell* prev_cell ;
    IntCell* next_cell ;

    // Constructeur :
    IntCell(int n) : content(n) {
        prev_cell = nullptr ;
        next_cell = nullptr ;
    }
};

class IntList {
public:    
    // constructeur et destructeur
    IntList() {
        first_cell = nullptr ;
        last_cell = nullptr ;
    }

    ~IntList() {
        while(not is_empty()) {
            remove_front() ;
        }
    }

    bool is_empty() {
        return first_cell == nullptr ;
    }

    void add_front (int n) {
        IntCell* cell = new IntCell(n) ;
        if(is_empty()) {
            first_cell = cell ;
            last_cell = cell ;
        }
        else {
            // (*cell).next_cell = first_cell ;
            // (*first_cell).prev_cell = cell ;
            // first_cell = cell ;
            IntCell* q = first_cell ;
            (*cell).next_cell = q ;
            (*q).prev_cell = cell ;
            first_cell = cell ;
        }
       
    }
    void add_back (int n) {
        IntCell* cell = new IntCell(n) ;
        if(is_empty()) {
            first_cell = cell ;
            last_cell = cell ;
        }
        else {
            (*cell).prev_cell = last_cell ;
            (*last_cell).next_cell = cell ;
            last_cell = cell ;
        }
    }
    void remove_front () {
        if (not is_empty()) {
            IntCell* p = first_cell ;
            if (size()==1) {
                first_cell = nullptr ;
                last_cell = nullptr ;
                delete p ;
            }
            else {
                first_cell = first_cell->next_cell ;
                first_cell->prev_cell = nullptr ;
                delete p ;
            }
        }
    }
    void remove_back () {
       if (not is_empty()) {
            IntCell* p = last_cell ;
            if (size()==1) {
                first_cell = nullptr ;
                last_cell = nullptr ;
                delete p ;
            }
            else {
                last_cell = last_cell->prev_cell ;
                last_cell->next_cell = nullptr ;
                delete p ;
            }
        }
    }

    void remove (int n) {
        if (not search(n))
            std::cout << "L'entier n'est pas dans la liste." << std::endl ;
        else {
            int s = size() ;
            IntCell* p = first_cell ;
            if ((*p).content == n) {
                std::cout << "remove_front effectué" << std::endl << " Value : " << (*p).content << std::endl ;
                remove_front() ;
            }
            else {
                for (int k = 1 ; k<s ; k++) {
                    p = (*p).next_cell ;
                    if ((*p).content = n) {
                        IntCell* p_prev = (*p).prev_cell ;
                        (*p_prev).next_cell = (*p).next_cell ;
                        if ((*p).next_cell != nullptr) {
                            IntCell* p_next = (*p).next_cell ;
                            (*p_next).prev_cell = (*p).prev_cell ;
                            delete p ;
                            std::cout << "Pas de remove_back" << std::endl ;
                        }
                        else
                            remove_back() ;
                            std::cout << "remove_back" << std::endl ;
                        break ;
                    }
                }
            }
        }
    }

            // else {
        //     for (int k = 1 ; k<s ; k++) {
        //         p = (*p).next_cell ;
        //         if ((*p).content = n) {
        //             (*((*p).prev_cell)).next_cell = (*p).next_cell ;
        //             if ((*p).next_cell != nullptr) {
        //                 (*((*p).next_cell)).prev_cell = (*p).prev_cell ;
        //                 delete p ;
        //             }
        //             else
        //                 remove_back() ;
        //             break ;
        //         }
        //     }
        // }

    bool search (int n) {
        int s = size() ;
        IntCell* p = first_cell ;
        if ((*p).content = n)
            return true ;
        for (int k = 1 ; k<s ; k++) {
            p = (*p).next_cell ;
            if ((*p).content = n)
                return true ;
        }
        return false ;
    }

    void print () {
        std::cout << "{" ;
        if (not is_empty()) {
            IntCell* pcell = first_cell ;
            while ((*pcell).next_cell != nullptr) {
                std::cout << (*pcell).content << ' ';
                pcell = (*pcell).next_cell ;
            }
            std::cout << (*pcell).content << ' ';
        }
        std::cout << "}" << std::endl ;
    }

    int size () {
        if (is_empty()) {
            return 0 ;
        }
        int s = 1 ;
        IntCell* pcell = first_cell ;
        while ((*pcell).next_cell != nullptr) {
            pcell = (*pcell).next_cell ;
            s = s+1 ;
        }
        return s ;
    }

private:
    // les attributs de la liste
    IntCell* first_cell ;
    IntCell* last_cell ;
};