#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include "codage.h"
#include "decodage.h"
#include "creataudio.h"
using namespace std;

bool test_textmorse() {
    string morse = "---.-.---.-...---.---.---...---.-.-...-.......---.---...---.---.---...-.---.-...-.-.-...-";
    string texte = "CODE MORSE" ;
    return morse == texttomorse(texte);
}

bool test_morsetext() {
    string morse = "---.-.---.-...---.---.---...---.-.-...-.......---.---...---.---.---...-.---.-...-.-.-...-";
    string texte = "CODE MORSE" ;
    return texte == morsetotext(morse);
}

void test_audio() {
    string morse = "---.-.---.-...---.---.---...---.-.-...-.......---.---...---.---.---...-.---.-...-.-.-...-";
    creataudio(morse) ;
    cout << "Vérifier la correspondance du son avec le code morse suivant :" << endl ;
    cout << morse << endl ;
}