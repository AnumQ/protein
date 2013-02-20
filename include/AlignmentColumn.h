#ifndef ALIGNMENTCOLUMN_H
#define ALIGNMENTCOLUMN_H
#include "stdafx.h"
#include "../include/AminoAcidCode.h"
#include "../include/AminoAcidColourCode.h"


using namespace std;


class AminoAcidColourCode;

class AlignmentColumn
{
    public:
        AlignmentColumn();
        void setColumn(string);
        string getColumn();
        void setAminoAcidCodeCount( vector<AminoAcidCode> );
        vector<AminoAcidCode> getAminoAcidCodeCount();
        void setAminoAcidColourCount( vector<AminoAcidColourCode> );
        vector<AminoAcidColourCode> getAminoAcidColourCount();

        vector<AminoAcidColourCode> AminoAcidColourCount;
        vector<AminoAcidCode> AminoAcidCodeCount;

        virtual ~AlignmentColumn();



        /* Attributes */

    protected:
    private:
    string column;
};

#endif // ALIGNMENTCOLUMN_H
