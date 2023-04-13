# OdeCPP
## Sumário
- [OdeCPP](#odecpp)
	- [Sumário](#sumário)
	- [Compilando](#compilando)
		- [Preparação](#preparação)
		- [Clonar repositório](#clonar-repositório)
		- [Dinâmica](#dinâmica)
		- [Estática](#estática)
		- [Ambos](#ambos)
	- [Utilizando](#utilizando)
		- [Dinâmica](#dinâmica-1)
		- [Estática](#estática-1)
		- [Observação](#observação)
	- [Documentação](#documentação)
		- [Diagrama de Classes](#diagrama-de-classes)
		- [Doxygen](#doxygen)
	- [Testes](#testes)
		- [Créditos](#créditos)
		- [Utilização](#utilização)

## Compilando
### Preparação
Tenha certeza de ter o git, g++, e make instalados.

Ubuntu/Debian:
```
sudo apt install build-essential git
```
Arch:
```
sudo pacman -S base-devel git
```

### Clonar repositório
```
git clone https://github.com/TarcisMoreda/OdeCpp.git
cd OdeCpp/build
```
### Dinâmica
```
make dynamic
sudo make install
```
Isso irá instalar a biblioteca nos locais padrões do Linux.

Obs.: É nescessário utilizar sudo para a instalação, ela cria diretórios e move arquivos em pastas protegidas do sistema (/usr/include e /usr/lib).

### Estática
```
make static
```
### Ambos
```
make
```

## Utilizando
### Dinâmica
Inclua a biblioteca no início do seu código com:
```
#include <OdeCpp/OdeCpp.h>
```
E compile seu código com a flag adicional.

Exemplo:
```
g++ main.cpp -lOdeCpp -o main.bin
./main.bin
```

### Estática
Para usar a biblioteca estática copie o arquivo libOdeCpp.a e todos os arquivos na pasta include em uma pasta lib em seu projeto, inclua a biblioteca no início do seu código com:
```
#include "lib/OdeCpp.h"
```

Na hora de compilar adicione as seguintes flags:
```
-L./lib -lOdeCpp
```
Exemplo:
```
g++ main.cpp -L./lib -lOdeCpp -o main.bin
./main.bin
```

### Observação
Uma biblioteca dinâmica irá ser lida na execução do programa, dessa forma caso seja atualizada o programa não precisará ser recompilado, a não ser que a versão nova mude o nome ou retire funções.

Já uma biblioteca estática é inserida dentro do binário do programa, fazendo o tamanho do programa e o tempo de compilação maiores, e caso haja uma atualização da biblioteca o programa deverá ser recompilado, porém há benefício de performance.

## Documentação
### Diagrama de Classes
O arquivo mostrando o diagrama de classes está incluso na pasta docs.

### Doxygen
Para gerar a documentação pelo doxygen apenas entre na pasta build e use o comando:
```
make docs
```
O comando irá gerar a pasta doxygen dentro de docs e abrirá o html no Firefox.

## Testes
### Créditos
A biblioteca de testes utilizada é a GoogleTest juntamente com lcov pra gerar coverage reports. 

### Utilização
Compile o teste:
```
cd OdeCpp/tests
make tests OU make coverage
./tests.bin
```