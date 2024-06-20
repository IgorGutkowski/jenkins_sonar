cmake_minimum_required(VERSION 3.10)

project(CPPPyramid)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ustawienia dla Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Pliki źródłowe
add_library(pyramid_lib src/pyramid.cpp)
target_include_directories(pyramid_lib PUBLIC include)

# Plik wykonywalny
add_executable(main src/main.cpp)
target_link_libraries(main pyramid_lib)

# Testy
add_executable(pyramid_test tests/test_pyramid.cpp)
target_link_libraries(pyramid_test GTest::GTest GTest::Main pyramid_lib)
add_test(NAME pyramid_test COMMAND pyramid_test)
