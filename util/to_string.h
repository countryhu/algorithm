#ifndef UTIL_TO_STRING_H
#define UTIL_TO_STRING_H

#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace util {

template <typename T>
std::string ToString(const T& t) {
  return std::to_string(t);
}

template <typename K, typename V>
std::string ToString(const std::map<K, V>& m,
  const std::string& split_token = ", ");

template <typename T>
std::string ToString(const std::set<T>& s,
  const std::string& split_token = ", ");

template <typename T>
std::string ToString(const std::vector<T>& t,
  const std::string& split_token = ", ");

template <typename K, typename V>
std::string ToString(const typename std::pair<K, V>& v) {
  std::ostringstream o;
  o << ToString(v.first) << ": " << ToString(v.second);
  return o.str();
}

template <typename T>
std::string ToString(const T& beg, const T& end,
  const std::string& split_token)
{
  std::ostringstream o;
  for (T it = beg; it != end; ++it) {
    if (it != beg)
      o << split_token;
    o << ToString(*it);
  }
  return o.str();
}

template <typename T>
std::string ToString(const std::vector<T>& t,
  const std::string& split_token = ", ") {
  std::ostringstream o;
  o << "[" << ToString(t.begin(), t.end(), split_token) << "]";
  return o.str();
}

template <typename K, typename V>
std::string ToString(const std::map<K, V>& m,
  const std::string& split_token = ", ") {
  std::ostringstream o;
  o << "{" << ToString(m.begin(), m.end(), split_token) << "}";
  return o.str();
}

template <typename T>
std::string ToString(const std::set<T>& s,
  const std::string& split_token = ", ") {
  std::ostringstream o;
  o << "{" << ToString(s.begin(), s.end(), split_token) << "}";
  return o.str();
}
} // util
#endif // UTIL_TO_STRING_H
