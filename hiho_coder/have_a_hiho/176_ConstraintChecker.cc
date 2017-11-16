#include <iostream>
#include <string>
#include <list>
#include <locale>
#include <set>
#include <stdlib.h>
#include <map>
#include <unistd.h>


/**
  题目1 : Constraint Checker
  时间限制:10000ms
  单点时限:1000ms
  内存限制:256MB
  描述
  Given a set of constraints like 0<N<=M<=100 and values for all the variables,
  write a checker program to determine if the constraints are satisfied.

  More precisely, the format of constraints is:

  token op token op ... op token

  where each token is either a constant integer or a variable represented by a capital letter
  and each op is either less-than ( < ) or less-than-or-equal-to ( <= ).

  输入
  The first line contains an integer N, the number of constraints. (1 ≤ N ≤ 20)

  Each of the following N lines contains a constraint in the previous mentioned format.

  Then follows an integer T, the number of assignments to check. (1 ≤ T ≤ 50)

  Each assignment occupies K lines where K is the number of variables in the constraints.

  Each line contains a capital letter and an integer, representing a variable and its value.

  It is guaranteed that:

  1. Every token in the constraints is either an integer from 0 to 1000000 or an variable represented by a capital letter from 'A' to 'Z'.

  2. There is no space in the constraints.

  3. In each assignment every variable appears exactly once and its value is from 0 to 1000000.

  输出
  For each assignment output Yes or No indicating if the constraints are satisfied.

  样例输入
  2
  A<B<=E
  3<=E<5
  2
  A 1
  B 2
  E 3
  A 3
  B 5
  E 10
  样例输出
  Yes
  No
  -----

  题目分析
  《Constraint Checker》题目分析
  本题是一道比较简单的字符串处理题目，做法也比较直观，不需要特别优化时间复杂度。

  首先为了方便检查，可以把限制条件都拆成若干个二元关系(token1 op token2)。例如样例中

  A<B<=E
  3<=E<5
  就可以拆成：

  A<B
  B<=E
  3<=E
  E<5
  在拆分过程中顺便把token是变量还是常量也求出来，方便最后的检查。

  之后对于一组赋值，我们可以用map保存每个变量的值。

  最后对于从限制条件拆出的所有二元关系，都检查一下是不是符合条件即可。
**/

struct Token {
  Token() {
  }

  Token(const std::string& tokenStr) {
    size_t i = 0;
    for (; i < tokenStr.size(); ++i) {
      if (!isdigit(tokenStr[i])) {
        isVar = true;
        varName = tokenStr;
        break;
      }
    }
    if (i == tokenStr.size()) {
      isVar = false;
      constant = atoi(tokenStr.c_str());
    }
  }

  bool isVar;
  std::string varName;
  int constant;
};

class Checker {
 public:
  explicit Checker(const Token& leftToken, const Token& rightToken, const std::string& opStr)
  : leftToken_(leftToken), rightToken_(rightToken), op_(opStr) {
  }

  bool CheckOK(std::map<std::string, int>& checkVars) {
    int leftValue = 0;
    if (leftToken_.isVar) {
      leftValue = checkVars[leftToken_.varName];
    } else {
      leftValue = leftToken_.constant;
    }

    int rightValue = 0;
    if (rightToken_.isVar) {
      rightValue = checkVars[rightToken_.varName];
    } else {
      rightValue = rightToken_.constant;
    }

    if (op_ == "<") {
      return leftValue < rightValue;
    } else { // op_ == "<="
      return leftValue <= rightValue;
    }
  }

 private:
  Checker() = delete;

  Token leftToken_;
  Token rightToken_;
  std::string op_;
};

void GetNextToken(const std::string& constraint, size_t* startIndex, Token* token) {
  size_t i = *startIndex;
  for (; i < constraint.size(); ++i) {
    if (constraint[i] == '<') {
      *token = Token(constraint.substr(*startIndex, i - *startIndex));
      *startIndex = i;
      return;
    }
  }
  // 到尾部了
  *token = Token(constraint.substr(*startIndex));
  *startIndex = i;
}

void GetNextOp(const std::string& constraint, size_t* startIndex, std::string* op) {
  size_t i = *startIndex;
  for (; i < constraint.size(); ++i) {
    if (constraint[i] != '<' && constraint[i] != '=') {
      *op = constraint.substr(*startIndex, i - *startIndex);
      *startIndex = i;
      return;
    }
  }
  // 到尾部了,异常
  *op = constraint.substr(*startIndex);
  *startIndex = i;
  std::cerr << "error:" << constraint << std::endl;
}

void ParseConstraint(const std::string& constraint, std::list<Checker>* constraints, std::set<std::string>* occuredVars) {
  size_t startIndex = 0;
  Token rightToken;
  GetNextToken(constraint, &startIndex, &rightToken);

  while (startIndex < constraint.size()) {
    Token leftToken = rightToken;

    std::string opStr;
    GetNextOp(constraint, &startIndex, &opStr);

    GetNextToken(constraint, &startIndex, &rightToken);

    constraints->push_back(Checker(leftToken, rightToken, opStr));

    // 统计出现过的变量个数
    if (leftToken.isVar) {
      occuredVars->insert(leftToken.varName);
    }
    if (rightToken.isVar) {
      occuredVars->insert(rightToken.varName);
    }
  }
}

int main() {
  // 输入判断式
  int N = 0;
  std::cin >> N;
  std::list<Checker> constraints;
  std::set<std::string> occuredVars;
  for (int i = 0; i < N; ++i) {
    std::string constraint;
    std::cin >> constraint;
    // 解析一串判断式成为二元判断
    ParseConstraint(constraint, &constraints, &occuredVars);
  }

  int T = 0;
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    // 每轮判断
    std::map<std::string, int> checkVars;
    int varNum = occuredVars.size();
    while (varNum--) {
      std::string varName;
      int varValue;
      std::cin >> varName >> varValue;
      checkVars[varName] = varValue;
    }

    // 判断
    auto iter =  constraints.begin();
    for (; iter != constraints.end(); ++iter) {
      auto& checker = *iter;
      if (!checker.CheckOK(checkVars)) {
        std::cout << "No" << std::endl;
        break;
      }
    }
    if (iter == constraints.end()) {
      std::cout << "Yes" << std::endl;
    }
  }
  return 0;
}
