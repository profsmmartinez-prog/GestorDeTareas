#include "Gestor.h"
#include <iostream>

void Manager::AgregarTarea(const Task& Tare) {
	Tareas.push_back(Tare);
}

void Manager::Mostrar() const{
	int i=1;
	for (const auto& t : Tareas) {
		std::cout << i++ << " " << t.getNom() << " | " << t.getEstado() << std::endl;
	}
}
void Manager::MarcarFin(int Num) {
	if (Num >= 0 && Num < Tareas.size()) {
		Tareas[Num].CambiarEstado();
	}
}

const std::vector<Task>& Manager::ObtenTarea() const {
	return Tareas;
}