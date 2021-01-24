#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include "codage.h"
#include "decodage.h"
#include "creataudio.h"
using namespace std;

int main() {
    string str = "";
    cout << "Entrez votre phrase en français ou en morse :" << endl ;
    getline(cin,str);
    if(str[0]=='-' || str[0]=='.') {
        cout << morsetotext(str) << endl;
    }
    else {
        string codemorse = texttomorse(str) ;
        cout << codemorse << endl;
        creataudio (codemorse) ;
    }
    return 0;
}
