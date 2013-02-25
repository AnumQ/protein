#ifndef VERTICALPOSITION_H
#define VERTICALPOSITION_H
#include "stdafx.h"
#include "../include/FileCreator.h"
#include "../include/ScoreMatrix.h"
#include "../include/ProteinSequence.h"
#include "../include/AlignmentColumn.h"
#include "../include/AminoAcidCode.h"
#include "../include/AminoAcidColourCode.h"

using namespace std;

class VerticalPosition
{
    public:
        VerticalPosition();
        void getUserInput();
        void setUserInput(string);
        string getInputValue();
        void run(vector<ProteinSequence>);
        void createColumns(vector<ProteinSequence>);
        void processColumns();
        vector<AlignmentColumn> getColumns();
        void createVerticalPosition(string);
        void createVerticalPositionColour(string);
        /* Attributes */

        vector<AlignmentColumn> Columns;

        AminoAcidCode j;
        vector<AminoAcidCode> Codes;
        AminoAcidColourCode d;
        vector<AminoAcidColourCode> Colours;

        virtual ~VerticalPosition();
    protected:
    private:
    string UserInput;
    string InputValue;
    FileCreator* outFile;
    vector<AlignmentColumn> AllColumns;
};

#endif // VERTICALPOSITION_H
