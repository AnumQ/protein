#include "../include/AminoAcidColourCode.h"

using namespace std;

AminoAcidColourCode::AminoAcidColourCode()
{
    //ctor
}

void AminoAcidColourCode::setColour(string c )
{
    colour = c;
}

string AminoAcidColourCode::getColour()
{
    return colour;
}

void AminoAcidColourCode::setCount(int c)
{
    count = c;
}

double AminoAcidColourCode::getCount()
{
    return count;
}

void AminoAcidColourCode::createColourCodes()
{
    AminoAcidColourCode Colour;
    ColourCodes.clear();

    Colour.setColour("RE");
    ColourCodes.push_back(Colour);

    Colour.setColour("BL");
    ColourCodes.push_back(Colour);

    Colour.setColour("MA");
    ColourCodes.push_back(Colour);

    Colour.setColour("GR");
    ColourCodes.push_back(Colour);

    Colour.setColour("GY");
    ColourCodes.push_back(Colour);
}

vector<AminoAcidColourCode> AminoAcidColourCode::getColourCodes()
{
    return ColourCodes;
}

AminoAcidColourCode::~AminoAcidColourCode()
{
    //dtor
}
