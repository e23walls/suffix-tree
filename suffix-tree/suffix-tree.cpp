#include <iostream>
#include <fstream>
#include "csv-parser.h"
#include "Token.h"

#define MYDEBUG

using namespace std;

void printMap(const map<string, size_t> & eventsToInts) {
    cout << "Map of Strings to Ints:\n";
    for (map<string, size_t>::const_iterator i = eventsToInts.begin(); i != eventsToInts.end(); i++) {
        cout << i->first << " : " << i->second << endl;
    }
    cout << endl;
}

// Want to split up into 100 tokens each
void parse_csv(string csv_file_name) {
    TreeNode * treeRoot = new TreeNode();
    deque<size_t> line_tokens;
    map<std::string, size_t> eventsToInts;

    bool has_row_names = false;
    cout << "file name: '" << csv_file_name << "'\n";

    if (csv_file_name.length()) {
        ifstream csv_file;
        csv_file.open (csv_file_name);
        for (int i = 0; i < 20; i++) {
            getNextLineAndSplitIntoTokens(csv_file, eventsToInts, line_tokens, has_row_names, i != 0);
        }
        cout << "Number of tokens: " << line_tokens.size() << endl;
        treeRoot->insert(line_tokens);
#ifdef MYDEBUG
        printMap(eventsToInts);
        treeRoot->print(0);
#endif

        csv_file.close();
    } else {
        cout << "Invalid file length";
    }
}

int main(int argc, const char * argv[]) {
    // Assume file is in command-line arg
    if (argc >= 2) {
        // Get file name from argv[1]
        parse_csv(argv[1]);
    }

    return 0;
}
