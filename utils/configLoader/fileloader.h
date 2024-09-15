#pragma once

#include <map>
#include <vector>

struct Node_t
{
        int line;
        std::string key;
        std::string comment;
        std::string dataValue;
};

class FileLoader
{
    public:
        FileLoader();
        ~FileLoader();

        bool loadFromFile(const std::string &filePath);
        bool getFromFile(std::string key, int& value);
        bool getFromFile(std::string key, float& value);
        bool getFromFile(std::string key, double& value);
        bool getFromFile(std::string key, bool& value);
        bool getFromFile(std::string key, std::string& value);

        bool parseLine(int lineNum, std::string rowData, Node_t& node);

    private:
        bool isWhiteChar(std::string rowData);
        bool isWhiteChar(char c);
        void eraseWhiteChar(std::string& str);

    private:
        std::vector<Node_t> mDataRow;
        std::map<std::string, std::string> mGetValueMap;

};

