cmake_minimum_required (VERSION 3.8)

project ("Interfaces" VERSION 0.1)

# Add source to project's executable.
add_library(${PROJECT_NAME}
    "IArithmetic.cpp"
    "IClonable.cpp"
    "IComparable.cpp"
    "IComparer.cpp"
    "IContainer.cpp"
    "IForwardIterator.cpp"
    "IIterator.cpp"
    "IObservable.cpp"
    "IObserver.cpp"
    "IPrintable.cpp")

target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# Tests and install targets.
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES
    "IArithmetic.h"
    "IClonable.h"
    "IComparable.h"
    "IComparer.h"
    "IContainer.h"
    "IForwardIterator.h"
    "IIterator.h"
    "IObservable.h"
    "IObserver.h"
    "IPrintable.h"
    DESTINATION include)
