#include "common.h"
#include "pass1.h"
#include "pass2.h"

int main(int argc, char* argv[]) {
    Pass1 pass1;
    unordered_map<string, int> ESTAB;
    vector<string> arg(argv, argv + argc);
    int memorySpace = pass1.execute(arg, ESTAB);
    vector<pair<string, int>> ESTABv(ESTAB.begin(), ESTAB.end());
    sort(ESTABv.begin(), ESTABv.end(), [](pair<string, int>& a, pair<string, int>& b) {
        return a.second < b.second;
    });
    for (auto &[k, v]:ESTABv) {
        cout << k << ":0x" << hex << v << "\n";
    }
    vector<char> memorycontent(memorySpace << 1, '.');
    Pass2 pass2;
    pass2.execute(arg, ESTAB, memorycontent);
    string res = "";
    for (int i = 0; i < memorycontent.size(); i++) {
        res += memorycontent[i];
    }
    int PROGADDR = stoi(arg[1], nullptr, 16);
    for (int i = 0; i < (memorySpace << 1); i++) {
        if (i % 32 == 0) {
            cout << "\n" << hex << uppercase << PROGADDR + (i >> 1) << " ";
        }
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}