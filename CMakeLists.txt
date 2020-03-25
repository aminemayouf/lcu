cmake_minimum_required (VERSION 3.8)

project ("LCU" VERSION 0.2)

option(USE_ALGORITHMS "Use algorithms sub-module" ON)
option(USE_data_structures "Use data structures sub-module" ON)
option(USE_EVENTS "Use events sub-module" ON)
option(USE_INTERFACES "Use interfaces sub-module" ON)
option(USE_SYSTEM "Use system sub-module" ON)

configure_file(Config.h.in Config.h)

# Include sub-projects.
if(USE_ALGORITHMS)
    add_subdirectory ("algorithms")
    list(APPEND EXTRA_LIBS Algorithms)
endif()
if(USE_data_structures)
    add_subdirectory ("data_structures")
    list(APPEND EXTRA_LIBS data_structures)
endif()
if(USE_EVENTS)
    add_subdirectory ("events")
    list(APPEND EXTRA_LIBS Events)
endif()
if(USE_INTERFACES)
    add_subdirectory ("interfaces")
    list(APPEND EXTRA_LIBS Interfaces)
endif()
if(USE_SYSTEM)
    add_subdirectory ("system")
    list(APPEND EXTRA_LIBS System)
endif()

# Add source to project's executable.
add_executable (${PROJECT_NAME}
    "main.cpp")

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find Config.h
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h"
  DESTINATION include
  )
