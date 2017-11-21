#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
  题目描述
  对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
  给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

  测试样例：
  "(()())",6
  返回：
  true

  测试样例：
  "()a()()",7
  返回：
  false

  测试样例：
  "()(()()",7
  返回：
  false

  -------
  题目分析
 **/

class Parenthesis {
 public:
  bool chkParenthesis(string A, int n) {
    if (n % 2 != 0) {
      return false;
    }
    return myChkParenthesis(A);
  }

 private:
  bool myChkParenthesis(const std::string& A) {
    std::vector<char> cache;
    cache.reserve(A.size());
    for (size_t i = 0; i < A.size(); ++i) {
      if (A[i] == '(') {
        cache.push_back('(');
      } else if (A[i] == ')') {
        if (cache.empty()) {
          return false;
        }
        cache.pop_back();
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  // 样例
  {
    Parenthesis obj;
    std::cout << obj.chkParenthesis("(()())", 6) << std::endl;
  }

  {
    Parenthesis obj;
    std::cout << obj.chkParenthesis("()a()()", 7) << std::endl;
  }


  {
    Parenthesis obj;
    std::cout << obj.chkParenthesis("()(()()", 7) << std::endl;
  }
  return 0;
}
