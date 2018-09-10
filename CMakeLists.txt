cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_SUPPRESS_REGENERATION true) 

project (Project_Dynamite)

# Main engine files

file(GLOB MAIN "dynamite/*.cpp" "dynamite/*.h" )
file(GLOB GAME "game/*.cpp" "game/*.h") 
file(GLOB COMPONENT "dynamite/component/*.h" "dynamite/component/*.cpp")
file(GLOB EVENT "dynamite/event/*.h" "dynamite/event/*.cpp")

# Includes
set(SDL2_DIR "external/SDL2")
set(JH_Essentials_DIR "external/JH_Essentials")

include_directories(${SDL2_DIR}/include ${JH_Essentials_DIR}/include)
link_directories(${SDL2_DIR}/lib/x64 ${JH_Essentials_DIR}/lib/x64)

# Add Executable

add_executable(Project_Dynamite ${MAIN} ${GAME} ${COMPONENT} ${EVENT})

# Link libraries
target_link_libraries(Project_Dynamite SDL2 SDL2main JH_Essentials opengl32.lib)

# TODO: Set Commands

# Filter groups
source_group("dynamite" FILES ${MAIN})
source_group("game" FILES ${GAME})
source_group("component" FILES ${COMPONENT})
source_group("event" FILES ${EVENT})




