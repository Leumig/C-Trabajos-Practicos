/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Passenger.h"

int main(void)
{
	setbuf(stdout, NULL);

	/*
	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort
	*/

	// ll_newLinkedList
	LinkedList* listaPasajeros = ll_newLinkedList();

	// ll_len
	int cant = ll_len(listaPasajeros);
	printf("Funcion ll_len // Cantidad de pasajeros: %d\n\n", cant);

	// ll_isEmpty
	int listaVacia = ll_isEmpty(listaPasajeros);
	printf("Funcion isEmpty // LinkedList vacia: [%d]\n", listaVacia);
	printf("[1] = SI // [0] = NO // [-1] = Puntero NULL\n\n");

	// ll_add
	Passenger* pass1 = Passenger_newParametros(1, "Mauro", 6000);
	Passenger* pass2 = Passenger_newParametros(2, "Emilia", 9500);
	Passenger* pass3 = Passenger_newParametros(3, "Ramiro", 7000);
	ll_add(listaPasajeros, pass1);
	ll_add(listaPasajeros, pass2);
	ll_add(listaPasajeros, pass3);
	printf("Funcion ll_add // Se agregaron 3 pasajeros\n\n");

	// ll_isEmpty
	listaVacia = ll_isEmpty(listaPasajeros);
	printf("Funcion isEmpty // LinkedList vacia: [%d]\n",listaVacia);
	printf("[1] = SI // [0] = NO // [-1] = Puntero NULL\n\n");

	// ll_len
	cant = ll_len(listaPasajeros);
	printf("Funcion ll_len // Cantidad de pasajeros: %d\n\n", cant);

	// ll_get
	Passenger* auxPass = ll_get(listaPasajeros, 2);
	printf("Funcion ll_get // Pedir pasajero 3: %d, %s, %.2f\n\n", auxPass->id, auxPass->nombre, auxPass->precio);

	// ll_set
	pass1 = Passenger_newParametros(1, "Luciano", 8500);
	ll_set(listaPasajeros, 0, pass1);
	Passenger* modPass = ll_get(listaPasajeros, 0);
	printf("Funcion ll_set // Setear pasajero 1: %d, %s, %.2f\n\n", modPass->id, modPass->nombre, modPass->precio);

	// ll_indexOf
	int indexOfPass1 = ll_indexOf(listaPasajeros, pass2);
	printf("Funcion ll_indexOf // Indice pasajero 2: %d\n\n", indexOfPass1);

	// ll_remove
	ll_remove(listaPasajeros, 2);
	printf("Funcion ll_remove // Se elimino un pasajero (el pass3)\n\n");

	// ll_len
	cant = ll_len(listaPasajeros);
	printf("Funcion ll_len // Cantidad de pasajeros: %d\n\n", cant);

	// ll_clear
	ll_clear(listaPasajeros);
	printf("Funcion ll_clear // Se eliminaron todos los pasajeros\n\n");

	// ll_isEmpty
	listaVacia = ll_isEmpty(listaPasajeros);
	printf("Funcion isEmpty // LinkedList vacia: [%d]\n", listaVacia);
	printf("[1] = SI // [0] = NO // [-1] = Puntero NULL\n\n");

	// ll_add
	pass1 = Passenger_newParametros(1, "Sofia", 6000);
	pass2 = Passenger_newParametros(2, "Xavier", 9500);
	pass3 = Passenger_newParametros(3, "Alberto", 7000);
	Passenger* pass4 = Passenger_newParametros(4, "Victor", 15000);
	Passenger* pass5 = Passenger_newParametros(5, "Carla", 12000);
	Passenger* pass6 = Passenger_newParametros(6, "Tamara", 8500);
	ll_add(listaPasajeros, pass1);
	ll_add(listaPasajeros, pass2);
	ll_add(listaPasajeros, pass3);
	ll_add(listaPasajeros, pass4);
	ll_add(listaPasajeros, pass5);
	ll_add(listaPasajeros, pass6);
	printf("Funcion ll_add // Se agregaron 6 pasajeros\n\n");

	// ll_len
	cant = ll_len(listaPasajeros);
	printf("Funcion ll_len // Cantidad de pasajeros: %d\n\n", cant);

	// ll_push
	Passenger* pushPass = Passenger_newParametros(555, "Puyol", 6500);
	ll_push(listaPasajeros, 3, pushPass);
	printf("Funcion ll_push // Se inserto un nuevo pasajero en el indice 3\n\n");

	// ll_indexOf
	int indexOfpushPass = ll_indexOf(listaPasajeros, pushPass);
	printf("Funcion ll_indexOf // Indice pasajero push: %d\n\n", indexOfpushPass);

	// ll_pop
	Passenger* popPass = NULL;
	popPass = ll_pop(listaPasajeros, 3);
	printf("Funcion ll_pop // Pasajero recibido y eliminado: %d %s %.2f\n\n", popPass->id, popPass->nombre, popPass->precio);

	// ll_contains
	int contains = ll_contains(listaPasajeros, pass4);
	printf("Funcion ll_contains // Existe el pass4: [%d]\n", contains);
	contains = ll_contains(listaPasajeros, popPass);
	printf("Funcion ll_contains // Existe el popPass (pass5): [%d]\n", contains);
	printf("[1] = SI // [0] = NO // [-1] = Puntero NULL\n\n");

	// ll_deleteLinkedList(LinkedList* this)
	ll_deleteLinkedList(listaPasajeros);
	printf("Funcion ll_deleteLinkedList // LinkedList eliminada\n\n");

	// ll_isEmpty
	listaVacia = ll_isEmpty(listaPasajeros);
	printf("Funcion isEmpty // LinkedList vacia: [%d]\n",listaVacia);
	printf("[1] = SI // [0] = NO // [-1] = Puntero NULL\n\n");

	// ll_newLinkedList
	LinkedList* nuevaLista1 = ll_newLinkedList();
	LinkedList* nuevaLista2 = ll_newLinkedList();
	printf("Funcion ll_newLinkedList // Se crearon dos nuevas LinkedList\n\n");

	// ll_containsAll
	pass1 = Passenger_newParametros(1, "Sofia", 6000);
	pass2 = Passenger_newParametros(2, "Xavier", 9500);
	pass3 = Passenger_newParametros(3, "Alberto", 7000);
	ll_add(nuevaLista1, pass1);
	ll_add(nuevaLista1, pass2);
	ll_add(nuevaLista1, pass3);
	ll_add(nuevaLista2, pass1);
	ll_add(nuevaLista2, pass2);
	ll_add(nuevaLista2, pass3);
	int containsAll = ll_containsAll(nuevaLista1, nuevaLista2);
	printf("Funcion containsAll // Ambas LinkedList contienen lo mismo: [%d]\n", containsAll);
	printf("[1] = SI // [0] = NO // [-1] = Puntero NULL\n\n");

	// ll_subList
	LinkedList* listaSublist = ll_subList(nuevaLista1, 0, 2);
	printf("Funcion ll_subList // Se creo una nueva LinkedList con los elementos (0-2) de 'nuevaLista1'\n\n");

	// ll_len
	cant = ll_len(listaSublist);
	printf("Funcion ll_len // Cantidad de pasajeros en listaSublist: %d\n\n", cant);

	// ll_clone
	LinkedList* listaClone = ll_clone(nuevaLista2);
	printf("Funcion ll_clone // Se hizo un clon de la nuevaLista2 llamado listaClone\n\n");

	// ll_len
	cant = ll_len(listaClone);
	printf("Funcion ll_len // Cantidad de pasajeros en listaClone: %d\n\n", cant);

	// ll_get
	auxPass = ll_get(listaClone, 1);
	printf("Funcion ll_get // Pedir pass2 de listaClone: %d, %s, %.2f\n\n", auxPass->id, auxPass->nombre, auxPass->precio);

	// ll_add
	pass4 = Passenger_newParametros(4, "Fabian", 9500);
	pass5 = Passenger_newParametros(5, "Lola", 8000);
	pass6 = Passenger_newParametros(6, "Bianca", 9000);
	ll_add(nuevaLista1, pass4);
	ll_add(nuevaLista1, pass5);
	ll_add(nuevaLista1, pass6);
	printf("Funcion ll_add // Se agregaron 3 pasajeros a listaNueva1\n\n");

	// ll_sort
	int criterio = 1; // 1 = Ascendente   0 = Descendente
	ll_sort(nuevaLista1, pasajeroCompararNombre, criterio);
	printf("Funcion ll_sort // Se ordeno la listaNueva1 por Nombre\n\n");
	listarPasajeros(nuevaLista1);

	criterio = 0;
	ll_sort(nuevaLista2, pasajeroCompararPrecio, criterio);
	printf("\n\nFuncion ll_sort // Se ordeno la listaNueva2 por Precio\n\n");
	listarPasajeros(nuevaLista2);

    return 0;
}
