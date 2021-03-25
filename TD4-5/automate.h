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
    bool getCellule(size_t i)const {if (i>=dimension)throw AutomateException("Erreur Cellule");return valeur[i];}
    void setCellule(size_t i,bool val){valeur[i]=val;}
};
std::ostream & operator<<(std::ostream & os,const Etat & e);



class Automate{
  private:
    unsigned short numero;
    string numeroBit;

  public:
    Automate(unsigned short num);
    Automate(string snum);

    unsigned short getNumero() const {return numero;}
    string getNumeroBit() const{return numeroBit;}

    void appliquerTransition(const Etat& dep, Etat& dest)const
    {
      for(int i=0;i<dep.getDimension();i++){dest.setCellule(i,dep.getCellule(i));}
    }
}

};
std::ostream & operator<<(std::ostream & os,const Automate & a);


class Simulateur{
  private:
    const Automate& automate;
    Etat * depart=nullptr;
    unsigned int nbMaxEtats;
    Etat ** etat;
    size_t rang=0;


  public:
    Simulateur(const Automate& a, size_t buf = 2):automate(a),etat(new Etat*[buf]),nbMaxEtats(buf){}
    Simulateur(const Automate& a,const Etat& dep, size_t buffer = 2):automate(a),depart(new Etat),etat(new Etat*[buf]),nbMaxEtats(buf){}

    void setEtatDepart(const Etat& e):{}

};
