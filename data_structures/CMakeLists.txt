cmake_minimum_required(VERSION 3.8)

project("data_structures" VERSION 0.1)

# Add source to project's executable.
file(GLOB data_structures_SRC
    "*.cpp"
)
add_library(${PROJECT_NAME} ${data_structures_SRC})

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
file(GLOB data_structures_H
    "*.h"
)
install(FILES
    ${data_structures_H}
    DESTINATION include)
