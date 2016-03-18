#ifndef CSV_parser_h
#define CSV_parser_h
#include <deque>
#include <string>
#include <sstream>
#include <map>

#define CR '\r'
#define LF '\n'
#define EOL "\r\n"

void getNextLineAndSplitIntoTokens(std::istream& str, std::map<std::string, size_t> & eventsToInts,
                                   std::deque<size_t> & result, bool & has_row_numbers, bool include);

#endif /* CSV_parser_h */
