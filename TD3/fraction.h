#include <iostream>
#include <string>
using namespace std;

namespace MATH {
    class Fraction {
        public:
        Fraction(int n = 0, int d = 1);
        ~Fraction();
        void setFraction (int num, int den);
        int getNumerateur () const;
        int getDenominateur () const;


        std::ostream& operator << (std::ostream& os);
        Fraction operator + (const Fraction& f1);
        Fraction operator ++ ();
        Fraction operator ++ (int i);

        friend std::ostream& operator << (std::ostream& os, const Fraction& fr);

        void simplification();

        Fraction somme(const Fraction& a);

        private:
        int numerateur, denominateur;
        
    };
    ostream& Fraction::operator << (ostream& os) {
        os <<getNumerateur()<<" / "<<getDenominateur();
        return os;
    }
    

    ostream& operator << (ostream& os, const Fraction& fr) {
        os <<fr.numerateur<<" / "<<fr.denominateur;
        return os;
    }
    
}

