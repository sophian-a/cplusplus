#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include "codage.h"
#include "decodage.h"
#include "creataudio.h"
#include "readaudio.h"
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

// On suppose que la création du fichier audio est correcte
// vr: correction de la fonction qui s'appelait test_read-audio et pas test_read_audio
bool test_read_audio() {
    string morse = "---.-.---.-...---.---.---...---.-.-...-.......---.---...---.---.---...-.---.-...-.-.-...-";
    creataudio(morse) ;
    string decod = readaudio("codemorse.wav") ;
    return decod == morse ;
}
