# Get Catch2
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests
    testMain.cpp
    testPPM.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2)
target_link_libraries(tests PUBLIC ppm)

target_include_directories(tests PUBLIC ../include)