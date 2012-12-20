#include "../include/ScoreMatrix.h"

using namespace std;
ScoreMatrix::ScoreMatrix( int x, int y, int s )
{
    setSequenceX(x);
    setSequenceY(y);
    setScore(s);
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

void ScoreMatrix::displayScoreMatrix()
{
 //   for ( size_t i = 0; i < Scores.size(); i++ )
    {

    }
}

ScoreMatrix::~ScoreMatrix()
{
    //dtor
}
