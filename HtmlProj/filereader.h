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
    vector<QString> content;
    vector<QString> getContent();
};

#endif // FILEREADER_H
