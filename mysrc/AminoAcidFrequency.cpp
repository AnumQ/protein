#include "../include/AminoAcidFrequency.h"
#include <stdio.h>
#include <math.h>

using namespace std;

AminoAcidFrequency::AminoAcidFrequency()
{
}

vector<ProteinSequence> AminoAcidFrequency::getFinalSeqs()
{
    return p3;
}

void AminoAcidFrequency::generateAminoAcidTables( vector<ProteinSequence> p )
{
    vector<ProteinSequence> p2 = assembleSeq(p);
    p3 = processSeq(p2);
    createPropertyTable(p3);
    createAminoAcidFrequency(p3);
}

void AminoAcidFrequency::createPropertyTable( vector<ProteinSequence> p )
{
    filename = "AminoAcidProperty.txt";
    fileOut.open(filename.c_str());
    filenames.push_back(filename);
    fileOut.write( filename.c_str(), filename.size() );

    string tab = "\t";
    string lbreak = "\n";

    fileOut.write( lbreak.c_str(), lbreak.size() );

    AminoAcidColourCode c;
    // create the name of the colours
    c.createColourCodes();
    // get the vector with the colours
    vector<AminoAcidColourCode> ColourCodes;
    ColourCodes = c.getColourCodes();


    for ( size_t i = 0; i < ColourCodes.size(); i++ )
    {
        if ( i == 0 )
        {
            string es = "     ";
            fileOut.write( es.c_str(), es.size() );
        }
        fileOut.write( tab.c_str(), tab.size() );
        string k = ColourCodes[i].getColour();

        fileOut.write( k.c_str(), k.size() );
    }

    string total = "Total";
    fileOut.write( tab.c_str(), tab.size() );
    fileOut.write( total.c_str(), total.size() );

    fileOut.write( lbreak.c_str(), lbreak.size() );

    vector<AminoAcidCode> AminoAcidCount;

    ScoreMatrix conversion;
    double percentage;
    for ( size_t i = 0; i < p.size(); i++ )
    {
        AminoAcidCount = p[i].getAminoAcidCount();
        string pdb = p[i].getPDB();
        pdb = pdb.substr(5, 7);
        fileOut.write( pdb.c_str(), pdb.size() );

        int t = 0;
        int ct = p[i].getSeqLength();

        for ( size_t n = 0; n < ColourCodes.size(); n++ )
        {
            int count = 0;
            fileOut.write( tab.c_str(), tab.size() );

            string k = ColourCodes[n].getColour();

            for ( size_t j = 0; j < AminoAcidCount.size(); j++ )
            {

                string AminoAcidColour = AminoAcidCount[j].getColour();
                if ( AminoAcidColour == k )
                {
                    int n = AminoAcidCount[j].getCount();
                    count = count + n;
                }
            }
            t = t + count;
            percentage = ((double)count/(double)ct)*100;;
            /*cout << pdb << " - " << ColourCodes[n].getColour() << " - "
            << ColourCodes[n].getCount() << endl;
            cout << "    " << pdb << " - " << ColourCodes[n].getColour() << " - "
            << percentage << endl; */


            string num = conversion.RoundToString(2, percentage);
            // if only real numbers are required: string num = conversion.number_to_string(count);
            fileOut.write( num.c_str(), num.size() );

        }

            fileOut.write( tab.c_str(), tab.size() );
            string totalp = conversion.number_to_string(100);
            fileOut.write( totalp.c_str(), totalp.size() );

            /* if only real numbers are needed
            string total = conversion.number_to_string(ct);
            fileOut.write( total.c_str(), total.size() );
            */

        fileOut.write( lbreak.c_str(), lbreak.size() );

    }

    fileOut.close();

}
/* Create the display in the Table */
void AminoAcidFrequency::createAminoAcidFrequency( vector<ProteinSequence> p )
{
    filename = "AminoAcidFrequency.txt";
    fileOut.open(filename.c_str());
    filenames.push_back(filename);
    fileOut.write( filename.c_str(), filename.size() );

    string AminoAcids = "ACDEFGHIKLMNPQRSTVWY";
    string tab = "\t";
    string lbreak = "\n";
    fileOut.write( lbreak.c_str(), lbreak.size() );

    for ( size_t i = 0; i < AminoAcids.size(); i++ )
    {
        if ( i == 0 )
        {
            string es = "     ";
            fileOut.write( es.c_str(), es.size() );
        }
        fileOut.write( tab.c_str(), tab.size() );
        char k = AminoAcids[i];

        fileOut.put(k);

    }

    //Add total
    string total = "Total";
    fileOut.write( tab.c_str(), tab.size() );
    fileOut.write( total.c_str(), total.size() );
    fileOut.write( lbreak.c_str(), lbreak.size() );

    vector<AminoAcidCode> AminoAcidCount;

    ScoreMatrix conversion;
    double percentage;
    for ( size_t i = 0; i < p.size(); i++ )
    {
        AminoAcidCount = p[i].getAminoAcidCount();
        string k = p[i].getPDB();
        k = k.substr(5, 7);
        fileOut.write( k.c_str(), k.size() );
        //fileOut.write( tab.c_str(), tab.size() );

        int t = p[i].getSeqLength();

        // perhaps add the code to create the dat for the colours here as well?

        double testtotal = 0;
        for ( size_t j = 0; j < AminoAcidCount.size(); j++ )
        {
            fileOut.write( tab.c_str(), tab.size() );

            int n = AminoAcidCount[j].getCount();

            percentage = ((double)n/(double)t)*100;;
            testtotal += percentage;

            string rnum = conversion.RoundToString(2, percentage);
            //string rnum = conversion.number_to_string(n);
            fileOut.write( rnum.c_str(), rnum.size() );
        }

        fileOut.write( tab.c_str(), tab.size() );

        string totalp = conversion.number_to_string(100);
        fileOut.write( totalp.c_str(), totalp.size() );

        /*total = conversion.number_to_string(t);
        fileOut.write( total.c_str(), total.size() ); */

        fileOut.write( lbreak.c_str(), lbreak.size() );

    }

    fileOut.close();

}

bool AminoAcidFrequency::openFile( string file )
{
    string i = file;
    readFile.open(i.c_str());
    if (!readFile.is_open() )
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

void AminoAcidFrequency::closeFile()
{
    if( verbose )
    cout << "Closing file .. " << endl;
    readFile.close();
}

void AminoAcidFrequency::clearFile()
{
	ifstream& File = readFile;
	if ( verbose )
	{
		cout << "Clearing file .. " << filename << endl;
	}
	File.clear();
	File.seekg( 0, ios::beg );

}

/* The Output.aln file from ClustalW shows the sequence related to one protein in
several lines depending on how it was aligned during multiple sequence alignment.
AssembleSeq assembles the sequence into one. */
vector<ProteinSequence> AminoAcidFrequency::assembleSeq( vector<ProteinSequence> p )
{
    ifstream& File = readFile;

    string LINE;
    string PDB = "pdb|";
    string currentPDB;
    string linePDB;
    string currentSeq;
    string genSeq;
    string Seq;
    int count = 0;

    //cout << "Assembling the sequences ... " << endl;

    for ( size_t i = 0; i < p.size(); i++ )
    {
        //cout << "p is " << p[i].getPDB() << endl;
        count = 0;
        clearFile();
        while ( !File.eof() )
        {
            getline(File, LINE);

            size_t check1 = LINE.find(PDB, 0);
            if ( check1 != string::npos )
            {
                linePDB = LINE.substr(0,11); // pdb number from the line

                currentPDB = p[i].getPDB(); // pdb number from the current vector object

                genSeq = LINE.substr(11, LINE.size());
                string currentSeq = RemoveSpaces(genSeq);

                if ( LINE.compare(0,11, currentPDB, 1, 11) == 0 )
                {
                    if ( count == 0 )
                        {
                            Seq = currentSeq;
                        }

                        if ( count > 0 )
                        {
                            Seq = Seq + currentSeq;
                        }

                        count++;
                }
            }

        }

        string mergedSeq = Seq;
        Seq.clear(); // clear Seq for so the new sequence is not added in the same line as the previous one

        string finalSeq;

        //Remove spaces
        for ( size_t i = 0; i < mergedSeq.size(); i++ )
        {
            char c = mergedSeq[i];
            if ( c != '\0' )
            {
                finalSeq.push_back(c);
            }
        }

        p[i].setSeq(finalSeq);
        // string gSeq = p[i].getSeq();
        // cout << gSeq << endl;

    }
    return p;
}

/* In Output.aln file the sequence is divided in several lines and the
PDB name is appearing several times displaying chunks of the sequence if it is too
long, moved, substituted, added, removed etc.
processSeq() makes sure only one instance of each protein name appears in
the list once the sequence has been assembled into one.
processSeq() also counts the number of each Amino Acid in a sequence and the total
number of Amino Acids in a sequence.  */
vector<ProteinSequence> AminoAcidFrequency::processSeq( vector<ProteinSequence> p )
{
    vector<ProteinSequence> processedP;
    processedP.clear();
    for ( size_t i = 0; i < p.size(); i++ )
    {
        string s = p[i].getSeq();
        if ( s != "" )
        {
            if ( i == 0)
                {
                    processedP.push_back(p[i]);
                }
            if ( i > 0 )
                {
                    if ( p[i].getSeq() != p[i-1].getSeq() )
                    {

                        processedP.push_back(p[i]);
                    }
                }
        }
    }

    Codes.clear();
    Colours.clear();
    int total;

    for ( size_t i = 0; i < processedP.size(); i++ )
    {
        total = 0;
        Codes = j.createAminoAcidCounters();
        c.createColourCodes();
        Colours = c.getColourCodes();

        string p = processedP[i].getPDB();
        string s = processedP[i].getSeq();

        string rc = RemoveSpaces(s);
            //cout << rc << endl;

            //cout << "size is " << s.size() << endl;
            for ( size_t u = 0; u < s.size(); u++ )
            {
                //cout << "" << s[u] << endl;
                if ( s[u] == '\0')
                {

                }

                else if ( s[u] == '-' )
                {
                }

                else
                {
                    total++;

                    //loop throught the aminoacid codes for a protein and if found then add the count to it.
                    for( size_t n = 0; n < Codes.size(); n++ )
                    {
                        char x = Codes[n].getCodeName();

                        //string colour = Codes[n].getColour();

                        //cout << "Code is " << x << " - " << colour << endl;
                        if ( s[u] == x )
                        {
                            Codes[n].addCodeCount(1); // adding 1 for each time the same letter is found

                        }

                    }
                    // loop through the sequence and get the colour count
                    for( size_t n = 0; n < Colours.size(); n++ )
                    {
                        int count = 0;

                        string k = Colours[n].getColour();

                        for ( size_t m = 0; m < Codes.size(); m++ )
                        {
                            string h = Codes[m].getColour();
                            if ( h == k )
                            {
                                int currentCount = Codes[m].getCount();
                                count = count + currentCount;
                            }
                        }
                        Colours[n].setCount(count);
                    }
                }
            }
        processedP[i].setAminoAcidCounts(Codes);
        processedP[i].setAminoAcidColourCount(Colours);
        processedP[i].setSeqLength(total);
        //cout << "Total is " << total << endl;
    }

    return processedP;
}


/* RemoveSpaces() removes spaces in a string */
string AminoAcidFrequency::RemoveSpaces( string s )
{
    string line = s;
    for ( size_t i = 0; i < line.size(); i++)
        {
            if ( line[i] == ' ')
              {
                     for ( size_t j = i; j < line.size(); j++ )
                     {
                           line[j] = line[j+1];
                     }
                     i = i - 1;
              }
        }
    return line;
}

string AminoAcidFrequency::RemoveSpaces2( string s )
{
    string finalLine;
    char c;

        //Remove spaces
    for ( size_t i = 0; i < s.size(); i++ )
    {
        c = s[i];
        if ( c != '\0')
        {
            finalLine.push_back(c);
        }
    }
    return finalLine;

}

/* RemoveTabs() removes tabs in a string */
string AminoAcidFrequency::RemoveTabs( string s )
{
    string line = s;
    for ( size_t i = 0; i < line.size(); i++)
        {
            if ( line[i] == '\t' )
              {
                     for ( size_t j = i; j < line.size(); j++ )
                     {
                           line[j] = line[j+1];
                     }
                     i = i - 1;
              }
        }
    return line;

}

AminoAcidFrequency::~AminoAcidFrequency()
{
    //dtor
}
