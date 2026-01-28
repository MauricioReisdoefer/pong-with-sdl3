# Documentação do Projeto: Pong com SDL3

## 1. Visão Geral do Projeto

O projeto **pong-with-sdl3** é uma implementação clássica do jogo Pong, desenvolvida em linguagem C e utilizando a biblioteca **SDL3 (Simple DirectMedia Layer 3)** para manipulação de gráficos, entrada de usuário e áudio. O código-fonte está estruturado em módulos para facilitar a organização e manutenção.

| Arquivo | Descrição |
| :--- | :--- |
| `main.c` | Contém a função principal (`main`), a inicialização do SDL3, o *game loop* e o tratamento de eventos. |
| `render.c` | Implementa as funções de renderização, como desenhar a tela de fundo e os retângulos (raquetes e bola). |
| `collision.c` | Contém a lógica para detecção de colisão, especificamente a colisão AABB (Axis-Aligned Bounding Box) entre a bola e as raquetes/paredes. |
| `color.h` | Define estruturas e constantes para cores. |
| `render.h` | Declara as funções de renderização implementadas em `render.c`. |
| `player.h` | Define a estrutura para as raquetes dos jogadores. |
| `ball.h` | Define a estrutura para a bola. |
| `collision.h` | Declara as funções de colisão implementadas em `collision.c`. |

## 2. Pré-requisitos para Compilação

Para compilar o projeto, é necessário ter instalado:

1. **Compilador C:** Recomenda-se o **GCC** (GNU Compiler Collection).
2. **Biblioteca SDL3:** Os arquivos de desenvolvimento (cabeçalhos e bibliotecas) da SDL3 devem estar instalados no seu sistema.

### 2.1. Instalação do SDL3

O processo de instalação varia conforme o sistema operacional:

* **Linux (Debian/Ubuntu):**

    ```bash
    sudo apt update
    sudo apt install libsdl3-dev
    ```

* **macOS (Homebrew):**

    ```bash
    brew install sdl3
    ```

* **Windows (MinGW/MSYS2):**
    Baixe os arquivos de desenvolvimento da SDL3 no site oficial e configure o ambiente de compilação (como o MinGW ou MSYS2) para que ele possa encontrar os diretórios `include` e `lib` da SDL3.

## 3. Instruções de Compilação

A compilação deve ser feita utilizando o GCC, ligando os arquivos fonte e as bibliotecas SDL3.

### 3.1. Compilação em Ambiente Windows (Modelo do Usuário)

Se você estiver em um ambiente Windows (como MinGW ou MSYS2) e tiver as bibliotecas SDL3 instaladas no caminho `C:/libs/SDL3/`, o comando de compilação será:

```bash
gcc main.c render.c collision.c -IC:/libs/SDL3/include -LC:/libs/SDL3/lib -lSDL3 -o pong.exe
```

**Explicação dos Parâmetros:**

| Parâmetro | Descrição |
| :--- | :--- |
| `main.c render.c collision.c` | Os arquivos fonte (`.c`) do projeto a serem compilados. |
| `-IC:/libs/SDL3/include` | **I**nclui o diretório onde estão os arquivos de cabeçalho (`.h`) da SDL3. |
| `-LC:/libs/SDL3/lib` | **L**iga o diretório onde estão os arquivos de biblioteca (`.lib` ou `.a`) da SDL3. |
| `-lSDL3` | **L**iga a biblioteca SDL3. |
| `-o pong.exe` | Define o nome do arquivo de saída (o executável) como `pong.exe`. |

### 3.2. Compilação em Ambiente Linux/macOS (Recomendado)

Em sistemas Unix-like, é comum usar o utilitário `sdl3-config` para obter automaticamente os *flags* de compilação e *linkagem* necessários.

```bash
gcc main.c render.c collision.c $(sdl3-config --cflags --libs) -o pong
```

**Explicação dos Parâmetros:**

| Parâmetro | Descrição |
| :--- | :--- |
| `$(sdl3-config --cflags --libs)` | Substitui o comando pelos *flags* de compilação (`-I...`) e *linkagem* (`-L... -l...`) corretos para a SDL3 instalada no sistema. |
| `-o pong` | Define o nome do arquivo de saída (o executável) como `pong`. |

## 4. Execução

Após a compilação bem-sucedida, execute o jogo a partir do terminal:

* **Windows:**

    ```bash
    ./pong.exe
    ```

* **Linux/macOS:**

    ```bash
    ./pong
    ```
