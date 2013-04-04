#ifndef INPUTFILE_H
#define INPUTFILE_H
#include "stdafx.h"
#include <iostream>
#include "FileCreator.h"
#include "FileRead.h"
using namespace std;

extern vector<ProteinSequence> p;

class ProteinSequence;

class InputFile
{
    public:
        InputFile();
        void run();
        void getSearchInput();
        void checkToStartAgain();
        void defineLevelOfHierarchy();
        void getPDBfromClassifiedList();
        void setCathCode( string );
        string getCathCode();
        string getFileInput();
        void closeInputFile();
        void closeFile();
        bool openFile( string file );
        void writeInputFile2(string);
        void writeInputFile(string);
        int getSeqC();
        void checkToProceed(bool f);
        void processInput();
        void determineSourceFile();
        bool determineSourceFile2();
        string getUserInputFile();
        void createSimplifiedSourceFile();
        void writeInputFileForRepresentatives();
        vector<ProteinSequence> getProteinData();
        vector<ProteinSequence> getAlignmentData();
        void writeSearchResults(int, string );
        void createSourceFile();

        /* Attributes */
        bool flag;

        virtual ~InputFile();
    protected:
    private:
    string dCath; // cathcode derived from the classified file
    string sourceFile;
    string levelOfHierarchy;
    string filename;
    string SearchCathCode;
    int seqC;
    ifstream fileInput;
    vector<string> pdblist;
    vector<string> Lines;
    string fsearch;
    ofstream sourceFil;
    ofstream infile;
    ofstream searchResults;
    stringstream convert;
    ProteinSequence currentSequence;
    vector<ProteinSequence> p;
    FileCreator* outFile;
};


#endif // INPUTFILE_H
