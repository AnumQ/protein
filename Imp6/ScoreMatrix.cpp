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

/* Generate score matrix from the results of the alignment */
void ScoreMatrix::generateScoreMatrix( vector<ScoreMatrix> m )
{
    string filename = "ScoreMatrix.txt";
    ofstream outfile;
    outfile.open(filename.c_str()); // open the file "ScoreMatrix.txt"

    string a = "ScoreMatrix\n";
    outfile.write(a.c_str(), a.size()); // write the headline

    int maxY = 0;
    int x, y, s;
    stringstream out;

    for ( size_t i = 0; i < m.size(); i++ )
    {
        int u = m[i].getSequenceY();

        if ( maxY < u )
        {
            maxY = u;
        }
    }

    string tab = "\t";
    string lbreak = "\n";

    for ( int i = 1; i <= maxY; i++ )
    {
        out.clear();
        out << i;
        outfile << tab;
        outfile << out.rdbuf(); // Write the horisontal count of the grid
    }

    outfile.write( lbreak.c_str(), lbreak.size() ); // add a line break

    bool b = false;

    int counter = 0;
    for ( int i = 1; i <= maxY; i++ )
    {
        out.clear();
        out << i;
        outfile << out.rdbuf(); // Write the vertical count of the grid

        for ( int j = 1; j <= maxY; j++ )
        {
            x = m[counter].getSequenceX();
            y = m[counter].getSequenceY();

            outfile << tab;
            if ( j == i )
            {
                b = true;
                int fullscore = 100;
                out << fullscore;
                outfile << out.rdbuf();
            }
            if ( j > i ) // i = 1, j = 2
            {
                //cout << endl;
                //cout << "i is " << i << endl;
                //cout << "j is " << j << endl;
                s = m[counter].getScore();

                if ( j == y )
                {
                    //cout << "score is " << s << endl;
                    out.clear();
                    out << s;
                    outfile << out.rdbuf();

                    // increment the count for the objects for the ScoringMatrix
                    counter++;
                }

            }
        }
        outfile.write( lbreak.c_str(), lbreak.size() );

    }
}

ScoreMatrix::~ScoreMatrix()
{
    //dtor
}
