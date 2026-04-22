// GestorDeTareas.cpp: define el punto de entrada de la aplicación.
/*
* Desarrollar una aplicación de consola en C++ para la gestión de tareas, 
utilizando programación orientada a objetos, almacenamiento persistente en formato JSON 
y un sistema de compilación con CMake.
El programa debe permitir al usuario administrar una lista de tareas mediante un menú interactivo. 
Cada tarea estará representada por un título y un estado que indica si ha sido completada o no.
Requisitos funcionales
•	Clase Task
o	Representa una tarea individual.
o	Debe contener:	
	Un título (std::string).
	Un estado (bool) que indique si está completada.
o	Métodos:
	Obtener el título.
	Consultar si está completada.
	Marcarla como completada.
•	Clase TaskManager
o	Administra un conjunto de tareas almacenadas en un std::vector.
o	Funcionalidades:
	Agregar nuevas tareas.
	Listar todas las tareas mostrando su estado.
	Marcar una tarea como completada mediante su índice.
	Proporcionar acceso a la lista de tareas para su almacenamiento.
•	Persistencia de datos
o	Las tareas deben guardarse en un archivo tasks.json.
o	Al iniciar el programa:
	Se deben cargar las tareas existentes desde el archivo si este existe.
o	Al finalizar cada operación:
	Se debe actualizar el archivo JSON con el estado actual de las tareas.
o	Se utiliza la biblioteca nlohmann/json para la manipulación del archivo.
•	Interfaz de usuario (consola)
o	Mostrar un menú con las siguientes opciones:
	Listar tareas
	Agregar tarea
	Marcar tarea como hecha
	Salir
o	Validar opciones inválidas.
o	Permitir ingresar texto completo para el título de la tarea.
•	Sistema de construcción
o	Utilizar CMake para compilar el proyecto.
o	Incluir los archivos fuente (.cpp) y encabezados (.h).
o	Configurar el estándar de C++ (C++20).
*/

#include <iostream>
#include "Nlohmann/json.hpp"
#include "Gestor.h"
#include <fstream>

int main()
{
	//Task Nuevo("Aprender C++");
	Manager Gesto;
	int Opc=0, Num=0;
	std::string Nombre;

	nlohmann::json Datos; //Inicialmente esta null;
	std::ifstream Origen("Datos.json"); //Creamos la variable que abrira el archivo .json
	if (Origen.is_open()) {
		Origen >> Datos;
		/*
		* [
		{"Estados":false,"Nombre":"Aprender C++"},
		{"Estados":true,"Nombre":"Cenar"},
		{"Estados":false,"Nombre":"Aprender GitHub"}
		* ]
		*/
		for (auto& item : Datos) {
			Gesto.AgregarTarea(Task(item["Nombre"],item["Estados"]));
		}
		Origen.close();
	}

	do {
		std::cout << "=== GESTOR DE TAREAS === \n";
		std::cout << "1.- Mostrar Tareas\n 2.- Agregar Tareas. \n 3.- Cambiar estado. \n 4.- Salir\n";

		std::cin >> Opc;
		switch (Opc) {
			case 1:
				Gesto.Mostrar();
				break;
			case 2:
				std::cout << "Ingrese el Nombre de la tarea: \n";
				std::cin.ignore();
				std::getline(std::cin,Nombre);
				Gesto.AgregarTarea(Task(Nombre));
				break;
			case 3:
				Gesto.Mostrar();
				std::cout << "Ingrese el indice de la tarea a finalizar: \n";
				std::cin >> Num;
				Gesto.MarcarFin(Num-1);
				break;
			case 4:
				std::cout << "Saliendo...\n";
				break;
			default:
				std::cout << "Opcion Invalida \n ";
				break;
		}
		//{"Titulo": "asdasdsa"}
	} while (Opc !=4);
	//std::cout << Nuevo.getNom() << " | " << Nuevo.getEstado();
	nlohmann::json Guardar = nlohmann::json::array();
	for (const auto& t: Gesto.ObtenTarea()) {
		Guardar.push_back({ {"Nombre", t.getNom()},{"Estados", t.getEstado()}});
	}
	auto V = Task("A");
	std::ofstream archivo("Datos.json");
	archivo << Guardar.dump(4);
	archivo.close();

}