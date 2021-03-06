#include "CSV-parser.h"
#include "Tree.h"
#include <iostream>


// @note - Taken from http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
//
// @param str - input string stream of file
//
// @returns - A vector of the tokens in the CSV file line, without commas or newlines
void getNextLineAndSplitIntoTokens(std::istream & str, std::map<std::string, size_t> & eventsToInts,
                                   std::deque<size_t> & result, bool & has_row_numbers, bool include = true) {
    std::string line;
    // TODO - specify the delimiter as a parameter to the method, not as an argument to std::getline.
    std::getline(str, line, CR);

    std::stringstream lineStream(line);
    std::string cell;

    int counter = 0;
    while(std::getline(lineStream, cell, ',')) {
        // Only include the events
        if (include && (NodeType)counter == NodeType::EVENT + (has_row_numbers ? 1 : 0)) {
            if (eventsToInts.find(cell) == eventsToInts.end()) {
                eventsToInts[cell] = eventsToInts.size();
            }
            result.push_back(eventsToInts[cell]);
        } else if (!include) {
            if (counter == 0 && cell == "") {
                has_row_numbers = true;
            }
        }
        std::cout << "'" << cell << "' \n";
        counter++;
    }
    std::cout << std::endl;
}


// @note - getline which handles the three types of newline characters: '\n', '\r', and '\n\r'.
//         From: http://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
//         I think this is probably really slow.
//
// @param is - input file stream for the file to read.
//
// @param t - string to read the data into.
std::istream& safeGetline(std::istream& is, std::string& t)
{
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    std::istream::sentry se(is, true);
    std::streambuf* sb = is.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                return is;
            case '\r':
                if(sb->sgetc() == '\n')
                    sb->sbumpc();
                return is;
            case EOF:
                // Also handle the case when the last line has no line ending
                if(t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char)c;
        }
    }
}

