<h1 align="center">Game Of Life - Conway</h1>
<p align="center">
  <img alt="Versão" src="https://img.shields.io/badge/vers%C3%A3o-1.0.0-blue.svg?cacheSeconds=2592000" />
  <a href="LICENSE" target="_blank">
    <img alt="Licença: MIT" src="https://img.shields.io/npm/l/react" />
  </a>
</p>

## Sumário 
- [Descrição](#descrição)
- [Regras do Jogo](#regras-do-jogo)
- [Recursos](#recursos)
- [Instalação](#instalação)
- [Configuração](#configuração)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Contribuidores](#contribuidores)
- [Mostre seu apoio](#mostre-seu-apoio)

## Descrição
O Jogo da Vida, criado pelo matemático britânico John Horton Conway em 1970, é um exemplo clássico de autômato celular, um modelo matemático para um sistema dinâmico que evolui em etapas discretas baseadas em regras simples. Apesar de suas regras simples, o Jogo da Vida pode exibir padrões complexos e fascinantes.

Este projeto implementa uma versão do Jogo da Vida em C, onde uma grade bidimensional de células vivas e mortas evolui ao longo do tempo de acordo com regras específicas. As células podem estar em dois estados: viva (representada por "■") ou morta (representada por "□"). A cada geração, as células mudam de estado com base na quantidade de células vizinhas vivas.

## Funcionalidades

- 🎮 Geração automática de padrões iniciais aleatórios ou importação de padrões a partir de um arquivo de entrada.
- 🖥️ Visualização em tempo real da evolução do padrão no console.
- 🌐 Interface gráfica simples para uma experiência visual mais imersiva.
- 📝 Documentação abrangente com instruções de uso, descrição das regras do jogo e informações sobre o projeto.

## Instalação
Para usar o Game Of Life localmente, basta clona o repositório usando:
```jsx
// Precisa-se ter o git instalado!
git clone https://github.com/luizfernandoin/GameOfLife
```
ou baixando um arquivo ZIP do código.

## Configuração
Aqui está um resumo de como configurar o aplicativo:

* **Passo 1** : Após clonar o repositório ou extrair o arquivo ZIP, navegue até o diretório raiz do projeto;
* **Passo 2** : No terminal, certifique-se de estar no diretório raiz do projeto;
* **Passo 3** : Ainda no terminal, verifique se possui o GNU instalado, precisa-se dele;
* **Passo 4** : Execute o programa através do seguinte comando:
```jsx
    ./game_of_life_executable
```
* **Passo 5** : Caso não tenha conseguido executar o programa, faça:
``` jsx

// Compila o arquivo game_of_life.c e produz um arquivo objeto chamado game_of_life.o.
gcc -c game_of_life.c -o game_of_life.o

// Produz um arquivo objeto chamado main.o.
gcc -c main.c -o main.o

// Vincula (linka) os dois arquivos objeto game_of_life.o e main.o para formar um executável chamado game_of_life_executable.
gcc game_of_life.o main.o -o game_of_life_executable
```

## Tecnologias Utilizadas
* C

## Contribuidores

<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="25%"><a href="https://github.com/luizfernandoin"><img src="https://avatars.githubusercontent.com/u/106038535?v=4?s=60" width="60px;" alt="Luiz"/><br /><sub><b>Luiz Fernando</b></sub></a><br /><a href="https://github.com/luizfernandoin/NewSpace/commits?author=luizfernandoin" title="Documentation">💻</a></td>
    </tr>
  </tbody>
</table>

## Show your support
Dê uma ⭐️ se este projeto ajudou você!