// Code implementing the emitter for the compiler
#include <fstream>
#include <iostream>
#include "emit.hpp"

Emitter::Emitter(const string &path)
{
    fullPath = path;
    header = "";
    code = "";
    code.reserve(4096);
}

void Emitter::emit(const string &codepiece)
{
    // appends the current string to the code that is to be emmited
    code += codepiece;
}

void Emitter::emitLine(const string &codepiece)
{
    // appends the current string to the code that is to be emmited ending with a newline
    code += codepiece;
    code += '\n';
}

void Emitter::headerLine(const string &codepiece)
{
    // appends the current string to the header part of the output code
    header += codepiece;
    header += '\n';
}

void Emitter::writeFile()
{
    // writes header and code to the output file whose path is set using the constructor
    ofstream outputFile(fullPath);
    outputFile << header;
    outputFile << code;
    outputFile.close();
}