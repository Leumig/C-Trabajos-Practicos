#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int statusFlight;
}Passenger;

Passenger* Passenger_new();

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,
								   char* codigoVueloStr, char* tipoPasajeroStr, char* statusFlightStr);
void Passenger_delete();

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);
int Passenger_getTipoPasajeroString(Passenger* e, char* tipoPasajero);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setStatusFlight(Passenger* this, int statusFlight);
int Passenger_getStatusFlight(Passenger* this, int* statusFlight);
int Passenger_getStatusFlightString(Passenger* e, char* statusFlight);


#endif /* PASSENGER_H_ */
