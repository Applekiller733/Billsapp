cmake_minimum_required(VERSION 3.27)
project(test3ex)

set(CMAKE_CXX_STANDARD 17)

# Enable automatic generation of moc, uic, and rcc files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include the current source directory in the search path for include files
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the required Qt6 packages
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

# Add the executable target
add_executable(test3ex main.cpp
        Domain/Bill.cpp
        Domain/Bill.h
        Repository/Repository.cpp
        Repository/Repository.h
        GUI/GUI.cpp
        GUI/GUI.h)

# Link the target with the Qt6 libraries
target_link_libraries(test3ex Qt6::Core Qt6::Widgets)