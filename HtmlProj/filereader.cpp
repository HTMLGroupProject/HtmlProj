#include "filereader.h"
#include <QFile>
#include <QTextStream>
#include <QString>
using namespace std;
//read the data from a file defined as a qfile from the form submitted by user with tags
vector<QString> content;

FileReader::FileReader()
{
 //read lines if *X == the letters for each tag shown in the outline assign the specific tag
}

vector<QString> FileReader::readLines(){
    //read lines if *X == the letters for each tag shown in the outline assign the specific tag
    //one line for the *Tag the next is the content
    //
    QFile inputFile("icecream.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        //qstring final takes each line combines every 2
        //make sure to remove the pointer (*) at beginning of the tag line
        QString ret = "";
       QTextStream in(&inputFile);
       //every 2 lines reset the ret string to blank
       //push the ret after every 2 to the vector
       while (!in.atEnd())
       {

           //return each line in a vector
           //concat the T tag line with the content on the next line
           for(int i = 0; i < 2; i++){
                QString line = in.readLine();
                ret += line += ",";

           }
           content.push_back(ret);
           ret = "";

          //...
       }
       inputFile.close();
    }
    //*h this is a header
    //<h1>this is a header</h1>
    //*p this is a paragraph
    return
}
