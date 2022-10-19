add_executable(shell-app main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# INCLUDE OPENCV DIRECTORIES
include_directories( 
    ${OpenCV_INCLUDE_DIRS})

# LINK LIBRARIES 
TARGET_LINK_LIBRARIES(
    shell-app ${OpenCV_LIBS})