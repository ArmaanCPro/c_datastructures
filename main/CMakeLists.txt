cmake_minimum_required(VERSION 3.28)

project(main)

if (MSVC)
	add_compile_options(/MP)
	add_compile_options(/W4 /wd4201 /WX)
else()
	add_compile_options(-W -Wall -Werror)
endif()

set (SOURCES
	"src/main.c"
	"src/linkedlist.h"
	)

source_group("src" FILES ${SOURCES})

add_executable(main ${SOURCES})
