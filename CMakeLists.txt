cmake_minimum_required(VERSION 3.10)
project(lyengine-c C)

add_executable(lyengine-c
	 src/main.c
	src/engine/entity/entity.c
	src/engine/math/vectors/vector2.c
	src/engine/scene/scene.c
	src/utils/json/json_loader.c
	src/utils/json/json_parser.c
)
target_include_directories(lyengine-c PRIVATE include)
target_link_libraries(lyengine-c PRIVATE cjson)
