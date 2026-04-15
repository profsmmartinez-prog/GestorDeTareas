#ifndef Gestor
#define Gestor
#include "Tarea.h"
#include <vector>

class Manager {
private:
	std::vector<Task> Tareas;
public:
	void AgregarTarea();
	void Mostrar() const;
	void MarcarFin(int Num);
	std::vector<Task>& ObtenTarea() const;
};

#endif