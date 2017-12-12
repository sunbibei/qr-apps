cmake_minimum_required(VERSION 2.8.3)
project(qr_apps)

add_definitions(-std=c++11)
# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  roscpp

  controller_manager
  hardware_interface
  qr_driver
  qr_next_control
)

# Declare a catkin package
catkin_package(
  LIBRARIES
  INCLUDE_DIRS
    include
  DEPENDS
    roscpp
)

###########
## Build ##
###########

# Build
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

set(SRC_ROOT            src)
set(SRC_EXAMPLES        examples/src)

set(SRC_APP             ${SRC_ROOT}/apps)

# Files define.
set(BIN_FILES           ${SRC_ROOT}/main.cpp
                        ${SRC_APP}/ros_robothw.cpp
                        ${SRC_APP}/ros_wrapper.cpp
)

set(EX_FILES            ${SRC_EXAMPLES}/qr_driver_test.cpp
                        ${SRC_EXAMPLES}/qr_driver_test2.cpp
                        ${SRC_EXAMPLES}/qr_driver_test3.cpp
)

## Declare a C++ library
add_library(${PROJECT_NAME}_test_lib
  ${EX_FILES}
)

## Declare a C++ executable
add_executable(${PROJECT_NAME}
  ${BIN_FILES}
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}_test_lib
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  qr_driver_sys_robot
  qr_next_control_framwork
)

#############
## Install ##
#############

install(DIRECTORY include/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

install(TARGETS ${PROJECT_NAME}
                ${PROJECT_NAME}_test_lib
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

foreach(dir include launch config)
  install(DIRECTORY ${dir}/
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
