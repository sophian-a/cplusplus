#include <map>
#include <string>
#include <iostream>
using namespace std;

// vr: il faudrait éviter de créer le dictionnaire à chaque fois que vous appelez la fonction texttomorse, vous auriez pu écrire une classe
string texttomorse(string str) {
  // vr: mettre plutôt un dictionnaire map<char, string> vous utiliserez ainsi des char 'A' plutôt que des char* "A"
  // vr: je ne comprends pas votre code morse https://www.lexilogos.com/clavier/morse.htm ou
    map<string, string> m;
    m["A"] = "-.---"; // vr: je ne comprends pas votre code ? 'A' est normalement ".-"
    m["B"] = "---.-.-"; // vr: erreur: pas le même codage que le 'B' de decodage.cpp
    m["C"] = "---.-.---.-";
    m["D"] = "---.-.-";
    m["E"] = "-";
    m["F"] = "-.-.---.-";
    m["G"] = "---.---.-";
    m["H"] = "-.-.-.-";
    m["I"] = "-.-";
    m["J"] = "-.---.---.---";
    m["K"] = "---.-.---";
    m["L"] = "-.---.-.-";
    m["M"] = "---.---";
    m["N"] = "---.-";
    m["O"] = "---.---.---";
    m["P"] = "-.---.---.-";
    m["Q"] = "---.---.-.---";
    m["R"] = "-.---.-";
    m["S"] = "-.-.-";
    m["T"] = "---";
    m["U"] = "-.-.---";
    m["V"] = "-.-.-.---";
    m["W"] = "-.---.---";
    m["X"] = "---.-.-.---";
    m["Y"] = "---.-.---.---";
    m["Z"] = "---.---.-.-";
    m[" "] = "." ;

    string trad = "" ;
    string car ;
    int len = str.size() ;
    for (int i=0 ; i<len ; i++) {
        car = str[i] ;
        trad.append(m[car]) ;
        if (i!=len-1) {
            trad.append("...");
        }
    }
    return trad ;
}
