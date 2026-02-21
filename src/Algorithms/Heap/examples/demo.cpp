/*
 * Heap Sort Demonstration Program
 * 
 * This program demonstrates various use cases and features of the heap sort
 * library including both max-heap and min-heap sorting with different data types.
 * 
 * Author: KADHIM SHAKIR
 * Email: kadhimshakir@yahoo.com
 * GitHub: https://github.com/NinjaTech404
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for std::copy
#include "../heap.hpp"

// Helper function to print array of any type
template<typename T>
void print_array(const T arr[], size_t size, const std::string& label) {
    std::cout << label << ": [";
    for(size_t i = 0; i < size; ++i) {
        std::cout << arr[i];
        if(i < size - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Helper function to print vector (alternative container)
template<typename T>
void print_vector(const std::vector<T>& vec, const std::string& label) {
    std::cout << label << ": [";
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if(i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Example 1: Basic integer sorting
void demo_integer_sorting() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 1: Integer Array Sorting" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 8, 42, 17};
    size_t size = std::size(arr);
    
    // Make a copy for min-heap demo
    int arr_copy[std::size(arr)];
    std::copy(std::begin(arr), std::end(arr), std::begin(arr_copy));
    
    std::cout << "Original array: ";
    print_array(arr, size, "");
    
    // Max-heap sort (ascending)
    heap::heap_sort(arr, size);
    std::cout << "After max-heap sort (ascending): ";
    print_array(arr, size, "");
    
    // Min-heap sort (descending)
    heap::min_heap_sort(arr_copy, size);
    std::cout << "After min-heap sort (descending): ";
    print_array(arr_copy, size, "");
}

// Example 2: Floating point numbers
void demo_floating_point() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 2: Floating Point Numbers" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    double values[] = {3.14, 2.718, 1.618, 0.577, 2.236, 1.414, 1.732};
    size_t size = std::size(values);
    
    std::cout << "Original doubles: ";
    print_array(values, size, "");
    
    heap::heap_sort(values, size);
    std::cout << "Sorted ascending: ";
    print_array(values, size, "");
}

// Example 3: Characters
void demo_characters() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 3: Character Array" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    char letters[] = {'z', 'a', 'm', 'b', 'y', 'c', 'x', 'd'};
    size_t size = std::size(letters);
    
    std::cout << "Original characters: ";
    print_array(letters, size, "");
    
    heap::heap_sort(letters, size);
    std::cout << "Sorted ascending: ";
    print_array(letters, size, "");
    
    // Show as string
    std::string str(letters, size);
    std::cout << "As string: " << str << std::endl;
}

// Example 4: Strings
void demo_strings() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 4: String Array" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    std::string words[] = {"banana", "apple", "cherry", "date", "elderberry", "fig"};
    size_t size = std::size(words);
    
    std::cout << "Original strings: ";
    print_array(words, size, "");
    
    heap::heap_sort(words, size);
    std::cout << "Sorted alphabetically: ";
    print_array(words, size, "");
}

// Example 5: Custom struct with comparison operators
struct Student {
    std::string name;
    int grade;
    
    // Define comparison operators for heap sort
    bool operator>(const Student& other) const {
        return grade > other.grade;
    }
    
    bool operator<(const Student& other) const {
        return grade < other.grade;
    }
};

// Overload stream operator for printing
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "{" << s.name << ": " << s.grade << "}";
    return os;
}

void demo_custom_struct() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 5: Custom Struct (Students by Grade)" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    Student students[] = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"Diana", 95},
        {"Eve", 88},
        {"Frank", 70}
    };
    size_t size = std::size(students);
    
    std::cout << "Original students: ";
    print_array(students, size, "");
    
    // Sort by grade ascending
    heap::heap_sort(students, size);
    std::cout << "Sorted by grade (ascending): ";
    print_array(students, size, "");
    
    // Sort by grade descending using min-heap
    heap::min_heap_sort(students, size);
    std::cout << "Sorted by grade (descending): ";
    print_array(students, size, "");
}

// Example 6: Performance comparison with different data patterns
void demo_data_patterns() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 6: Different Data Patterns" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    const size_t SIZE = 10;
    
    // Already sorted array
    int sorted[SIZE];
    for(size_t i = 0; i < SIZE; ++i) sorted[i] = i + 1;
    std::cout << "Already sorted: ";
    print_array(sorted, SIZE, "");
    heap::heap_sort(sorted, SIZE);
    std::cout << "After heap sort: ";
    print_array(sorted, SIZE, "");
    
    // Reverse sorted array
    int reversed[SIZE];
    for(size_t i = 0; i < SIZE; ++i) reversed[i] = SIZE - i;
    std::cout << "\nReverse sorted: ";
    print_array(reversed, SIZE, "");
    heap::heap_sort(reversed, SIZE);
    std::cout << "After heap sort: ";
    print_array(reversed, SIZE, "");
    
    // Array with duplicates
    int duplicates[] = {5, 2, 5, 1, 2, 5, 1, 2, 5, 1};
    std::cout << "\nWith duplicates: ";
    print_array(duplicates, SIZE, "");
    heap::heap_sort(duplicates, SIZE);
    std::cout << "After heap sort: ";
    print_array(duplicates, SIZE, "");
}

// Example 7: Working with std::vector (conversion needed)
void demo_vector_integration() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 7: Working with std::vector" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    std::vector<int> vec = {42, 17, 33, 8, 19, 27, 5, 12};
    print_vector(vec, "Original vector");
    
    // Convert vector to array for heap sort
    // Note: heap sort works directly with contiguous memory
    heap::heap_sort(vec.data(), vec.size());
    print_vector(vec, "After heap sort");
}

// Example 8: Partial sorting demonstration
void demo_partial_sort() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "EXAMPLE 8: Partial Array Sorting" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 8, 42, 17};
    size_t full_size = std::size(arr);
    
    std::cout << "Full array: ";
    print_array(arr, full_size, "");
    
    // Sort only first 5 elements
    heap::heap_sort(arr, 5);
    std::cout << "After sorting first 5 elements: ";
    print_array(arr, full_size, "");
    
    // Sort the remaining elements
    heap::heap_sort(arr + 5, full_size - 5);
    std::cout << "After sorting remaining elements: ";
    print_array(arr, full_size, "");
}

int main() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "HEAP SORT LIBRARY DEMONSTRATION" << std::endl;
    std::cout << "Author: KADHIM SHAKIR" << std::endl;
    std::cout << "Email: kadhimshakir@yahoo.com" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    // Run all demonstrations
    demo_integer_sorting();
    demo_floating_point();
    demo_characters();
    demo_strings();
    demo_custom_struct();
    demo_data_patterns();
    demo_vector_integration();
    demo_partial_sort();
    
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "DEMONSTRATION COMPLETE" << std::endl;
    std::cout << std::string(60, '=') << "\n" << std::endl;
    
    return 0;
}
