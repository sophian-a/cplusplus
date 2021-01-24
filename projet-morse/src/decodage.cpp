#include <map>
#include <string>
#include <iostream>
using namespace std;

string trad_mot_m(string mot) {
    map<string, string> m;
    m["-.---"] = "A" ;
    m["---.-.-.-"] = "B" ;
    m["---.-.-.-"] = "C" ;
    m["---.-.---.-"] = "D" ;
    m["-"] = "E" ;
    m["-.-.---.-"] = "F" ;
    m["---.---.-"] = "G" ;
    m["-.-.-.-"] = "H" ;
    m["-.-"] = "I" ;
    m["-.---.---.---"] = "J" ;
    m["---.-.---"] = "K" ;
    m["-.---.-.-"] = "L" ;
    m["---.---"] = "M" ;
    m["---.-"] = "N" ;
    m["---.---.---"] = "O" ;
    m["-.---.---.-"] = "P" ;
    m["---.---.-.---"] = "Q" ;
    m["-.---.-"] = "R" ;
    m["-.-.-"] = "S" ;
    m["---"] = "T" ;
    m["-.-.---"] = "U" ;
    m["-.-.-.---"] = "V" ;
    m["-.---.---"] = "W" ;
    m["---.-.-.---"] = "X" ;
    m["---.-.---.---"] = "Y" ;
    m["---.---.-.-"] = "Z" ;
    string mottrad = "" ;
    string lettre ;
    int i = 0 ; // on va travailler avec des doubles curseurs
    int j = 0 ;
    while (j!=-1) {
        j=mot.find("...", i); // on sépare les lettres
        lettre = mot.substr(i, j-i);
        mottrad.append(m[lettre]) ;
        i=j+3;
    }
    return mottrad;
}

string morsetotext(string str) { // on veut séparer les séquences puis les convertir en texte puis les réassembler
    string trad = "" ;
    string mot ;
    // int len = str.size() ;
    int i = 0 ; // on va travailler avec des doubles curseurs
    int j = 0 ;
    while (j!=-1) {
        j=str.find(".......", i); // on sépare les mots
        mot = str.substr(i, j-i);
        trad.append(trad_mot_m(mot));
        if (j!=-1) {
            trad.append(" ");
        }
        i=j+7;
    }
    return trad ;
}