#include "../include/DistanceMatrix.h"

using namespace std;

FileReader *currentFile;

DistanceMatrix::DistanceMatrix()
{
    //ctor
}

void DistanceMatrix::createSimilarityMatrixCodes( vector<ProteinSequence> p )
{
    double maxD = getMaxDistance();
    //cout << "MAXD: " << maxD << endl;
    double currentValue;
    size_t count = 0;

    string tab = "\t";
    string lbreak = "\n";
    // Create a file
    outFile = new FileCreator();
    string file = "SimilarityMatrix-AminoAcidCodes.txt";
    filenames.push_back(file);
    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();

    string totalSequences = countSeqs(p);
    oFile.write( totalSequences.c_str(), totalSequences.size() );
    oFile.write( lbreak.c_str(), lbreak.size() );

    ScoreMatrix convert;

    for ( size_t i = 0; i < p.size(); i++ )
    {
       for ( size_t j = 0; j < p.size(); j++ )
       {
            if ( j > 0 )
            {
                oFile.write( tab.c_str(), tab.size());
            }

           if ( i == j )
           {
                string zero = convert.number_to_string(1);
                //zero = zero + "   ";
                oFile.write( zero.c_str(), zero.size() );
           }

           if ( j > i )
           {
               if ( count < DistanceValues.size() )
               {
                    currentValue = DistanceValues[count].getDistanceScore();
                    double similarity = 1 - (currentValue/maxD);

                    string s = convert.RoundToString(2, similarity);

                    oFile.write( s.c_str(), s.size() );
               }
               count++;

           }

           if ( i > j )
           {
               for ( size_t k = 0; k < DistanceValues.size(); k++ )
               {
                   size_t x = DistanceValues[k].getSequenceX();
                   size_t y = DistanceValues[k].getSequenceY();

                   double curScore = DistanceValues[k].getDistanceScore();



                   double similarity = 1 - (curScore/maxD);



                   if ( x == j && y == i ) // i =2, j = 1
                   {
                       //cout << x << ":" << y << " = " << similarity << endl;
                       string num = convert.RoundToString(2, similarity);
                       //string num = convert.double_to_string(s);
                       //string num = convert.RoundToString(2, s);
                       //string num = "-";
                       oFile.write( num.c_str(), num.size() );
                   }

               }

           }




       }
           //count++;
        oFile.write( lbreak.c_str(), lbreak.size() );
    }

    oFile.close();
}

void DistanceMatrix::createSimilarityMatrixColours( vector<ProteinSequence> p )
{
    double maxD = getMaxDistance();
    //cout << "MAXD: " << maxD << endl;
    double currentValue;
    size_t count = 0;

    string tab = "\t";
    string lbreak = "\n";
    // Create a file
    outFile = new FileCreator();
    string file = "SimilarityMatrix-AminoAcidColours.txt";
    filenames.push_back(file);
    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();

    string totalSequences = countSeqs(p);
    oFile.write( totalSequences.c_str(), totalSequences.size() );
    oFile.write( lbreak.c_str(), lbreak.size() );

    ScoreMatrix convert;

    for ( size_t i = 0; i < p.size(); i++ )
    {
       for ( size_t j = 0; j < p.size(); j++ )
       {
            if ( j > 0 )
            {
                oFile.write( tab.c_str(), tab.size());
            }

           if ( i == j )
           {
                string zero = convert.number_to_string(1);
                //zero = zero + "   ";
                oFile.write( zero.c_str(), zero.size() );
           }

           if ( j > i )
           {
               if ( count < DistanceValues.size() )
               {
                    currentValue = DistanceValues[count].getDistanceScore();
                    double similarity = 1 - (currentValue/maxD);

                    string s = convert.RoundToString(2, similarity);

                    oFile.write( s.c_str(), s.size() );
               }
               count++;

           }

           if ( i > j )
           {
               for ( size_t k = 0; k < DistanceValues.size(); k++ )
               {
                   size_t x = DistanceValues[k].getSequenceX();
                   size_t y = DistanceValues[k].getSequenceY();

                   double curScore = DistanceValues[k].getDistanceScore();



                   double similarity = 1 - (curScore/maxD);



                   if ( x == j && y == i ) // i =2, j = 1
                   {
                       //cout << x << ":" << y << " = " << similarity << endl;
                       string num = convert.RoundToString(2, similarity);
                       //string num = convert.double_to_string(s);
                       //string num = convert.RoundToString(2, s);
                       //string num = "-";
                       oFile.write( num.c_str(), num.size() );
                   }

               }

           }




       }
           //count++;
        oFile.write( lbreak.c_str(), lbreak.size() );
    }

    oFile.close();
}

void DistanceMatrix::createDistanceTableColours( vector<ProteinSequence> p )
{
    vector<AminoAcidColourCode> AminoAcidColours;
    double prevNum;
    double currentNum;
    double total;
    size_t j = 0;
    size_t i = 0;
    size_t count = 0;
    double percentage1;
    double percentage2;

    string tab = "\t";
    string lbreak = "\n";

    // Create a file
    outFile = new FileCreator();
    string file = "DistanceTable-AminoAcidColours.txt";
    filenames.push_back(file);

    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();
    oFile.write( file.c_str(), file.size() );
    //get data to write
    ScoreMatrix convert;

    //oFile.write( lbreak.c_str(), lbreak.size() );
    //writeHorizontalFirstLine( p, oFile, tab);
    oFile.write( lbreak.c_str(), lbreak.size() );

    /*string totalSequences = countSeqs(p);
    oFile.write( totalSequences.c_str(), totalSequences.size() );
    oFile.write( lbreak.c_str(), lbreak.size() ); */

    AminoAcidColours = p[count].getAminoAcidColourCount();

    DistanceValues.clear();
    //initialize maxDistance to 0;
    setMaxDistance(0);

    while ( count < p.size() )
    {
        i = 0;
        total = 0;
        double t2 = 0;
        while ( i < p.size() )
        {
            if ( i > 0 && count < i )
            {
                j = 0;
                while ( j < AminoAcidColours.size() )
                {
                    AminoAcidColours = p[count].getAminoAcidColourCount();
                      int pcount = p[count].getSeqLength();
                    prevNum = AminoAcidColours[j].getCount();
                      percentage1 = ((double)prevNum/(double)pcount)*100;;

                    AminoAcidColours = p[i].getAminoAcidColourCount();
                      int pi = p[i].getSeqLength();
                    currentNum = AminoAcidColours[j].getCount();
                      percentage2 = ((double)currentNum/(double)pi)*100;;

                    double distance = pow((prevNum - currentNum), 2);
                    double d2 = pow((percentage1 - percentage2), 2);
                   // cout << prevNum << " - " << currentNum << " = Distance: " << distance << endl;
                   // cout << percentage1 << " - " << percentage2 << " = D2: " << d2 << endl;
                    total = total + distance; // calculating the total of actual numbers
                    t2 = t2 + d2; // calculating the total of percentages
                    j = j + 1;
                }
                    //cout << "       Total is " << total << endl; //displaying the total of actual numbers
                    // cout << "       T2 is " << t2 << endl; // displaying the total of the percentages
                    double sqrTotal = sqrt(total);
                //cout << "       Kvadrat av det er " << sqrTotal << endl;
                    sqrTotal = sqrt(t2);
                   // cout << "       Square root of t2 er " << sqrTotal << endl;
                    //add t2 to the vector
                    currentDScore.setSequenceX(count);
                    currentDScore.setSequenceY(i);
                    currentDScore.setDistanceScore(sqrTotal);

                    int a = currentDScore.getSequenceX();
                    int b = currentDScore.getSequenceY();
                    double c = currentDScore.getDistanceScore();
                    //cout << a << ":" << b << " = " << c << endl;

                    DistanceValues.push_back(currentDScore);
                    //check for maxDistance
                    if ( sqrTotal > maxDistance )
                    {
                        setMaxDistance(sqrTotal);
                    }

                //string sqrRoot = convert.double_to_string(sqrTotal);
                string sqrRoot = convert.RoundToString(3, sqrTotal);
                oFile.write( sqrRoot.c_str(), sqrRoot.size() );
            }

            if ( i == j || count == i )
            {
                string zero = convert.number_to_string(0);
                    zero = zero + "   ";
                oFile.write( zero.c_str(), zero.size() );
            }

            if ( count > i )
            {
                string empty = "---   ";
                oFile.write( empty.c_str(), empty.size() );

            }
            oFile.write( tab.c_str(), tab.size());

            i++;
        }
        oFile.write( lbreak.c_str(), lbreak.size() );
        count++;

    }

    outFile->closeFile();


}


void DistanceMatrix::createDistanceTableCodes( vector<ProteinSequence> p )
{

    int prevNum;
    int currentNum;
    double total;
    size_t j = 0;
    size_t i = 0;
    size_t count = 0;
    double percentage1;
    double percentage2;

    string tab = "\t";
    string lbreak = "\n";

    // Create a file
    outFile = new FileCreator();
    string file = "DistanceTable-AminoAcidCodes.txt";
    filenames.push_back(file);
    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();
    oFile.write( file.c_str(), file.size() );
    //get data to write
    ScoreMatrix convert;
    vector<AminoAcidCode> AminoAcidCount;

    //oFile.write( lbreak.c_str(), lbreak.size() );
    //writeHorizontalFirstLine( p, oFile, tab);
    oFile.write( lbreak.c_str(), lbreak.size() );

    /*string totalSequences = countSeqs(p);
    oFile.write( totalSequences.c_str(), totalSequences.size() );
    oFile.write( lbreak.c_str(), lbreak.size() ); */



    AminoAcidCount = p[count].getAminoAcidCount();

    DistanceValues.clear();
    //initialize maxDistance to 0;
    setMaxDistance(0);

    while ( count < p.size() )
    {
        i = 0;
        total = 0;
        double t2 = 0;
        while ( i < p.size() )
        {

           /* if ( i < count )
            {
                oFile.write( tab.c_str(), tab.size());
            } */
            if ( i > 0 && count < i )
            {
                j = 0;
                while ( j < AminoAcidCount.size() )
                {
                    AminoAcidCount = p[count].getAminoAcidCount();
                      int pcount = p[count].getSeqLength();
                    prevNum = AminoAcidCount[j].getCount();
                      percentage1 = ((double)prevNum/(double)pcount)*100;;

                    AminoAcidCount = p[i].getAminoAcidCount();
                      int pi = p[i].getSeqLength();
                    currentNum = AminoAcidCount[j].getCount();
                      percentage2 = ((double)currentNum/(double)pi)*100;;

                    double distance = pow((prevNum - currentNum), 2);
                    double d2 = pow((percentage1 - percentage2), 2);
                    //cout << prevNum << " - " << currentNum << " = Distance: " << distance << endl;
                    //cout << percentage1 << " - " << percentage2 << " = D2: " << d2 << endl;
                    total = total + distance;
                        t2 = t2 + d2;
                    j = j + 1;
                }
                //cout << "       Total is " << total << endl;
                  // cout << "       T2 is " << t2 << endl;
                double sqrTotal = sqrt(total);
                //cout << "       Kvadrat av det er " << sqrTotal << endl;
                    sqrTotal = sqrt(t2);
                    //cout << "       Square root of t2 er " << sqrTotal << endl;
                    //add t2 to the vector
                    currentDScore.setSequenceX(count);
                    currentDScore.setSequenceY(i);
                    currentDScore.setDistanceScore(sqrTotal);

                    int a = currentDScore.getSequenceX();
                    int b = currentDScore.getSequenceY();
                    double c = currentDScore.getDistanceScore();
                    //cout << a << ":" << b << " = " << c << endl;

                    DistanceValues.push_back(currentDScore);
                    //check for maxDistance
                    if ( sqrTotal > maxDistance )
                    {
                        setMaxDistance(sqrTotal);
                    }

                //string sqrRoot = convert.double_to_string(sqrTotal);
                string sqrRoot = convert.RoundToString(3, sqrTotal);
                oFile.write( sqrRoot.c_str(), sqrRoot.size() );
            }

            if ( i == j || count == i )
            {
                string zero = convert.number_to_string(0);
                    zero = zero + "   ";
                oFile.write( zero.c_str(), zero.size() );
            }

            if ( count > i )
            {
                string empty = "---   ";
                oFile.write( empty.c_str(), empty.size() );

            }
            oFile.write( tab.c_str(), tab.size());

            i++;
        }
        oFile.write( lbreak.c_str(), lbreak.size() );
        count++;

    }

    outFile->closeFile();


}

void DistanceMatrix::setMaxDistance( double num )
{
    maxDistance = num;
}

double DistanceMatrix::getMaxDistance()
{
    return maxDistance;
}

string DistanceMatrix::countSeqs(vector<ProteinSequence> p )
{
    ScoreMatrix convert;
    int countSeq = 0;
    for( size_t i = 0; i < p.size(); i++ )
    {
        countSeq++;
    }

    string number = convert.number_to_string(countSeq);
    return number;

}


void DistanceMatrix::writeHorizontalFirstLine( vector<ProteinSequence> p, ofstream& oFile, string tab )
{
    ScoreMatrix convert;
    vector<string> SeqNumber;
    int countSeq = 0;
    //oFile.write( tab.c_str(), tab.size());
    for( size_t i = 0; i < p.size(); i++ )
    {
        oFile.write( tab.c_str(), tab.size());
        if ( i > 0)
        {
            oFile.write( tab.c_str(), tab.size());
        }
        countSeq++;
        string s = "S";
        string seqNum = convert.number_to_string(countSeq);
        s = s + seqNum;
        SeqNumber.push_back(s);
        oFile.write( s.c_str(), s.size() );
    }

}
DistanceMatrix::~DistanceMatrix()
{
    delete outFile;
}
