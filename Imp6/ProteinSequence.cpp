#include "../include/ProteinSequence.h"

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

ProteinSequence::~ProteinSequence()
{
    //dtor
}
