#ifndef LINEAR_HPP
#define LINEAR_HPP

#include <cstddef>
#include <stdexcept>

namespace linear{

const static size_t LIMIT = -1;

/* >====> Non-Rcursive Linear Search Function <====<*/
template<class T>
size_t non_rec_linear_search(T* arr, T key, size_t  N);

/* >====> Rcursive Linear Search Function <====<*/
template<class T>
size_t rec_linear_search (T* arr, T key, size_t N);

#include "linear.cpp"

}
#endif
