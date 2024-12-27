cmake_minimum_required(VERSION 3.10)
project(lab2_v6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized -fsanitize=address -g")

# Указание директории с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/include)

# Добавление библиотек
add_library(Arguments src/Arguments.cpp)
add_library(Row_Or_Line src/Row_Or_Line.cpp)
add_library(some_functions src/some_functions.cpp)

# для main.cpp
add_executable(main main.cpp)
target_link_libraries(main Arguments Row_Or_Line some_functions)

# для benchmark.cpp
add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark Arguments Row_Or_Line some_functions)