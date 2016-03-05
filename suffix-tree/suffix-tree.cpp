#include <iostream>
#include <fstream>
#include "csv-parser.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // Assume file is in command-line arg
    string csv_file_name = "";
    bool has_row_names = 0;
    if (argc >= 2) {
        // Get file name from argv[1]
        csv_file_name = argv[1];
    }
    cout << "file name: '" << csv_file_name << "'\n";

    if (csv_file_name.length()) {
        ifstream csv_file;
        csv_file.open (csv_file_name);
        for (int i = 0; i < 20; i++) {
            vector<string> line_tokens = getNextLineAndSplitIntoTokens(csv_file);
            if (i == 0) {
                if (line_tokens.size() && line_tokens[0] == "") {
                    has_row_names = 1;
                }
                // Don't insert the line tokens in this case because this is the first line,
                // which is just labels for the columns.
            } else {
                // Insert the line tokens here.
            }
        }
        
        csv_file.close();
    } else {
        cout << "Invalid file length";
    }

    return 0;
}
