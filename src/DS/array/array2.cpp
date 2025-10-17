#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <iterator>
namespace DSA{
    using size_t = long unsigned int;
    template<class T, size_t S>
    class array {
        private:
            T elements[S ? S : 1]; //C-Style array
        public:
            /*assigning*/
            array() = default; //declaration
            array(std::initializer_list<T> list){ //assigning with a list
                if(list.size() > S) { throw std::out_of_range("Error: Size is exceeded!"); }
                size_t index = 0;
                for(const T& element : list){ 
                    this->elements[index] = element;
                    ++index;
                }
            }

            constexpr void operator=(std::initializer_list<T> list)  { //assigning with an other object (Copy constructure)
                if(list.size() > S) { throw std::out_of_range("Error: Size is exceeded!"); }
                size_t index = 0;
                for(const T& element : list){
                    this->elements[index] = element;
                    ++index;
                }
            } 

            constexpr void operator=(const array& other){ //assigning with an other object (Copy constructure)
                size_t index = 0;
                for(const T& element : other){
                    this->elements[index] = element;
                    ++index;
                }
            } 
            ~array() = default;//destructor



            //accessing
            constexpr T& operator[](size_t index) noexcept { return this->elements[index]; } //access by []
            constexpr const T& operator[](size_t index) const noexcept { return this->elements[index]; } //access by []
                                                                                                     
            constexpr T& at(size_t index){ // access by a function with an exception
                if(index >= S){ throw std::out_of_range("Error: Index is out of range!"); }
                return this->elements[index];
            }
            constexpr const T& at(size_t index) const { // access by a function with an exception
                if(index >= S){ throw std::out_of_range("Error: Index is out of range!"); }
                return this->elements[index];
            }

            constexpr T& front(void) noexcept { return this->elements[0]; } // access 1st element
            constexpr const T& front(void) const noexcept { return this->elements[0]; } // access 1st element

            constexpr T& back(void) noexcept { return this->elements[S - 1]; } //access last element
            constexpr const T& back(void) const noexcept { return this->elements[S - 1]; } //access last element
                                                    
            constexpr T* begin(void) noexcept { return this->elements; } //access by first memory address
            constexpr const T* begin(void) const noexcept { return this->elements; } //access by first memory address
            constexpr const T* cbegin(void) const noexcept { return this->elements; } //access by first memory address
                                                                             //
            constexpr T* end(void) noexcept { return (this->elements + S); } //access by last memory address
            constexpr const T* end(void) const noexcept { return (this->elements + S); } //access by last memory address
            constexpr const T* cend(void) const noexcept { return (this->elements + S); } //access by last memory address
               
            constexpr std::reverse_iterator<T*> rbegin(void) noexcept { return std::reverse_iterator<T*>(this->end()); } //access by first memory address
            constexpr const std::reverse_iterator<T*> rbegin(void) const noexcept { return std::reverse_iterator<const T*>(this->end()); } //access by first memory address
            constexpr const std::reverse_iterator<T*> crbegin(void) const noexcept { return std::reverse_iterator<const T*>(this->cend()); } //access by first memory address
                                                                             //
            constexpr std::reverse_iterator<T*> rend(void) noexcept { return std::reverse_iterator<T*>(this->begin()); } //access by last memory address
            constexpr const std::reverse_iterator<T*> rend(void) const noexcept { return std::reverse_iterator<const T*>(this->begin()); } //access by last memory address
            constexpr const std::reverse_iterator<T*> crend(void) const noexcept { return std::reverse_iterator<T*>(this->cbegin()); } //access by last memory address
            
            //c-style array
            constexpr T* data (void) noexcept { return this->elements; } //access the raw c-style array
            constexpr const T* data (void) const noexcept { return this->elements; } //access the raw c-style array
            //size and capacity
            constexpr const size_t size(void) const noexcept { return S; }

            constexpr const size_t max_size(void) const noexcept { return S; }
            
            constexpr bool empty(void) noexcept { return S == 0; }
            
            //operations
            constexpr void fill (const T& value){ std::fill_n(elements, S, value); }

            constexpr void swap (array& other) noexcept(std::is_nothrow_swappable_v<T>) { std::swap_ranges(this->elements, this->end(), other.begin()); }
    };
}
