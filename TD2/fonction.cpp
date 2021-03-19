#include <iostream>

void inverse(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
void inverse(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
    return;
}

*/