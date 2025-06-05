#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int numeroImparAleatorio() {
    int num;
    do {
        num = rand() % 99 + 1;
    } while (num % 2 == 0);
    return num;
}

int numeroParAleatorio() {
    int num;
    do {
        num = rand() % 99 + 1;
    } while (num % 2 != 0);
    return num;
}

int main() {
    srand(time(NULL));
    int vector[30];

    for (int i = 0; i < 30; i++) {
        if (i % 2 == 0)  
            vector[i] = numeroImparAleatorio();
        else  
            vector[i] = numeroParAleatorio();
    }

    for (int i = 0; i < 30; i++) {
        cout << "Posición " << i << ": " << vector[i] << endl;
    }
}
