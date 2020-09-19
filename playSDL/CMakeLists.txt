cmake_minimum_required(VERSION 3.10)
project(PlaySDL)

set(CMAKE_CXX_STANDARD 11)
set(SDL_DIR /usr/local/Cellar/sdl2/2.0.9_1/) # 这个SDL开发包的路径，可以通过brew info sdl2查出来
include_directories(${SDL_DIR}/include/) # 添加SDL头文件搜索路径
link_libraries(${SDL_DIR}/lib/) # 增加SDL链接库目录

add_executable(PlaySDL main.cpp)

target_link_libraries(PlaySDL SDL2 SDL2_test SDL2main) # 链接目标库
