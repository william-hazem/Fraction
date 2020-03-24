#include "header\\Real.hpp"

Real::Real() {}

Real::Real(int x, int y) : numerador(x), denominador(y == 0 ? 1 : y) {}

Real::Real(float x)
{
    this->setNumerator(0);
    this->setDenominator(1);
    ftor(x, &numerador, &denominador);
}

Real::Real(double x)
{
    this->setNumerator(0);
    this->setDenominator(1);
    ftor(x, &numerador, &denominador);
}

Real::~Real() {}

void Real::simplify()
{
    int divisor = mdc(this->getNumerador(), this->getDenominador());
    this->setNumerator(this->getNumerador() / divisor);
    this->setDenominator(this->getDenominador() / divisor);

    if(this->getDenominador() < 0)
    {
        this->setDenominator(this->getDenominador() * -1);
        this->setNumerator(this->getNumerador() * -1);
    }
}

int Real::mdc(int num1, int num2)
{
    int _mod;
    do
    {
        _mod = num1 % num2;
        num1 = num2;
        num2 = _mod;
        
    } while (_mod != 0);
    return num1;
}

Real &Real::operator+(const Real &real_num) const
{
    int novo_numerador = 0, novo_denominador = 1;
    if(this->getDenominador() == 1 && real_num.getDenominador() == 1)
        novo_numerador = this->getNumerador() + real_num.getNumerador();
    else
    {    
        if(this->getDenominador() == real_num.getDenominador())
        {
            novo_numerador = this->getNumerador() + real_num.getNumerador(); 
            novo_denominador = this->getDenominador();
        }
        else
        {
            novo_numerador = this->getNumerador() * real_num.getDenominador() + real_num.getNumerador() * this->getDenominador(); 
            novo_denominador = this->getDenominador() * real_num.getDenominador();
        }
            
    }
    Real *aux = new Real(novo_numerador, novo_denominador);
    aux->simplify();
    return *aux;
}

Real &Real::operator/(const Real &real) const
{
    Real *realPtr = new Real(this->getNumerador() * real.getDenominador(), this->getDenominador() * real.getNumerador());
    realPtr->simplify();
    return *realPtr;
}

Real &Real::operator*(const Real &real) const
{
    Real *realPtr = new Real(this->getNumerador() * real.getNumerador(), this->getDenominador() * real.getDenominador());
    realPtr->simplify();
    return *realPtr;
}

Real &Real::operator-() const
{
    Real *realPtr = new Real(this->getNumerador(), this->getDenominador());
    realPtr->simplify();
    realPtr->setNumerator(realPtr->getNumerador() * -1);
    return *realPtr;
}

Real &Real::operator-(const Real &real) const
{
    return (*this + (-real));
}

int Real::getNumerador() const {return numerador;}
int Real::getDenominador() const {return denominador;}
double Real::get() const {return this->getNumerador() / this->getDenominador();}
void Real::setNumerator(int numerator){this->numerador = numerator;}
void Real::setDenominator(int denominator){this->denominador = denominator;}

std::ostream &operator<<(std::ostream &output, const Real &real)
{
    output << real.getNumerador();
    if(real.getDenominador() != 1)
        output << "/" << real.getDenominador();
    return output;
}

std::istream &operator>>(std::istream &input, Real &real)
{
    string leitura;
    input >> leitura;
    int denominator = 1, numerator;
    for(unsigned i = 0; i < leitura.length(); i++)
    {
        if(leitura[i] == '/' || leitura[i] == '\\')
        {
            numerator = stoi(leitura.substr(0,i));
            denominator = stoi(leitura.substr(i+1, leitura.length()-1));
            break;
        }
        if(leitura[i+1] == '\0')
            numerator = stoi(leitura);
    }
    if(denominator == 0)
       denominator = 1;
    real.setNumerator(numerator);
    real.setDenominator(denominator);
    return input;
}