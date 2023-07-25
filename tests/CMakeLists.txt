# CMakeLists.txt in the tests directory
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)


# Add the test source files using GLOB_RECURSE
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true 
  "*.cpp"
)

# Define the test target (e.g., 'tests' executable)
add_executable(Grind75Tests ${TEST_SOURCES})

# Link the Catch2 library to the test target
target_link_libraries(Grind75Tests PRIVATE Catch2::Catch2WithMain)

# Include the 'src' directory to access header files from there
target_include_directories(Grind75Tests PUBLIC ${CMAKE_SOURCE_DIR}/src)
