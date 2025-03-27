#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

// Saldo iniziale del conto
int saldo = 1000;

// Mutex per proteggere l'accesso al saldo
mutex mtx;

// Funzione eseguita da ciascun thread
void prelievo(string nome){
    for(int i = 0; i < 5; i++){
        // Importo casuale tra 50 e 300 euro
        int importo = rand() % 251 + 50;
        
        // Simula un ritardo prima di tentare il prelievo
        sleep(rand() % 2 + 1);

        // Sezione critica: acceso protetto al saldo
        mtx.lock();
        cout << nome << " tenta di prelevare " << importo << " euro." << endl;

        if(saldo >= importo){
            saldo -= importo;
            cout << nome << " ha prelevato con successo." << endl;
        } else {
            cout << nome << " non ha potuto prelevare: saldo insufficiente." << endl;
        }

        cout << "Saldo attuale: " << saldo << " euro.\n" << endl;
        mtx.unlock();

        // Attesa tra un prelievo e l'altro
        sleep(rand() % 2 + 1);
    }
}

int main(){
    srand(time(NULL)); // Inizializzazione del generatore casuale

    // Creazione dei tre thread
    thread t1(prelievo, "Cliente 1");
    thread t2(prelievo, "Cliente 2");
    thread t3(prelievo, "Cliente 3");

    // Attesa della conclusione dei thread
    t1.join();
    t2.join();
    t3.join();

    cout << "\nOperazioni concluse. Saldo finale: " << saldo << " euro." << endl;

    return 0;
}
