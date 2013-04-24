#ifndef VERTICALCOLUMN_H
#define VERTICALCOLUMN_H
#include "stdafx.h"
#include "../include/FileCreator.h"
#include "../include/ScoreMatrix.h"
#include "../include/ProteinSequence.h"
#include "../include/AlignmentColumn.h"
#include "../include/AminoAcidCode.h"
#include "../include/AminoAcidColourCode.h"

using namespace std;

class VerticalColumn
{
    public:
        VerticalColumn();
        void getUserInput();
        void setUserInput(string);
        string getInputValue();
        void generateVerticalColumnComposition(vector<ProteinSequence>);
        void createColumns(vector<ProteinSequence>);
        void processColumns();
        vector<AlignmentColumn> getColumns();
        void createVerticalColumnCodes(string);
        void createVerticalColumnColour(string);
        /* Attributes */

        vector<AlignmentColumn> Columns;

        AminoAcidCode j;
        vector<AminoAcidCode> Codes;
        AminoAcidColourCode d;
        vector<AminoAcidColourCode> Colours;

        virtual ~VerticalColumn();
    protected:
    private:
    string UserInput;
    string InputValue;
    FileCreator* outFile;
    vector<AlignmentColumn> AllColumns;
};

#endif // VerticalColumn_H
