cmake_minimum_required(VERSION 3.5)
project(YourProjectName)

# Настройка Qt
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)  # Включить обработку мета-объектов

# Ищем пакет Qt (версия 6 или 5)
find_package(Qt6 COMPONENTS Widgets REQUIRED)  # Для Qt6
# ИЛИ для Qt5:
# find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp
        DepositCalculator.h)



# Подключаем библиотеки
target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Widgets  # Для Qt6
        # Qt5::Widgets # Для Qt5
)