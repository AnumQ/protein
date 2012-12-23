#ifndef SCOREMATRIX_H
#define SCOREMATRIX_H
#include "stdafx.h"
#include <sstream>
using namespace std;

class ScoreMatrix
{
    public:
        ScoreMatrix();
        void setSequenceX(int X);
        void setSequenceY(int Y);
        void setScore(int S);
        int getSequenceX();
        int getSequenceY();
        int getScore();
        void generateScoreMatrix( vector<ScoreMatrix> );
        virtual ~ScoreMatrix();
    protected:
    private:
    int SequenceX;
    int SequenceY;
    int SequenceScore;
    vector<ScoreMatrix> thismatrix;

};

#endif // SCOREMATRIX_H
