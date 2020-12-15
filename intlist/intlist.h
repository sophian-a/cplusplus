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
        // ...
    }
};

class IntList {
public:    
    // constructeur et destructeur
    IntList() {
        // ...
    }

    // ~IntList() {
    //     // ...
    // }

    bool is_empty() {
        return first_cell == 0 ;
    }

    void add_front (int n) {
        IntCell cell(n) ;
        if(is_empty()) {
            first_cell = &cell ;
            last_cell = &cell ;
        }
        else {
            cell.next_cell = first_cell ;
            first_cell = &cell ;
        }
       
    }
    void add_back (int n) {
        IntCell cell(n) ;
        if(is_empty()) {
            first_cell = &cell ;
            last_cell = &cell ;
        }
        else {
            cell.prev_cell = first_cell ;
            last_cell = &cell ;
        }
    }
    // void remove_front () {
    //    // votre code ici
    // }
    // void remove_back () {
    //    // votre code ici
    // }
    // void remove (/* argument */) {
    //    // votre code ici
    // }
    // /* type ici */ search (/* argument */) {
    // }

    void print () {
        std::cout << "{" ;
        IntCell cell = *first_cell ;
        std::cout << cell.content << " " ;
        std::cout << "}" << std::endl ;
    }

    // int size () {
    //     // ...
    // }

private:
    // les attributs de la liste
    IntCell* first_cell ;
    IntCell* last_cell ;
};