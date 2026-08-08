#include <map>
#include <set>

#include "lex.hpp"
#include "emit.hpp"

class Parser
{
public:
    map<TokenType, string> tokens;
    Lexer lexer;
    Emitter emitter;
    Token curToken;
    Token peekToken;
    set<string> symbols;

    Parser(Lexer tlexer, Emitter temitter);

    // return true if the current token matches
    bool checkToken(TokenType kind);

    // return true if the next token matches
    bool checkPeek(TokenType kind);

    // try to match current token. If not, error. Advances the current token
    void match(TokenType kind);

    // advances the current token
    void nextToken();

    void abort(const string &message);

    // Production rules

    // program ::= {statement}
    void program();

    // statement
    void statement();

    // newline
    void newline();

    // expression
    void expression();

    // dot
    void dot();

    // comparison
    void comparison();

    // logical (leka level)
    void logical();

    // logical and (inka level)
    void logicalAnd();

    // logical not (kadhu)
    void logicalNot();

    // check if comparison operator
    bool isComparisonOperator();

    // term
    void term();

    // unary
    void unary();

    // primary
    void primary();
};