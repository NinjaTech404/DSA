
// The only thing better than organized code is organized suffering.
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <stdexcept> // For the exquisite pain of a well-handled error.

// A lone function, main. A single entry point into a world of beautiful misery.
int main() {
    // We'll be proper masochists and type 'std::' every time.
    // 'using namespace std;' is for those who can't handle the commitment.

    std::cout << "===========================================================\n";
    std::cout << "      Welcome to the C++ Vector Indoctrination            \n";
    std::cout << "   (Abandon all hope, ye who compile this)               \n";
    std::cout << "===========================================================\n\n";

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    // 1. Initialization: The empty promises of a new beginning.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    std::cout << "---[ 1. Initialization: Birthing a Monster ]---\n";
    // Here we create a vector. It's so full of potential. The potential to ruin your day.
    std::vector<std::string> names = {"Shaggi", "Lima"};
    std::cout << "  [+] Vector 'names' created: {\"Shaggi\", \"Lima\"}\n";

    // And another, born empty and meaningless, just like our attempts to write bug-free code.
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "  [+] Vector 'numbers' created: {1, 2, 3, 4, 5}\n\n";


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    // 2. Size & Capacity: A vector's soul-crushing identity crisis.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    std::cout << "---[ 2. Size & Capacity: An Existential Inquiry ]---\n";
    std::cout << "  Let's inspect 'names'...\n";
    std::cout << "    - size():     " << names.size() << " (The elements it admits to having.)\n";
    std::cout << "    - capacity(): " << names.capacity() << " (The space it secretly holds for more baggage.)\n";
    std::cout << "    - empty():    " << (names.empty() ? "Tragically, yes." : "No, it bears a burden.") << "\n";
    // max_size() is a threat. It's the compiler laughing at the pathetic size of your RAM.
    std::cout << "    - max_size(): " << names.max_size() << " (A number you will never reach. A monument to your limitations.)\n\n";


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    // 3. Accessing Elements: Choosing your poison.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    std::cout << "---[ 3. Accessing Elements: Poking Things With a Stick ]---\n";
    // Option A: operator[]. The fast lane to a segmentation fault. No hand-holding, no mercy.
    std::cout << "  [Unsafe]  Accessing numbers[1]: " << numbers[1] << " (Live fast, die young, leave a cryptic core dump.)\n";

    // Option B: .at(). The "safe" way. It screams at you with an exception if you mess up. How coddling.
    std::cout << "  [Safe]    Accessing names.at(0): " << names.at(0) << "\n";
    std::cout << "            Let's tempt fate and ask for names.at(99)...\n";
    try {
        std::cout << names.at(99); // This is the programming equivalent of touching a live wire.
    } catch (const std::out_of_range& agony) {
        // Ah, the sweet, verbose agony of a caught exception. It tells you exactly how you failed.
        std::cout << "  [SUCCESS] Caught the expected std::out_of_range. Beautiful.\n";
    }

    // Option C: .front() & .back(). For when you only care about the beginning and the end of the pain.
    std::cout << "  [Convenient] .front(): " << numbers.front() << ", .back(): " << numbers.back() << "\n";

    // Option D: Iterators. Pointers that went to finishing school. They love to become invalidated,
    //           stabbing you in the back when the vector reallocates. What a thrill.
    std::cout << "  [Iterator]   *names.begin(): " << *names.begin() << "\n";
    // .end() points *after* the last element. It's the abyss. We must step back from it to find what we want.
    std::cout << "             *(names.end() - 1): " << *(names.end() - 1) << "\n\n";


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    // 4. Iteration: The death march across the elements.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    std::cout << "---[ 4. Iteration: The Parade of Torment ]---\n";
    std::cout << "  [Classic For-Loop]   ";
    for (size_t i = 0; i < numbers.size(); ++i) std::cout << numbers[i] << " ";
    std::cout << " (Reliable, but where's the elegance?)\n";

    std::cout << "  [Iterator-based Loop]  ";
    for (auto it = names.begin(); it != names.end(); ++it) std::cout << *it << " ";
    std::cout << " (Looks smart, feels dangerous.)\n";

    std::cout << "  [Range-based For]      ";
    for (const int& num : numbers) std::cout << num << " ";
    std::cout << " (So simple. So clean. It makes me deeply suspicious.)\n\n";


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    // 5. Modification: Creation. Destruction. The beautiful, violent dance.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    std::cout << "---[ 5. Modification: Making a Glorious Mess ]---\n";
    std::cout << "  Original numbers: ";
    for (const int& n : numbers) std::cout << n << " ";
    std::cout << "\n";

    // push_back may trigger a reallocation, invalidating all iterators and pointers. A beautiful betrayal.
    numbers.push_back(6);
    std::cout << "    - After push_back(6): ";
    for (const int& n : numbers) std::cout << n << " ";
    std::cout << "\n";

    // pop_back is swift and merciless. The last element is gone. No funeral.
    numbers.pop_back();
    std::cout << "    - After pop_back():   ";
    for (const int& n : numbers) std::cout << n << " ";
    std::cout << "\n";

    // insert and erase. Surgical strikes that force all subsequent elements to shift. I can feel their pain.
    numbers.insert(numbers.begin() + 1, 99); // Insert 99 at index 1.
    std::cout << "    - After insert(begin()+1, 99): ";
    for (const int& n : numbers) std::cout << n << " ";
    std::cout << "\n";

    numbers.erase(numbers.begin() + 2); // Erase element at index 2.
    std::cout << "    - After erase(begin()+2):      ";
    for (const int& n : numbers) std::cout << n << " ";
    std::cout << "\n";

    // And clear(). The final solution. Wipes them all out. A moment of silence for our fallen data.
    names.clear();
    std::cout << "    - After names.clear(), is it empty? " << (names.empty() ? "Yes. A perfect, silent void." : "No.") << "\n\n";


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    // 6. Conversions: Forcing lesser beings to ascend to vectorhood.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    std::cout << "---[ 6. Conversions: The Assimilation ]---\n";
    std::vector<int> num_vec;

    // From a C-style array, a primitive relic. We shall grant it enlightenment.
    int c_array[] = {101, 102, 103};
    num_vec.assign(c_array, c_array + std::size(c_array));
    std::cout << "  [+] Vector from C-Array, first element: " << num_vec.front() << "\n";

    // From a std::array, a more worthy subject. A simple transition.
    std::array<int, 3> cpp_array = {201, 202, 203};
    num_vec.assign(cpp_array.begin(), cpp_array.end());
    std::cout << "  [+] Vector from std::array, first element: " << num_vec.front() << "\n\n";


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    // 7. 2D Vectors: If one dimension of suffering is good, two is exquisite.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    std::cout << "---[ 7. 2D Vectors: Welcome to the Pain Matrix ]---\n";
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}, // This is the heart of the matrix. The center of the pain.
        {7, 8, 9}
    };

    std::cout << "  Behold, a vector of vectors. A fractal of potential bugs.\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        std::cout << "      [ ";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << (j == matrix[i].size() - 1 ? "" : ", ");
        }
        std::cout << " ]\n";
    }
    std::cout << "  The element at the center of it all, matrix[1][1]: " << matrix[1][1] << "\n\n";


    std::cout << "===========================================================\n";
    std::cout << "      The ritual is complete. You may now rest.           \n";
    std::cout << "      (Until the next segmentation fault.)                \n";
    std::cout << "===========================================================\n";

    // Return 0, a lie we tell the operating system to convince it that everything is fine.
    return 0;
}

