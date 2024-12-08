cmake_minimum_required(VERSION 3.30)
project(VideoToASCII)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories( include )

add_executable(VideoToASCII main.cpp
        src/PixelToAsciiConverter.cpp
        src/VideoProcessor.cpp
        src/FrameProcessor.cpp
        src/AsciiRenderer.cpp)

target_link_libraries(VideoToASCII ${OpenCV_LIBS})
