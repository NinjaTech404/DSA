# => Setting Cmake Versions
cmake_minimum_required(VERSION 3.10...4.1.2)

message("-- => cmake version set to (3.10 <=> 4.1.2)!")

# => Peoject Details
project(
  My_DSA_Project
  DESCRIPTION "A C++ REPO for studying Data Structures and Algorithms."
  VERSION 1.0.0
  LANGUAGES CXX
)

message("-- => project details set => (A C++ REPO for...)!")

# => Setting C++ Compiler Details
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

message("-- => c++ compiler details set!")

# => Project CodeBase Structure
set(MAIN ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_executable(main ${MAIN})


include_directories(${CMAKE_SOURCE_DIR}/src) # Source Directory
include_directories(${CMAKE_SOURCE_DIR}/src/DS/node) # Node Data Structure Header
include_directories(${CMAKE_SOURCE_DIR}/src/DS/array) # C++ Style Array Data Structure Header
include_directories(${CMAKE_SOURCE_DIR}/src/Algorithms/Heap) # Heap Sorting Algorithms

message("-- => project codebase structure set!")

# => Setting a target "run" for excuting the binary "main"
add_custom_target(
  run
  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/main
  DEPENDS main
  COMMENT "executing the target..."
)

message("-- => target generated, named => (run)!")

# => Enabling the testing feature (ctest) for this project
enable_testing()
add_test(
  NAME MAIN_DSA_TESTS
  COMMAND $<TARGET_FILE:main>
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

message("-- => testing feature enabled, named => (MAIN_DSA_TESTS)!")

# => Enabling the packaging feature
include(CPack)

message("-- => packaging feature enabled!")

