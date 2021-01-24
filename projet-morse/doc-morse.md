# Projet C++
## Traducteur morse-français
Sophian AKKARI
Janvier 2021

### Choix d'écriture du morse
Pour ce programme, nous avons choisi une écriture qui ne nécessite que deux caractères (il s'agit en fait du _vrai_ morse).
* un point (ou _ti_) s'écrit : `-`
* un tiret (ou _ta_) s'écrit : `---`
* entre deux caractères, on laisse un espace, codé par un point : `.`
* entre deux lettre, on laisse trois espaces : `...`
* entre deux mots, on laisse sept espaces : `.......`
Ainsi, CODE MORSE s'écrit :
    ---.-.---.-...---.---.---...---.-.-...-.......---.---...---.---.---...-.---.-...-.-.-...-
Il faut bien utiliser les caractères `-` et `.` sans quoi le programme ne fonctionnera pas correctement.

### Fonctionnement du programme
Pour lancer le programme, il faut le compiler (commande `make`) puis l'exécuter : `./morse`
Puis le programme demande à l'utilisateur de saisir sa phrase à coder/décoder ou le nom du fichier audio à décoder (avec l'extension `.wav` !). Le programme reconnaît automatiquement s'il s'agit de morse ou de texte ou d'un nom de fichier. Le texte doit être écrit en majuscule. Le code morse doit respecter les conventions décrites ci-dessus. Lee fichier doit être situé dans le même répertoire.
* S'il s'agit de texte, le programme affiche la traduction en morse (avec les points et les tirets) et génère un fichier .wav dans le même répertoire, nommé `codemorse.wav` et qui correspond au code morse en version audio. Deux fréquences différentes sont utilisées pour coder le point et le tiret : un silence correspond au point et un son au tiret (avec point et tiret qui se réfèrent à la syntaxe utilisée par le programme).
* S'il s'agit de morse, le programme traduit en alphabet latin et affiche simplement la traduction.
* S'il s'agit d'un fichier audio, le programme affiche la traduction en alphabet latin.

### Spécifications techniques de génération du format wav
Le programme est paramétré avec une fréquence à 500 Hz. Un tiret ou un point est transformé en un son d'une demi seconde.

### Tests
Des fonctions de tests ont été codées dans le fichier `tests.cpp`. 
Elles ne sont pas incluses dans le main de la fonction morse (contenu dans le fichier `morse.cpp`). Cependant, il existe un fichier `tests.h` qui permet d'inclure des fonctions de tests dans le programme (ou dans un autre). On a pris soin de protéger les fichiers contre l'inclusion multiple.
Bien entendu, le code morse présent dans le fichier de test n'a pas été obtenu avec le programme mais sur internet. Cependant, le test de la fonction de lecture d'un fichier `.wav` nécessite le fonctionnement correct de la fonction de création d'un fichier `.wav`.
