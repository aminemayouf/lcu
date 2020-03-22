cmake_minimum_required (VERSION 3.8)

project ("DataStructures" VERSION 0.1)

# Add source to project's executable.
file(GLOB DATA_STRUCTURES_SRC
    "*.cpp"
)
add_library(${PROJECT_NAME} ${DATA_STRUCTURES_SRC})

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
file(GLOB DATA_STRUCTURES_H
    "*.h"
)
install(FILES
    ${DATA_STRUCTURES_H}
    DESTINATION include)
