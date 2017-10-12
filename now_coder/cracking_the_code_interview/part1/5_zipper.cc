#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
  题目描述
  利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。
  若压缩后的字符串没有变短，则返回原先的字符串。
  给定一个string iniString为待压缩的串(长度小于等于10000)，保证串内字符均由大小写英文字母组成，返回一个string，
  为所求的压缩后或未变化的串。
  测试样例
  "aabcccccaaa"
  返回："a2b1c5a3"
  "welcometonowcoderrrrr"
  返回："welcometonowcoderrrrr"

  -----
  题目分析
  逻辑注意点：
  1. 此题输出不一定是原始压缩字符串
  2. 必须重新申请空间，无法在原有字符串基础上操作，因为每个字符向前或向后偏移不定。
  3. 注意"若压缩没有变短"，说明长度相等的时候返回原始
  参数范围注意点：
  1. 全是大小写英文字母组成
  错题本：
  1. 没有考虑a12b13c1这类数字是多位的情况。



  方案一:从头遍历iniString，压缩字符追加到新的string最后根据size与原始length比较决定返回哪个。
  优点：一次便利iniString. 逻辑相对简单，不容易出错
  缺点: 不知道最终压缩长度，追加次数过多效率较低，需要优化.可以考虑预申请2*length的空间,用resize
  或者用链表动态数组，最后来一次合并。

  方案二：先来一次便利，找到需要多长的空间。然后根据空间判断是否应该申请空间并加密.
  优点：可以精确的申请空间，并压缩，防止不必要的空间和拷贝时间操作浪费。
  缺点: 需要两次遍历，同时有数学公式，稍微容易出错.
 **/

class Zipper {
 public:
  string zipString(string iniString) {
    // 计算所需长度
    size_t zipLength = zip(iniString);

    // 压缩需要不小于原长度
    if (zipLength >= iniString.size()) {
      return iniString;
    }

    // 压缩
    string zipString;
    zipString.reserve(zipLength); // 此句很有必要，防止内部不停地重新分配内存
    zip(iniString, &zipString);

    return zipString;
  }

 private:
  size_t zip(const string& iniString, string* zipString = NULL) {
    // 可以直接返回的
    if (iniString.size() <= 1) {
      if (zipString != NULL) {
        *zipString = iniString;
      }
      return iniString.size();
    }

    // abcccccaaa
    // 下面iniString.size() > 2
    int baseIndex = 0;

    // 首字母入栈
    int zipLength = 1;
    if (zipString != NULL) {
      zipString->append(string(1, iniString[0]));
    }

    for (size_t i = 1; i < iniString.size(); ++i) {
      if (iniString[i] != iniString[baseIndex]) {
        // 推入上一个数字
        string numStr = std::to_string(i - baseIndex);
        if (zipString != NULL) {
          zipString->append(numStr);
        }
        zipLength += numStr.size();

        // 推入新字母
        if (zipString != NULL) {
          zipString->append(string(1, iniString[i]));
        }
        zipLength += 1;

        baseIndex = i;
      }
    }
    // 推入最后一个数字
    string numStr = std::to_string(iniString.size() - baseIndex);
    if (zipString != NULL) {
      zipString->append(numStr);
    }
    zipLength += numStr.size();

    return zipLength;
  }
};

static int caseN = 0;
void TestCase(string input, string expectOutput) {
  Zipper obj;
  auto output = obj.zipString(input);
  if (output == expectOutput) {
    cout << "case" << ++caseN << ": check ok. with input:" << input 
        << "\n output as expect:" << output << endl;
  } else {
    cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
        << "case" << ++caseN << ": check failed. with input:" << input 
        << "\n-------------------------------\n"
        << "   expectOutput:" << expectOutput
        << "\n-------------------------------\n"
        << "but actuaOutput:" << output 
        << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  }
}
// int main() {
  // TestCase("aabcccccaaa", "a2b1c5a3");
  // TestCase("welcometonowcoderrrrr", "welcometonowcoderrrrr");
  // TestCase("", "");
  // TestCase("a", "a");
  // TestCase("aa", "aa");
  // TestCase("aaa", "a3");
  // TestCase("jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF", "j6x7o2Z1L8Q9L8E1C1X7I9h1j2y3S2o9m3u2E9n7f6A5l8b4k12K6h9o10Y1C6O9M10i6v7W4k6w7M1m8L3w7k3j6t4Q9a7F7l9g10P6u8a1Y6w1Q3F10a5p1X7x6Q9s5G4f7d6p3Q6H3T3a6G6d2y5M1h2l10N8U3W6L9Y10T2K8i7t7X9L3H1Z7s4j2J3E5O5t10B2t6T10r4t4R5y2o6a9r7P7j2P4d10H4n10S10z2H9d6D3z3h5f10t6e8E9a6c10F8");
  // return 0;
// }
