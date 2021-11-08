#include <stdio.h>
#include <iostream>
using namespace std;

bool isInfo(char[]);
bool isWarning(char[]);
bool isError(char[]);

int main() {

// assign files
FILE *log, *info, *warning, *error;
log = fopen("winlog.txt", "r");
info = fopen ("information.txt", "w");
warning = fopen ("warning.txt", "w");
error = fopen ("error.txt", "w");

// fetch data per line
char line[350];

while(fgets(line, 350, log) != NULL) {

    // verify information types
    if(isInfo(line)) {
        fprintf(info, "%s", line);
        cout << "!!INFORMATION!!! " << endl;
        cout << line << endl;
    }

    if(isWarning(line)) {
        fprintf(warning, "%s", line);
        cout << "!!WARNING!!! " << endl;
        cout << line << endl;
        
    }

    if(isError(line)) {
        fprintf(error, "%s", line);
        cout << "!!ERROR!!! " << endl;
        cout << line << endl;
    }

}

cout << "--- END OF PROGRAM ---";

return 0;
}

bool isInfo(char input[]) {
    char temp[13] = "Information,";

    for(int i = 0; i < 12; i++) {
        if(temp[i] != input[i]) {
            return false;
        }
    }
    return true;
}

bool isWarning(char input[]) {
    char temp[9] = "Warning,";

    for(int i = 0; i < 8; i++) {
        if(temp[i] != input[i]) {
            return false;
        }
    }
    return true;
}

bool isError(char input[]) {
    char temp[7] = "Error,";

    for(int i = 0; i < 6; i++) {
        if(temp[i] != input[i]) {
            return false;
        }
    }
    return true;
}