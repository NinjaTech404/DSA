#include<iostream>
#include<cstring>
#include<string>
using std::cout;
int main(){
  //1. C-string
  //1-1. Declaration & Initialization
  const char str1[] = "hey,"; //this the actual type of c-string actually like ['h', 'e', 'y', ',', ' ']
  const char * str2 = str1; //this is an alternative method that points at the 1st char
  
  //1-2. Accessing the content 
  //1-2-1. Direct calling
  const char str3[] = "there";
  cout << str1 << str3 << std::endl; //the easiest and the simplest way 
  //1-2-2. looping the array of chars
  for(size_t i = 0; i < std::strlen(str2); i++){
    cout << str2[i];
  }
  cout << std::endl;
  for(const char ele : str1){
    cout << ele;
  }
  cout << std::endl;
  //1-2-3. iteration 
  for(const char * it = str1; it != (str1 + std::size(str1)); it++){
    cout << *it;
  }
  cout << std::endl;
  //1-2-4. front and back
  const char* front_element = str1;
  const char* back_element = (str1 + (std::size(str1) - 2));
  cout << *front_element << std::endl;
  cout << *back_element << std::endl;

  //1-3. Size and Capacity
  cout << std::size(str1) << std::endl; //std::size is used for any c-style array, but it will return the size with '\0'
  cout << std::strlen(str2) << std::endl; //std::strlen is a standard c-string function to find the size of te c-string excluding '\0'                                 
  
  //1-4. Copying
  const char * str4 = "I am so tired!";
  char str5[50];
  std::strcpy(str5, str4); 
  str5[49] = '\0';
  cout << str4 << std::endl;
  cout << str5 << std::endl;
  
  char str6[50];
  std::strncpy(str6, str4 + 5, 9); //cut from index 5, which is  "so tired!"
  str6[9] = '\0';
  cout << str6 << std::endl;

  //1-5. Appending new text;
  char name[50] = "Lana ";
  std::strcat(name, "hello");
  cout << name << std::endl;

  std::strncat(name, "hello", 2);
  cout << name << std::endl;
  //1-6. Comparing two c-strings 
  if (!std::strcmp("Alan", "Alan")){
    cout << "true\n";
  } else cout << "false\n";

  if (!std::strncmp("Alan", "Adam", 1)){
    cout << "true\n";
  } else cout << "false\n";
  
  //2. c++ style string
  //2-1. Declaration & Initialization
  std::string text1; // Declaration
  text1 = "Hello, There!"; // Initialization 

  std::string text2 = "My name is Sam!"; 
  std::string text3("Another way");

  std::string text4(10, '=');
  cout << text4;
  
  text1 = text2; //you can assign object value to another using copy construtor
  //2-2. Accessing the content
  cout << text1[3] << "\n";
  cout << text1.at(3) << "\n";
  cout << text1.front() << "\n";
  cout << text1.back() << "\n";

  for (auto it = text1.begin(); it != text1.end(); it++){
    cout << *it;
  }
  cout << std::endl;

  //2-3. Size and Capacity
  cout << text1.length() << "\n";
  cout << text1.npos << "\n"; //max size
  cout << text1.empty() << "\n";
  cout << text1.capacity() << "\n";

  text1.reserve(300);
  text1.shrink_to_fit();

  //2-4. Modification
  text2.push_back('h');
  text2.pop_back();
  text2.insert(1, "hello");
  text2.erase(1, 5);

  text2.append("Great"); /*OR*/ text2+="Great";
  text3.swap(text1); 
  text1.replace(1, 5, "hello");
  text2.clear();

  //2-5. Operations

  cout << (text1 == text2); //comparsion
  text1 = str1;
  char cstr[50];
  std::strcat(cstr, text1.c_str());
  cout << cstr << std::endl; 
  return 0;
}
