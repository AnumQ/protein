#ifndef SCOREMATRIX_H
#define SCOREMATRIX_H
#include "stdafx.h"
#include "../src/pairwise/FullPairwiseAlign.h"

using namespace std;
class ScoreMatrix
{
    public:
        ScoreMatrix(int x, int y, int score );
        void setSequenceX(int X);
        void setSequenceY(int Y);
        void setScore(int S);
        int getSequenceX();
        int getSequenceY();
        int getScore();
        void displayScoreMatrix();

        virtual ~ScoreMatrix();
    protected:
    private:
    int SequenceX;
    int SequenceY;
    int SequenceScore;
};

#endif // SCOREMATRIX_H
