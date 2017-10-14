#include <string>
#include <iostream>

using namespace std;

class Different {
 public:
  bool checkDifferent(string iniString) {
    if(iniString.size() > 256)
      return false;

    bool chars[256]={0};
    for (size_t i = 0; i < iniString.size(); ++i) {
      if (chars[(size_t)iniString[i]]) {
        return false;
      }
      chars[(size_t)iniString[i]] = true;
    }
    return true;
  }
};

int main() {
  Different df;
  string str="abcdefghijklm123";
  cout << "str:[" << str << "] result:" << df.checkDifferent(str) << endl;

  string str1="abcdefghijklmk123";
  cout << "str:[" << str1 << "] result:" << df.checkDifferent(str1) << endl;
  return 0;
}
