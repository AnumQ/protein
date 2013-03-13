#include "../include/AminoAcidCode.h"

using namespace std;

AminoAcidCode::AminoAcidCode()
{
    //ctor
}

void AminoAcidCode::setCodeName(char i)
{
    code = i;
    codeCount = 0;
    distribution = 0;
}

char AminoAcidCode::getCodeName()
{
    return code;
}

void AminoAcidCode::setColour(string c )
{
    colour = c;
}

string AminoAcidCode::getColour()
{
    return colour;
}

void AminoAcidCode::addCodeCount(int count)
{
    codeCount = codeCount + count;
}

int AminoAcidCode::getCount()
{
    return codeCount;
}

void AminoAcidCode::addDistributionCount(int d)
{
    distribution = distribution + d;
}

int AminoAcidCode::getDistribution()
{
    return distribution;
}

void AminoAcidCode::setComposition(double c)
{
    comp = c;
}

double AminoAcidCode::getComposition()
{
    return comp;
}
vector<AminoAcidCode> AminoAcidCode::createAminoAcidCounters()
{
    AminoAcidCounters.clear();
    AminoAcidCode currentCode;
    AminoAcidCodes = "ACDEFGHIKLMNPQRSTVWY";
    for ( size_t x = 0; x < AminoAcidCodes.size(); x++ )
        {
            char c = AminoAcidCodes[x];
            currentCode.setCodeName(c);
            if ( c == 'A' || c == 'V' || c == 'F' || c == 'P'
                || c == 'M' || c == 'I' || c == 'L' || c == 'W' )
            {
                currentCode.setColour("RE");
            }
            else if ( c == 'D' || c == 'E')
            {
                currentCode.setColour("BL");
            }
            else if ( c == 'R' || c == 'K' )
            {
                currentCode.setColour("MA");
            }
            else if ( c == 'S' || c == 'T' || c == 'Y' || c == 'H'
                || c == 'C' || c == 'N' || c == 'G' || c == 'Q' )
            {
                currentCode.setColour("GR");
            }
            else
            {
                currentCode.setColour("GY");
            }


            AminoAcidCounters.push_back(currentCode);
        }
    return AminoAcidCounters;
}

void AminoAcidCode::assignAminoAcidComposition()
{
    ScoreMatrix convert;
    composition = createAminoAcidCounters();
    string compdata = "(A) 8.25 (Q) 3.93 (L) 9.66 (S) 6.56 \n"
                      "(R) 5.53 (E) 6.75 (K) 5.84 (T) 5.34 \n"
                      "(N) 4.06 (G) 7.08 (M) 2.42 (W) 1.08 \n"
                      "(D) 5.45 (H) 2.27 (F) 3.86 (Y) 2.92 \n"
                      "(C) 1.37 (I) 5.96 (P) 4.70 (V) 6.87";

    for( size_t i = 0; i < compdata.size(); i++ )
    {
        char currentchar = compdata[i];
        for( size_t j = 0; j < composition.size(); j++ )
        {
            char c = composition[j].getCodeName();
            if ( currentchar == c )
            {
                string num = compdata.substr(i+3, 5);
                double comp = convert.string_to_double(num);
                composition[j].setComposition(comp);
                //cout << c << ":" << comp << endl;
                num.clear();
            }
        }
    }

}

vector<AminoAcidCode> AminoAcidCode::getAminoAcidComposition()
{
    return composition;
}

AminoAcidCode::~AminoAcidCode()
{
    //dtor
}
