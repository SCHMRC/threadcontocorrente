Scrivi un programma in C++ che simuli un conto corrente con un saldo iniziale di 1000 euro.
Tre thread rappresentano tre persone diverse che cercano di prelevare soldi in momenti diversi.
Ogni persona tenta 5 prelievi, con importi casuali tra 50€ e 300€.
Il prelievo può avvenire solo se c’è abbastanza denaro sul conto.
L’accesso al saldo deve essere protetto da un mutex, per evitare errori o condizioni di race.
Dopo ogni operazione, stampa:
Chi ha tentato il prelievo
Quanto ha richiesto
Se il prelievo è riuscito o meno
Il saldo aggiornato
