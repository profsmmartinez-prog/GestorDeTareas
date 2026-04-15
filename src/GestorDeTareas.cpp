// GestorDeTareas.cpp: define el punto de entrada de la aplicación.
// Generar un Gestor de Tareas
//
#include <iostream>
#include "Gestor.h"

int main()
{
	Task Nuevo("Aprender C++");

	std::cout << Nuevo.getNom() << " | " << Nuevo.getEstado();
}
