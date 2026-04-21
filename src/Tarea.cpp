#include "Tarea.h"

Task::Task(std::string Nom) : Nombre(Nom), Estado(0) {}

Task::Task(std::string Nom, bool Edo) : Nombre(Nom), Estado(Edo) {}


std::string Task::getNom() const {
	return Nombre;
}
bool Task::getEstado() const {
	return Estado;
}
void Task::CambiarEstado() {
	Estado = 1;
}
