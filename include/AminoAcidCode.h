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
        void addDistributionCount(int);
        int getDistribution();
        void setComposition(double );
        double getComposition();
        vector<AminoAcidCode> createAminoAcidCounters();
        void assignAminoAcidComposition();
        vector<AminoAcidCode> getAminoAcidComposition();

        virtual ~AminoAcidCode();
    protected:
    private:
    char code;
    string colour;
    int codeCount;
    string AminoAcidCodes;
    vector<AminoAcidCode> composition;
    vector<AminoAcidCode> AminoAcidCounters;
    double comp;
    int distribution;
};

#endif // AMINOACIDCODE_H
