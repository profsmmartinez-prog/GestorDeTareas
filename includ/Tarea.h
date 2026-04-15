#ifndef Tarea
#define Tarea
#include <string>

class Task {
private:
	std::string Nombre;
	bool Estado;
public:
	Task(std::string Nom);
	std::string getNom() const;
	bool getEstado() const;
	void CambiarEstado();
};

#endif