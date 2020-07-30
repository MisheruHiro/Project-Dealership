#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_odierna{
	int giorno;
}data_odierna;

struct pacchetto_optional{
	char optional[21];
	struct pacchetto_optional* next;
}pac_opt;

typedef struct veicolo_nuovo{
	char marca_modello[31];
	char carburante[11];
	char colore[11];
	int cilindrata;
}veicolo_n;

struct lista_nuovo{
	veicolo_n veic_n;
	struct pacchetto_optional *head_opt;
	struct lista_nuovo* next;
};

typedef struct viecolo_usato{
	char marca_modello[31];
	char carburante[11];
	char colore[11];
	int cilindrata;
	int chilometraggio;
}veicolo_u;

struct lista_usato{
	veicolo_u veic_u;
	struct lista_usato* next;
};

typedef struct ordine_veicolo{
	int giorno2;
	char marca_modello[31];
	char carburante[11];
	char colore[11];
	int cilindrata;
}ordine_v;

struct lista_ordini{
	ordine_v ordi;
	struct pacchetto_optional *head_opt;
	struct lista_ordini* next;
};

//NUOVO//Funzione usata per la stampa della lista dei veicoli nuovi, se non comprendono gli optional la casella relativa rimane vuota.
void stampa_lista_nuovo(struct lista_nuovo *head_n){
	struct pacchetto_optional *temp_opt=NULL; //temp_opt è un puntatore temporaneo che punta agli optional di un veicolo
	
	printf("\nLista_nuovo:\n");
	while(head_n!=NULL){
		temp_opt=head_n->head_opt;
		printf("\nMarca&Modello\t\tCarburante\t\tColore\t\tCilindrata\t\tOptional\n");
		printf("%s\t\t%s\t\t\t%s\t\t%dcc\t\t\t", head_n->veic_n.marca_modello, head_n->veic_n.carburante, head_n->veic_n.colore, head_n->veic_n.cilindrata);
		
		while(temp_opt!=NULL){
			printf("%s; ", temp_opt->optional);
			temp_opt=temp_opt->next;
		}
		printf("\n");
		head_n=head_n->next;
	}
}

//USATO//Funzione usata per la stampa della lista dei viecoli usati.
void stampa_lista_usato(struct lista_usato *head_u){
	
	printf("\nLista usato:\n");
	while(head_u!=NULL){
		printf("\nMarca&Modello\t\tCarburante\t\tColore\t\tCilindrata\t\tChilometraggio\n");
		printf("%s\t\t%s\t\t\t%s\t\t%dcc\t\t\t%dkm\n", head_u->veic_u.marca_modello, head_u->veic_u.carburante, head_u->veic_u.colore, head_u->veic_u.cilindrata, head_u->veic_u.chilometraggio);
		
		head_u=head_u->next;
	}
}

//NUOVO//Funzione usata per inserire gli elementi che compongono il veicolo nella lista. Gli optional vengono inseriti sempre in questa funzione, se non viene aggiunto nessun optional la testa head_opt punterà a NULL.
void lista_nuovo(struct lista_nuovo **head_n, char* marca_modello, char* carburante, char* colore, int cilindrata){
	char risposta;
	veicolo_n veic_n;
	
	strcpy(veic_n.marca_modello, marca_modello);
	strcpy(veic_n.carburante, carburante);
	strcpy(veic_n.colore, colore);
	veic_n.cilindrata=cilindrata;
	
	struct lista_nuovo *p;
	struct lista_nuovo *r=*head_n, *q=*head_n;
	p=(struct lista_nuovo*)malloc(sizeof(struct lista_nuovo));
	p->veic_n=veic_n;
	p->next=*head_n;
	
	while ((q!=NULL) && (strcmp(q->veic_n.marca_modello, p->veic_n.marca_modello)<0)){
		r = q;
		q = q->next;
	}
	
	if(q==*head_n){
	*head_n=p;
	}
		
	else {
	r->next = p;
	p->next = q;
	}
	
	printf("\nHai inserito %s con alimentazione a %s, colore %s e cilindrata %dcc\n", veic_n.marca_modello, veic_n.carburante, veic_n.colore, veic_n.cilindrata);
	printf("\nVuoi aggiungere gli optional?\ninserisci la risposta(S/N):");
	fflush(stdin);
	scanf(" %c", &risposta);
	
	if(risposta=='s'){
		struct pacchetto_optional *testa_opt=NULL;
		char optional[21];
	
		while(risposta=='s'){
			printf("\nInserisci l'optional:\n");
			scanf(" %s", optional);
			
			struct pacchetto_optional *o;
			o=(struct pacchetto_optional*)malloc(sizeof(struct pacchetto_optional));
			strcpy(o->optional, optional);
			o->next=testa_opt;
			testa_opt=o;
			
			printf("\nVuoi inserire un altro oprional?\nInserisci S o N:");
			scanf(" %c", &risposta);
		}
		p->head_opt=testa_opt;
		printf("\nVeicolo inserito!\n");
	}
	else{
		p->head_opt=NULL;
		printf("\nVeicolo Inserito\n");
	}
}

//NUOVO//Funzione usata per l'inserimento di un veicolo nuovo.
void inserimento_auto_nuove(struct lista_nuovo **head_n){
	veicolo_n veic_n;
	char c;
	char risposta;
	
	char marca_modello[31];
	char carburante[11];
	char colore[11];
	int cilindrata;
	
	while((c=getchar())!='\n' && c!=EOF); //Svuota il Buffer
	
	printf("\ninserisci la marca ed il modello del veicolo: (usare '_' per distanziare le parole)\n");
	gets(marca_modello);
	printf("inserisci il tipo di carburante usato:\n");
	gets(carburante);
	printf("inserisci il colore:\n");
	gets(colore);
	printf("inserisci la cilindrata:\n");
	scanf("%d", &cilindrata);
	
	lista_nuovo(head_n, marca_modello, carburante, colore, cilindrata);
}

//USATO//Funzione usata per inserire gli elementi che compongono il veicolo (in questo caso usato) nella lista.
void lista_usato (struct lista_usato **head_u, char* marca_modello, char* carburante, char* colore, int cilindrata, int chilometraggio){
	veicolo_u veic_u;
	
	strcpy(veic_u.marca_modello, marca_modello);
	strcpy(veic_u.carburante, carburante);
	strcpy(veic_u.colore, colore);
	veic_u.cilindrata=cilindrata;
	veic_u.chilometraggio=chilometraggio;
	
	struct lista_usato *p;
	struct lista_usato *r=*head_u, *q=*head_u; 
	p=(struct lista_usato*)malloc(sizeof(struct lista_usato));
	p->veic_u=veic_u;
	p->next=*head_u;
	
	while ((q!=NULL) && (strcmp(q->veic_u.marca_modello, p->veic_u.marca_modello)<0)){
		r = q;
		q = q->next;
	}
	
	if(q==*head_u){
	*head_u=p;
	}
		
	else {
	r->next = p;
	p->next = q;
	}
}

//USATO//Funzione usata per l'inserimento di un veicolo usato
void inserimento_auto_usate(struct lista_usato **head_u){
	char c;
	
	char marca_modello[31];
	char carburante [11];
	char colore [11];
	int cilindrata;
	int chilometraggio;
	
	while((c=getchar())!='\n' && c!=EOF); //Svuota il Buffer
	
	printf("\nInserisci la marca ed il modello del veicolo (usare '_' per distanziare le parole):\n");
	fflush(stdin);
	gets(marca_modello);
	printf("Inserisci il tipo di carburante usato:\n");
	fflush(stdin);
	gets(carburante);
	printf("inserisci il colore:\n");
	fflush(stdin);
	scanf("%s",colore);
	printf("inserisci la cilindrata:\n");
	fflush(stdin);
	scanf("%d",&cilindrata);
	printf("inserisci il chilometraggio:\n");
	fflush(stdin);
	scanf("%d",&chilometraggio);
	
	lista_usato(head_u, marca_modello, carburante, colore, cilindrata, chilometraggio);
	printf("\nVeicolo Inserito\n");
}

//Funzione deidicata per la stampa delle liste dei veicoli.
void stampa_lista_auto(struct lista_usato *head_u, struct lista_nuovo *head_n){
	int opzione;
	
	printf("\nSeleziona la lista da stampare:\n");
	printf("1- Lista nuovo\n");
	printf("2- Lista usato\n");
	printf("Inserisci:");
	scanf("%d", &opzione);
	
	switch(opzione){
		case 1:
			stampa_lista_nuovo(head_n);
			break;
			
		case 2:
			stampa_lista_usato(head_u);
			break;
			
		default:
			printf("\nAttenzione: Comando inesistente\n");
			break;
	}
}

//ORDINE//Funzione usata per inserire gli elementi che compongono il veicolo nella lista ordini. Gli optional vengono inseriti sempre in questa funzione, se non viene aggiunto nessun optional la testa head_opt punterà a NULL.
void lista_ordini(struct lista_ordini **head_ord, int giorno2,  char* marca_modello, char* carburante, char* colore, int cilindrata){
	char risposta;
	ordine_v ordi;
	
	ordi.giorno2=giorno2;
	strcpy(ordi.marca_modello, marca_modello);
	strcpy(ordi.carburante, carburante);
	strcpy(ordi.colore, colore);
	ordi.cilindrata=cilindrata;
	
	struct lista_ordini *temp_ord;
	struct lista_ordini *po;
	po=(struct lista_ordini *)malloc(sizeof(struct lista_ordini));
	po->ordi=ordi;
	po->next=NULL;
	
	if(*head_ord==NULL){
		*head_ord=po;
	}
	
	else{
		temp_ord=*head_ord;
		while(temp_ord->next!=NULL){
			temp_ord=temp_ord->next;
		}
		temp_ord->next=po;
	}
	
	printf("\nHai inserito l'ordine per %s con alimentazione a %s, colore %s e cilindrata %dcc\n", ordi.marca_modello, ordi.carburante, ordi.colore, ordi.cilindrata);
	printf("\nVuoi aggiungere gli optional?\ninserisci la risposta(S/N):");
	fflush(stdin);
	scanf(" %c", &risposta);
	
	if(risposta=='s'){
		struct pacchetto_optional *testa_opt=NULL;
		char optional[21];
	
		while(risposta=='s'){
			printf("\nInserisci l'optional:\n");
			scanf(" %s", optional);
		
			struct pacchetto_optional *or;
			or=(struct pacchetto_optional*)malloc(sizeof(struct pacchetto_optional));
			strcpy(or->optional, optional);
			or->next=testa_opt;
			testa_opt=or;
		
			printf("\nVuoi inserire un altro oprional?\nInserisci S o N:");
			scanf(" %c", &risposta);
		}
		po->head_opt=testa_opt;
		printf("\nVeicolo Inserito\n");
	}
	else{ 
		po->head_opt==NULL;
		printf("\nVeicolo Inserito\n");
	}
}

//ORDINE//Funzione usata per l'inserimento di un veicolo nuovo da ordinare.
void inserimento_ordine_veicolo(struct lista_ordini **head_ord, int giorno){
	ordine_v ordi;
	
	char c;
	char marca_modello[30];
	char carburante[10];
	char colore[10];
	int cilindrata;
	int giorno2;
	
	while((c=getchar())!='\n' && c!=EOF); //Svuota il Buffer
	
	//giorno=data_odierna.giorno;
	
	printf("\ninserisci la marca ed il modello del veicolo (usare '_' per distanziare le parole):\n");
	gets(marca_modello);
	printf("inserisci il tipo di carburante usato:\n");
	gets(carburante);
	printf("inserisci il colore:\n");
	gets(colore);
	printf("inserisci la cilindrata:\n");
	scanf("%d", &cilindrata);
	
	printf("\nUna volta eseguita l'ordinazione il veicolo verrà consegnato una settimana dopo la richiesta\nLa Data di oggi è %d.\n", giorno);
	printf("Inserisci il giorno di consegna:");
	scanf("%d", &giorno2);
	
	lista_ordini(head_ord, giorno2, marca_modello, carburante, colore, cilindrata);
}

//USATO//Funzione usata per eliminare il veicolo usato che è stato venduto
void cancella_veicolo_usato(struct lista_usato **head_u, char* marca_modello){
	
	struct lista_usato *pre=*head_u, *suc=*head_u;
	while((suc!=NULL)&& strcmp(suc->veic_u.marca_modello, marca_modello)){
		pre=suc;
		suc=suc->next;
	}
	if(suc==NULL) return;
	
	if(suc==*head_u) *head_u=(*head_u)->next;
	else pre->next=suc->next;
	
	free(suc);
}

//USATO//Funzione usata per la ricerca di un veicolo usato
struct lista_usato* trova_veicolo(struct lista_usato *head_u, char* marca_modello){
	struct lista_usato *p;
	p=head_u;
	
	while((p!=NULL)&& strcmp(p->veic_u.marca_modello, marca_modello)){
		p=p->next;
	}
	return p;
}

//USATO//Funzione deidicata alla vendita dei viecoli usati.
void vendita_usato(struct lista_usato **head_u){
	struct lista_usato *veicolo;
	char c;
	char risposta='s';
	char marca_modello[30];
	
	while(risposta=='s'){
		printf("\nInsrisci la marca ed il modello del veicolo (usare '_' per distanziare le parole):\n");
		
		while((c=getchar())!='\n' && c!=EOF); //Svuota il Buffer
		gets(marca_modello);
	
		veicolo=trova_veicolo(*head_u, marca_modello);
	
		if(veicolo==NULL){ 
			printf("\nIl veicolo non è presente!\nVuoi rieseguire la ricerca?\n Inserisci S o N:");
			scanf(" %c", &risposta);
		}
		
		else { 
			printf("\nTrovato!\nProseguire con l'acquisto?\nInserisci S o N:");
			scanf(" %c", &risposta);
		
			if(risposta=='s'){
				cancella_veicolo_usato(head_u, marca_modello);
				printf("\nVenduto!!\nIl veicolo è stato eliminato dalla lista\n");
				risposta='n';
			}
		}
	}
}

//NUOVO//Funzione usata per eliminare il veicolo nuovo (senza optional) che è stato venduto.
void cancella_veicolo_nuovo(struct lista_nuovo **head_n, char* marca_modello){
	struct pacchetto_optional *temp_opt=NULL;
	int i;
	
	struct lista_nuovo *pre=*head_n, *suc=*head_n;
	for(i=0; i<2;){
		if(suc==NULL) return;
		temp_opt=suc->head_opt;
		i=0;
		
		if(strcmp(suc->veic_n.marca_modello, marca_modello)==0){
			i++;
		}
		else{
			pre=suc;
			suc=suc->next;
			continue;
		}
	
		if(temp_opt->optional==NULL){
			i++;
		}
		else{ 
			pre=suc;
			suc=suc->next;
			continue;
		}
	}
	
	if(suc==*head_n) *head_n=(*head_n)->next;
	else pre->next=suc->next;
	
	free(suc);
}

//NUOVO//Funzione usata per eliminare il veicolo nuovo (con optional) che è stato venduto.
void cancella_veicolo_nuovo_opt(struct lista_nuovo **head_n, char* marca_modello, char* carburante, char* colore, int cilindrata){
	struct pacchetto_optional *temp_opt=NULL;
	int i;
	
	struct lista_nuovo *pre=*head_n, *suc=*head_n;
	for(i=0; i<5;){
		if(suc==NULL) return;
		temp_opt=suc->head_opt;
		i=0;
		
		if(strcmp(suc->veic_n.marca_modello, marca_modello)==0){
			i++;
		}
		else{
			pre=suc;
			suc=suc->next;
			continue;
		}
		
		if(strcmp(suc->veic_n.carburante, carburante)==0){
			i++;
		}
		else{ 
			pre=suc;
			suc=suc->next;
			continue;
		}
		
		if(strcmp(suc->veic_n.colore, colore)==0){
			i++;
		}
		else{ 
			pre=suc;
			suc=suc->next;
			continue;
		}
		
		if(suc->veic_n.cilindrata==cilindrata){
			i++;
		}
		else{ 
			pre=suc;
			suc=suc->next;
			continue;
		}
		
		if(temp_opt->optional!=NULL){
			i++;
		}
		else{ 
			pre=suc;
			suc=suc->next;
			continue;
		}
	}
	
	if(suc==*head_n) *head_n=(*head_n)->next;
	else pre->next=suc->next;
	
	free(suc);
}

//NUOVO//Funzione usata per la ricerca di un viecolo nuovo comprendenti gli optional.
struct lista_nuovo* trova_veicolo_nuovo_opt(struct lista_nuovo *head_n, char* marca_modello, char* carburante, char* colore, int cilindrata){
	struct pacchetto_optional *temp_opt=NULL;
	
	int i;
	for(i=0; i<5;){
		while(head_n==NULL) return head_n; //se head_n è uguale a NULL il veicolo che si sta cercando non è presente
		temp_opt=head_n->head_opt;
		i=0;
		
		if(strcmp(head_n->veic_n.marca_modello, marca_modello)==0){
			i++;
		}
		else{
			head_n=head_n->next;
			continue;
		}
		
		if(strcmp(head_n->veic_n.carburante, carburante)==0){
			i++;
		}
		else{ 
			head_n=head_n->next;
			continue;
		}
		
		if(strcmp(head_n->veic_n.colore, colore)==0){
			i++;
		}
		else{ 
			head_n=head_n->next;
			continue;
		}
		
		if(head_n->veic_n.cilindrata==cilindrata){
			i++;
		}
		else{ 
			head_n=head_n->next;
			continue;
		}
	
		if(temp_opt->optional!=NULL){
			i++;
		}
		else{ 
			head_n=head_n->next;
			continue;
		}
	}
	return head_n;
}

//NUOVO//Funzione usata per la ricerca di un veicolo nuovo senza optional.
struct lista_nuovo* trova_veicolo_nuovo(struct lista_nuovo *head_n, char* marca_modello){
	struct pacchetto_optional *temp_opt;
	
	int i;
	for(i=0; i<2;){
		while(head_n==NULL) return head_n; //se head_n è uguale a NULL il veicolo che si sta cercando non è presente
		temp_opt=head_n->head_opt;
		i=0;
		
		if(strcmp(head_n->veic_n.marca_modello, marca_modello)==0){
			i++;
		}
		else{
			head_n=head_n->next;
			continue;
		}
	
		if(temp_opt->optional==NULL){
			i++;
		}
		else{ 
			head_n=head_n->next;
			continue;
		}
	}
	return head_n;
}

//NUOVO//Funzione dedicata per la vendita di un veicolo nuovo accessoriato.
void versione_accessoriata(struct lista_nuovo **head_n, struct lista_ordini **head_ord, int giorno){
	struct lista_nuovo *veicolo_n_opt;
	
	char c;
	char risposta='s';
	char marca_modello[30];
	char carburante[10];
	char colore[10];
	int cilindrata;
	
	while(risposta=='s'){
		while((c=getchar())!='\n' && c!=EOF); //Svuota il Buffer
		
		printf("\nInsrisci la marca ed il modello del veicolo (usare '_' per distanziare le parole):\n");
		gets(marca_modello);
		printf("inserisci il tipo di carburante:\n");
		gets(carburante);
		printf("inserisci il colore:\n");
		gets(colore);
		printf("inserisci la cilindrata:\n");
		scanf("%d", &cilindrata);
	
		veicolo_n_opt=trova_veicolo_nuovo_opt(*head_n, marca_modello, carburante, colore, cilindrata);
		
		if(veicolo_n_opt==NULL){ 
			char risposta2;
			printf("\nIl veicolo non è presente\nVuoi eseguire l'ordine?\nInserisci S o N:");
			scanf(" %c", &risposta2);
			
			if(risposta2=='s'){ 
				inserimento_ordine_veicolo(head_ord, giorno);
				return;
			}
			else { 
				printf("\nVuoi rieseguire la ricerca?\nInserisci S o N:");
				scanf(" %c", &risposta);
			}
		}
	
		else { 
			printf("\nTrovato!\nProseguire con l'acquisto?\nInserisci S o N:");
			scanf(" %c", &risposta);
			
			if(risposta=='s'){
				cancella_veicolo_nuovo_opt(head_n, marca_modello, carburante, colore, cilindrata);
				printf("\nVenduto!!\nIl veicolo è stato eliminato dalla lista\n");
				risposta='n';
			}
		}
	}
}

//NUOVO//Funzione dedicata per la vendita di un veicolo nuovo di serie.
void versione_base(struct lista_nuovo **head_n){
	struct lista_nuovo *veicolo_n;
	
	char c;
	char risposta='s';
	char marca_modello[30];
	
	while(risposta=='s'){
		while((c=getchar())!='\n' && c!=EOF); //Svuota il Buffer
		printf("\nInsrisci la marca ed il modello del veicolo (usare '_' per distanziare le parole):\n");
		gets(marca_modello);
	
		veicolo_n=trova_veicolo_nuovo(*head_n, marca_modello);
	
		if(veicolo_n==NULL){ 
			printf("\nIl veicolo non è presente!\nVuoi rieseguire la ricerca?\n Inserisci S o N:");
			scanf(" %c", &risposta);
		}
	
		else { 
			printf("\nTrovato!\nProseguire con l'acquisto?\nInserisci S o N:");
			scanf(" %c", &risposta);
		
			if(risposta=='s'){
				cancella_veicolo_nuovo(head_n, marca_modello);
				printf("\nVenduto!!\nIl veicolo è stato eliminato dalla lista\n");
				risposta='n';
			}
		}
	}
}

//NUOVO//Funzione dedicata alla scelta del viecolo che si vuole vendere.
void vendita_nuovo(struct lista_nuovo **head_n, struct lista_ordini **head_ord, int giorno){
	
	int opzione;
		
		printf("\nScegliere la versione:\n");
		printf("1- Versione Accessoriata\n");
		printf("2- Versione Base\n");
		printf("Inserisci: ");
		scanf("%d", &opzione);
		
		switch(opzione){
			case 1:
				versione_accessoriata(head_n, head_ord, giorno);
				break;
				
			case 2:
				versione_base(head_n);
				break;
				
			default:
				printf("\nAttenzione: Comando inesistente\n");
				break;
		}
}

//ORDINE//Funzione usata per la stampa della lista dei veicoli ordinati
void stampa_lista_ordini(struct lista_ordini *head_ord){
	struct pacchetto_optional *temp_opt; //temp_opt è un puntatore temporaneo che punta agli optional di un veicolo
	
	printf("\nLista_ordini:\n");
	while(head_ord!=NULL){
		temp_opt=head_ord->head_opt;
		printf("\nConsegna\t\tMarca&Modello\t\tCarburante\t\tColore\t\tCilindrata\t\tOptional\n");
		printf("%d\t\t%s\t\t%s\t\t\t%s\t\t%dcc\t\t\t", head_ord->ordi.giorno2, head_ord->ordi.marca_modello, head_ord->ordi.carburante, head_ord->ordi.colore, head_ord->ordi.cilindrata);
		
		while(temp_opt!=NULL){
			printf("%s; ", temp_opt->optional);
			temp_opt=temp_opt->next;
		}
		printf("\n");
		head_ord=head_ord->next;
	}
}

//ORDINE//Funzione usata per eliminare il veicolo ordinato che è stato copiato nella lista dei veicoli nuovi
void cancella_veicolo_ordinato(struct lista_ordini **head_ord, int giorno){
	
	struct lista_ordini *pre=*head_ord, *suc=*head_ord;
	while((suc!=NULL) && (suc->ordi.giorno2!=giorno)){
		pre=suc;
		suc=suc->next;
	}
	if(suc==NULL) return;
	
	if(suc==*head_ord) *head_ord=(*head_ord)->next;
	else pre->next=suc->next;
	
	free(suc);
}

//ORDINE//Funzione usata per la ricerca di un ordine, se è arrivato qualcosa stamperà la stringa "Veicolo consegnato!!".
struct lista_ordini* ricerca_ordine_veicolo(struct lista_ordini **head_ord, int giorno, struct lista_nuovo **head_n){
	char c;
	char n;
	char risposta;
	char marca_modello[30];
	char carburante[10];
	char colore[10];
	int cilindrata;
	
	while((c=getchar())!='\n' && c!=EOF); //Svuota il Buffer
	
	struct lista_ordini *p;
	p=*head_ord;
	
	while((p!=NULL) && (p->ordi.giorno2!=giorno)){
		p=p->next;
	}
	if(p!=NULL){
		printf("\nVeicolo consegnato!!\n%s con alimentazione a %s, colore %s e cilindrata %dcc è arrivata!!\n", p->ordi.marca_modello, p->ordi.carburante, p->ordi.colore, p->ordi.cilindrata);
		printf("\nVuoi aggiungerlo alla lista nuovo?\nInserisci S o N:");
		scanf(" %c", &risposta);
		
		if(risposta=='s'){
			strcpy(marca_modello, p->ordi.marca_modello);
			strcpy(carburante, p->ordi.carburante);
			strcpy(colore, p->ordi.colore);
			cilindrata=p->ordi.cilindrata;
			
			printf("\nAttenzione: Gli optional devono essere trascritti manualmente per un fattore di sicurezza\nStampo la lista:\n\n");
			
			if(p->head_opt==NULL) printf("(Nessun optional presente!)\n");
			
			else{
				while(p->head_opt!=NULL){
					printf("%s; ", p->head_opt->optional);
					p->head_opt=p->head_opt->next;
				}
			}
			printf("\nContinuo?\nInserisci S o N:");
			scanf(" %c", &n);
			
			if(n=='s'){
				lista_nuovo(head_n, marca_modello, carburante, colore, cilindrata);
				cancella_veicolo_ordinato(head_ord, giorno);
			}
		}
	}
}

//ORDINE//Funzione dedicata alla stampa e ricerca di un eventuale nuovo arrivo.
void ordini_effettuati(struct lista_ordini **head_ord, int giorno, struct lista_nuovo **head_n){
	
	stampa_lista_ordini(*head_ord);
	ricerca_ordine_veicolo(head_ord, giorno, head_n);
}

//CARICA//Funzione di caricamento del file sulla lista ordini
void file_ordini(struct lista_ordini **head_ord){
	int n_opt;
	FILE* OR=fopen("auto_ordinate.txt", "r");
	FILE* OP=fopen("optional_ord.txt", "r");
	
	if(OR==NULL){
		perror("\nERRORE: Impossibile aprire il file auto_ordinate.txt!");
		exit(1);
	}
	
	if(OP==NULL){
		perror("\nERRORE: Impossibile aprire il file optional_ord.txt!");
		exit(1);
	}
	int giorno2;
	char marca_modello[31];
	char carburante[11];
	char colore[11];
	int cilindrata;
	
	while(fscanf(OR, "%d%s%s%s%d%d\n", &giorno2, marca_modello, carburante, colore, &cilindrata, &n_opt)!=EOF){
		ordine_v ordi;
		
		ordi.giorno2=giorno2;
		strcpy(ordi.marca_modello, marca_modello);
		strcpy(ordi.carburante, carburante);
		strcpy(ordi.colore, colore);
		ordi.cilindrata=cilindrata;
		
		struct lista_ordini *temp_ord;
		struct lista_ordini *po;
		po=(struct lista_ordini *)malloc(sizeof(struct lista_ordini));
		po->ordi=ordi;
		po->next=NULL;
		
		if(*head_ord==NULL){
			*head_ord=po;
		}
		
		else{
			temp_ord=*head_ord;
			while(temp_ord->next!=NULL){
				temp_ord=temp_ord->next;
			}
			temp_ord->next=po;
		}
		
		int cont=0;
		
		struct pacchetto_optional *testa_opt=NULL;
		char optional[21];
		
		if(n_opt!=0){
			while(fscanf(OP, "%s", optional)!=EOF){
			
				struct pacchetto_optional *or;
				or=(struct pacchetto_optional*)malloc(sizeof(struct pacchetto_optional));
				strcpy(or->optional, optional);
				or->next=testa_opt;
				testa_opt=or;
				cont++;
				
				if(cont==n_opt) break;
			}
			po->head_opt=testa_opt;
			fscanf(OP, "\n");
		}
		else{ 
			po->head_opt=NULL;
			fscanf(OP, "\n");
		}
	}
	fclose(OR);
	fclose(OP);
}

//CARICA//Funzione di caricamento del file sulla lista nuovo
void file_auto_n(struct lista_nuovo **head_n){
	int n_opt;
	FILE* N=fopen("auto_nuove.txt", "r");
	FILE* OP=fopen("optional.txt", "r");
	
	if(N==NULL){ 
		perror("\nERRORE: Impossibile aprire il file auto_nuove.txt!");
		exit(1);
	}
	
	if(OP==NULL){
		perror("\nERRORE: Impossibile aprire il file optional.txt!");
		exit(1);
	}
	char marca_modello[31];
	char carburante[11];
	char colore[11];
	int cilindrata;
	
	while(fscanf(N, "%s%s%s%d%d\n", marca_modello, carburante, colore, &cilindrata, &n_opt)!=EOF){
		veicolo_n veic_n;
	
		strcpy(veic_n.marca_modello, marca_modello);
		strcpy(veic_n.carburante, carburante);
		strcpy(veic_n.colore, colore);
		veic_n.cilindrata=cilindrata;
	
		struct lista_nuovo *p;
		struct lista_nuovo *r=*head_n, *q=*head_n;
		p=(struct lista_nuovo*)malloc(sizeof(struct lista_nuovo));
		p->veic_n=veic_n;
		p->next=*head_n;
	
		while ((q!=NULL) && (strcmp(q->veic_n.marca_modello, p->veic_n.marca_modello)<0)){
			r = q;
			q = q->next;
		}
	
		if(q==*head_n){
		*head_n=p;
		}
		
		else {
		r->next = p;
		p->next = q;
		}
		
		int cont=0;
		
		struct pacchetto_optional *testa_opt=NULL;
		char optional[21];
		
		if(n_opt!=0){
			while(fscanf(OP, "%s", optional)!=EOF){
				
				struct pacchetto_optional *o;
				o=(struct pacchetto_optional*)malloc(sizeof(struct pacchetto_optional));
				strcpy(o->optional, optional);
				o->next=testa_opt;
				testa_opt=o;
				cont++;
				
				if(cont==n_opt) break;
			}
			p->head_opt=testa_opt;
			fscanf(OP, "\n");
		}
		else{
			p->head_opt=NULL;
			fscanf(OP, "\n");
		}
	}
	fclose(N);
	fclose(OP);

}

//CARICA//Funzione di caricamento del file sulla lista usato
void file_auto_u(struct lista_usato **head_u){
	int i=0;
	FILE* U=fopen("auto_usate.txt", "r");
	
	if(U==NULL){ 
		perror("\nERRORE: Impossibile aprire il file auto_usate.txt!");
		exit(1);
	}
	char marca_modello[31];
	char carburante[11];
	char colore[11];
	int cilindrata;
	int chilometraggio;
	
	while(fscanf(U, "%s%s%s%d%d\n", marca_modello, carburante, colore, &cilindrata, &chilometraggio)!=EOF){
		
		lista_usato(head_u, marca_modello, carburante, colore, cilindrata, chilometraggio);
	}
	fclose(U);
}

//CARICA//Funzione che avvia i tre processi di caricamento dei file prima di eseguire il programma
void leggi_file(struct lista_ordini **head_ord, struct lista_nuovo **head_n, struct lista_usato **head_u){
	file_auto_n(head_n);
	file_auto_u(head_u);
	file_ordini(head_ord);
}

//SALVA//Funzione di salvataggio della lista ordini sul file
void salva_file_o(struct lista_ordini *head_ord){
	struct pacchetto_optional *temp_opt; //temp_opt è un puntatore temporaneo che punta agli optional di un veicolo
	int i;
	
    FILE* OR=fopen("auto_ordinate.txt","w");
    FILE* OP=fopen("optional_ord.txt", "w");
	
	if (OR==NULL){ 
		printf("\nERRORE: Impossibile salvare il file auto_ordinate.txt!");
		exit(1);
	}
    else{
		while(head_ord!=NULL){
			temp_opt=head_ord->head_opt;
	
			if(OP==NULL){
				printf("\nERRORE: Impossibile salvare il file optional_ord.txt!");
				exit(1);
			}
			else{
				i=0;
				while(temp_opt!=NULL){
					fprintf(OP, "%s ", temp_opt->optional);
					temp_opt=temp_opt->next;
					i++;
				}
				fprintf(OP, "\n");
			}
			fprintf(OR, "%d %s %s %s %d %d\n", head_ord->ordi.giorno2, head_ord->ordi.marca_modello, head_ord->ordi.carburante, head_ord->ordi.colore, head_ord->ordi.cilindrata, i);
			head_ord=head_ord->next;
		}
	}
}

//SALVA//Funzione di salvataggio della lista nuovo sul file
void salva_file_n(struct lista_nuovo *head_n){
	struct pacchetto_optional *temp_opt; //temp_opt è un puntatore temporaneo che punta agli optional di un veicolo
	int i;
	
    FILE* N=fopen("auto_nuove.txt","w");
    FILE* OP=fopen("optional.txt", "w");
	
	if (N==NULL){ 
		printf("\nERRORE: Impossibile salvare il file auto_nuove.txt!");
		exit(1);
	}
    else{
		while(head_n!=NULL){
			temp_opt=head_n->head_opt;
	
			if(OP==NULL){
				printf("\nERRORE: Impossibile salvare il file optional.txt!");
				exit(1);
			}
			else{
				i=0;
				while(temp_opt!=NULL){
					fprintf(OP, "%s ", temp_opt->optional);
					temp_opt=temp_opt->next;
					i++;
				}
				fprintf(OP, "\n");
			}
			fprintf(N, "%s %s %s %d %d\n", head_n->veic_n.marca_modello, head_n->veic_n.carburante, head_n->veic_n.colore, head_n->veic_n.cilindrata, i);
			head_n=head_n->next;
		}
	}
}

//SALVA//Funzione di salvataggio della lista usato sul file
void salva_file_u(struct lista_usato *head_u){
	
    FILE* U=fopen("auto_usate.txt","w");
    
	if (U==NULL){ 
		printf("\nERRORE: Impossibile salvare il file auto_usate.txt!");
		exit(1);
	}
    else {
		while(head_u!=NULL){
		
			fprintf(U, "%s %s %s %d %d\n", head_u->veic_u.marca_modello, head_u->veic_u.carburante, head_u->veic_u.colore, head_u->veic_u.cilindrata, head_u->veic_u.chilometraggio);
			head_u=head_u->next;
		}
		fclose(U);
	}
}

//SALVA//Funzione che avvia i tre processi di salvataggio dei file prima di uscire dal programma
void salva_file(struct lista_ordini *head_ord, struct lista_nuovo *head_n, struct lista_usato *head_u){
	salva_file_n(head_n);
	salva_file_u(head_u);
	salva_file_o(head_ord);
}

//MENU//Funzione principale dedicata alla scelta dell'operazione da eseguire. Per terminare la funzione (e di conseguenza il programma) bisognera selezzionare l'opzione 0.
void menu_principale (struct lista_nuovo **head_n, struct lista_usato **head_u, struct lista_ordini **head_ord, int giorno){
	
	char domanda_uscita='n';
	int opzione;
	
	while(domanda_uscita!='s'){
		printf("\nBenvenuto nel menu principale, che operazione vuoi eseguire?\n");
		printf("1- Inserimento auto nuove\n");
		printf("2- Inserimento auto usate\n");
		printf("3- Auto presenti in concessionaria\n");
		printf("4- Vendita Nuovo\n");
		printf("5- Vendita Usato\n");
		printf("6- Elenco ordini effettuati\n");
		printf("7- Ordina un veicolo\n");
		printf("0- Esci\n");
		printf("Inserisci:");
		scanf("%d", &opzione);
		
		switch(opzione){
			case 1:
				inserimento_auto_nuove(head_n);
				break;
				
			case 2:
				inserimento_auto_usate(head_u);
				break;
				
			case 3:
				stampa_lista_auto(*head_u, *head_n);
				break;
				
			case 4:
				vendita_nuovo(head_n, head_ord, giorno);
				break;
				
			case 5:
				vendita_usato(head_u);
				break;
				
			case 6:
				ordini_effettuati(head_ord, giorno, head_n);
				break;
				
			case 7:
				inserimento_ordine_veicolo(head_ord, giorno);
				break;
				
			case 0:
				printf("\nSei sicuro di uscire dal programma? Verrà eseguito il savateggio del lavoro\nScrivi S o N\n");
				scanf(" %c", &domanda_uscita);
				if(domanda_uscita=='s'){
					salva_file(*head_ord, *head_n, *head_u);
					printf("\nArrivederci!\n");
					exit(0);
				}
				else printf("\nAnnullamento uscita\n");
				break;
				
			default:
				printf("\nAttenzione: Comando inesistente\n");
				break;
		}
	}
}

//MAIN//Funzione principale di partenza dove vengono chiesti password e successivamente la data di esecuzione del programma. Se la password è errata il programma stamperà una stringa e uscirà dall'esecuzione.
int main(){
	struct lista_usato *head_u=NULL;
	struct pacchetto_optional *head_opt=NULL;
	struct lista_nuovo *head_n=NULL;
	struct lista_ordini *head_ord=NULL;
	
	char pass[10]="Ludostorm";
	char password[10];
	printf("inserisci la password:\n");
	scanf(" %s", password);
	
	data_odierna data_odierna;
	int giorno;
	if(strcmp(password, pass)==0){
		printf("\nBenvenuto! che giorno è oggi?\nla data deve essere inserita secondo questo schema: AAAAMMGG\n");
		scanf("%d", &giorno);
		data_odierna.giorno=giorno;
		leggi_file(&head_ord, &head_n, &head_u);
		menu_principale(&head_n, &head_u, &head_ord, giorno);
	}
	else printf("\nSpiacente la Password è errata\n");
}
