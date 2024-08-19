include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(unittests rational_tests.cpp ../src/rational.cpp
        polynom_test.cpp)
target_include_directories(unittests PRIVATE ../src)

target_link_libraries(unittests gtest_main)
include(GoogleTest)
gtest_discover_tests(unittests)