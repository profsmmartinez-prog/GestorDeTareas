# CMakeList.txt: proyecto de CMake para GestorDeTareas, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.15)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
project("Programa")

include(FetchContent)
FetchContent_Declare(nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git GIT_TAG v3.11.3)

FetchContent_MakeAvailable(nlohmann_json)

add_library(Libreria src/Gestor.cpp src/Tarea.cpp)
target_include_directories(Libreria PUBLIC includ)
#target_compile_features(Libreria Public CXX_STANDARD 20)
add_executable(app "src/GestorDeTareas.cpp")

target_link_libraries(app PRIVATE Libreria PRIVATE nlohmann_json::nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET app PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
#