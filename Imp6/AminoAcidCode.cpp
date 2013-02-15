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

AminoAcidCode::~AminoAcidCode()
{
    //dtor
}
