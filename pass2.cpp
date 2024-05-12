#include "pass2.h"
#include "common.h"

void Pass2::processTRecord(string line, int CSADDR, int PROGADDR, vector<char>& memorycontent) {
    Common common;
    int addr = stoi(line.substr(1, 6), nullptr, 16);
    addr += CSADDR;
    int memoryArrayIndex = (addr - PROGADDR) << 1;
    int length = (stoi(line.substr(7, 2), nullptr, 16)) << 1;
    for (int i = 0; i < length; i++) {
        memorycontent[memoryArrayIndex] = line[9 + i];
        memoryArrayIndex++;
    }
}

void Pass2::processMRecord(string line, int CSADDR, int PROGADDR, vector<char>& memorycontent, unordered_map<string, int>& ESTAB) {
    Common common;
    int addr = stoi(line.substr(1, 6), nullptr, 16);
    addr += CSADDR;
    int memoryArrayIndex = (addr - PROGADDR) << 1;
    int ml = stoi(line.substr(7, 2), nullptr, 16);
    if (ml == 5) {
        memoryArrayIndex++;
    }
    string currentMemoryValue = "";
    for (int i = 0; i < ml; i++) {
        currentMemoryValue += memorycontent[memoryArrayIndex + i];
    }
    int value = common.getDec(currentMemoryValue, ml << 2);
    string token = line.substr(10);
    if (line[9] == '+') {
        value += ESTAB[token];
    }
    else {
        value -= ESTAB[token];
    }
    string result = common.hexToString(common.getHex(value, ml << 2), ml);
    for (int i = 0; i < ml; i++) {
        memorycontent[memoryArrayIndex] = result[i];
        memoryArrayIndex++;
    }
}

void Pass2::execute(vector<string>& argv, unordered_map<string, int>& ESTAB, vector<char>& memorycontent) {
    int PROGADDR = stoi(argv[1], nullptr, 16);
    int CSADDR = PROGADDR;
    for (int i = 2; i < argv.size(); i++) {
        Common common;
        vector<string> lines = common.readfile(argv[i]);
        for (int l = 1; l < lines.size(); l++) {
            if (lines[l].substr(0, 1) == "T") {
                processTRecord(lines[l], CSADDR, PROGADDR, memorycontent);
            }
            else if (lines[l].substr(0, 1) == "M") {
                processMRecord(lines[l], CSADDR, PROGADDR, memorycontent, ESTAB);
            }
        }
        CSADDR += stoi(lines[0].substr(13, 6), nullptr, 16);
    }
}