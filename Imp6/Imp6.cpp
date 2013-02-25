#include "stdafx.h"
#include "conio.h"
#include "alignment/Alignment.h"
#include "alignment/Sequence.h"
#include "general/clustalw.h"
#include "general/UserParameters.h"
#include "substitutionMatrix/SubMatrix.h"
#include "general/Utility.h"
#include "fileInput/FileReader.h"
#include "interface/InteractiveMenu.h"
#include "interface/CommandLineParser.h"
#include "general/DebugLog.h"
#include "general/ClustalWResources.h"
#include "general/Stats.h"
#include "pairwise/FullPairwiseAlign.h"
#include "../include/InputFile.h"
#include "../include/ProteinSequence.h"
#include "../include/ScoreMatrix.h"
#include "../include/AminoAcidFrequency.h"
#include "../include/AminoAcidCode.h"
#include "../include/DistanceMatrix.h"
#include "../include/VerticalPosition.h"

namespace clustalw
{
    UserParameters* userParameters;
    Utility* utilityObject;
    SubMatrix *subMatrix;
    DebugLog* logObject;
    Stats* statsObject;
}
using namespace std;
using namespace clustalw;

void ClustalWInitializers()
{
    clustalw::userParameters = new clustalw::UserParameters(false);
	clustalw::utilityObject = new clustalw::Utility();
	clustalw::subMatrix = new clustalw::SubMatrix();
    clustalw::statsObject = new clustalw::Stats();

}
void setUserParameters()
{
    userParameters->setDisplayInfo(true);
	userParameters->setMenuFlag(true);
	userParameters->setInteractive(true);
}
bool verbose;
void defineverbose()
{
    cout << "Please define verbose: (Y/N)" << endl;
    char c;
    cin >> c;

    switch(c)
    {
        case 'y':
            verbose = true;
            cout << "Verbose is TRUE. Displaying details while running.\n" << endl;
            break;
        case 'n':
            verbose = false;
            cout << "Verbose is FALSE. No details available.\n" << endl;
            break;
        default:
            verbose = false;
            cout << "Choose default. Verbose is FALSE." << endl;
            break;
    }
}
void welcome()
{
    cout << "/*****************************************************************************/\n"
            "/* ##     ## ##### ##     ####   ####  ###  ### ####                         */\n"
            "/*  ## # ##  ##    ##    ##     ##  ## ## ## ## ##                           */\n"
            "/*   ## ##   ##### #####  ####   ####  ##    ## ####                         */\n"
            "/*                                                                           */\n"
            "/*                                                                           */\n"
            "/*****************************************************************************/" << endl;
}

vector<string> filenames;
int main(int argc, char **argv)
{
    welcome();
    defineverbose();

    filenames.clear();

    ClustalWInitializers();
    clustalw::ClustalWResources *resources = clustalw::ClustalWResources::Instance();
    resources->setPathToExecutable(string(argv[0]));
    setUserParameters();

    InputFile start;// object reads from an input file and creates a new file
    start.run();

	string offendingSeq;
	Clustal* clustalObj;
	clustalObj = new clustalw::Clustal();
	int u = clustalObj->sequenceInput(false, &offendingSeq);
	string phylipName;
	clustalObj->align(&phylipName);

    AminoAcidFrequency Table;
    Table.openFile("TEST-OutputFile.aln");

    vector<ProteinSequence> p1;
    p1 = start.getProteinData();
    Table.generateAminoAcidTables(p1);

    p1.clear();
    p1 = Table.getFinalSeqs();

    DistanceMatrix dm;
    dm.createDistanceTableCodes(p1);
    dm.createSimilarityMatrixCodes(p1);
    dm.createDistanceTableColours(p1);
    dm.createSimilarityMatrixColours(p1);

    VerticalPosition vp;
    vp.run(p1);

    cout<< "\nPROCESS COMPLETED!\nThe following files were created:\n" << endl;
    for ( size_t i = 0; i < filenames.size(); i++ )
    {
        cout << "\t" << i+1 << ". " << filenames[i] << endl;
    }
    return 0;
}
