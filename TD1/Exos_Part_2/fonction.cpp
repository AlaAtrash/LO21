#include<iostream>
/*
int fct(int x) { 
    std::cout<<"1:"<<x<<"\n"; 
    return 0; 
}


int fct(float y) { 
    std::cout<<"2:"<<y<<"\n"; 
    return 0; 
}


int fct(int x, float y) { 
    std::cout<<"3:"<<x<<y<<"\n"; 
    return 0; 
}


float fct(float x, int y){ 
    std::cout<<"4:"<<x<<y<<"\n"; 
    return 3.14; 
}


void exercice_surcharge(){
    int i=3,j=15;
    float x=3.14159,y=1.414;
    char c='A';
    double z=3.14159265;
    fct(i); //appel 1
    fct(x); //appel 2
    fct(i,y); //appel 3
    fct(x,j); //appel 4
    fct(c); //appel 5
    fct(i,j); //appel 6 : appel de deux int, donc marche pas 
    fct(i,c); //appel 7 : appel d'un int et d'un char, donc marche pas 
    fct(i,z); //appel 8
    fct(z,z); //appel 9 : appel de deux double, donc marche pas
}


*/

double* pt0=0;
double* pt1=4096; //rvalue est un int
double* pt2=(double*)4096;
void* pt3=pt1;
pt1=pt3; //lvalue a un pb
pt1=(double*)pt3; //lvalue a un pb
double d1=36;
const double d2=36;
double* pt4=&d1;
const double* pt5=&d1;
*pt4=2.1;
*pt5=2.1; //peut pas modifier une valeur de pointeur const
pt4=&d2;
pt5=&d2;
double* const pt6=&d1;
pt6=&d1;
*pt6=2.78;
double* const pt6b=&d2;
const double* const pt7=&d1;
pt7=&d1;
*pt7=2.78;
double const* pt8=&d1;
pt8=&d2;
pt8=&d1;
*pt8=3.14;