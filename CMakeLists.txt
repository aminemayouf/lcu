cmake_minimum_required (VERSION 3.8)

project ("LCU" VERSION 0.1)

option(USE_ALGORITHMS "Use provided algorithms" ON)

configure_file(Config.h.in Config.h)

# Include sub-projects.
if(USE_ALGORITHMS)
    add_subdirectory ("Algorithms")
    list(APPEND EXTRA_LIBS Algorithms)
endif()

# Add source to project's executable.
add_executable (${PROJECT_NAME}
    "Main.cpp")

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find Config.h
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
