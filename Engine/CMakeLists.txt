cmake_minimum_required(VERSION 3.12)

project(UglyEngine VERSION 0.0.1
                  DESCRIPTION "A simple game engine"
                  LANGUAGES CXX)

# Add plog 
find_path(PLOG_INCLUDE_DIRS "plog/Appenders/AndroidAppender.h")

# Add glfw
find_package(glfw3 CONFIG REQUIRED)

# Add Vulkan
find_package(Vulkan REQUIRED)

# Set sources files path
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/UglyEngine)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Configure version 
configure_file (
    "${INC_DIR}/Version.h.in"
    "${INC_DIR}/Version.h"
)

# List of header files
set(HEADERS
    UglyEngine.h
    Version.h
    Core.h
    Application.h
    Engine.h
)
# List of source files
set(SRCS
    LogFormatter.h
    LogFormatter.cpp
    Application.cpp
    Engine.cpp
)

# Generate filename with path
foreach(H ${HEADERS})
    list(APPEND ALL_HEADERS ${INC_DIR}/${H})
endforeach() 
foreach(S ${SRCS})
    list(APPEND ALL_SRCS ${SRC_DIR}/${S})
endforeach()

# Create library
add_library(${PROJECT_NAME} STATIC ${ALL_SRCS} ${ALL_HEADERS})

# Set C++17 feature
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Add libraries
target_link_libraries(${PROJECT_NAME} PUBLIC glfw Vulkan::Vulkan)

# Add directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PLOG_INCLUDE_DIRS})

# Set include directory for compilation
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include/UglyEngine)

# Set include directory for clients
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${INC_DIR}/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
    PRIVATE src)
