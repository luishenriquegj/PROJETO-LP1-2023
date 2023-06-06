cmake_minimum_required(VERSION 3.16.3)
Project(teste VERSION 0.1 LANGUAGES CXX)

include_directories (include)

add_executable (program
  src/main.cpp
  src/music.cpp
  src/playlist.cpp
  src/removeSongFromAll.cpp
  src/system.cpp
  src/compareLists.cpp
)
