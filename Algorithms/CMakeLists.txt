cmake_minimum_required (VERSION 3.8)

project ("Algorithms" VERSION 0.1)

# Add source to project's executable.
add_library(${PROJECT_NAME}
    "Algorithms.cpp"
    "Conversion.cpp"
#    "Encoding.cpp"
    "Encryption.cpp"
    "Searching.cpp"
    "Sorting.cpp"
    "Utility.cpp"
    "Validation.cpp")

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS Algorithms DESTINATION lib)
install(FILES
    "Conversion.h"
#    "Encoding.h"
    "Encryption.h"
    "Searching.h"
    "Sorting.h"
    "Utility.h"
    "Validation.h"
    DESTINATION include)
