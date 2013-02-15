#ifndef PROTEINSEQUENCE_H
#define PROTEINSEQUENCE_H
#include "stdafx.h"

#include "../include/AminoAcidCode.h"
#include "../include/AminoAcidColourCode.h"

using namespace std;

class AminoAcidCode;
class AminoAcidColourCode;

class ProteinSequence
{
    public:
        ProteinSequence();
        void setCathCode( string );
        string getCathCode();
        void setPDB( string );
        string getPDB();
        void setSeq( string );
        string getSeq();
        void setSeqLength( int );
        int getSeqLength();
        void setAminoAcidCounts( vector<AminoAcidCode> );
        vector<AminoAcidCode> getAminoAcidCount();
        void setAminoAcidColourCount( vector<AminoAcidColourCode> );
        vector<AminoAcidColourCode> getAminoAcidColourCount();
        virtual ~ProteinSequence();
    protected:
    private:
    string cath;
    string pdb;
    string seq;
    int seqLength;
    vector<AminoAcidColourCode> AminoAcidColourCount;
    vector<AminoAcidCode> AminoAcidCount;
};

#endif // PROTEINSEQUENCE_H
