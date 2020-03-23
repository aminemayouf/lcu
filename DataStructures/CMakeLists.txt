cmake_minimum_required(VERSION 3.8)

project("DataStructures" VERSION 0.1)

# Add source to project's executable.
file(GLOB DataStructures_SRC
    "*.cpp"
)
add_library(${PROJECT_NAME} ${DataStructures_SRC})

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
file(GLOB DataStructures_H
    "*.h"
)
install(FILES
    ${DataStructures_H}
    DESTINATION include)
