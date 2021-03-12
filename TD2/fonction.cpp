#include "fonction.h"

/* ----- EXO 12 ------ */
/*void inverse(int*a,int*b){
    cout << "pointeur\n";
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inverse(int& a,int& b){
    cout << "ref\n";
    int temp = a;
    a = b;
    b = temp;
}*/

/* ----- EXO 13 ------ */
/*void raz(essai& x){
    x.n = 0;
    x.x = 0;
}

void raz(essai* x){
    x->n = 0;
    x->x = 0;
}*/

/* ----- EXO 14 ------ */
/*void init(point& pt,int _x,int _y,int _z) {
    pt.x=_x; 
    pt.y=_y; 
    pt.z=_z;
    cout << "x = " << pt.x << " y = " << pt.y << " z = " << pt.z << "\n";
}

void essai_init(){
    point p;
    init(p);
    init(p,1);
    init(p,1,2);
    init(p,1,2,3);
}*/

/* ----- EXO 15 ------ */

/*void essai_alloc(){
    int* pt_int;
    double *pt_double;
    pt_int= new int;
    pt_double= new double[100];
    delete pt_int;
    delete[] pt_double;
}*/

/* ----- EXO 16 ------ */

/* ----- EXO 17 ------ */

/*void raz(personne& x){ // Q1
    x.age = 0;
    x.nom[0] = '\0';
}

void affiche_struct(const personne* xxx){  // Q2
    cout << "Nom = " << xxx->nom << " Age = " << xxx->age << "\n";
}

void affiche_tab(const personne* tab, int n){ // Q3
    for(int i = 0; i<n; i++)
        affiche_struct(&tab[i]);
}

void init_struct(personne* xxx, char * chaine, int n){ // Q4
    xxx->age = n;
    int i=0;
    while(chaine[i]){
        xxx->nom[i] = chaine[i];
        i++;
    }
    xxx->nom[i] = '\0';
}

void copy_struct(personne* source, personne* destination){ // Q5
    *destination = *source;
}

void copy_tab(personne* source, personne* destination, int n){ // Q6
    for(int i=0; i<n; i++){
        destination[i] = source[i];
    }
}*/

/* ----- EXO 18 ------ */

/*void raz(personne& x){
    x.age = 0;
    x.nom = '\0';
}

void affiche_struct(const personne* xxx){
    cout << "Nom = " << xxx->nom << " Age = " << xxx->age << "\n";
}

void affiche_tab(const personne* tab, int n){
    for(int i = 0; i<n; i++)
        affiche_struct(&tab[i]);
}

void init_struct(personne* xxx, string& chaine, int n){
    xxx->age = n;
    int i=0;
    xxx->nom = chaine;
}

void copy_struct(personne* source, personne* destination){
    *destination = *source;
}

void copy_tab(personne* source, personne* destination, int n){
    for(int i=0; i<n; i++){
        destination[i] = source[i];
    }
}*/

/* ----- EXO 19 ------ */

/*int& operation(compte* tab, const string& c) {
	int i = 0;
	while (tab[i].id != c)
		i++;
	return tab[i].solde;
};

void essai_comptes() {
	compte tab[4] = { {"courant", 0},{"codevi", 1500 },
	{"epargne", 200 }, { "cel", 300 } };
	operation(tab, "courant") = 100;
	operation(tab, "codevi") += 100;
	operation(tab, "cel") -= 50;
	for (int i = 0; i < 4; i++) cout << tab[i].id << " : " << tab[i].solde << "\n";
}*/