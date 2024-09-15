#include "fileloader.h"
#include <iostream>
#include <fstream>
#include <cctype>

FileLoader::FileLoader()
{
    mDataRow.clear();
    mGetValueMap.clear();
}

FileLoader::~FileLoader()
{

}

bool FileLoader::loadFromFile(const std::string &filePath)
{
    std::ifstream file;
    file.open(filePath.data(), std::ios::in);

    bool isSuccess = true;
    if(file.is_open())
    {
        std::string rowData;
        int line = 0;
        while(std::getline(file,rowData))
        {
            Node_t lineData;
            if(!parseLine(line++,rowData,lineData))
            {
                isSuccess = false;
                break;
            }
            mDataRow.push_back(lineData);
            if(lineData.key.size() > 0 && lineData.dataValue.size() > 0)
            {
                mGetValueMap[lineData.key] = lineData.dataValue;
            }
        }
        file.close();
    }else
    {
        isSuccess = false;
    }

    return isSuccess;
}

bool FileLoader::getFromFile(std::string key, int &value)
{
    auto search = mGetValueMap.find(key);
    if(search != mGetValueMap.end())
    {
        value = atoi(search->second.data());
        return true;
    }
    else return false;
}

bool FileLoader::getFromFile(std::string key, float &value)
{
    auto search = mGetValueMap.find(key);
    if(search != mGetValueMap.end())
    {
        value = static_cast<float>(atof(search->second.data()));
        return true;
    }
    else return false;
}

bool FileLoader::getFromFile(std::string key, double &value)
{
    auto search = mGetValueMap.find(key);
    if(search != mGetValueMap.end())
    {
        value = atof(search->second.data());
        return true;
    }
    else return false;
}

bool FileLoader::getFromFile(std::string key, bool &value)
{
    auto search = mGetValueMap.find(key);
    if(search != mGetValueMap.end())
    {
        std::string str = search->second;
        for(size_t i = 0; i < str.size(); i++)
        {
            str.at(i) = std::tolower(str.at(i), std::locale());
        }
        if(str == "true" || str == "1")
        {
            value = true;
            return true;
        }else if(str == "false" || str == "0")
        {
            value = false;
            return true;
        }
        else return false;
    }
    else return false;
}

bool FileLoader::getFromFile(std::string key, std::string &value)
{
    auto search = mGetValueMap.find(key);
    if(search != mGetValueMap.end())
    {
        value = search->second;
        return true;
    }
    else return false;
}

bool FileLoader::parseLine(int lineNum, std::string rowData, Node_t &node)
{
    node.line = lineNum;
    if(isWhiteChar(rowData))
    {
        return true;
    }

    eraseWhiteChar(rowData);
    size_t pos = rowData.find('#');

    if(pos != std::string::npos && pos == 0)
    {
        node.comment = rowData.substr(pos);
        return true;
    }else if(pos == std::string::npos)
    {
        pos = rowData.find(':');
        if(pos == std::string::npos)
        {
            return true;
        }else
        {
            node.dataValue = rowData.substr(pos + 1);
            rowData.erase(pos);
            node.key = rowData.substr(0, rowData.size());
            if(isWhiteChar(node.key) || isWhiteChar(node.dataValue))
            {
                return false;
            }
            eraseWhiteChar(node.key);
            eraseWhiteChar(node.dataValue);
        }
    }
    return true;
}

bool FileLoader::isWhiteChar(std::string rowData)
{
    for(std::string::size_type i = 0; i < rowData.size(); i++)
    {
        if(!isWhiteChar(rowData.at(i)))
        {
            return false;
        }
    }
    return true;
}

bool FileLoader::isWhiteChar(char c)
{
    if(c == ' ' || c == '\n' || c == '\t' || c == '\r')
        return true;
    else return false;
}

void FileLoader::eraseWhiteChar(std::string &str)
{
    size_t begin = 0;
    while(isWhiteChar(str.at(begin)))
    {
        begin++;
    }
    str.erase(0,begin);

    size_t last = str.size() - 1;
    while(isWhiteChar(str.at(last)))
    {
        last--;
    }
    str.erase(last + 1);
}
