#ifndef AMINOACIDCODE_H
#define AMINOACIDCODE_H
#include "stdafx.h"

using namespace std;


class AminoAcidCode
{
    public:
        AminoAcidCode();
        void setCodeName(char);
        char getCodeName();
        void setColour( string );
        string getColour();
        void addCodeCount(int);
        int getCount();
        vector<AminoAcidCode> createAminoAcidCounters();

        virtual ~AminoAcidCode();
    protected:
    private:
    char code;
    string colour;
    int codeCount;
    string AminoAcidCodes;
    vector<AminoAcidCode> AminoAcidCounters;





};

#endif // AMINOACIDCODE_H
