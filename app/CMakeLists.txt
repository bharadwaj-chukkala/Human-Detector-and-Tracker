add_executable(shell-app main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)


# LINK LIBRARIES 
TARGET_LINK_LIBRARIES(
    shell-app ${OpenCV_LIBS})