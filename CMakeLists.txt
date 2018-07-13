cmake_minimum_required(VERSION 3.9)
project(untitled2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Menu.cpp Menu.h Dziura.cpp Dziura.h samochod.cpp samochod.h WindowGame.cpp WindowGame.h SmallView.cpp SmallView.h Numery.cpp Numery.h instrukcja.cpp instrukcja.h)
add_executable(untitled2 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(untitled2 ${SFML_LIBRARIES})
endif()