#include <iostream>
#include <string.h>
#include <bitset>
#include <stdio.h>
#include <list>
#include <vector>

using namespace std;

/**
  题目描述
  数组A包含了0到n的所有整数，但其中缺失了一个。对于这个问题，我们设定限制，使得一次操作无法取得数组number里某个整数的完整内容。
  唯一的可用操作是询问数组中第i个元素的二进制的第j位(最低位为第0位)，该操作的时间复杂度为常数，
  请设计算法，在O(n)的时间内找到这个数。
  给定一个数组number，即所有剩下的数按从小到大排列的二进制各位的值，如A[0][1]表示剩下的第二个数二进制从低到高的第二位。
  同时给定一个int n，意义如题。请返回缺失的数。
  测试样例：
  [[0],[0,1]]
  返回：1

  -----

  题目分析
  1.如果累加n(n+1)/2 对此题需要模拟，算法复杂度为O(nlogn)
  2.
 **/

class Finder {
 public:
  int findMissing(vector<vector<int> > numbers, int n) {
    (void)n;
    // 初始化辅助列表
    list<size_t> cared_indexes;
    for (size_t i = 0; i < numbers.size(); ++i) {
      cared_indexes.push_back(i);
    }

    int ret_num = 0;
    int calc_pos = 0;
    while (true) {
      // 计算第calc_pos位, 1和0的数量
      int count0 = 0, count1 = 0;
      GetBitCount(numbers, calc_pos, cared_indexes, &count0, &count1);

      // 0101010 只可能：count0 - count1 = 1 或 count0 - count1 = 0
      if (count0 - count1 == 0 || count0 - count1 == -1) { // 如果拿走的是0
        // 清除cared_indexes 中无效数字
        EraseUncareIndex(numbers, calc_pos, 1, &cared_indexes);
      } else if (count0 - count1 == 2 || count0 - count1 == 1) { // 如果拿走的是1
        // 第calc_pos位为1 累加到结果中
        ret_num |= 1 << calc_pos;
        // 清除cared_indexes 中无效数字
        EraseUncareIndex(numbers, calc_pos, 0, &cared_indexes);
      } else {
        cerr << " error. cout0:" << count0 << " count1:" << count1;
      }

      // 所有的都排除了
      if (cared_indexes.empty()) {
        break;
      }

      // 计算下一位
      calc_pos++;
    }
    return ret_num;
  }

 private:
  void GetBitCount(const vector<vector<int> >& numbers, size_t pos, const list<size_t>& cared_indexes,
                   int* count0, int* count1) {
    *count0 = 0;
    *count1 = 0;
    auto iter = cared_indexes.begin();
    for (; iter != cared_indexes.end(); ++iter) {
      size_t careed_index = *iter;
      // 第pos位存在，并且为1
      if (numbers[careed_index].size() - 1 >= pos && numbers[careed_index][pos] == 1) {
        *count1 = *count1 + 1;
      } else {
        *count0 = *count0 + 1;
      }
    }
  }

  void EraseUncareIndex(const vector<vector<int> >& numbers, size_t calc_pos, int uncare_bit, list<size_t>* cared_indexes) {
    auto iter = cared_indexes->begin();
    for (; iter != cared_indexes->end();) {
      size_t cared_index = *iter;
      int bit = GetBit(numbers[cared_index], calc_pos);
      if (bit == uncare_bit) {
        iter = cared_indexes->erase(iter);
      } else {
        ++iter;
      }
    }
  }

  int GetBit(const vector<int>& number, size_t pos) {
    if (number.size() - 1 < pos) {
      return 0;
    }
    return number[pos];
  }
};

int main() {
  vector<vector<int> >  vec{{0}, {0, 1}};
  Finder obj;
  int ret = obj.findMissing(vec, 2);
  cout << ret << endl;
  return 0;
}
