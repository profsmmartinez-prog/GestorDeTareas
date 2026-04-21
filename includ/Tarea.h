#ifndef Tarea
#define Tarea
#include <string>

class Task {
private:
	std::string Nombre;
	bool Estado;
public:
	Task(std::string Nom);
	Task(std::string Nom, bool Edo);
	std::string getNom() const;
	bool getEstado() const;
	void CambiarEstado();
};

#endif