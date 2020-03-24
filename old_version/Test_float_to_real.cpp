#include<iostream>
#include <type_traits>
#include <iomanip>
#include <string>
#include <clocale>
using namespace std;

#include "float_to_real2.h"


int main()
{
    setlocale(LC_ALL,"Portuguese");

    float valor = 0;
    cout << "Digite um valor numerico: " << endl;
    cin >> valor;
    real_basic resposta = ftor(valor);

    cout << "O numerador e  : " << resposta._numerator   << endl;
    cout << "O denominador e: " << resposta._denominator << endl;
    system("pause");
    return 1;
}



