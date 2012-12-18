#ifndef INPUTFILE_H
#define INPUTFILE_H
#include "stdafx.h"
#include <iostream>
using namespace std;

class InputFile
{
    public:
        InputFile();
        void getSearchInput();
        void defineLevelOfHierarchy();
        void getPDBfromClassifiedList();
        void setCathCode( string CathC );
        string getFileInput();
        void closeInputFile();
        void closeFile();
        bool openFile( string file );
        string getCathCode();
        void writeInputFile();
        int getSeqC();
        void checkToProceed(bool f);
        void processInput();
        void determineSourceFile();
        bool flag;
        void createSimplifiedSourceFile();
        void writeInputFileForRepresentatives();
        void deleteProteinObjects();

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
    ofstream infile;

};


#endif // INPUTFILE_H
