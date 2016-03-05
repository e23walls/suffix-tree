#ifndef CSV_parser_h
#define CSV_parser_h
#include <vector>
#include <string>
#include <sstream>

#define CR '\r'
#define LF '\n'
#define EOL "\r\n"

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str);

#endif /* CSV_parser_h */
