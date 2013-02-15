#include "../include/ScoreMatrix.h"

using namespace std;

ScoreMatrix::ScoreMatrix()
{
    //ctor
}

void ScoreMatrix::setSequenceX( int X )
{
    SequenceX = X;
}

int ScoreMatrix::getSequenceX()
{
    return SequenceX;
}

void ScoreMatrix::setSequenceY( int Y )
{
    SequenceY = Y;
}

int ScoreMatrix::getSequenceY()
{
    return SequenceY;
}

void ScoreMatrix::setScore( int S )
{
    SequenceScore = S;
}

int ScoreMatrix::getScore()
{
    return SequenceScore;
}

void ScoreMatrix::setDistanceScore( double d )
{
    DistanceScore = d;
}

double ScoreMatrix::getDistanceScore()
{
    return DistanceScore;
}
/* Convert an int to a string */
string ScoreMatrix::number_to_string(int number)
{
	return dynamic_cast<std::stringstream *> (&(std::stringstream() << number))->str();
}

string ScoreMatrix::double_to_string(double number)
{
	return dynamic_cast<std::stringstream *> (&(std::stringstream() << number))->str();
}

string ScoreMatrix::RoundToString(int precision, double val )
{
   // cout << setprecision(precision) << val << endl;
    //return dynamic_cast<std::stringstream *> (&(std::stringstream() setprecision(presicion) << value;
    std::stringstream s;
    s << std::setprecision(precision) << val;
    std::string num = s.str();
    return num;
}
/* Generate score matrix from the results of the alignment */
void ScoreMatrix::generateScoreMatrix( vector<ScoreMatrix> m )
{
    string filename = "ScoreMatrix.txt";
    ofstream outfile;
    outfile.open(filename.c_str()); // open the file "ScoreMatrix.txt"

    int maxY = 0;
    int x, y, s;
    int x2, y2, s2;
    stringstream out;

    for ( size_t i = 0; i < m.size(); i++ )
    {
        int u = m[i].getSequenceY();

        if ( maxY < u )
        {
            maxY = u;
        }
    }

    string max = number_to_string(maxY);
    outfile.write( max.c_str(), max.size() );

    string tab = "\t";
    string lbreak = "\n";

    //outfile.write( lbreak.c_str(), lbreak.size() ); // add a line break

    bool b = false;

    int counter = 0;
    int counter2 = 0;
    for ( int i = 1; i <= maxY; i++ )
    {
        outfile.write( lbreak.c_str(), lbreak.size() );

        for ( int j = 1; j <= maxY; j++ )
        {
            x = m[counter].getSequenceX(); // x = 1
            y = m[counter].getSequenceY();  // y = 2



            if ( j == i )
            {
                b = true;
                int fullscore = 100;

                string f = number_to_string(fullscore);
                outfile.write(f.c_str(), f.size() );
            }
            if ( j > i ) // i = 1, j = 2 --- i = 2, j = 3
            {
                s = m[counter].getScore();

                if ( j == y )
                {
                    string t = number_to_string(s);
                    outfile.write(t.c_str(), t.size() );
                    // increment the count for the objects for the ScoringMatrix
                    counter++;
                }
            }

            if ( i > j ) // i = 2, j = 1   --- i = 3, j = 2
            {
               // A[i,j]=A[j,i] when i>j
               for ( size_t k = 0; k < m.size(); k++ )
               {
                    x2 = m[k].getSequenceX(); // x = 1
                    y2 = m[k].getSequenceY();  // y = 2

                    s2 = m[k].getScore();

                    if ( i == y2 && j == x2 ) //
                    {
                        string t = number_to_string(s2);
                        outfile.write(t.c_str(), t.size() );
                    }

               }



            }
            outfile.write( tab.c_str(), tab.size() );
        }
    }
}

ScoreMatrix::~ScoreMatrix()
{
    //dtor
}
