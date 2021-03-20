#include "fraction.h"
using namespace MATH;
using namespace std;





Fraction::Fraction(int n, int d) {
    numerateur = n;
    denominateur = d;
    simplification();
    cout<<"Construction de l'objet"<<endl;
}

Fraction::~Fraction() {
    cout<<"Destruction de l'objet"<<endl;
}

void Fraction::setFraction(int num, int den)  {
    numerateur = num;
    denominateur = den;
    simplification();
}

int Fraction::getNumerateur () const {
    return numerateur;
}
int Fraction::getDenominateur () const {
    return denominateur;
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


Fraction Fraction::somme(const Fraction& a) {
    return Fraction((this->getNumerateur()* a.getDenominateur() + a.getNumerateur() * this->getDenominateur()), this->getDenominateur() * a.getDenominateur());
}

Fraction Fraction::operator + (const Fraction& f1) {
    return this->somme(f1);
    //return (f1.getNumerateur() * this->getDenominateur() + this->getNumerateur() * f1.getNumerateur(), f1.getDenominateur() * this->getDenominateur());
}


Fraction Fraction::operator ++ () {
    Fraction f = Fraction((this->getNumerateur() + this->getDenominateur()), this->getDenominateur());
    *this = f;
    return f;
}

Fraction Fraction::operator ++ (int i) {
    Fraction f = *this;
    *this = Fraction((this->getNumerateur() + this->getDenominateur()), this->getDenominateur());
    return f;
}
