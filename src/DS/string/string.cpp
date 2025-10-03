
// We're back in the abyss, this time to play with strings.
// One is a relic from a time of cavemen and buffer overflows.
// The other is its civilized descendant that handles its own baggage.
// This will be fun.
#include <iostream>
#include <string>   // For the modern, sanitized C++ string.
#include <cstring>  // For the ancient, cursed C-string rituals (strcpy, strlen, etc.).

// The one and only function. Our entire universe is contained within these curly braces.
int main() {
    // We will not be using 'using namespace std;'. That is a shortcut.
    // We are here to suffer, and that means typing 'std::' until our fingers bleed.

    std::cout << "***********************************************************\n";
    std::cout << "      A Tale of Two Strings: A Study in Self-Harm          \n";
    std::cout << "***********************************************************\n";

    //=========================================================================//
    // PART I: The C-String - Wielding Raw, Unspeakable Power
    // Here, you are the memory manager. The null terminator is your god.
    // One wrong move, and you're in the shadow realm of undefined behavior.
    //=========================================================================//
    std::cout << "\n\n---[ PART I: The C-String (The Ways of the Ancients) ]---\n";
    std::cout << "      (Here be dragons, buffer overflows, and despair)\n";
    std::cout << "---------------------------------------------------------\n";

    // --- 1.1 Declaration: Forging our weapon ---
    std::cout << "\n  [1.1] Declaration & Initialization:\n";
    const char str1[] = "hey,"; // An array of chars. It knows its own size at compile time. It is finite, mortal.
    const char* str2 = " there"; // A pointer to a string literal. A mysterious stranger. It doesn't know its length, it just points and prays it finds a '\0' before trespassing memory.
    std::cout << "    - str1 (char[]): \"" << str1 << "\"\n";
    std::cout << "    - str2 (char*):  \"" << str2 << "\"\n";

    // --- 1.2 Accessing: Staring into the void ---
    std::cout << "\n  [1.2] Accessing the Characters:\n";
    // The easy way, lulling you into a false sense of security.
    std::cout << "    - Direct Output: " << str1 << str2 << "\n";
    // The hard way: marching through the array, character by character, like a prisoner on a death march.
    std::cout << "    - Classic Loop:  ";
    for (size_t i = 0; i < std::strlen(str1); ++i) { // strlen() recalculates the length EVERY. SINGLE. TIME. Beautifully inefficient.
        std::cout << str1[i];
    }
    std::cout << "\n";
    // Pointer arithmetic. The way our ancestors did it, by candlelight, while fighting off pterodactyls.
    std::cout << "    - Pointer Walk:  ";
    for (const char* it = str2; *it != '\0'; ++it) { // We walk until we hit the null terminator, the abyss at the end of the string.
        std::cout << *it;
    }
    std::cout << "\n";

    // --- 1.3 Size: The physical vs. the metaphysical ---
    std::cout << "\n  [1.3] Size vs. Length:\n";
    // `size` includes the null terminator. It's the physical space the string occupies in memory.
    std::cout << "    - std::size(str1):   " << std::size(str1) << " (The body, including the soul-sucking '\\0'.)\n";
    // `strlen` does NOT include the null terminator. It's the string's perceived length. Its ego.
    std::cout << "    - std::strlen(str1): " << std::strlen(str1) << " (The personality, excluding the void.)\n";

    // --- 1.4 Manipulation: Dangerous rituals ---
    std::cout << "\n  [1.4] Copying and Splicing (The Dark Arts):\n";
    const char* source = "I am so tired!";
    char dest[50]; // A buffer. A sacrificial altar. We pray it's big enough.

    // strcpy: No bounds checking. Just pure, unadulterated trust. What could possibly go wrong?
    std::strcpy(dest, source);
    std::cout << "    - strcpy: Copied \"" << source << "\" into dest -> \"" << dest << "\"\n";

    // strncpy: The "safer" cousin that often forgets the null terminator if the source is too long.
    // It tries to help, but often just creates new, more interesting problems.
    char partial_dest[10];
    std::strncpy(partial_dest, source + 5, 9); // copy "so tired!"
    partial_dest[9] = '\0'; // MANUALLY add the null terminator or face eternal damnation.
    std::cout << "    - strncpy: Copied a piece -> \"" << partial_dest << "\"\n";

    // strcat: Appending by faith. Again, no safety net. Just vibes and the hope you don't overwrite reality.
    char name[50] = "Lana ";
    std::strcat(name, "is my name.");
    std::cout << "    - strcat: Appended to 'Lana ' -> \"" << name << "\"\n";

    // --- 1.5 Comparison: Trial by combat ---
    std::cout << "\n  [1.5] Comparison:\n";
    // strcmp returns 0 if they are equal. Because in C, 0 means "no difference," which is success. Perfectly intuitive.
    if (std::strcmp("Alan", "Alan") == 0) {
        std::cout << "    - strcmp: \"Alan\" is equal to \"Alan\". Of course.\n";
    }
    if (std::strncmp("Adam", "Alan", 1) == 0) {
        std::cout << "    - strncmp: The first character of \"Adam\" and \"Alan\" is the same. A shallow victory.\n";
    }


    //=========================================================================//
    // PART II: The std::string - Safety, Sanity, and Soullessness
    // This is the modern way. The memory manages itself. It's convenient.
    // It's comfortable. It's for people who have lost the will to suffer.
    //=========================================================================//
    std::cout << "\n\n---[ PART II: The std::string (The Modern Sanitarium) ]---\n";
    std::cout << "      (Objects, methods, and a suspicious lack of segfaults)\n";
    std::cout << "-----------------------------------------------------------\n";

    // --- 2.1 Declaration: Less prayer, more syntax ---
    std::cout << "\n  [2.1] Declaration & Initialization:\n";
    std::string text1 = "Hello, There!";
    std::string text2("My name is Sam!");
    std::string text3(10, '='); // A string made of 10 '=' characters. A wall of mediocrity.
    std::cout << "    - text1: \"" << text1 << "\"\n";
    std::cout << "    - text2: \"" << text2 << "\"\n";
    std::cout << "    - text3: \"" << text3 << "\"\n";

    // --- 2.2 Accessing: Safe and predictable ---
    std::cout << "\n  [2.2] Accessing the Characters:\n";
    std::cout << "    - text1[3]:   " << text1[3] << " (The C-style way, fast and reckless.)\n";
    std::cout << "    - text1.at(3): " << text1.at(3) << " (The C++ way, it screams if you hurt it.)\n";
    std::cout << "    - .front():   " << text1.front() << ", .back(): " << text1.back() << " (Convenient, isn't it?)\n";
    // The iterator loop, as requested. For those who miss the raw feeling of pointers but want the C++ safety blanket.
    // It's like wearing full plate armor to a pillow fight.
    std::cout << "    - Iterator Loop: ";
    for (auto it = text1.begin(); it != text1.end(); ++it) {
        std::cout << *it;
    }
    std::cout << "\n";

    // --- 2.3 Size & Capacity: An object's introspection ---
    std::cout << "\n  [2.3] Size, Capacity, and other Navel-Gazing:\n";
    std::cout << "    - .size()/.length(): " << text1.size() << " (It knows its own length. How arrogant.)\n";
    std::cout << "    - .capacity():       " << text1.capacity() << " (The space it's hoarding.)\n";
    std::cout << "    - .max_size():       " << text1.max_size() << " (Another threat.)\n";
    text1.reserve(300); // Pre-allocating room for future pain.
    std::cout << "    - After .reserve(300), capacity is now: " << text1.capacity() << "\n";
    text1.shrink_to_fit(); // Releasing its baggage. A spiritual cleanse.
    std::cout << "    - After .shrink_to_fit(), capacity is now: " << text1.capacity() << "\n";

    // --- 2.4 Modification: Civilized alteration ---
    std::cout << "\n  [2.4] Modification (No manual labor required):\n";
    std::string mod_me = "Mutate";
    std::cout << "    - Original: " << mod_me << "\n";
    mod_me.push_back('d'); // Add a character. Simple.
    std::cout << "    - push_back('d'): " << mod_me << "\n";
    mod_me.pop_back(); // Remove it. No tears shed.
    std::cout << "    - pop_back(): " << mod_me << "\n";
    mod_me.insert(6, " Me"); // Insert a string. It just... works.
    std::cout << "    - insert(6, \" Me\"): " << mod_me << "\n";
    mod_me += " Please"; // Append with an operator. The sheer luxury.
    std::cout << "    - += \" Please\": " << mod_me << "\n";
    std::string piece = mod_me.substr(0, 6); // Carve out a piece of its soul.
    std::cout << "    - substr(0, 6): " << piece << "\n";

    // --- 2.5 Conversion: Bridging the two worlds ---
    std::cout << "\n  [2.5] Conversion: A Dialogue With the Past:\n";
    // It gives you a POINTER. A read-only one. It's like being shown a priceless artifact that you're not allowed to touch.
    const char* c_str_view = text2.c_str();  // Guaranteed to be null-terminated. A sacred promise.
    const char* data_view = text2.data();    // Also null-terminated since C++11. Before that? A gamble. A beautiful, dangerous gamble where it might not be.
    
    std::cout << "    - text2.c_str() gives us a view: \"" << c_str_view << "\"\n";
    std::cout << "    - text2.data()  also gives a view: \"" << data_view << "\" (Today, it's safe. In 2003, it lived on the edge.)\n";

    // Now, for the final lesson in pain: copying that C-string view into a buffer you control.
    char my_c_buffer[50];
    // The WRONG way, the way of madness, is to strcat to an uninitialized buffer.
    // std::strcat(my_c_buffer, text2.c_str()); // <-- THIS IS A PORTAL TO HELL. DO NOT OPEN.

    // The RIGHT way is to COPY first, then you can append.
    std::strcpy(my_c_buffer, text2.c_str()); // We use the blessed c_str() for the ritual.
    std::cout << "    - Properly copied into a C-buffer: \"" << my_c_buffer << "\"\n";


    std::cout << "\n***********************************************************\n";
    std::cout << "      You have survived. You are now enlightened.           \n";
    std::cout << "      Go forth and sin no more (with C-strings).            \n";
    std::cout << "***********************************************************\n";

    // We return 0, pretending this was a successful and painless experience.
    return 0;
}

