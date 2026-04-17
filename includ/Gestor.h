#ifndef Gestor
#define Gestor
#include "Tarea.h"
#include <vector>

class Manager {
private:
	std::vector<Task> Tareas;
public:
	void AgregarTarea(const Task& Tare);
	void Mostrar() const;
	void MarcarFin(int Num);
	const std::vector<Task>& ObtenTarea() const;
};

#endif