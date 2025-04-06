cmake_minimum_required(VERSION 3.10)
project(Timber)

set(CMAKE_CXX_STANDARD 17)

# set the SFML library path
set(SFML_DIR "~/")

# Define source and include directories
set(SRC_DIR src)
set(INCLUDE_DIR include)

# Include all source files (.cpp, .cc)
file(GLOB SOURCES CMAKE_CONFIGURE_DEPENDS
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.cc"
)

# Add include directory (for header file lookup)
include_directories(${INCLUDE_DIR})

# Find SFML libraries
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML libraires
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

# Set output directry for the built executable (bin folder)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
