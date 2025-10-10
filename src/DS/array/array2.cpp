#include <initializer_list>
#include <stdexcept>
namespace DSA{
    using size_t = long unsigned int;
    template<class T, size_t S>
    class array {
        private:
            T data[S]; //C-Style array
        public:
            /*assigning*/
            array() = default; //declaration
            ~array() = default;
            array(std::initializer_list<T> list){ //assigning with a list
                if(list.size() > S) { throw std::out_of_range("Error: Size is exceeded!"); }
                size_t index = 0;
                for(const T& element : list){ 
                    this->data[index] = element;
                    ++index;
                }
            }

            constexpr void operator=(std::initializer_list<T> list)  { //assigning with an other object (Copy constructure)
                if(list.size() > S) { throw std::out_of_range("Error: Size is exceeded!"); }
                size_t index = 0;
                for(const T& element : list){
                    this->data[index] = element;
                    ++index;
                }
            } 

            constexpr void operator=(const array& other){ //assigning with an other object (Copy constructure)
                size_t index = 0;
                for(const T& element : other){
                    this->data[index] = element;
                    ++index;
                }
            } 

            //accessing
            constexpr T& operator[](size_t index) noexcept { return this->data[index]; } //access by []
            constexpr const T& operator[](size_t index) const noexcept { return this->data[index]; } //access by []
                                                                                                     //
            constexpr T& at(size_t index) { // access by a function with an exception
                if(index >= S){ throw std::out_of_range("Error: Index is out of range!"); }
                return this->data[index];
            }

            constexpr T& front() noexcept { return this->data[0]; } // access 1st element
            constexpr const T& front() const noexcept { return this->data[0]; } // access 1st element

            constexpr T& back() noexcept { return this->data[S - 1]; } //access last element
            constexpr const T& back() const noexcept { return this->data[S - 1]; } //access last element
                                                    
            constexpr T* begin() noexcept { return this->data; } //access by first memory address
            constexpr const T* begin() const noexcept { return this->data; } //access by first memory address
                                                                             //
            constexpr T* end() noexcept { return (this->data + S); } //access by last memory address
            constexpr const T* end() const noexcept { return (this->data + S); } //access by last memory address

            //size and capacity
            constexpr size_t size() noexcept { return S; }
            constexpr const size_t size() const noexcept { return S; }

            constexpr size_t max_size() noexcept { return S; }
            constexpr const size_t max_size() const noexcept { return S; }

    };
}
#include<iostream>
using namespace std;
int main (){
    try{
        const DSA::array<int, 3> nums2 = {1, 2};
        DSA::array<int, 3> n;
        n = {1, 2, 3};
        cout << n.size() << endl;
        cout << n.back() << endl;

    }
    catch(const std::out_of_range& err){
        cout << err.what() << endl;
    }
    //for(auto ele : n) cout << ele << endl;
}
