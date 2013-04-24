#ifndef AMINOACIDCOMPOSITION_H
#define AMINOACIDCOMPOSITION_H
#include "stdafx.h"
#include "../include/FileCreator.h"
#include "../include/AminoAcidCode.h"
#include "../include/AminoAcidColourCode.h"

using namespace std;

class AminoAcidCode;
class AminoAcidColourCode;

class AminoAcidComposition
{
    public:
        AminoAcidComposition();
        void createAminoAcidFrequency( vector<ProteinSequence> );
        bool openFile(string);
        void closeFile();
        void clearFile();
        void createPropertyTable( vector<ProteinSequence> );
        void generateAminoAcidTables( vector<ProteinSequence> );
        vector<ProteinSequence> assembleSeq( vector<ProteinSequence> );
        vector<ProteinSequence> processSeq( vector<ProteinSequence> );
        vector<ProteinSequence> getFinalSeqs();
        string RemoveSpaces(string);
        string RemoveSpaces2(string);
        string RemoveTabs( string );

        /* Attributes */
        AminoAcidCode j;
        vector<AminoAcidCode> Codes;
        AminoAcidColourCode c;
        vector<AminoAcidColourCode> Colours;

        virtual ~AminoAcidComposition();
    protected:
    private:
    string filename;
    ifstream readFile;
    ofstream fileOut;
    string aaCodes;
    vector<ProteinSequence> p3;

};

#endif // AminoAcidComposition_H
