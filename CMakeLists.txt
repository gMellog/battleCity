cmake_minimum_required(VERSION 3.14)
project(battleCity)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SOURCE ${CMAKE_SOURCE_DIR}/src/)

add_executable(battle_city
               ${SOURCE}main.cpp
               ${SOURCE}Game.cpp
               ${SOURCE}Player.cpp
               ${SOURCE}InvisibleWall.cpp
               ${SOURCE}Bullet.cpp
               ${SOURCE}Actor.cpp
               ${SOURCE}Brick.cpp
               ${SOURCE}Stone.cpp
               ${SOURCE}Base.cpp
               ${SOURCE}LevelCreator.cpp
  )

set_target_properties(battle_city
                      PROPERTIES
                      CXX_STANDARD 14
                      CXX_STANDARD_REQUIRED ON
)

target_include_directories(battle_city
			   PRIVATE
			   ${CMAKE_SOURCE_DIR}/inc/
)

target_link_libraries(battle_city
                      sfml-graphics
                      sfml-audio
)
