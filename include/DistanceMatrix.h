#ifndef DISTANCEMATRIX_H
#define DISTANCEMATRIX_H
#include "stdafx.h"
#include <math.h>
#include "../include/FileReader.h"
#include "../include/FileCreator.h"
#include "../include/ProteinSequence.h"

using namespace std;

class DistanceMatrix
{
    public:
        DistanceMatrix();
        void createSimilarityMatrixCodes( vector<ProteinSequence> );
        void createSimilarityMatrixColours( vector<ProteinSequence> );
        void createDistanceTableColours( vector<ProteinSequence> );
        void createDistanceTableCodes(vector<ProteinSequence>);
        void setMaxDistance( double );
        double getMaxDistance();
        void writeHorizontalFirstLine(vector<ProteinSequence> p, ofstream& oFile, string tab );
        string countSeqs(vector<ProteinSequence> );
        ScoreMatrix currentDScore;
        vector<ScoreMatrix> DistanceValues;
        virtual ~DistanceMatrix();
    protected:

    private:
        double maxDistance;
        char c;
        FileCreator* outFile;


};

#endif // DISTANCEMATRIX_H
