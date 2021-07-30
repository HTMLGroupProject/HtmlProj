#include "filereader.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
using namespace std;

//indicates position of * by a Tag
const int POS_AFTER_STAR = 1;

// indicates number of characters left to extract after the *
const int REST_OF_THE_CHARS = 1;

//read the data from a file defined as a qfile from the form submitted by user with tags
vector<QString> content;

//keeps track of all tags that will be used
vector<QString> tags = {"*T", "*P", "*S", "*X", "*C", "*H", "*I", "*E", "*D", "*R", "*B", "*O"};

//keeps track of tags in the text file such as: *T  etc...
vector<string> tagsFromFile;

//stores the formatted text content after the tags such as: *T some text written here
vector<string> contentFromFile;

FileReader::FileReader()
{
    //read lines if *X == the letters for each tag shown in the outline assign the specific tag
}

vector<QString> FileReader::readLines()
{
    //read lines if *X == the letters for each tag shown in the outline assign the specific tag
    //one line for the *Tag the next is the content

    //----- add the path to your file here ----
    QFile inputFile("testTextFile.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        //qstring final takes each line combines every 2
        QString ret = "";
        QTextStream in(&inputFile);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            ret += line;
            content.push_back(ret);
            ret = "";
        }
        inputFile.close();
    }
    return content;
}

//This function returns the formatted tags
vector<char *> FileReader::returnTags(vector<QString> dataFromFile)
{
    for (size_t index = 0; index < dataFromFile.size(); index++)
    {
        // checking if elment of dataFromFile is a tag.
        bool isPresent = (find(tags.begin(), tags.end(), dataFromFile[index]) != tags.end());
        if (isPresent)
        {
            //if its a tag then push tag into the tagsFromFile vector after the *.
            tagsFromFile.push_back(dataFromFile[index].toStdString().substr(POS_AFTER_STAR, REST_OF_THE_CHARS));
        }
    }

    //into tag function only accepets character tags
    //converting vector of strings into a vector of characters *
    vector<char *> charTagsFromFile;

    //make sure vector's capacity is enough for all tags in the file
    //https://www.cplusplus.com/reference/vector/vector/reserve/
    charTagsFromFile.reserve(tagsFromFile.size());

    //convert string tags into char tags
    for (auto &strTag : tagsFromFile)
        charTagsFromFile.push_back(&strTag[0]);

    return charTagsFromFile;
}

//this function returns the formatted content
vector<string> FileReader::returnContent(vector<QString> dataFromFile)
{
    for (size_t index = 0; index < dataFromFile.size(); index++)
    {
        // checking if elment of dataFromFile is a tag.
        bool isPresent = (find(tags.begin(), tags.end(), dataFromFile[index]) != tags.end());

        if (!isPresent)
        {
            if (dataFromFile[index] != "")
            {
                //if its not a tag and we're not at an empty space then push the content of the file in to the contentsFromFile vector.
                contentFromFile.push_back(dataFromFile[index].toStdString());
            }
        }
    }
    return contentFromFile;
}
