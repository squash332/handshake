cmake_minimum_required(VERSION 3.14)
include(cmake/prelude.cmake)

project(
    handshake
    VERSION 0.1.0
    DESCRIPTION "A game about my engineering journey"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Fetch dependencies ----
include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

# ---- Declare library ----
add_library(
    handshake_lib OBJECT
    source/game.cpp
)

target_include_directories(
    handshake_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(handshake_lib PUBLIC cxx_std_17)
target_link_libraries(handshake_lib PUBLIC raylib)

# ---- Declare executable ----
add_executable(handshake_exe source/main.cpp)
add_executable(handshake::exe ALIAS handshake_exe)

set_property(TARGET handshake_exe PROPERTY OUTPUT_NAME handshake)
target_compile_features(handshake_exe PRIVATE cxx_std_17)
target_link_libraries(handshake_exe PRIVATE handshake_lib)

# ---- Install rules ----
if(NOT CMAKE_SKIP_INSTALL_RULES)
    include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----
if(NOT handshake_DEVELOPER_MODE)
    return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
    message(
        AUTHOR_WARNING
        "Developer mode is intended for developers of handshake"
    )
endif()

include(cmake/dev-mode.cmake)