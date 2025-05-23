cmake_minimum_required(VERSION 3.17)

project(SkydelExamplePlugins VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

if(NOT WIN32)
    set(CMAKE_CXX_COMPILER /usr/bin/g++-11 CACHE FILEPATH "GNU C++ compiler")
    set(Qt5_VERSION 5.15.2 CACHE STRING "Version of Qt5 you want to find")
    set(Qt5_ROOT /opt/Qt CACHE FILEPATH "Directory where you installed Qt5")
    set(Qt5_DIR "${Qt5_ROOT}/${Qt5_VERSION}/gcc_64/lib/cmake" CACHE FILEPATH "")
    list(APPEND CMAKE_PREFIX_PATH ${Qt5_DIR})
    set(PLUGIN_INSTALL_DIR "$ENV{HOME}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder where the plug-in examples are installed")
else()
    list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64/lib/cmake")
    set(PLUGIN_INSTALL_DIR "$ENV{HOMEPATH}/Documents/Skydel-SDX/Plug-ins" CACHE PATH "Define the destination folder where the plug-in examples are installed")
endif()

set(CMAKE_INSTALL_PREFIX ${PLUGIN_INSTALL_DIR})
set(CMAKE_INSTALL_LIBDIR .)

### Dependencies
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Skydel Plugins SDK
include(FetchContent)
FetchContent_Declare(
  SkydelPlugin
  GIT_REPOSITORY https://github.com/alexis-giraudet/skydel-plug-ins.git
  GIT_TAG        v25-4-0
)
FetchContent_MakeAvailable(SkydelPlugin)

# Example Plugins
add_subdirectory(source)
