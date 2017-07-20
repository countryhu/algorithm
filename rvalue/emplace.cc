#include <iostream>
#include <map>
#include <vector>

class Complicated {
 public:
  Complicated() {
    std::cout << "empty construct" << std::endl;
  }
  explicit Complicated(int x, int y, int z)
    : x_(x), y_(y), z_(z) {
      std::cout << "3params construct" << std::endl;
  }

  Complicated(const Complicated& rhs)
    : x_(rhs.x_), y_(rhs.y_), z_(rhs.z_) {
      std::cout << " copy" << std::endl;
  }

  ~Complicated() {
    std::cout << " ~desconstruct" << std::endl;
  }
 private:
  int x_;
  int y_;
  int z_;
};

int main() {
  std::map<int, Complicated> m;
  std::cout << " pre map.insert:" << std::endl;
  m.insert(std::make_pair(4, Complicated(1, 2, 3)));

  std::cout << "\n pre map.[]:" << std::endl;
  m[4] = Complicated(1, 2, 3);

  std::cout << "\n pre map.emplace:" << std::endl;
  m.emplace(4, Complicated(1, 2, 3));

  std::vector<Complicated> v;
  v.reserve(4);

  std::cout << "\n pre vector.push_back:" << std::endl;
  v.push_back(Complicated(1, 2, 3));

  std::cout << "\n pre vector.emplace_back:" << std::endl;
  v.emplace_back(1, 2, 3);

  std::cout << "\n pre return:" << std::endl;
  return 0;
}
