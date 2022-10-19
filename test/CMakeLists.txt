set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../app/ReadData.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
