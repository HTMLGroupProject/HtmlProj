#include <QCoreApplication>
#include <QFile>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "filereader.h"
#include "intoTag.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileReader fr;

    //stores all data from file, tags and content.
    vector<QString> dataFromFile;

    vector<string> content;
    vector<char *> tags;

    //passing data from file to vector
    dataFromFile = fr.readLines();

    content = fr.returnContent(dataFromFile);
    tags = fr.returnTags(dataFromFile);

    char inputChar;
    string contentStr;
    string result;

    //printing contents
    for (size_t i = 0; i < content.size(); i++)
    {
        inputChar = *(tags[i]);
        contentStr = content[i];
        result = intoTag(inputChar, content[i]);
        cout << result << endl;
    }

    // ------------- Do writing here after all tags are implemente, check intoTag.cpp file --------------

    //return a.exec();
    return 0;
}
