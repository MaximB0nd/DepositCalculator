cmake_minimum_required(VERSION 3.5)
project(YourProjectName)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Ищем пакет Qt (версия 6 или 5)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        DepositCalculator.h)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Widgets
)