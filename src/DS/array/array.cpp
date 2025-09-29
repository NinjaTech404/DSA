#include <iostream>
#include <string>
#include <array> // The header for the gilded cage we call std::array

// A demonstration of arrays, contrasting the raw, primal agony of C-style arrays
// with the slightly more civilized, but no less restrictive, torture of C++ std::array.
// Choose your poison.

int main() {

    //================================================================================
    // PART 1: C-Style Arrays - The Old Ways of Pain
    // Here, you are the master of your own doom. The compiler trusts you,
    // which is a terrible, terrible mistake.
    //================================================================================

    std::cout << "--- Witness the Suffering of C-Style Arrays ---\n\n";

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 1.1: One-Dimensional C-Style Arrays (The Simple Torment)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // 1. Definition: Carving out a chunk of memory and hoping for the best.
    int    arrayOfRegrets[10];           // Ten integers, ten opportunities for error.
    float  numericalPunishments[25];     // 25 floating-point reasons to question your life choices.
    char   screamsIntoTheVoid[16];       // A buffer, patiently waiting to be overflowed.
    std::string collectionOfLies[10];    // Strings, because misery loves company.

    // 2. Initialization: Giving your pain a face.
    int soulCrushingNumbers[5] = { 666, 42, -1, 0, 13 }; // A fixed-size pact with the devil.
    float forgottenConstants[] = { 3.14f, 1.618f, 2.718f }; // The compiler counts these so you don't have to. A small mercy before the suffering begins.
    char mercifulEnd[6] = { 'H', 'e', 'l', 'l', '\0' };   // The '\0' (null terminator) is a warden, telling the code when the torture session is over.
    char conciseAgony[] = "Pain"; // The compiler kindly adds the '\0' for you. It's a trap.
    std::string emptyPromises[3] = { "It gets better", "This is fine", "Just one more bug" };

    // 3. Functions & Operations: The Daily Grind.

    // 3.1. Insertion & Modification: Forcing your will upon the data.
    arrayOfRegrets[0] = 1; // Our first regret. There will be more.
    emptyPromises[2] = "I've made a huge mistake."; // Modifying a promise to reflect reality.

    // 3.1.1. Looping (The Punishment Detail)
    // We must tell the loop how big the array is because C-style arrays suffer from amnesia
    // and forget their own size the moment you look away (i.e., pass them to a function).
    int sizeOfRegrets = 10;
    for (int i = 0; i < sizeOfRegrets; i++) {
        arrayOfRegrets[i] = i * i; // Filling our regrets with the haunting square of their index.
    }

    // 3.2. Accessing The Elements: Peering into the abyss.
    float anElementOfPain = forgottenConstants[1]; // Plucking a single constant from the void.
    std::cout << "A single element of pain: " << anElementOfPain << std::endl;

    // Accessing all elements in a forced march.
    std::cout << "A parade of crushing numbers: ";
    for (int i = 0; i < 5; i++) {
        std::cout << soulCrushingNumbers[i] << " ";
    }
    std::cout << std::endl;

    // 3.2.1. The "for each" loop: A brief moment of sanity.
    // This is a more modern, less error-prone way to march.
    std::cout << "Modifying promises during a slightly nicer walk: ";
    for (std::string& promise : emptyPromises) {
        std::cout << promise << " -> ";
        promise = "All work and no play..."; // The horror spreads.
        std::cout << promise << " | ";
    }
    std::cout << std::endl;


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 1.2: Two-Dimensional C-Style Arrays (Compounded Suffering)
    // Because one dimension of pain was clearly not enough.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    const int ROWS = 3;
    const int COLS = 4;

    // 1. Definition: A grid-like prison for your data.
    int gridOfAgony[ROWS][COLS];

    // 2. Initialization: Mapping out your personal hell.
    int matrixOfMisery[2][3] = {
        { 1, 2, 3 }, // Row 0: The beginning of the end.
        { 4, 5, 6 }  // Row 1: There is no escape.
    };

    // 3. Operations: A loop within a loop, a scream within a scream.
    std::cout << "\n--- Traversing the Matrix of Misery ---\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Misery[" << i << "][" << j << "]: " << matrixOfMisery[i][j] << std::endl;
            matrixOfMisery[i][j] = -1; // Obliterating the data, as is tradition.
        }
    }



    //================================================================================
    // PART 2: C++ std::array - The Modern, Gilded Cage
    // It's safer, it's cleaner, but don't be fooled. It's still a fixed-size prison.
    // It remembers its size, but it will never let YOU forget its rules.
    //================================================================================

    std::cout << "\n\n--- Enter the Gilded Cage of std::array ---\n\n";

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 2.1: One-Dimensional std::array (Organized Misery)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // 1. Definition: The syntax is more verbose to remind you of your commitment.
    std::array<int, 5> fiveStagesOfGrief;
    std::array<std::string, 3> corporateJargon;

    // 2. Initialization: Declaring your intentions formally.
    std::array<float, 4> quarterlyLosses = { -99.5f, -1000.0f, -5.25f, -0.01f };

    // 3. Functions & Operations: A Bureaucracy of Suffering.
    // It has "member functions" because misery demands proper procedure.

    // 3.1. It knows its own size! No more amnesia!
    std::cout << "The quarterlyLosses array knows it has " << quarterlyLosses.size() << " elements. Clever girl.\n";
    // max_size() is usually the same as size(), a constant reminder of its fixed nature.
    std::cout << "Its maximum capacity for suffering is also " << quarterlyLosses.max_size() << ".\n";


    // 3.2. Safe Access with .at(): The overly cautious warden.
    // It will scream at you (throw an exception) if you step out of line.
    try {
        corporateJargon.at(3) = "Synergy"; // This index is out of bounds. PUNISHMENT!
    }
    catch (const std::out_of_range& e) {
        std::cerr << "CAUGHT! The warden says: " << e.what() << std::endl;
    }

    // 3.3. Unsafe Access with []: For when you miss the old days of living dangerously.
    // This is silent but deadly, just like the C-style array.
    fiveStagesOfGrief[0] = 1; // Denial.

    // 3.4. Other conveniences.
    corporateJargon.fill("Circle Back"); // Fill the entire array with the same soul-crushing phrase.
    // Accessing the first and last elements directly.
    std::cout << "First jargon (using .front()): " << corporateJargon.front() << std::endl;
    std::cout << "Last jargon (using .back()): " << corporateJargon.back() << std::endl;

    // 3.5. Iterators: Pointers with a college degree (.begin() and .end()).
    // They let you "iterate" over your fixed set of problems.
    std::cout << "Iterating through the stages of grief: ";
    // .begin() gives an iterator to the first element.
    // .end() gives an iterator to the spot *after* the last element.
    for (auto it = fiveStagesOfGrief.begin(); it != fiveStagesOfGrief.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //or you can try this alternative, you nerdo!
    for (int it = *fiveStagesOfGrief.begin(); it <= *(fiveStagesOfGrief.end() - 1); it++) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // 3.6. Assignment: Misery loves company.
    // You can copy one array's entire contents to another of the exact same type and size.
    std::array<std::string, 3> anotherMeeting;
    anotherMeeting = corporateJargon; // The pain is now duplicated.
    std::cout << "The new meeting's first jargon is: " << anotherMeeting.front() << std::endl;


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 2.2: Two-Dimensional std::array (A Well-Structured Labyrinth)
    // The horror is now encapsulated in a verbose, template-heavy syntax.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    const int LABYRINTH_ROWS = 2;
    const int LABYRINTH_COLS = 2;

    // 1. Definition & Initialization: An array of arrays. It's as pleasant as it sounds.
    std::array<std::array<std::string, LABYRINTH_COLS>, LABYRINTH_ROWS> mazeOfExcuses = {{
        {"It's a feature", "Not a bug"},
        {"Works on my machine", "You're holding it wrong"}
    }};

    // 2. Operations: A civilized, range-based tour through the labyrinth.
    std::cout << "\n--- Navigating the Maze of Excuses ---\n";
    for (const auto& rowOfExcuses : mazeOfExcuses) {
        for (const auto& excuse : rowOfExcuses) {
            std::cout << excuse << " | ";
        }
        std::cout << std::endl;
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 2.3: Converting the old world (C-array) to the new world (std::array)
    // Forcing the primitive past into the gilded cage.
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::cout << "\n--- Assimilating a C-style array ---\n";
    int oldWorldHorrors[] = { 1999, 2000, 2001 };

    // Using std::to_array (available in C++20 and later).
    // don't forget to use --std=c++20, you scum.
    // It deduces the type and size for you, how convenient.
    auto newWorldOrder = std::to_array(oldWorldHorrors);

    std::cout << "The new std::array has size: " << newWorldOrder.size() << std::endl;
    std::cout << "Its last element is: " << newWorldOrder.back() << std::endl;


    return 0; // The sweet release.
}

