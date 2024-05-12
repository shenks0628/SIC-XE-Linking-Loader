#include "common.h"

string Common::hexToString(string hexstr, int length) {
    for (char& c:hexstr) {
        c = toupper(c);
    }
    if (hexstr.length() < length) {
        hexstr = string(length - hexstr.length(), '0') + hexstr;
    }
    return hexstr;
}

int Common::getDec(string hexstr, int bits) {
    int intval = stoi(hexstr, nullptr, 16);
    if (intval >= int(pow(2, bits - 1))) {
        intval -= int(pow(2, bits));
    }
    return intval;
}

string Common::getHex(int val, int bits) {
    // Perform modulo operation to handle overflow
    val = (val + (1 << bits)) % (1 << bits);
    // Convert integer to hexadecimal string
    stringstream ss;
    ss << hex << uppercase << val;
    string hexStr = ss.str();
    // Pad with leading zeros if necessary
    int digits = bits / 4; // Each hex digit represents 4 bits
    int hexLength = hexStr.length();
    if (hexLength < digits) {
        hexStr = string(digits - hexLength, '0') + hexStr;
    }
    return hexStr;
}

vector<string> Common::readfile(string srcfile) {
    vector<string> lines;
    ifstream fp(srcfile);
    if (!fp.is_open()) {
        return lines;
    }
    string line;
    while (getline(fp, line)) {
        lines.push_back(line);
    }
    fp.close();
    return lines;
}

string Common::getNameWithoutSpace(string originalname) {
    vector<string> list;
    string name = "";
    for (int i = 0; i < originalname.length(); i++) {
        if (originalname[i] == ' ') {
            break;
        }
        name += originalname[i];
    }
    return name;
}