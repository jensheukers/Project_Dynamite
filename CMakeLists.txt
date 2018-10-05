#cmake . -DCMAKE_GENERATOR_PLATFORM=x64
cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_SUPPRESS_REGENERATION true) 

project (Project_Dynamite)

# Main engine files

file(GLOB MAIN "dynamite/*.cpp" "dynamite/*.h" )
file(GLOB GAME "game/*.cpp" "game/*.h") 
file(GLOB COMPONENT "dynamite/component/*.h" "dynamite/component/*.cpp")
file(GLOB EVENT "dynamite/event/*.h" "dynamite/event/*.cpp")
file(GLOB MATH "dynamite/math/*.h" "dynamite/math/*.cpp")

# Includes
set(SDL2_DIR "external/SDL2")
set(GLEW_DIR "external/glew")

include_directories(${SDL2_DIR}/include ${GLEW_DIR}/include)
link_directories(${SDL2_DIR}/lib/x64 ${GLEW_DIR}/lib/x64 ${SDL2_DIR}/lib/x86 ${GLEW_DIR}/lib/Win32)

# Add Executable

add_executable(Project_Dynamite ${MAIN} ${GAME} ${COMPONENT} ${EVENT} ${MATH})

set(CMAKE_CXX_FLAGS_RELEASE "/MD")
set(CMAKE_CXX_FLAGS_DEBUG "/MD")

# Link libraries
target_link_libraries(Project_Dynamite SDL2 SDL2main opengl32.lib glew32.lib glew32s.lib)

# TODO: Set Commands
add_custom_command(TARGET Project_Dynamite POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy
						${CMAKE_SOURCE_DIR}/SDL2.dll $<TARGET_FILE_DIR:Project_Dynamite>)

add_custom_command(TARGET Project_Dynamite POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy
						${CMAKE_SOURCE_DIR}/glew32.dll $<TARGET_FILE_DIR:Project_Dynamite>)
						
						
add_custom_command(TARGET Project_Dynamite POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E make_directory
						$<TARGET_FILE_DIR:Project_Dynamite>/resources)

add_custom_command(TARGET Project_Dynamite POST_BUILD 
					COMMAND ${CMAKE_COMMAND} -E copy_directory
						${CMAKE_SOURCE_DIR}/game/resources $<TARGET_FILE_DIR:Project_Dynamite>/resources)


# Filter groups
source_group("dynamite" FILES ${MAIN})
source_group("game" FILES ${GAME})
source_group("component" FILES ${COMPONENT})
source_group("event" FILES ${EVENT})
source_group("math" FILES ${MATH})




