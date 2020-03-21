cmake_minimum_required (VERSION 3.8)

project ("Events" VERSION 0.1)

# Add source to project's executable.
add_library(${PROJECT_NAME}
    "AEventHandler.cpp"
    "Event.cpp"
    "EventHandler.cpp"
    "EventHandlerForMemberFunctions.cpp"
    "EventHandlerForNonMemberFunctions.cpp")

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES
    "AEventHandler.h"
    "Event.h"
    "EventHandler.h"
    "EventHandlerForMemberFunctions.h"
    "EventHandlerForNonMemberFunctions.h"
    DESTINATION include)
