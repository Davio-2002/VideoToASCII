cmake_minimum_required(VERSION 3.30)
project(VideoToASCII)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${headers} src)

add_executable(VideoToASCII

        main.cpp
        src/FrameProcessor.cpp
        headers/FrameProcessor.h
        headers/UniversalAsciiConverter.h
        headers/UniversalReader.h
)

target_link_libraries(VideoToASCII ${OpenCV_LIBS})
