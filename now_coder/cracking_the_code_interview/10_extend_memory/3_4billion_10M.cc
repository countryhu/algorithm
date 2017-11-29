#include <iostream>
#include <vector>
#include <bitset>

/**
  题目描述
  40亿个互不相同的非负数字，用10M内存找出一个不存在的整数
  测试样例：
  [1,2,3...100000,100002,100003...40bill]
  返回：
  100001

  -------
  题目分析
  0. 10M=2^23B = 2^26b 无法用位标记 40亿(2^32)
  1. 只能考虑桶排序，40亿=2^32, 10M 最多有10M/4B=2^23 = 100w个桶, 那么每个桶可以放2^32/2^23 = 2^9 = 4000个数字
 **/

const int kBucketCount = 10000;
const int kRangeUnit = 4000;

class FindLostNum {
 public:
  int findLostNum(std::vector<unsigned int> nums) {
    int lostRangeIndex = FindLostRangeIndex(nums);
    return FindLostRangeNum(nums, kRangeUnit * lostRangeIndex, kRangeUnit * (lostRangeIndex + 1) - 1);
  }

 private:
  int FindLostRangeIndex(const std::vector<unsigned int>& nums) {
    // 限用10M内存
    unsigned int ranges[kBucketCount] = {0};
    for (auto& num : nums) {
      ranges[num / kRangeUnit] ++;
    }

    for (int i = 0; i < kBucketCount; ++i) {
      if (ranges[i] < kRangeUnit) {
        return i;
      }
    }
    return 0;
  }

  int FindLostRangeNum(const std::vector<unsigned int>& nums, unsigned int startNum, unsigned int endNum) {
    std::bitset<kRangeUnit> numFlags;
    for (auto& num : nums) {
      if (num >= startNum && num <= endNum) {
        numFlags.set(num - startNum, 1);
      }
    }

    for (int i = 0; i < kRangeUnit; ++i) {
      if (numFlags[i] == 0) {
        return startNum + i;
      }
    }
    return 0;
  }
};

int main() {
  // 样例
  {
    FindLostNum obj;
    unsigned int lostNum = 2999998;
    std::vector<unsigned int> nums;
    nums.reserve(kBucketCount * kRangeUnit);
    for (unsigned int i = 0; i < lostNum; ++i) {
      nums.push_back(i);
    }
    for (unsigned int i = lostNum + 1; i < kBucketCount * kRangeUnit; ++i) {
      nums.push_back(i);
    }
    std::cout << "obj.findLostNum([0,100000],[100002,4000000001))=" << lostNum  << ":" << obj.findLostNum(nums) << std::endl;
  }
  return 0;
}
