add_executable(shell-app main.cpp HumanClassifier.cpp HumanDetector.cpp 
PerceptionModule.cpp ReadData.cpp RectsandConfidences.cpp Transformation.cpp  )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)


# LINK LIBRARIES 
TARGET_LINK_LIBRARIES(
    shell-app ${OpenCV_LIBS})