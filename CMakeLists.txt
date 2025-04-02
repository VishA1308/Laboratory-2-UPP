# Установить минимальную версию CMake
cmake_minimum_required(VERSION 3.24.2)

# Название проекта и язык
project(testproj VERSION 0.1 LANGUAGES CXX)


# Загрузка Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Для Windows: предотвращение переопределения настроек компилятора/линковщика родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
enable_testing()

# Добавление исполняемого файла для основного приложения
add_executable(testproj main.cpp candle.cpp candle.h)


# Линковка с Google Test
target_link_libraries(testproj PRIVATE GTest::gtest_main)

# Включение Google Test для автоматического обнаружения тестов
include(GoogleTest)
gtest_discover_tests(testproj)
