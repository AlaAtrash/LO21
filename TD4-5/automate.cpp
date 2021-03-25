#include "automate.h"
#include <stdio.h>
//#include <iostream>


//using namespace std;

std::ostream & operator<<(std::ostream & os,const Etat & e){ // on renvoi un ostream donc besoin d'une amitié
  os<<"[";
  for(int i = 0;i<e.getDimension();i++){os<<","<<e.getCellule(i);}
  os<<"]";
  return os;
}

std::ostream & operator<<(std::ostream & os,const Automate & a){ // on renvoi un ostream donc besoin d'une amitié
  os<<"Regle "<<a.getNumero()<<","<<a.getNumeroBit();
  return os;
}
unsigned short NumBitToNum(const std::string& num) {
  if(num.size() != 8)throw AutomateException("Numero d’automate indefini");

  int puissance = 1;
  unsigned short numero = 0;

  for(int i = 7; i >= 0; i--) {
    if(num[i] == '1') numero += puissance;
    else if(num[i] != '0')throw AutomateException("Numero d’automate indefini");
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

  Automate::Automate(unsigned short num):numero(num),numeroBit(NumToNumBit(num)){}
  Automate::Automate(string snum):numero(NumBitToNum(snum)),numeroBit(snum){}

  /*[CORRECTION] void Automate::appliquerTransition(const Etat& dep, Etat& dest) const {
  if (dep.getDimension() != dest.getDimension()) dest = dep;
  for (size_t i = 0; i < dep.getDimension(); i++) {
      unsigned short conf=0;
      if (i > 0) conf+=dep.getCellule(i - 1) * 4;
      conf+=dep.getCellule(i)*2;
      if (i < dep.getDimension()-1) conf+=dep.getCellule(i + 1);
      dest.setCellule(i, numeroBit[7-conf]-’0’);
  }*/
