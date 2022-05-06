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
make
```
Será gerado o arquivo OdeCpp.so para a biblioteca.

## Testes
### Preparação
Adicione o arquivo acutest.hpp na pasta tests, basta pega-lo da biblioteca:

https://github.com/mity/acutest

### Utilização
Compile o teste:
```
cd OdeCpp/tests
make
./tests.bin
```