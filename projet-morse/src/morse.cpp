#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>

#include "codage.h"
#include "decodage.h"
#include "creataudio.h"
#include "readaudio.h"

#include "tests.h"
using namespace std;

// vr: évite de mettre du code dans le main appelle une fonction ou une méthode de classe sur un objet
void menu_morse () {
  string str = "";
  cout << "Entrez votre phrase en français ou en morse :" << endl ;
  // vr: dire qu'on peut entrer un fichier wav
  getline(cin,str);
  int len = str.length() ;
  if(str[0]=='-' || str[0]=='.') {
    cout << morsetotext(str) << endl;
  }
  else if (str[len-4]=='.' && str[len-3]=='w') {
    cout << morsetotext(readaudio(str)) << endl ;
  }
  else {
    string codemorse = texttomorse(str) ;
    cout << codemorse << endl;
    creataudio (codemorse) ;
  }
}

int main() {
  /*
  test_textmorse();
  test_morsetext();
  test_audio();
  test_read_audio();
  */
  menu_morse();
  return 0;
}
