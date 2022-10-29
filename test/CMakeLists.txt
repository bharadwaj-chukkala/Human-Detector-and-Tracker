set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test_ReadData.cpp
    ../app/ReadData.cpp
    test_HumanClassifier.cpp
    ../app/HumanClassifier.cpp
    test_HumanDetector.cpp
    ../app/HumanDetector.cpp
    test_PerceptionModule.cpp
    ../app/PerceptionModule.cpp
    test_RectsandConfidences.cpp
    ../app/RectsandConfidences.cpp
    test_Transformation.cpp
    ../app/Transformation.cpp



)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

include_directories(
    ${CMAKE_SOURCE_DIR}/app
)
