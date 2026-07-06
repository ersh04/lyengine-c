cmake_minimum_required(VERSION 3.10)
project(c-project C)

add_executable(c-project
	 src/main.c
	src/engine/entity/entity.c
	src/engine/math/vectors/vector2.c
	src/engine/scene/scene.c
	src/utils/json/json_loader.c
	src/utils/json/json_parser.c
)
target_include_directories(c-project PRIVATE include)
target_link_libraries(c-project PRIVATE cjson)
