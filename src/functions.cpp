namespace super { 
template<typename T>
bool console (T value) {
  if (std::cout << value << std::endl){
    return true;
  }
  return false;
}
}
