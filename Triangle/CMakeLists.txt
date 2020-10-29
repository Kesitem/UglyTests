cmake_minimum_required(VERSION 3.12)

project(Triangle VERSION 1.0
                  DESCRIPTION "Draw a triangle with vulkan"
                  LANGUAGES CXX)

# Create library
add_executable(${PROJECT_NAME} main.cpp)

# Set C++17 feature
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE UglyEngine)
