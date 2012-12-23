#include "../include/InputFile.h"
#include "../include/ProteinSequence.h"

using namespace std;

InputFile::InputFile()
{
    determineSourceFile();
    getSearchInput();
    setCathCode( SearchCathCode );

    defineLevelOfHierarchy();
    if ( !levelOfHierarchy.empty() )
    {
        if ( openFile( levelOfHierarchy ) == true )
        {
            getPDBfromClassifiedList();
            closeFile();
            if ( (openFile( sourceFile )) == true )
            {
                writeInputFileForRepresentatives();
                closeInputFile();
                closeFile();
            }

        }
    }
    else
    {
        if ( (openFile( sourceFile )) == true )
        {
           getCathCode();
           writeInputFile();
           closeInputFile();
           closeFile();
        }
    }


}

void InputFile::getSearchInput()
{
    cout << "   Please enter the CathCode: ";
    cin >> SearchCathCode;
    //getline( cin, SearchCathCode );
}

void InputFile::defineLevelOfHierarchy()
{
    cout << "   Please define the level of CATH hierarchy nodes: \n"
            "\t1. 35 %\n"
            "\t2. 60 %\n"
            "\t3. 95 %\n"
            "\t4. 100 %\n"
            "\t5. No representatives\n" << endl;
    int x;
    cin >> x;

    switch(x)
    {
        case 1:
            levelOfHierarchy = "D:/Documents/FinalYearProject/CathDomainList.S35.v3.5.c";
            break;
        case 2:
            levelOfHierarchy = "D:/Documents/FinalYearProject/CathDomainList.S60.v3.5.c";
            break;
        case 3:
            levelOfHierarchy = "D:/Documents/FinalYearProject/CathDomainList.S95.v3.5.c";
            break;
        case 4:
            levelOfHierarchy = "D:/Documents/FinalYearProject/CathDomainList.S100.v3.5.c";
            break;
        case 5:
            cout << "No hierarchy chosen\n";
            levelOfHierarchy = "";
            break;
        default:
            cout << "No hierarchy chosen\n";
            levelOfHierarchy = "";
            break;
    }
}

void InputFile::getPDBfromClassifiedList()
{
    ifstream& File = fileInput;
    char c;
    string LINE;
    pdblist.clear();
    string pdb;
    string CmpSearchCathCode = SearchCathCode;
    CmpSearchCathCode.push_back('.');

    int i = 0;

    while ( !File.eof() )
    {
        while ( File.get(c) )
        {
            if ( c != '\n')
            {
                if ( c != ' ')
                {
                    LINE.push_back(c);
                }
                else
                {
                    if ( LINE.size() != 0 )
                    {
                        int pos;
                        if ( i == 0 )
                        {
                            pos = 0;
                            pdb = LINE;
                        }
                        if ( i > 0 && i < 10 )
                        {
                            string k = ".";
                            dCath.insert(pos, LINE);
                            pos = dCath.length();

                            if ( i < 9 )
                            {
                                dCath.insert(pos, k);
                            }
                            pos = dCath.length();
                        }
                        i++;
                    }
                    LINE.clear();
                }
            }
            else
            {
                if ( CmpSearchCathCode.compare(0, dCath.size(), dCath, 0, CmpSearchCathCode.size()) == 0 )
                {
                    string j = ">pdb|";
                    pdb.insert(0, j);
                    pdb.push_back('\n');
                    pdblist.push_back(pdb);
                }
                dCath.clear();
                i = 0;
                LINE.clear();
            }
        }
    }
}

void InputFile::setCathCode( string CathC )
{
    SearchCathCode = CathC;
}

string InputFile::getCathCode()
{
    return SearchCathCode;
}

string InputFile::getFileInput()
{
    return sourceFile;
}

void InputFile::determineSourceFile()
{
    cout << "   Which source file do you wish to use? \n"
            "\t1. Input2 (Test file )\n"
            "\t2. Cath Domain Description File V3.3.0 (Cath Database)\n"
            "\t3. Cath Domain Description File V3.5.0 (Cath Database)\n"
            "\t4. Cath Domain Description File V3.5.0 (Simplified version)\n" << endl;
    int x;
    cin >> x;

    switch(x)
    {
        case 1:
            sourceFile = "D:/Documents/FinalYearProject/Input2.txt";
            break;
        case 2:
            sourceFile = "D:/Documents/FinalYearProject/CathDomainDescriptionFile.v3.5.0.c";
            break;
        case 3:
            sourceFile = "D:/Documents/FinalYearProject/CathDomainDescriptionFile.v3.c";
            break;
        case 4:
            sourceFile = "D:/Documents/FinalYearProject/CathDomainDescriptionFile.Simplified.c";
            break;
        default:
            cout << "Choosing default: Input2.txt" << endl;
            sourceFile = "D:/Documents/FinalYearProject/Input2.txt";
            break;
    }

}

bool InputFile::openFile( string file )
{
    //sourceFile = "D:/Documents/FinalYearProject/CathDomainDescriptionFile.v3.c";
    string i = file;
    fileInput.open(i.c_str());
    if (!fileInput.is_open() )
	{
		cerr << "Error opening file: " << i << endl;
		return false;
	}
	else
	{
	    if( verbose )
        cout << "Opened file: " << i << endl;
		return true;
	}
}

void InputFile::closeFile()
{
    if( verbose )
    cout << "Closing file .. " << endl;
    fileInput.close();
}

void InputFile::closeInputFile()
{
    infile.close();
}

void InputFile::writeInputFileForRepresentatives()
{
    vector<ProteinSequence> p;
    ProteinSequence currentSequence;

    seqC = 0;
    filename = "InputFile.txt";
    infile.open(filename.c_str());

    ifstream& File = fileInput;
    string LINE;
    int count = 0;
    string cathCode;
    string cathWord = "CATHCODE";
    string pdb;
    string pdbWord = "DSEQH";
    string seq;
    string seqWord = "DSEQS";
    char c;
    size_t check1, check2, check3;
    cout << "Fetching the representative sequences... \n";

    while ( !File.eof() )
    {
        while ( File.get(c) )
        {
            if ( c != '\n')
            {
                LINE.push_back(c);
            }
            else
            {
                Lines.push_back(LINE);
                check1 = LINE.find( cathWord, 0 );
                check2 = LINE.find( pdbWord, 0 );
                check3 = LINE.find( seqWord, 0 );
                if ( check1 != string::npos )
                {
                    int position = cathWord.size();
                    for ( size_t i = position; i < LINE.size(); i++)
                    {
                        if ( LINE[i] == ' ')
                        {
                            //don't do anything
                        }
                        else
                        {
                            cathCode.push_back(LINE[i]);
                        }
                    }
                    {
                        currentSequence.setCathCode(cathCode); // set the cathcode for the protein
                    }
                    cathCode.clear();
                }

                if ( check2 != string::npos )
                {
                    int position = pdbWord.size();
                    for ( size_t i = position; i < LINE.size(); i++)
                    {
                        if ( LINE[i] == ' ')
                        {
                            //don't do anything
                        }
                        else
                        {
                            pdb.push_back(LINE[i]);
                            currentSequence.setPDB(pdb + '\n');
                        }
                    }
                    string n = currentSequence.getPDB();
                    count = seqC;
                    for( size_t i = 0; i < pdblist.size(); i++ )
                    {
                        if ( pdblist[i] == n )
                        {
                            infile.write( (n.c_str()), n.size() );
                            seqC++;
                        }
                    }
                    pdb.clear();
                }
                if ( check3 != string::npos )
                {
                    int position = seqWord.size();
                    for ( size_t i = position; i < LINE.size(); i++)
                    {
                        if ( LINE[i] == ' ')
                        {
                            //don't do anything
                        }
                        else
                        {
                            seq.push_back(LINE[i]);
                            currentSequence.setSeq(seq + '\n');
                        }
                    }
                    string o = currentSequence.getSeq();
                    if ( seqC > count )
                    {
                        infile.write( (o.c_str()), o.size() );
                    }
                    seq.clear();
                }
                LINE.clear();
            }
        }
    }
}


void InputFile::writeInputFile()
{
    vector<ProteinSequence> p;
    ProteinSequence currentSequence;

    seqC = 0;
    filename = "InputFile.txt";
    infile.open(filename.c_str());

    ifstream& File = fileInput;
    string LINE;

    string cathCode;
    string cathWord = "CATHCODE";
    string pdb;
    string pdbWord = "DSEQH";
    string seq;
    string seqWord = "DSEQS";
    char c;
    size_t check1, check2, check3;
    cout << "Fetching the sequences... ";
    while ( !File.eof() )
    {
        while ( File.get(c) )
        {
            if ( c != '\n')
            {
                LINE.push_back(c);
            }
            else
            {
                Lines.push_back(LINE);
                check1 = LINE.find( cathWord, 0 );
                check2 = LINE.find( pdbWord, 0 );
                check3 = LINE.find( seqWord, 0 );
                if ( check1 != string::npos )
                {
                    int position = cathWord.size();
                    for ( size_t i = position; i < LINE.size(); i++)
                    {
                        if ( LINE[i] == ' ')
                        {
                            //don't do anything
                        }
                        else
                        {
                            cathCode.push_back(LINE[i]);

                        }
                    }
                   // if ( strcmp( SearchCathCode.c_str(), cathCode.c_str() ) == 0 )
                 //   if ( cathCode == SearchCathCode )
                    {
                        currentSequence.setCathCode(cathCode);

                        string m = currentSequence.getCathCode();
                    }
                    cathCode.clear();
                }
                if ( check2 != string::npos )
                {
                    int position = pdbWord.size();
                    for ( size_t i = position; i < LINE.size(); i++)
                    {
                        if ( LINE[i] == ' ')
                        {
                            //don't do anything
                        }
                        else
                        {
                            pdb.push_back(LINE[i]);
                            currentSequence.setPDB(pdb + '\n');
                        }
                    }
                    string n = currentSequence.getPDB();
                    if ( (currentSequence.getCathCode()) == SearchCathCode )
                    {
                        //cout << currentSequence->getCathCode() << endl;
                        infile.write( (n.c_str()), n.size() );
                        seqC++;
                    }
                    pdb.clear();
                    //cout << LINE << endl;
                }
                if ( check3 != string::npos )
                {
                    int position = seqWord.size();
                    for ( size_t i = position; i < LINE.size(); i++)
                    {
                        if ( LINE[i] == ' ')
                        {
                            //don't do anything
                        }
                        else
                        {
                            seq.push_back(LINE[i]);
                            currentSequence.setSeq(seq + '\n');
                        }
                    }
                    string o = currentSequence.getSeq();
                    if ( (currentSequence.getCathCode()) == SearchCathCode )
                    {
                       // cout << o << endl;
                        infile.write( (o.c_str()), o.size() );
                        //seqC++;
                    }

                    seq.clear();
                }
                //cout << LINE << endl;
                LINE.clear();
            }
        }
    }
}

int InputFile::getSeqC()
{
    return seqC;
}

void InputFile::checkToProceed( bool f )
{
    flag = f;
    int sc = getSeqC();

    if ( sc > 0 )
    {
        if ( flag == true )
        {
            cout << "Found " << sc << " sequence(s).\n" << endl;
        }
        processInput();
    }
    else
    {
        cout << "No sequences found. Exiting..." << endl;
    }
}

void InputFile::processInput()
{
    char c;
    char y = 'y';
    char n = 'n';

    cout << "Do you wish to proceed? (Y/N) " << flush;
    cin >> c;
    if ( c == y)
    {
        cout << "Proceding with the alignment..." << endl;
    }
    else if ( c == n )
    {
        cout << "Exiting the program..." << endl;
        exit(1);
    }
    else
    {
        cout << "Invalid input. Please try again. (Y/N)" << endl;
        flag = false;
        checkToProceed( flag );
    }
}

void InputFile::createSimplifiedSourceFile()
{
    ofstream ofile;
    string f = "CathDomainDescriptionFile.Simplified.0";
    ofile.open(f.c_str());

    string source = "D:/Documents/FinalYearProject/CathDomainDescriptionFile.v3.5.0.c";
    ifstream file;
    file.open(source.c_str());
    if (!file.is_open() )
	{
		cerr << "Error opening file: " << source << endl;
    }
    cout << "Stating the process. " << endl;
    string LINE;

    string cathCode;
    string cathWord = "CATHCODE";
    string pdb;
    string pdbWord = "DSEQH";
    string seq;
    string seqWord = "DSEQS";
    char c;
    size_t check1, check2, check3;

     while ( !file.eof() )
    {
        while ( file.get(c) )
        {
            if ( c != '\n')
            {
                LINE.push_back(c);
            }
            else
            {
                //cout << LINE << endl;
                check1 = LINE.find( cathWord, 0 );
                check2 = LINE.find( pdbWord, 0 );
                check3 = LINE.find( seqWord, 0 );

                if ( check1 != string::npos )
                {
                    cout << LINE << endl;
                    cathCode = LINE + "\n";
                    ofile.write((cathCode.c_str()), cathCode.size());
                }
                if ( check2 != string::npos )
                {
                    cout << LINE << endl;
                    pdb = LINE + "\n";
                    ofile.write( (pdb.c_str()), pdb.size());
                }
                if ( check3 != string::npos )
                {
                    cout << LINE << endl;
                    seq = LINE + "\n";
                    ofile.write( (seq.c_str()), seq.size());
                }
                LINE.clear();

               /* */

            }
        }
    }
}

InputFile::~InputFile()
{
}
