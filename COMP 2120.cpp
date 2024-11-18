//COMP 2120
//Realizado por Karim Goveo Colón (condiciones y manejo del output)
//Realizado por Yamilette M. Matías González (arrays y loops)

#include <iostream>
#include <string>
using namespace std;

int main() {
	string peliculas[] = {
		"Transformers", "Pacific Rim", "Black Panther",
		"Avatar", "Scarface", "Star Wars", "Mission IMpossible",
		"Iron Man", "Superman", "Deadpool"
	} ;
	bool disponibilidad[] = {
		true, true, true, true, true, true, true, true, true, true
	} ;

	const int cantidades = 10;
	int opciones;

	while (true) {
		cout << "===============================================================================================" << endl;
		cout << "Bienvenidos Renta tu Película " << endl;
		cout << "Aquí puedes rentar y devolver. Abajo tendrá opciones para interactuar con el menú. " << endl;
		cout << "===============================================================================================" << endl;
		cout << "Opción 1 - Rentar" << endl;
		cout << "Opción 2 - Devolver" << endl;
		cout << "Opción 0 - Salir" << endl;
		cout << endl << "Escoge cualquiera de las tres opciones: ";
		cin >> opciones;

		if (opciones == 0) {
			cout << endl << "Oprimió 0. Gracias por visitar." << endl;
			break;
		}

		else if (opciones == 1) {
			cout << endl << "Aquí están todas las películas para rentar: " << endl;

			for (int rnt = 0; rnt < cantidades; rnt++) {
				cout << rnt + 1 << ". " << peliculas[rnt] << " - " << "estado" " = " << (disponibilidad[rnt] ? "disponible" : "rentada") << endl;
			}

			cout << endl << "En la pantalla le indicará si está rentada o no. " << endl;
			cout << "Si quiere volver al menú, oprima 0. " << endl;
			cout << endl << "Escoge la película que quiere rentar: ";
			cin >> opciones;

			if (opciones == 0) {
				cout << endl << "Oprimió 0. Será devuelto al principio." << endl;
				continue;
			}

			if (opciones < 1 || opciones > cantidades) {
				cout << endl << "Escribió algo incorrecto. Será devuelto al principio." << endl;
				continue;
			}

			if (disponibilidad[opciones - 1]) {
				cout << endl << "Has rentado la siguiente película: \"" << peliculas[opciones - 1] << "\"." << " Será devuelto al principio." << endl;
				disponibilidad[opciones - 1] = false;
			}

			else {
				cout << endl << "Lo sentimos, pero la película: \"" << peliculas[opciones - 1] << "\" ya está rentada." << endl;
			}
		}
		else if (opciones == 2) {

			cout << endl << "Aqui enseñará las películas que ha rentado: " << endl;
			bool anyrnt = false;

			for (int rnt = 0; rnt < cantidades; rnt++) {
				if (!disponibilidad[rnt]) {
					cout << rnt + 1 << ". " << peliculas[rnt] << endl;
					anyrnt = true;
				}
			}

			if (!anyrnt) {
				cout << endl << "No tiene ninguna película para devolver. Será devuelto al principio.\n" << endl;
				continue;
			}

			cout << endl << "Si quiere volver al menú, oprima 0. " << endl;
			cout << "Oprima el número de la película que quiera devolver: ";
			cin >> opciones;

			if (opciones == 0) {
				cout << endl << "Oprimió 0. Será devuelto al principio.." << endl;
				continue;
			}

			if (opciones < 1 || opciones > cantidades) {
				cout << endl << "Escribió algo incorrecto. Será devuelto al principio." << endl;
				continue;
			}

			if (!disponibilidad[opciones - 1]) {
				cout << endl << "Has devuelto la película: \"" << peliculas[opciones - 1] << "\"." << " Será devuelto al principio." << endl;
				disponibilidad[opciones - 1] = true;
			}
			else {
				cout << "La película: \"" << peliculas[opciones - 1] << "\" ya está disponible. Será devuelto al principio." << endl;
			}
		}
		else {
			cout << endl << "Escribió algo incorrecto . Será devuelto al principio." << endl;
		}
		cout << endl;
	}

	return 0;
}