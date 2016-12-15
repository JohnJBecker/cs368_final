cmake_minimum_required(VERSION 3.6)
project(cs368_project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    Ingredient.cpp
    Ingredient.hpp
    main.cpp
    Recipe.cpp
    Recipe.hpp)

add_executable(cs368_project ${SOURCE_FILES})