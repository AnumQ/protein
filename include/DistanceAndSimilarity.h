#ifndef DISTANCEANDSIMILARITY_H
#define DISTANCEANDSIMILARITY_H
#include "stdafx.h"
#include <math.h>
#include "../include/FileRead.h"
#include "../include/FileCreator.h"
#include "../include/ProteinSequence.h"

using namespace std;

class DistanceAndSimilarity
{
    public:
        DistanceAndSimilarity();
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
        virtual ~DistanceAndSimilarity();
    protected:

    private:
        double maxDistance;
        char c;
        FileCreator* outFile;


};

#endif // DistanceAndSimilarity_H
