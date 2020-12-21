cmake_minimum_required(VERSION 3.1)
project(formal_languages_second_practicum)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/bin")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(formal_languages_second_practicum main.cpp ContextFreeGrammar.cpp Early.cpp)
enable_testing()
add_executable(Test tests.cpp ContextFreeGrammar.cpp Early.cpp)

target_link_libraries(Test Threads::Threads ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})
set(CMAKE_EXE_LINKER_FLAGS --coverage)
target_link_libraries(Test -fprofile-arcs)
install (
        TARGETS Test
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
)

install (
        TARGETS formal_languages_second_practicum
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
)