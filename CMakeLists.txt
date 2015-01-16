#MESSAGE("PROJECT_NAME=${PROJECT_NAME}")
#MESSAGE("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
#MESSAGE("PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")
#MESSAGE("CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
#MESSAGE("CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")

cmake_minimum_required (VERSION 2.6)

project (GPIOSQLDaemon)

set (GPIOSQLDaemon_VERSION 1)

set (CMAKE_CXX_FLAGS "-std=c++11")

configure_file (
  "${PROJECT_SOURCE_DIR}/GPIOSQLDaemon.h.in"
  "${PROJECT_BINARY_DIR}/GPIOSQLDaemon.h"	
  )
  
include_directories("${PROJECT_BINARY_DIR}")

add_executable(gpiosqldaemon ../source/daemon.c)

#add_executable(gpio_test ../source/gpio_test/gpio_test.cpp)


find_package( RpiHw )

if ( RpiHw_FOUND )

    # Set the path to the header files
    include_directories( ${RpiHw_INCLUDE_DIRS} )

    # Compile the project
    add_executable( gpio_test ${CMAKE_SOURCE_DIR}/source/gpio_test/gpio_test.cpp)

    # Link the library to the project
    target_link_libraries( gpio_test ${RpiHw_LIBRARIES} )

endif()



#install (FILES GPIOSQLDaemon.h DESTINATION include)  
#install (TARGETS gpiosqldaemon DESTINATION bin)

