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
- [Funcionalidades](#funcionalidades)
- [Instalação](#instalação)
- [Configuração](#configuração)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Contribuidores](#contribuidores)
- [Mostre seu apoio](#mostre-seu-apoio)

## Descrição
O Jogo da Vida, criado pelo matemático britânico John Horton Conway em 1970, é um exemplo clássico de autômato celular, um modelo matemático para um sistema dinâmico que evolui em etapas discretas baseadas em regras simples. Apesar de suas regras simples, o Jogo da Vida pode exibir padrões complexos e fascinantes.

Este projeto implementa uma versão do Jogo da Vida em C, onde uma grade bidimensional de células vivas e mortas evolui ao longo do tempo de acordo com regras específicas. As células podem estar em dois estados: viva (representada por "■") ou morta (representada por "□"). A cada geração, as células mudam de estado com base na quantidade de células vizinhas vivas.

## Regras do Jogo

As células evoluem de acordo com as seguintes regras:

1. Qualquer célula viva com menos de dois vizinhos vivos morre de solidão.
2. Qualquer célula viva com dois ou três vizinhos vivos vive para a próxima geração.
3. Qualquer célula viva com mais de três vizinhos vivos morre de superpopulação.
4. Qualquer célula morta com exatamente três vizinhos vivos se torna uma célula viva.

## Funcionalidades

- 🎮 Geração automática de padrões iniciais aleatórios ou importação de padrões a partir de um arquivo de entrada.
- 🖥️ Visualização em tempo real da evolução do padrão no console.
- 🌐 Interface gráfica simples para uma experiência visual mais imersiva.
- 🔄 Possibilidade de ajustar a velocidade de evolução do jogo.
- 📁 Salvamento automático do estado atual do jogo.
- 📊 Estatísticas detalhadas sobre a evolução do padrão, como número de células vivas e mortas em cada geração.
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
    ./game_of_life_exe
```
* **Passo 5** : Caso não tenha conseguido executar o programa, faça:
``` jsx

// Compila os arquivo system_info.c, game_of_life.c, file.c e main.c, vincula (linka) os arquivos objeto produzidos e, forma um executável chamado game_of_life_exe.
gcc system_info.c game_of_life.c file.c main.c -o game_of_life_exe

```

## Argumentos de Inicialização

Este programa permite configurar três argumentos opcionais para controlar o comportamento do Game of Life.

### Uso

```jsx
./game_of_life_exe [OPÇÕES]
```


| Args  | Descrição | Exemplo | Default |
| ------------- | ------------- | ------------- | ------------- |
| `rows=<valor>`  | Define o número de linhas na grade do Game of Life. | `./game_of_life_executavel rows=30` | `rows=20` |
| `cols=<valor>`  | Define o número de colunas na grade do Game of Life. | `./game_of_life_executavel cols=40` | `cols=20` |
| `sleep=<valor>`  | Define o intervalo de tempo (em segundos) entre gerações. | `./game_of_life_executavel sleep=2` | `sleep=1` |


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

## Mostre seu apoio
Dê uma ⭐️ se este projeto ajudou você!