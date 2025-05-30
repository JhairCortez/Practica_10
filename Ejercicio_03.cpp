#include <iostream>
#include <map>
#include <sstream>
using namespace std;

map<string, char> crearDiccionarioMorse() {
    map<string, char> morse;
    morse[".-"] = 'A';     morse["-..."] = 'B';   morse["-.-."] = 'C';
    morse["-.."] = 'D';    morse["."] = 'E';      morse["..-."] = 'F';
    morse["--."] = 'G';    morse["...."] = 'H';   morse[".."] = 'I';
    morse[".---"] = 'J';   morse["-.-"] = 'K';    morse[".-.."] = 'L';
    morse["--"] = 'M';     morse["-."] = 'N';     morse["---"] = 'O';
    morse[".--."] = 'P';   morse["--.-"] = 'Q';   morse[".-."] = 'R';
    morse["..."] = 'S';    morse["-"] = 'T';      morse["..-"] = 'U';
    morse["...-"] = 'V';   morse[".--"] = 'W';    morse["-..-"] = 'X';
    morse["-.--"] = 'Y';   morse["--.."] = 'Z';
    morse["-----"] = '0';  morse[".----"] = '1';  morse["..---"] = '2';
    morse["...--"] = '3';  morse["....-"] = '4';  morse["....."] = '5';
    morse["-...."] = '6';  morse["--..."] = '7';  morse["---.."] = '8';
    morse["----."] = '9';
    return morse;
}

string morseADecodificado(string entrada) {
    map<string, char> morse = crearDiccionarioMorse();
    stringstream ss(entrada);
    string codigo, resultado = "";

    while (ss >> codigo) {
        if (codigo == "/") {
            resultado += " ";
        } else if (morse.count(codigo)) {
            resultado += morse[codigo];
        } else {
            resultado += '?';
        }
    }
    return resultado;
}

int main() {
    string codigoMorse;
    cout << "Ingrese el texto en código Morse (separe letras con espacios y palabras con '/'): ";
    getline(cin, codigoMorse);

    string traducido = morseADecodificado(codigoMorse);
    cout << "Texto traducido: " << traducido << endl;

    return 0;
}
