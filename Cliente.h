#pragma once
#include<iostream>
#include<string>
using namespace std;

class Cliente {
private:
	int codigoCliente;
	string nombreApe;
	int dni;
	int ruc;
public:
	Cliente() {

	}
	/*Cliente(int codigo_, string nombreApe_, int dni_, int ruc_) {
		int codigoCliente = codigo_;
		string nombreApe = nombreApe_;
		int dni = dni_;
		int ruc = ruc_;

	}*/
	~Cliente() {

	}

	void setCodigoCliente(int valor) {
		codigoCliente = valor;
	}
	void setNombreApe(string valor) {
		nombreApe = valor;
	}
	void setDni(int valor) {
		dni = valor;
	}
	void setRuc(int valor) {
		ruc = valor;
	}
	int getCodigoCliente() {
		return this->codigoCliente;
	}
	string getNombreApe() {
		return this->nombreApe;
	}
	int getDni() {
		return this->dni;
	}
	int getRuc() {
		return this->ruc;
	}

};
