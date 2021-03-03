#include<iostream>
#include<string>
#include"fonction.h"
using namespace std;
void exerciceA(){
    int r; double p, s; const float pi = 3.14159;
    cout<<"donnez le rayon entier d'un cercle : ";
    cin>>r;
    p=2*pi*r;
    s=pi*r*r;
    cout<<"le cercle de rayon "<<r<<" a un perimetre de "<<p<<" et une surface de "<<s<<".";
}