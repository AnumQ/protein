#include "../include/ProteinSequence.h"
#include "../include/AminoAcidCode.h"

using namespace std;

ProteinSequence::ProteinSequence()
{
    //ctor
}

void ProteinSequence::setCathCode( string c )
{
    cath = c;
}

void ProteinSequence::setPDB( string p )
{
    pdb = p;
}

void ProteinSequence::setSeq( string s )
{
    seq = s;
}

void ProteinSequence::setSeqLength( int l )
{
    seqLength = l;
}

void ProteinSequence::setAminoAcidCounts( vector<AminoAcidCode> a )
{
    AminoAcidCount.clear();
    for ( size_t i = 0; i < a.size(); i++ )
    {
        AminoAcidCount.push_back(a[i]);

    }
}

vector<AminoAcidCode> ProteinSequence::getAminoAcidCount()
{
    return AminoAcidCount;
}

void ProteinSequence::setAminoAcidColourCount( vector<AminoAcidColourCode> p )
{
    AminoAcidColourCount.clear();
    for ( size_t i = 0; i < p.size(); i++ )
    {
        AminoAcidColourCount.push_back(p[i]);
    }

}
vector<AminoAcidColourCode> ProteinSequence::getAminoAcidColourCount()
{
    return AminoAcidColourCount;
}

string ProteinSequence::getCathCode()

{
    return cath;
}

string ProteinSequence::getPDB()
{
    return pdb;
}

string ProteinSequence::getSeq()
{
    return seq;
}

int ProteinSequence::getSeqLength()
{
    return seqLength;
}

ProteinSequence::~ProteinSequence()
{
    //dtor
}
