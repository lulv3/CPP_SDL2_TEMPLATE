cmake_minimum_required(VERSION 3.10)

# Projektname festlegen
project(SDL2Game)

# C++ Standard auf 11 setzen
set(CMAKE_CXX_STANDARD 11)

# SDL2 Konfiguration
set(SDL2_DIR "third_party/SDL2-2.30.1")

# Include-Verzeichnisse hinzufügen
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    "third_party/SDL2-2.30.1/include"
)

# Quelldateien festlegen
file(GLOB SOURCES "src/*.cpp")

# Ausführbare Datei erstellen
add_executable(${PROJECT_NAME} ${SOURCES})

# Setze das Subsystem auf Windows, um die Konsole zu verstecken
if(WIN32)
    set_target_properties(SDL2Game PROPERTIES WIN32_EXECUTABLE true)
endif()

# Verknüpfen der SDL2-Bibliotheken
target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/third_party/SDL2-2.30.1/lib/x64/SDL2.lib" "${PROJECT_SOURCE_DIR}/third_party/SDL2-2.30.1/lib/x64/SDL2main.lib")
