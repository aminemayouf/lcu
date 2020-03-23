cmake_minimum_required(VERSION 3.8)

project("Events" VERSION 0.1)

# Add source to project's executable.
file(GLOB Events_SRC
    "*.cpp"
)
add_library(${PROJECT_NAME} ${Events_SRC})

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
file(GLOB Events_H
    "*.h"
)
install(FILES
    ${Events_H}
    DESTINATION include)
