#include "../include/VerticalPosition.h"

using namespace std;

VerticalPosition::VerticalPosition()
{
    //ctor
}

void VerticalPosition::getUserInput()
{
    cout << "\nPlease enter the min percentage of the distribution of Amino Acids (vertically):";
    cin >> UserInput;
    //getline( cin, SearchCathCode );
}

void VerticalPosition::setUserInput(string s )
{
    InputValue = s;
}

string VerticalPosition::getInputValue()
{
    return InputValue;
}

void VerticalPosition::run(vector<ProteinSequence> p )
{
    createColumns(p);
    processColumns();

    //get user input
    getUserInput();
    setUserInput(UserInput);
    string input = getInputValue();
    //will need to convert the value,
    //pluss check constraint to ensure that the value is only an integer


    createVerticalPosition(input);
    createVerticalPositionColour(input);
}

void VerticalPosition::createColumns( vector<ProteinSequence> p )
{
    string tab = "\t";
    string lbreak = "\n";
    outFile = new FileCreator();
    string file = "outFiles//VerticalColumns.txt";
    filenames.push_back(file);
    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();

    oFile.write( file.c_str(), file.size() );
    oFile.write( lbreak.c_str(), lbreak.size() );
    oFile.write( lbreak.c_str(), lbreak.size() );
    size_t column = 0;

    AlignmentColumn currentColumn;
    AllColumns.clear();
    string col;
    size_t i = 0;

    //for ( size_t i = 0; i < p.size(); i++ )
    while ( i < p.size() )
    {
        string s = p[i].getSeq();
        //get first letter.
        char c = s[column];
        col.push_back(c);

        if ( i == (p.size()-1) )
        {
            currentColumn.setColumn(col);
            AllColumns.push_back(currentColumn);
            oFile.write(col.c_str(), col.size());
            oFile.write( lbreak.c_str(), lbreak.size() );
            //string k = currentColumn.getColumn();
            //cout << "" << k << " size " << k.size() << endl;

            col.clear();

            column++;

            if ( column < s.size() )
            {
                i = 0;
            }
            else
            {
                i = p.size();
            }
        }
        else
        {
            i++;
        }
    }

    oFile.close();

}

vector<AlignmentColumn> VerticalPosition::getColumns()
{
    return AllColumns;
}

void VerticalPosition::processColumns()
{
    Columns = getColumns();

    char c;

    Codes.clear();
    Colours.clear();

    for( size_t i = 0; i < Columns.size(); i++ )
    {
        // read the column line
        Codes = j.createAminoAcidCounters();
        d.createColourCodes();
        Colours = d.getColourCodes();
        string currentColumn = Columns[i].getColumn();
        for ( size_t j = 0; j < currentColumn.size(); j++ )
        {

            c = currentColumn[j];

                if ( c == '\0')
                {

                }

                else if ( c == '-' )
                {
                }

                else
                {
                    // need to do the same thing as i did for the proteins..
                    //cout << "c is " << c << endl;

                    for( size_t n = 0; n < Codes.size(); n++ )
                    {
                        char x = Codes[n].getCodeName();

                        //string colour = Codes[n].getColour();

                        //cout << "Code is " << x << " - " << colour << endl;
                        if ( c == x )
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
        //each columns knows how many of each it has.
        Columns[i].setAminoAcidCodeCount(Codes);
        Columns[i].setAminoAcidColourCount(Colours);

    }
}

void VerticalPosition::createVerticalPosition(string input)
{
    string tab = "\t";
    string lbreak = "\n";
    outFile = new FileCreator();
    string file = "outFiles//ColumnCalculationsCodes.txt";
    filenames.push_back(file);
    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();

    oFile.write( file.c_str(), file.size() );
    oFile.write( lbreak.c_str(), lbreak.size() );

    //oFile.write( tab.c_str(), tab.size() );


    ScoreMatrix convert;
    double inputnum = convert.string_to_double(input);
    double percentage;
    double hundred = 100;
    double total = 0;

    vector<AminoAcidCode> ColumnCodes;
    ColumnCodes = j.createAminoAcidCounters();

    //add the character '-' to the list of counters
    char dash = '-';
    j.setCodeName(dash);
    ColumnCodes.push_back(j);
    char currentAminoAcidCode;
    string n;
    for( size_t i = 0; i < ColumnCodes.size(); i++ )
    {
        n.clear();
        currentAminoAcidCode = ColumnCodes[i].getCodeName();
        n.push_back(currentAminoAcidCode);
        oFile.write( n.c_str(), n.size() );
        oFile.write( tab.c_str(), tab.size() );
    }

    string t = "Total";
    oFile.write(t.c_str(), t.size());

    oFile.write( lbreak.c_str(), lbreak.size() );
    //columns comes from processColumns results - public attribute
    for( size_t i = 0; i < Columns.size(); i++ )
    {
        total = 0;
        string cVal = Columns[i].getColumn();
        int colSize = cVal.size();

        //oFile.write(cVal.c_str(), cVal.size());

        ColumnCodes = Columns[i].getAminoAcidCodeCount();

        for( size_t j = 0; j < ColumnCodes.size(); j++ )
        {
            int count = ColumnCodes[j].getCount();

            //if ( count > 0 )
            {
                char c = ColumnCodes[j].getCodeName();

                //string n = convert.number_to_string(count);
                percentage = ((double)count/(double)colSize)*100;;
                //percentage = ((double)count/(double)colSize);
                string n = convert.RoundToString(3, percentage);
                //string num;
                //num.push_back(c);
                //num = num + ":" + n;
                double nNum = convert.string_to_double(n);
                if ( nNum >= inputnum )
                {
                  oFile.write(n.c_str(), n.size());
                }
                else
                {
                    n = "-";
                    oFile.write(n.c_str(), n.size());

                }
                total = total + percentage;
                oFile.write( tab.c_str(), tab.size() );
            }
        }
        //count the dashes here
        double dashcount = hundred - total;
        string d = convert.RoundToString(3, dashcount);
        double dNum = convert.string_to_double(d);
        if ( dNum >= inputnum )
        {
          oFile.write(d.c_str(), d.size());
        }
        else
        {
            d = "-";
            oFile.write(d.c_str(), d.size());
        }

        oFile.write( tab.c_str(), tab.size() );
        double tp = total + dashcount;
        t = convert.RoundToString(3, tp);
        oFile.write(t.c_str(), t.size());


        oFile.write( lbreak.c_str(), lbreak.size() );

    }

    oFile.close();
}

void VerticalPosition::createVerticalPositionColour(string input)
{
    string tab = "\t";
    string lbreak = "\n";
    outFile = new FileCreator();
    string file = "outFiles//ColumnCalculationsColours.txt";
    filenames.push_back(file);
    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();

    oFile.write( file.c_str(), file.size() );
    oFile.write( lbreak.c_str(), lbreak.size() );
    //oFile.write( tab.c_str(), tab.size() );
    ScoreMatrix convert;
    double inputnum = convert.string_to_double(input);
    double percentage;
    double total = 0;
    double hundred = 100;

    vector<AminoAcidColourCode> ColumnColours;
    d.createColourCodes();
    ColumnColours = d.getColourCodes();

    //add the character '-' to the list of counters
    string dash = "-";
    d.setColour(dash);
    ColumnColours.push_back(d);

    string currentColour;
    string n;
    for( size_t i = 0; i < ColumnColours.size(); i++ )
    {

        currentColour = ColumnColours[i].getColour();
        oFile.write( currentColour.c_str(), currentColour.size() );
        oFile.write( tab.c_str(), tab.size() );
    }

    string t = "Total";
    oFile.write(t.c_str(), t.size());

    oFile.write( lbreak.c_str(), lbreak.size() );
    //vector<AminoAcidCode> ColumnCodes;

    //columns comes from processColumns results - public attribute
    for( size_t i = 0; i < Columns.size(); i++ )
    {
        total = 0;
        string cVal = Columns[i].getColumn();
        int colSize = cVal.size();

        //oFile.write( cVal.c_str(), cVal.size() );

        ColumnColours = Columns[i].getAminoAcidColourCount();

        for( size_t j = 0; j < ColumnColours.size(); j++ )
        {
            double count = ColumnColours[j].getCount();

                string colour = ColumnColours[j].getColour();

                //string n = convert.RoundToString(3, count );
                percentage = ((double)count/(double)colSize)*100;;
                //percentage = ((double)count/(double)colSize);
                string n = convert.RoundToString(3, percentage);
                double nNum = convert.string_to_double(n);
                if ( nNum >= inputnum )
                {
                  oFile.write(n.c_str(), n.size());
                }
                else
                {
                    n = "-";
                    oFile.write(n.c_str(), n.size());

                }
                total = total + percentage;
                oFile.write( tab.c_str(), tab.size() );
        }

        //count the dashes here
        double dashcount = hundred - total;
        string d = convert.RoundToString(3, dashcount);
        double dNum = convert.string_to_double(d);
        if ( dNum >= inputnum )
        {
          oFile.write(d.c_str(), d.size());
        }
        else
        {
            d = "-";
            oFile.write(d.c_str(), d.size());
        }

        oFile.write( tab.c_str(), tab.size() );
        double tp = total + dashcount;
        t = convert.RoundToString(3, tp);
        oFile.write(t.c_str(), t.size());

        oFile.write( lbreak.c_str(), lbreak.size() );

    }

    oFile.close();
}



VerticalPosition::~VerticalPosition()
{
    delete outFile;
    //dtor
}
