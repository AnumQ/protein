#ifndef INPUTFILE_H
#define INPUTFILE_H
#include "stdafx.h"
#include <iostream>
using namespace std;

extern vector<ProteinSequence> p;

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
        void writeInputFile();
        int getSeqC();
        void checkToProceed(bool f);
        void processInput();
        void determineSourceFile();
        void determineSourceFile2();
        void createSimplifiedSourceFile();
        void writeInputFileForRepresentatives();
        vector<ProteinSequence> getProteinData();
        void writeSearchResults(int, string );

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
    ofstream infile;
    ofstream searchResults;
    stringstream convert;
    ProteinSequence currentSequence;
    vector<ProteinSequence> p;
};


#endif // INPUTFILE_H
