 #include "fonction.h"

/* ----- EXO 12 ------ */
/*int main(){
    int a = 54, b=47;
    cout << "a = " << a << " b = " << b << "\n";
    inverse(&a,&b);
    cout << "a = " << a << " b = " << b << "\n";
    inverse(a,b);
    cout << "a = " << a << " b = " << b << "\n";
    return 0;
}*/

/* ----- EXO 13 ------ */
/*int main(){
    essai testpointeur, testref;
    testpointeur.n = 66;
    testpointeur.x = 44;
    raz(testref);
    cout << "n = " << testref.n << " x = " << testref.x << "\n";
    testpointeur.n = 88;
    testpointeur.x = 22;
    raz(&testpointeur);
    cout << "n = " << testpointeur.n << " x = " << testpointeur.x << "\n";
    return 0;
}*/

/* ----- EXO 14 ------ */
/*int main(){
    essai_init();
    return 0;
}*/

/* ----- EXO 15 ------ */
/*int main(){
    essai_alloc();
    return 0;
}*/

/* ----- EXO 16 ------ */
/*#include <array>
using namespace std;

constexpr int calcul(int x) {
    return 2*x + 1; 
}

constexpr int getNumber(){
    return 3; 
}

int main(){
    constexpr int N = getNumber();
    array<int,calcul(N)> tableau;
    return 0;
}*/

/* ----- EXO 17 ------ */

/*int main(){ // Q7
    personne xxx; // Q1
    raz(xxx); 

    affiche_struct(&xxx); // Q2

    personne* tab = new personne[100]; // Q3
    for(int i = 0; i<10; i++){
        raz(tab[i]);
    }
    affiche_tab(tab,10);

    personne yyy; // Q4
    char nom[] = "Jean";
    init_struct(&yyy, nom, 47);
    affiche_struct(&yyy);

    personne zzz; // Q5
    copy_struct(&yyy, &zzz);
    affiche_struct(&zzz);

    personne* tab2 = new personne[100]; // Q6
    for(int i = 0; i<10; i++){
        init_struct(&tab2[i], nom, i*10+5);
    }
    affiche_tab(tab2,10);
    personne* tab3 = new personne[100];
    copy_tab(tab2,tab3,10);
    affiche_tab(tab3,10);

    delete[] tab;
    delete[] tab2;
    delete[] tab3;
    return 0;
}*/

/* ----- EXO 18 ------ */

/*int main(){
    personne xxx;
    raz(xxx); 

    affiche_struct(&xxx);

    personne* tab = new personne[100];
    for(int i = 0; i<10; i++){
        raz(tab[i]);
    }
    affiche_tab(tab,10);

    personne yyy;
    string nom = "Jean";
    init_struct(&yyy, nom, 47);
    affiche_struct(&yyy);

    personne zzz;
    copy_struct(&yyy, &zzz);
    affiche_struct(&zzz);

    personne* tab2 = new personne[100];
    for(int i = 0; i<10; i++){
        init_struct(&tab2[i], nom, i*10+5);
    }
    affiche_tab(tab2,10);
    personne* tab3 = new personne[100];
    copy_tab(tab2,tab3,10);
    affiche_tab(tab3,10);

    delete[] tab;
    delete[] tab2;
    delete[] tab3;
    return 0;
}*/

/* ----- EXO 19 ------ */

/*int main(){
    essai_comptes();
    return 0;
}*/