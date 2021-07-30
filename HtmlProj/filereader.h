#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>
#include <QString>
using namespace std;

class FileReader
{
public:
    FileReader();
    vector<QString> readLines();
    //    vector<QString> content;
    //    vector<QString> getContent();

    //returns the tags extracted from the file
    vector<char *> returnTags(vector<QString> dataFromFile);

    //returns the content extracted from the file
    vector<string> returnContent(vector<QString> dataFromFile);
};

#endif // FILEREADER_H
