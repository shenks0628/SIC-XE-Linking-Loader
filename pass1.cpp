#include "pass1.h"
#include "common.h"

int Pass1::execute(vector<string>& argv, unordered_map<string, int>& ESTAB) {
    int PROGADDR = stoi(argv[1], nullptr, 16);
    int CSADDR = PROGADDR;
    int memoryspacelen = 0;
    for (int i = 2; i < argv.size(); i++) {
        Common common;
        vector<string> lines = common.readfile(argv[i]);
        // Header Record
        string csname = common.getNameWithoutSpace(lines[0].substr(1, 6));
        int cslength = stoi(lines[0].substr(13, 6), nullptr, 16);
        memoryspacelen += cslength;
        ESTAB[csname] = CSADDR;
        for (int l = 1; l < lines.size(); l++) {
            if (lines[l].substr(0, 1) != "D") {
                continue;
            }
            // D Record
            int n = (lines[l].length() - 1) / 12;
            for (int j = 0; j < n; j++) {
                string name = common.getNameWithoutSpace(lines[l].substr(1 + (12 * j), 6));
                int addr = stoi(lines[l].substr(7 + (12 * j), 6), nullptr, 16);
                ESTAB[name] = CSADDR + addr;
            }
        }
        CSADDR += cslength;
    }
    return memoryspacelen;
}