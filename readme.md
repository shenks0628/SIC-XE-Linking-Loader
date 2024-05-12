這個專案在實作 sic/xe 的 linking loader，以下為各檔案之概述與說明：
- common.h 裡宣告 Common class，common.cpp 裡 define Common class 裡各 function 的內容 (reading files and format conversion)
- pass1.h 裡宣告 Pass1 class，pass1.cpp 裡 define Pass1 class 裡各 function 的內容 (asssigns addresses to all external symbols)
- pass2.h 裡宣告 Pass2 class，pass2.cpp 裡 define Pass2 class 裡各 function 的內容 (performs the actual loading, relocation, and linking)
- linkingloader.cpp 為主程式，依序呼叫 Pass1.execute 和 Pass2.execute 並輸出最終結果
- 程式使用方式：
    - ``` g++ linkingloader.cpp common.cpp pass1.cpp pass2.cpp ```
    - ``` ./a.out <program load address> <your *.obj file(s)> ```
    - ex. ``` ./a.out 4000 PROGA.obj PROGB.obj PROGC.obj ```
- PROGX.obj 為課本的範例 object file
- output.txt 為此程式以 ``` ./a.out 4000 PROGA.obj PROGB.obj PROGC.obj ``` 跑出來的結果
- sample.txt 為老師給的範例程式以相同參數跑出來的標準結果
