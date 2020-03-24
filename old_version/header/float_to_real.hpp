#include <type_traits>
#include <iostream>
using namespace std;


/*
    Não funciona por causa de problemas de relação com valores
*/

struct real_basic
{
    int num;
    int den;
};

/*
template<typename type>
real_basic float_to_real(type a)
{
    int novo_numerador = 0, novo_denominador = 1;
    if(std::is_compound<type>::value)
        throw "No sense type";
    if(std::is_floating_point<type>::value)
    {
        unsigned int i = 0;
        type numerador_aux = a - (int) a;
        while(true)
        {
            if(numerador_aux == (int) numerador_aux)
                break;
            numerador_aux = numerador_aux * 10;
            i++;
        }
        
        for(unsigned ci = 0; ci < i; ci++)
            novo_denominador *= 10;
        novo_numerador = numerador_aux + (int) a * novo_denominador;
    }
    else
    {
        if(std::is_integral<type>::value)
            novo_numerador = a;
    }
    real_basic r;
    r.num = novo_numerador;
    r.den = novo_denominador;
    return r;
}
*/

template<typename type>
real_basic float_to_real(type a)
{
    int novo_numerador = 0, novo_denominador = 1;
    
    if(std::is_floating_point<type>::value)
    {
    	cout << "Entrou" << endl;
        unsigned int i = 0;
        type numerador_aux = a - (int) a;
        cout << "a = " << a << "---" << "(int)a = " << (int) a << endl;
        cout << "numerador_aux	 : " << numerador_aux << endl;
        type verificador = numerador_aux;
        while(true)
        {

        	cout << "Condicao: " << (numerador_aux == (int) numerador_aux) << endl;
            if(numerador_aux == (int) numerador_aux || verificador == 0.0d || verificador == 0.0f)
                break;
            numerador_aux = numerador_aux * 10;
            verificador = numerador_aux - (int) numerador_aux;
            cout << "novo -> numerador_aux: " << numerador_aux << endl;
            i++;
        }
        cout << "O valor de i	 : " << i << endl;
        
        
        for(unsigned ci = 0; ci < i; ci++)
            novo_denominador *= 10;
        novo_numerador = numerador_aux + (int) a * novo_denominador;
        cout << "novo numerador	 : " << novo_numerador << endl;
        cout << "novo denominador: " << novo_denominador << endl;
    }
    else
    {
        if(std::is_integral<type>::value)
            novo_numerador = a;
    }
    real_basic r;
    r.num = novo_numerador;
    r.den = novo_denominador;
    return r;
}