#ifndef _AUTOMATE_H
#define _AUTOMATE_H
#include <string>
#include <iostream>
using namespace std;


class AutomateException {
  public:
    AutomateException(const std::string& message):info(message) {}
    std::string getInfo()const{return info; }
  private:
    std::string info;
  };
#endif

unsigned short NumBitToNum(const std::string& num) {
  if(num.size() != 8)throw AutomateException("Numero d’automate indefini");

  int puissance = 1;
  unsigned short numero = 0;

  for(int i = 7; i >= 0; i--) {
    if(num[i] == ’1’) numero += puissance;
    else if(num[i] != ’0’)throw AutomateException("Numero d’automate indefini");
    puissance*= 2;
  }
    return numero;
  }


    std::string NumToNumBit(unsigned short num) {
      std::string numeroBit;
      if(num > 256)throw AutomateException("Numero d’automate indefini");
      unsigned short p = 128;
      int i = 7;
      while(i >= 0) {if(num >= p) { numeroBit.push_back('1'); num -= p; }else{ numeroBit.push_back('0'); }
        i--;
        p = p / 2;
      }
      return numeroBit;
    }

class Etat {
  private:
    size_t dimension; //nb de cellule
    bool * valeur;

  public:
    Etat(size_t dim):dimension(dim),valeur(new bool[dim]){
      for (int i=0;i<dim;i++){valeur[i]=false;}
    }//constructeur
    ~Etat(){delete[] valeur;}//destructeur
    Etat(const Etat & e):dimension(e.dimension),valeur(new bool[e.dimension]){//constructeur de recopie
      for (int i=0;i<e.dimension;i++){valeur[i]=e.valeur[i];}
    }
    Etat & operator=(const Etat & e){
      if (this!=&e){
        dimension = e.dimension;
        bool * newval = new bool[e.dimension];
        for (int i=0;i<e.dimension;i++){newval[i]=e.valeur[i];}
        bool * old = valeur;
        valeur = newval;
        delete[] old;
        delete[] newval;
        return *this;
      }
      printf("Impossible d'affecter une instance à elle même\n");
    }

    size_t getDimension() const {return dimension;}
    bool getCellule(size_t i)const {return valeur[i];}
    void setCellule(size_t i,bool val){valeur[i]=val;}
};
std::ostream & operator<<(std::ostream & os,const Etat & e);


class Automate{
  private:
    unsigned short numero;
    string numeroBit;

  public:
    Automate()
    unsigned short getNumero() {retrun numero;}
    string getNumeroBit() {retrun numeroBit;}


};
