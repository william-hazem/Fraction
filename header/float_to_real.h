#include<string>
using std::to_string;
using std::string;

/* Convert a floating number to two integers(numerator and denominator) */
void ftor(float value_to_convert, int *_numerator, int *_denominator)
{
    string value_str = to_string(value_to_convert);
    unsigned i = 0, qta_significativos = 0;
    while(true)
    {   
        if(value_str[i] == '.' || value_str[i] == ',')
        {
            for(unsigned ci = value_str.length() - 1; ci > i; ci--)
            {
                if(value_str[ci] != '0')
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
        value_to_convert *= 10;
        *_denominator *= 10;
    }
    *_numerator = value_to_convert;
}