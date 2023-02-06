# CMake instructions to make the static lib

ADD_LIBRARY(MyStaticLib STATIC
        src/window.c)


# CMake instructions to test using the static lib

SET(APP_EXE StaticTest)

ADD_EXECUTABLE(${APP_EXE}
        unit_tests/main.c)

TARGET_LINK_LIBRARIES(${APP_EXE}
        MyStaticLib)