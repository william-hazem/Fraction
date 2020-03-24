#include<string>
using std::to_string;
using std::string;

struct real_basic  
{
    int _numerator, _denominator;
    real_basic() : _numerator(0) , _denominator(1) {}
};
/* 
    Variante que apenas usa as strings para processar as casas decimais sem que erros por imprecisão ocorram 
    fazendo uma convertendo os tipos do seguinte modo: float -> string -> int -> real;
*/
real_basic float_to_real (float valor_entrada)
{
    real_basic  valor_saida;
    string string_entrada = to_string(valor_entrada), new_num;
    unsigned i = 0, qta_significativos = 0;
    while(true)
    {   
        if(string_entrada[i] == '.' || string_entrada[i] == ',')
        {
            for(unsigned ci = 0; ci < i; ci++)
                new_num += string_entrada[ci];
            /* Conta quantos números significativos há após a virgula */
            for(unsigned ci = string_entrada.length() - 1; ci > i; ci--)
            {
                if(string_entrada[ci] != '0')
                {
                    qta_significativos = ci - i;
                    for (unsigned vi = i + 1; vi <= i + qta_significativos; vi++)
                        new_num += string_entrada[vi];
                    break;
                }    
            }    
            break;
        }
        i++;
    }
    valor_saida._numerator = stoi(new_num);
    for (unsigned ci = 0; ci < qta_significativos; ci++)
    {
        valor_saida._denominator *= 10;
    }
    return valor_saida;
}

/* 
    Variante que apenas usa as strings para processar as casas decimais sem que erros por imprecisão ocorram 
    e sem redefinir que haja um conversão float -> string -> inteiro -> real
    A conversão usada é: float -> inteiro -> real;
*/



real_basic ftor(float valor_entrada)
{
    real_basic  valor_saida;
    string string_entrada = to_string(valor_entrada);
    unsigned i = 0, qta_significativos = 0;
    while(true)
    {   
        if(string_entrada[i] == '.' || string_entrada[i] == ',')
        {
            /* Conta quantos números significativos há após a virgula*/
            for(unsigned ci = string_entrada.length() - 1; ci > i; ci--)
            {
                if(string_entrada[ci] != '0')
                {
                    qta_significativos = ci - i;
                    break;
                }    
            }    
            break;
        }
        i++;
    }
    for (unsigned ci = 0; ci < qta_significativos; ci++)
    {
        valor_entrada *= 10;
        valor_saida._denominator *= 10;
    }
    valor_saida._numerator = valor_entrada;
    return valor_saida;
}

void ftor(float valor_entrada, int *_numerator, int *_denominator)
{
    real_basic valor_saida = ftor(valor_entrada);
    *_numerator = valor_saida._numerator;
    *_denominator = valor_saida._denominator;
}