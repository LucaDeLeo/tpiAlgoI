cmake_minimum_required(VERSION 3.5)
project(juegoDeLaVida)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES_TEST
        main.cpp
        ejercicios.cpp
        auxiliares.cpp
	tests/EJ01_toroideValidoTEST.cpp
	tests/EJ02_posicionesVivasTEST.cpp
	tests/EJ03_densidadPoblacionTEST.cpp
	tests/EJ04_evolucionDePosicionTEST.cpp
	tests/EJ05_evolucionToroideTEST.cpp
	tests/EJ06_evolucionMultipleTEST.cpp
	tests/EJ07_esPeriodicoTEST.cpp
	tests/EJ08_primosLejanosTEST.cpp
	tests/EJ09_seleccionNaturalTEST.cpp
	tests/EJ10_fusionarTEST.cpp
	tests/EJ11_vistaTrasladadaTEST.cpp
	tests/EJ12_menorSuperficieVivaTEST.cpp
        )
add_executable(juegoDeLaVida ${SOURCE_FILES_TEST})

target_link_libraries(juegoDeLaVida gtest gtest_main)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# -g: Hace que podamos debuggear el programa.
# --coverage: Hace que se pueda calcular el cubrimiento de los casos de test.
set(CMAKE_CXX_FLAGS "-g --coverage")
# Un temita de gcov que no se lleva tan bien con CMake,
# y entonces hay que poner esta línea.
# Para más información, ver https://texus.me/2015/09/06/cmake-and-gcov/.
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
