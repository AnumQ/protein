#ifndef SCOREMATRIX_H
#define SCOREMATRIX_H
#include "stdafx.h"
using namespace std;

class ScoreMatrix
{
    public:
        ScoreMatrix();
        void setSequenceX(int X);
        int getSequenceX();
        void setSequenceY(int Y);
        int getSequenceY();
        void setScore(int);
        int getScore();
        void setDistanceScore(double);
        double getDistanceScore();
        void generateScoreMatrix( vector<ScoreMatrix> );
        string number_to_string(int number);
        string double_to_string(double number);
        string RoundToString(int, double );
        double string_to_double(const std::string& s);
        virtual ~ScoreMatrix();
    protected:
    private:
    int SequenceX;
    int SequenceY;
    int SequenceScore;
    double DistanceScore;
    vector<ScoreMatrix> thismatrix;

};

#endif // SCOREMATRIX_H
