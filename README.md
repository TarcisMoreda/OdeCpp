# OdeCPP
## Sumário
- [OdeCPP](#odecpp)
	- [Sumário](#sumário)
	- [Compilando](#compilando)
		- [Preparação](#preparação)
		- [Compilação](#compilação)
	- [Testes](#testes)
		- [Preparação](#preparação-1)
		- [Utilização](#utilização)

## Compilando
### Preparação
Tenha certeza de ter o git e g++ instalados.

### Compilação
Compile a biblioteca:
```
git clone https://github.com/TarcisMoreda/OdeCpp.git
cd OdeCpp/build
```
Para a biblioteca dinânica(.so):
```
make dynamic
```
Para a biblioteca estática(.a):
```
make static
```
Para ambos:
```
make
```

## Testes
### Preparação
A biblioteca acutest.hpp está incluída de acordo com o Copyright escrito na mesma, créditos ao autor:

https://github.com/mity/acutest

### Utilização
Compile o teste:
```
cd OdeCpp/tests
make
./tests.bin
```