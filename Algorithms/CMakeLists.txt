cmake_minimum_required(VERSION 3.8)

project("Algorithms" VERSION 0.1)

# Add source to project's executable.
file(GLOB Algorithms_SRC
    "*.cpp"
)
list(FILTER Algorithms_SRC EXCLUDE REGEX "./Encoding.cpp$")
if(USE_DATASTRUCTURES)
    list(APPEND Algorithms_SRC "Encoding.cpp")
endif()

add_library(${PROJECT_NAME} ${Algorithms_SRC})

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
file(GLOB Algorithms_H
    "*.h"
)
list(FILTER Algorithms_H EXCLUDE REGEX "./Encoding.h$")
if(USE_DATASTRUCTURES)
    list(APPEND Algorithms_H "Encoding.h")
endif()

install(FILES
    ${Algorithms_H}
    DESTINATION include)
