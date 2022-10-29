set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test_ReadData.cpp
    test_HumanClassifier.cpp
    test_HumanDetector.cpp
    test_PerceptionModule.cpp
    test_RectsandConfidences.cpp
    test_Transformation.cpp



)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
