# OdeCPP
## Sumário
- [OdeCPP](#odecpp)
	- [Sumário](#sumário)
	- [Compilando](#compilando)
		- [Preparação](#preparação)
		- [Clonar repositório](#clonar-repositório)
		- [Dinâmica](#dinâmica)
		- [Estática](#estática)
	- [Utilização](#utilização)
		- [Dinânica](#dinânica)
		- [Estática](#estática-1)
		- [Observação](#observação)
	- [Testes](#testes)
		- [Preparação](#preparação-1)
		- [Utilização](#utilização-1)

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

Obs.: É nescessário utilizar sudo para a instalação, ela cria diretórios e move arquivos em pastas protegidas do sistema.

### Estática
```
make static
```
Para ambos:
```
make
```

## Utilização
### Dinânica
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
Para os menos informados uma biblioteca dinâmica irá ser lida na execução do programa, dessa forma caso seja atualizada o programa não precisará ser recompilado, a não ser que a versão nova mude o nome ou retire funções.

Já uma biblioteca estática é inserida dentro do binário do programa, fazendo o tamanho do programa e o tempo de compilação maiores, e caso haja uma atualização da biblioteca o programa deverá ser recompilado, porém há benefício de performance.

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