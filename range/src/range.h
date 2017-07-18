#include <cmath>
#include <stdexcept>
#include <sstream>

namespace detail_range {

template <typename value_type>
class const_iter {
 public:
  const_iter(size_t cursor, value_type value, value_type step)
    : cursor_(cursor), value_(value), step_(step) {
  }

  value_type operator*() const {
    return value_;
  }

  const_iter& operator++() {
    value_ += step_;
    ++ cursor_;
    return *this;
  }

  bool operator!=(const const_iter& rhs) {
    return cursor_ != rhs.cursor_;
  }

 public:
  size_t cursor_;
  value_type value_;
  value_type step_;
};

template <typename value_type>
class impl {
 public:
  impl(value_type begin, value_type end, value_type step)
    : begin_(begin), end_(end), step_(step) {
    max_count_ = GetAdjestAccount();
  }

  const const_iter<value_type> begin() const {
    return { 0, begin_, step_ };
  }

  const const_iter<value_type> end() const {
    return { max_count_, begin_, step_ };
  }

 private:
  size_t GetAdjestAccount() {
    if (step_ > 0 && begin_ > end_) {
      std::ostringstream ostr;
      ostr << "End value must be greater than begin value. step_="
        << step_ << " begin_=" << begin_ << " end_=" << end_;
      throw std::logic_error(ostr.str());
    } else if (step_ < 0 && begin_ < end_) {
      std::ostringstream ostr;
      ostr << "End value must be less than begin value. step_="
        << step_ << " begin_=" << begin_ << " end_=" << end_;
      throw std::logic_error(ostr.str());
    }
    size_t max_steps = static_cast<size_t>((end_ - begin_) / step_);

    if (std::abs(begin_ + step_ * max_steps - end_) > 0.0001 ) {
      ++ max_steps;
    }
    return max_steps;
  }
 private:
  value_type begin_;
  value_type end_;
  value_type step_;
  size_t max_count_;
};
} // namespace detail_range

template <typename T>
detail_range::impl<T> range(T end) {
  return detail_range::impl<T>({}, end, 1);
}

template <typename T>
detail_range::impl<T> range(T begin, T end) {
  return detail_range::impl<T>(begin, end, 1);
}

template <typename T, typename U>
auto range(T begin, T end, U step)
  -> detail_range::impl<decltype(begin+step)> {
  return detail_range::impl<decltype(begin+step)>(begin, end, step);
}
