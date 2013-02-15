#ifndef AMINOACIDCOLOURCODE_H
#define AMINOACIDCOLOURCODE_H
#include "stdafx.h"

using namespace std;

class AminoAcidColourCode
{
    public:
        AminoAcidColourCode();
        void setColour( string );
        string getColour();
        void setCount(int);
        double getCount();
        void createColourCodes();
        vector<AminoAcidColourCode> getColourCodes();
        virtual ~AminoAcidColourCode();
    protected:
    private:
    string colour;
    int count;
    vector<AminoAcidColourCode> ColourCodes;

};

#endif // AMINOACIDCOLOURCODE_H
