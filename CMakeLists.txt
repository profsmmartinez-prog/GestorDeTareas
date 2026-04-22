# CMakeList.txt: proyecto de CMake para GestorDeTareas, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.10)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Programa")
##include_directories(includ libs)
add_library(libreria src/Gestor.cpp src/Tarea.cpp) # (Nom de Variable "Espacio" Archivos.cpp que estaran dentro del modulo)
target_include_directories(libreria PUBLIC includ) # (Nom de Variable "Espacio" Publico/Privado Directorio donde se encuentran los .h/.hpp)

#find_package()
include_directories(libs)

# Agregue un origen al ejecutable de este proyecto.
add_executable (Programa "src/GestorDeTareas.cpp")

target_link_libraries(Programa PRIVATE libreria)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Programa PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
#