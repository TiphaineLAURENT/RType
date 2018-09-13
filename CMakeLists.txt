cmake_minimum_required(VERSION 3.12)
project(R_type)

set(CMAKE_CXX_STANDARD 17)
if (UNIX)
    list(APPEND CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules")
elseif(WIN32)
    list(APPEND CMAKE_MODULE_PATH "c:/SFML/cmake/Modules")
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SOURCE_FILES src/RType.cpp src/RType.hpp src/RessourcesManager.cpp src/RessourcesManager.hpp src/EventManager.cpp src/EventManager.hpp src/Object.cpp src/Object.hpp src/Character.cpp src/Character.hpp src/Player.cpp src/Player.hpp src/Event.cpp src/Event.hpp src/Displayable.cpp src/Displayable.hpp src/Colisable.cpp src/Colisable.hpp src/Projectile.cpp src/Projectile.hpp src/Enemy.cpp src/Enemy.hpp src/WorldBorder.cpp src/WorldBorder.hpp src/Menu.cpp src/Menu.hpp src/Option.cpp src/Option.hpp src/Hearts.cpp src/Hearts.hpp)
add_executable(RType main.cpp ${SOURCE_FILES})

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(RType ${SFML_LIBRARIES})
endif()

set_target_properties(RType PROPERTIES LINKER_LANGUAGE CXX)
