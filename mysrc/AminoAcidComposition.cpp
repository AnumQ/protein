#include "../include/AminoAcidComposition.h"
#include <stdio.h>
#include <math.h>

using namespace std;

AminoAcidComposition::AminoAcidComposition()
{
}

vector<ProteinSequence> AminoAcidComposition::getFinalSeqs()
{
    return p3;
}

void AminoAcidComposition::generateAminoAcidTables( vector<ProteinSequence> p )
{
    vector<ProteinSequence> p2 = assembleSeq(p);
    p3 = processSeq(p2);
    createAminoAcidFrequency(p3);
    createPropertyTable(p3);

}

void AminoAcidComposition::createPropertyTable( vector<ProteinSequence> p )
{
    filename = "outFiles//AminoAcidProperty.txt";
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
    vector<AminoAcidColourCode> Distribution;
    Distribution = c.getColourCodes();


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
    int DistributionTotal = 0;

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
        DistributionTotal += ct;

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
            Distribution[n].addDistributionCount(count);
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

    double pDistribution;
    for ( size_t i = 0; i < Distribution.size(); i++ )
    {
        if ( i == 0 )
        {
            string es = "Total";
            fileOut.write( es.c_str(), es.size() );
        }
        fileOut.write( tab.c_str(), tab.size() );
        int AminoAcidD = Distribution[i].getDistribution();
        //cout << AminoAcidD << endl;
        pDistribution = ((double)AminoAcidD/(double)DistributionTotal)*100;;
        string d = conversion.RoundToString(2, pDistribution);
        //string d = conversion.number_to_string(AminoAcidD);
        fileOut.write( d.c_str(), d.size() );

    }

    fileOut.write( tab.c_str(), tab.size() );
    int pt = 100;
    string DistributionTotalNum = conversion.number_to_string(pt);
    fileOut.write( DistributionTotalNum.c_str(), DistributionTotalNum.size() );

    fileOut.write( lbreak.c_str(), lbreak.size() );

    //Get the Amino Acid Composition
    j.assignAminoAcidComposition();
    vector<AminoAcidCode> composition = j.getAminoAcidComposition();
    double t = 0;

    for ( size_t i = 0; i < ColourCodes.size(); i++ )
    {
        if ( i == 0 )
        {
            string es = "CompD";
            fileOut.write( es.c_str(), es.size() );
        }

        string u = ColourCodes[i].getColour();
        for ( size_t j = 0; j < composition.size(); j++ )
        {
            string h = composition[j].getColour();

            if ( u == h )
            {
                double distr = composition[j].getComposition();
                ColourCodes[i].setComposition(distr);
            }

        }
        //cout << ColourCodes[i].getComposition() << endl;
        fileOut.write( tab.c_str(), tab.size() );
        double k = ColourCodes[i].getComposition();
        t = t+k;
        string comp = conversion.RoundToString(2,k);

        fileOut.write( comp.c_str(), comp.size() );

    }
    int y = (int)round(t);
    string tnum = conversion.number_to_string(y);
    fileOut.write( tab.c_str(), tab.size() );
    fileOut.write( tnum.c_str(), tnum.size() );



    fileOut.close();

}
/* Create the display in the Table */
void AminoAcidComposition::createAminoAcidFrequency( vector<ProteinSequence> p )
{
    filename = "outFiles//AminoAcidFrequency.txt";
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
    vector<AminoAcidCode> Distribution;
    Distribution = j.createAminoAcidCounters();
    int DistributionTotal = 0;

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
        DistributionTotal += t;
        // perhaps add the code to create the dat for the colours here as well?

        double testtotal = 0;
        for ( size_t j = 0; j < AminoAcidCount.size(); j++ )
        {
            fileOut.write( tab.c_str(), tab.size() );

            int n = AminoAcidCount[j].getCount();

            percentage = ((double)n/(double)t)*100;;
            //cout << percentage << endl;
            Distribution[j].addDistributionCount(n);

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

    double pDistribution;
    for ( size_t i = 0; i < Distribution.size(); i++ )
    {
        if ( i == 0 )
        {
            string es = "Total";
            fileOut.write( es.c_str(), es.size() );
        }
        fileOut.write( tab.c_str(), tab.size() );
        int AminoAcidD = Distribution[i].getDistribution();

        pDistribution = ((double)AminoAcidD/(double)DistributionTotal)*100;;
        string d = conversion.RoundToString(2, pDistribution);

        fileOut.write( d.c_str(), d.size() );

    }
    fileOut.write( tab.c_str(), tab.size() );
    int pt = 100;
    string DistributionTotalNum = conversion.number_to_string(pt);
    fileOut.write( DistributionTotalNum.c_str(), DistributionTotalNum.size() );


    fileOut.write( lbreak.c_str(), lbreak.size() );

    //Get the Amino Acid Composition
    j.assignAminoAcidComposition();
    vector<AminoAcidCode> composition = j.getAminoAcidComposition();
    double t = 0;
    for ( size_t i = 0; i < composition.size(); i++ )
    {
        if ( i == 0 )
        {
            string es = "CompD";
            fileOut.write( es.c_str(), es.size() );
        }
        fileOut.write( tab.c_str(), tab.size() );
        double k = composition[i].getComposition();
        t = t+k;
        string comp = conversion.RoundToString(2,k);

        fileOut.write( comp.c_str(), comp.size() );

    }
    int y = (int)round(t);
    string tnum = conversion.number_to_string(y);
    fileOut.write( tab.c_str(), tab.size() );
    fileOut.write( tnum.c_str(), tnum.size() );



    fileOut.close();

}

bool AminoAcidComposition::openFile( string file )
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

void AminoAcidComposition::closeFile()
{
    if( verbose )
    cout << "Closing file .. " << endl;
    readFile.close();
}

void AminoAcidComposition::clearFile()
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
vector<ProteinSequence> AminoAcidComposition::assembleSeq( vector<ProteinSequence> p )
{
    // This is the MSA file
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
        // sequence without dashes
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
                //cout << "linePDB: " << linePDB << " " << linePDB.size() << endl;
                currentPDB = p[i].getPDB(); // pdb number from the current vector object
                //cout << "currentPDB: " << currentPDB << " " << currentPDB.size() << endl;
                genSeq = LINE.substr(11, LINE.size());
                //cout << "genSeq: " << genSeq << endl;
                string currentSeq = RemoveSpaces(genSeq);

                if ( LINE.compare(0,11, currentPDB, 1, 11) == 0 )
                {
                    //cout << "currentSeq " << currentSeq << endl;
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
        // mergedSeq is the merged sequence including spaces
        string mergedSeq = Seq;
        //cout << "mergedSeq is " << mergedSeq << endl;
        Seq.clear(); // clear Seq for so the new sequence is not added in the same line as the previous one

        string finalSeq; // mergedSeq WITHOUT spaces

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
         string gSeq = p[i].getSeq();
        //cout << "Final: " << gSeq << endl;

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
vector<ProteinSequence> AminoAcidComposition::processSeq( vector<ProteinSequence> p )
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
string AminoAcidComposition::RemoveSpaces( string s )
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

string AminoAcidComposition::RemoveSpaces2( string s )
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
string AminoAcidComposition::RemoveTabs( string s )
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

AminoAcidComposition::~AminoAcidComposition()
{
    //dtor
}
