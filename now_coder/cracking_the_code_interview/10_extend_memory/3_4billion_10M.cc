#include <iostream>
#include <vector>

/**
  题目描述
  40亿个互不相同的非负数字，用10M内存找出一个不存在的整数
  测试样例：
  [1,2,3...100000,100002,100003...40bill]
  返回：
  100001

  -------
  题目分析
 **/

class FindLostNum {
 public:
  int findLostNum(std::vector<unsigned int> nums) {
    (void)nums;
    return 0;
  }
};

int main() {
  // 样例
  {
    FindLostNum obj;
    unsigned int maxNum = 4000000000;
    unsigned int lostNum = 100001;
    std::vector<unsigned int> nums;
    nums.reserve(maxNum);
    for (unsigned int i = 0; i < lostNum; ++i) {
      nums.push_back(i);
    }
    for (unsigned int i = lostNum + 1; i < maxNum; ++i) {
      nums.push_back(i);
    }
    std::cout << "obj.findLostNum(1)=1:" << obj.findLostNum(nums) << std::endl;
  }
  return 0;
}
