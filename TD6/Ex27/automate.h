#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <iostream>
#include <math.h>

using namespace std;
class AutomateException {
public:
AutomateException(const std::string& message):info(message) {}
std::string getInfo() const { return info; }
private:
std::string info;
};

class Etat {
    private:
        size_t dimension;
        bool* valeur;
    public:
        Etat(size_t s = 0);
        Etat(const Etat& et);
        bool getCellule(size_t i) const;
        size_t getDimension() const;
        void setCellule(size_t i, bool val);
        friend std::ostream& operator << (std::ostream& os, const Etat& et);
        Etat& operator = (const Etat& et);
};



class Automate {
    private:
        unsigned short numero;
        string numeroBit;

    public:
        Automate(unsigned short i);
        Automate(string i);
        unsigned short getNumero() const;
        string getNumeroBit() const;
        void appliquerTransition(const Etat& dep, Etat& dest) const;
        friend std::ostream& operator << (std::ostream& os, const Automate& aut);
};


class Simulateur {
    private:
        const Automate& automate;
        const Etat* depart;
        int nbMaxEtats;
        Etat** etats;
        size_t rang;
    public:
        void setEtatDepart(const Etat& e);
        Simulateur(const Automate& a, size_t buf = 2);
        Simulateur(const Automate& a, const Etat& dep, size_t buffer = 2);
        ~Simulateur();
        void next();
        void run(size_t nbSteps);
        void reset();
        const Etat& dernier()const;
        size_t getRangDernier() const;
};

unsigned short NumBitToNum(const std::string& num);
std::string NumToNumBit(unsigned short num);

#endif // AUTOMATE_H
