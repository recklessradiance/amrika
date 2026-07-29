// header file containing the interface for the Emitter class
#include <iostream>

using namespace std;
class Emitter
{
public:
    string fullPath;
    string header;
    string code;

    Emitter()
    {
        header = "";
        code = "";
    }
    Emitter(const string &path);

    void emit(const string &codepiece);

    void emitLine(const string &codepiece);

    void headerLine(const string &codepiece);

    void writeFile();
};