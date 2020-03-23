cmake_minimum_required(VERSION 3.8)

project("Interfaces" VERSION 0.1)

# Add source to project's executable.
file(GLOB Interfaces_SRC
    "*.cpp"
)
add_library(${PROJECT_NAME} ${Interfaces_SRC})

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
file(GLOB Interfaces_H
    "*.h"
)
install(FILES
    ${Interfaces_H}
    DESTINATION include)
