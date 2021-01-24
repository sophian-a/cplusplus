#include <map>
#include <string>
#include <iostream>
using namespace std;

string texttomorse(string str) {
    map<string, string> m;
    m["A"] = "-.---";
    m["B"] = "---.-.-";
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