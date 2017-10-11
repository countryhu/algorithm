#include <string>
#include <iostream>

using namespace std;

class Reverse {
public:
    string reverseString(string iniString) {
      if (iniString.empty()) 
        return "";

      // 1. find the end
      int end = iniString.size() - 1;
      int begin = 0;
      while (begin < end) {
        // 2. swap
        char temp = iniString[begin];
        iniString[begin] = iniString[end];
        iniString[end] = temp;
        ++begin;
        --end;
      }
      return iniString;
    }
};

int main() {
  Reverse obj;
  if (obj.reverseString("abcdefghijklm123") == "321mlkjihgfedcba") {
    cout << "abcdefghijklm123 check ok" << endl;
  }

  if (obj.reverseString("12") == "21") {
    cout << "12 check ok" << endl;
  }
  if (obj.reverseString("1") == "1") {
    cout << "1 check ok" << endl;
  }

  if (obj.reverseString("") == "") {
    cout << "null check ok" << endl;
  }
  return 0;
}
