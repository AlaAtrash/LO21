#include "fraction.h"
using namespace std;

namespace MATH {
    class Fraction {
        public:
        Fraction();
        Fraction(int n, int d);
        void setFraction (int num, int den);
        int getNumerateur ();
        int getDenominateur ();


        friend std::ostream& operator << (ostream& os, const Fraction& fr);



        void simplification();

        Fraction somme(Fraction& a, Fraction& b);

        private:
        int numerateur, denominateur;
    };
    Fraction::Fraction(int n, int d) {
        numerateur = n;
        denominateur = d;
    }

    void Fraction::setFraction(int num, int den)  {
        numerateur = num;
        denominateur = den;
        simplification();
    }

    int Fraction::getNumerateur () {
        return numerateur;
    }
    int Fraction::getDenominateur ()  {
        return denominateur;
    }
    ostream& operator << (ostream& os, const Fraction& fr) {
        os <<fr.numerateur<<" / "<<fr.denominateur;
        return os;
    }


    void Fraction::simplification(){
    // si le numerateur est 0, le denominateur prend la valeur 1
    if (numerateur==0) { denominateur=1; return; }
    /* un denominateur ne devrait pas être 0;
    si c’est le cas, on sort de la méthode */
    if (denominateur==0) return;
    /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
    Denominateur (PGCD) entre le numerateur et le denominateur */
    int a=numerateur, b=denominateur;
    // on ne travaille qu’avec des valeurs positives...
    if (a<0) a=-a; 
    if (b<0) b=-b;
    while(a!=b){ if (a>b) a=a-b; else b=b-a; }
    // on divise le numerateur et le denominateur par le PGCD=a
    numerateur/=a; denominateur/=a;
    // si le denominateur est négatif, on fait passer le signe - au denominateur
    if (denominateur<0) { denominateur=-denominateur; numerateur=-numerateur; }
    }



    Fraction Fraction::somme(Fraction& a, Fraction& b) {
        setFraction((a.numerateur * b.denominateur + b.numerateur * a.denominateur), a.denominateur * b.denominateur);
    }
}

