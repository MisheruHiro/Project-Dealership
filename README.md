# Project-Dealership
Il programma consiste nella gestione delle vendite e ordini di una Concessionaria Automobilistica, è gestibile solo dall’amministratore. La schermata principale sarà disposta utilizzando uno Switch Case come segue:

Attenzione: Prima che il progamma vi mostri quetsa schermata ci sarà una richiesta di inserire la password (Ludostorm), e vi chiederà in oltre di aggiungere la data odierna nel programma.

Menu

1- Inserimento auto nuove

2- Inserimento auto usate

3- Auto presenti in concessionaria

4- Vendita Nuovo

5- Vendita Usato

6- Elenco Ordini Effettuati

7- Ordina un veicolo

0- Esci

►Nell’opzione “Inserimento auto nuove/usate” verranno prese in considerazione le seguenti caratteristiche: marca, modello, carburante, colore e cilindrata, tramite l’inserimento da tastiera. Il programma chiederà inoltre se aggiungere anche il pacchetto optional, se la risposta è affermativa l’utente amministratore potrà inserire singolarmente gli optional che saranno presenti nel pacchetto, se invece è negativa il campo degli optional rimarrà vuoto.
Questi valori verranno inseriti all’interno di due Struct (una per il veicolo nuovo e l’altra per il pacchetto optional che dovrebbe comprendere quel mezzo se presente), verrà eseguito un inserimento ordinato in una lista per ottimizzare il lavoro, e avverrà per marca e modello del veicolo. Le liste saranno divise per auto nuove e usate. Nelle auto usate al posto degli optional sarà presente il chilometraggio.

►Nell’opzione “Auto presenti in concessionaria” il programma chiederà, tramite un altro Switch Case, quale lista delle auto vuole visualizzare scegliendo tra “Lista nuovo” e “Lista usato”. Verrà eseguita una funzione per stampare la lista desiderata. La lista riguardante il nuovo verrà stampata eseguendo due printf dedicati uno per la lista “lista_nuovo” e l’altro per la lista “pacchetto_optional”, in questo modo si avrà una visuale chiara sui veicoli che avranno o meno gli optional. Riporto un esempio:
  
  Marca e Modello   carburante    colore    cilindrata    optional
  Fiat Panda        Diesel        Rosso     1300cc        cerchi in lega; climatizzatore;
  Volkswagen Golf   Benzina       Grigio    1500cc

►Nell’opzione “Vendita Nuovo/Usato” verrà chiesto inizialmente di inserire, sempre tramite tastiera, marca e modello dell’auto. Successivamente il programma chiederà, tramite uno Switch Case, di scegliere tra Versione base e Versione Accessoriata.
-Nella sezione Versione Accessoriata sarà possibile scegliere il carburante, il colore, la cilindrata e l’eventuale pacchetto optional (quest’ultimo per verificare se è presente il pacchetto verrà eseguito un controllo alla testa della lista, se risulta come valore NULL allora il pacchetto non è presente, se invece la testa punta ad un elemento allora è presente).
-Nella sezione Versione base sì cercherà il veicolo solo per marca e modello senza l’aggiunta di altre caratteristiche.
La scelta della versione sarà possibile solo per la vendita del nuovo. Se il veicolo cercato non risulta nella lista, il programma chiederà se lo si vuole ordinare, in questo modo la funzione, che attualmente è eseguita, terminerà e passerà alla funzione dedicata agli ordini, questa scelta sarà disponibile solo per il nuovo. Quando verrà venduto un veicolo il programma eseguirà la cancellazione dell’elemento dalla lista.

►Nell’opzione “Elenco Ordini Effettuati” il programma eseguirà la stampa della lista su schermo seguendo un ordine per data di consegna, successivamente il programma effettuerà una scansione della lista per eventuali nuovi arrivi, confrontando la data di esecuzione del programma con quella della lista. Se il programma troverà una o più auto in arrivo lo stesso giorno, chiederà se si vorrà spostare il veicolo nella lista delle auto nuove per poi cancellarla dalla lista degli ordini.

►Nell’opzione “Ordina un veicolo” il programma chiederà di inserire marca, modello, carburante, colore, cilindrata e pacchetto optional (se richiesto) del mezzo cercato. Gli ordini effettuati verranno inseriti in una lista con ordine cronologico di data di arrivo utilizzando un inserimento in coda, e arriveranno una settimana dopo la richiesta. Questa opzione può essere eseguita sia nel menu principale che nell’opzione “Vendita Nuovo”.

►Nell’opzione “Esci” il programma eseguirà la chiusura e salverà il lavoro sui file.
