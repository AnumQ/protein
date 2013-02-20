#include "../include/AlignmentColumn.h"

using namespace std;

AlignmentColumn::AlignmentColumn()
{
    //ctor
}

void AlignmentColumn::setColumn(string c)
{
    column = c;
}

string AlignmentColumn::getColumn()
{
    return column;
}

void AlignmentColumn::setAminoAcidCodeCount( vector<AminoAcidCode> a )
{
    AminoAcidCodeCount.clear();
    for ( size_t i = 0; i < a.size(); i++ )
    {
        AminoAcidCodeCount.push_back(a[i]);
    }
}

vector<AminoAcidCode> AlignmentColumn::getAminoAcidCodeCount()
{
    return AminoAcidCodeCount;
}

void AlignmentColumn::setAminoAcidColourCount( vector<AminoAcidColourCode> a )
{
    for ( size_t i = 0; i < a.size(); i++ )
    {
         AminoAcidColourCount.push_back(a[i]);
    }

}

vector<AminoAcidColourCode> AlignmentColumn::getAminoAcidColourCount()
{
    return AminoAcidColourCount;

}
AlignmentColumn::~AlignmentColumn()
{
    //dtor
}
