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

//ne veut pas compiler je sais pas pourquoi
