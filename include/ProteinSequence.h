#ifndef PROTEINSEQUENCE_H
#define PROTEINSEQUENCE_H
#include "stdafx.h"

using namespace std;

class ProteinSequence
{
    public:
        ProteinSequence();
        void setCathCode( string );
        void setPDB( string );
        void setSeq( string );
        string getCathCode();
        string getPDB();
        string getSeq();
        virtual ~ProteinSequence();
    protected:
    private:
    string cath;
    string pdb;
    string seq;
};

#endif // PROTEINSEQUENCE_H
