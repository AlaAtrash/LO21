#include "automate.h"

using namespace std;


//*************************************
//              Etat
//*************************************


Etat::Etat(size_t s) {
    dimension = s;
    valeur = new bool[dimension];
    for (int i = 0; i < dimension; i++) {
        valeur[i] = 0;
    }
}

Etat::Etat(const Etat& et) {
    dimension = et.getDimension();
    valeur = new bool[dimension];
    for (int i = 0; i < dimension; i++) {
        valeur[i] = et.valeur[i];
    }
}

bool Etat::getCellule(size_t i) const {
    return valeur[i - 1];
}

size_t Etat::getDimension() const {
    return dimension;
}

void Etat::setCellule(size_t i, bool val) {
    valeur[i - 1] = val;
}


ostream& operator << (ostream& os, const Etat& et) {
    for (int i = 0; i < et.dimension; i++) {
        if (et.valeur[i] == 0) {
            os << ".";
        } else {
            os << "X";
        }
    }
    return os;
}

Etat& Etat::operator = (const Etat& et) {
    if (&et != this) {
        if (et.dimension != this->dimension) {
            dimension = et.dimension;
            delete[] valeur;
            valeur = nullptr;
            valeur = new bool[et.dimension];
        }
        for (size_t i = 0; i < et.dimension; i++) {
            valeur[i] = et.valeur[i];
        };
    };
    return *this;
}

//*************************************
//             Automate
//*************************************

unsigned short NumBitToNum(const std::string& num) {
    if (num.size() != 8) throw AutomateException("Numero d’automate indefini");
    int puissance = 1;
    unsigned short numero = 0;
    for (int i = 7; i >= 0; i--) {
        if (num[i] == '1') numero += puissance;
        else if (num[i] != '0') throw AutomateException("Numero d’automate indefini");
        puissance *= 2;
    }
    return numero;
}

std::string NumToNumBit(unsigned short num) {
    std::string numeroBit;
    if (num > 256) throw AutomateException("Numero d’automate indefini");
    unsigned short p = 128;
    int i = 7;
    while (i >= 0) {
        if (num >= p) { numeroBit.push_back('1'); num -= p; }
        else { numeroBit.push_back('0'); }
        i--;
        p = p / 2;
    }
    return numeroBit;
}

void Automate::appliquerTransition(const Etat& dep, Etat& dest) const {
    if (dest.getDimension() == 0) dest = dep;
    for (size_t i = 0; i < dep.getDimension(); i++)
    {
        unsigned short conf = 0;
        if (i < dep.getDimension() - 1) conf += dep.getCellule(i + 1);
        conf += dep.getCellule(i) * 2;
        if (i > 0) conf += dep.getCellule(i - 1) * 4;
        dest.setCellule(i, numeroBit[7 - conf] - '0');
    }
}

unsigned short Automate::getNumero() const{
    return numero;
}
string Automate::getNumeroBit() const {
    return numeroBit;
}

Automate::Automate(unsigned short i) {
    numero = i;
    numeroBit = NumToNumBit(i);
}

Automate::Automate(string i) {
    numeroBit = i;
    numero = NumBitToNum(i);
}

ostream& operator << (ostream& os, const Automate& aut) {
    os << aut.numero << " : "<< aut.numeroBit<<endl;
    return os;
}




//*************************************
//             Simulateur
//*************************************


void Simulateur::setEtatDepart(const Etat& e) {
    depart = &e;
    etats[0] = new Etat(*depart);
    rang = 0;
}

Simulateur::Simulateur(const Automate& a, size_t buf) : automate(a), nbMaxEtats(buf) {
    etats = new Etat*[nbMaxEtats];
    for (int i = 0; i < nbMaxEtats; i++) {
        etats[i] = nullptr;
    }

}


Simulateur::Simulateur(const Automate& a, const Etat& dep, size_t buffer) : automate(a), nbMaxEtats(buffer), depart(&dep) {
    etats = new Etat*[nbMaxEtats];
    for (int i = 0; i < nbMaxEtats; i++) {
        etats[i] = nullptr;
    }
    etats[0] = new Etat(*depart);
    rang = 0;
}

void Simulateur::next() {
    rang++;
    int adr = rang % nbMaxEtats;
    etats[adr] = new Etat();
    automate.appliquerTransition(*etats[(rang - 1) % nbMaxEtats], *etats[adr]);
}

void Simulateur::run(size_t nbSteps) {
    for (int i = 0; i < nbSteps; i++) {
        next();
    }
}

void Simulateur::reset() {
    for (int i = 0; i < nbMaxEtats; i++) {
        etats[i] = nullptr;
    }
    etats[0] = new Etat(*depart);
    rang = 0;
}


size_t Simulateur::getRangDernier() const {
    return (rang + 1);
}


Simulateur::~Simulateur() {
    for (int i = 0; i < nbMaxEtats; i++) {
        delete(etats[i]);
    }
}

const Etat& Simulateur::dernier() const {
    return *etats[rang % nbMaxEtats];
}
