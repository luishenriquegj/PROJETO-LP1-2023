
# PROJETO LP1 PARA UNIDADE 1 DE 2023

Projeto avaliativo da primeira unidade de Lingaguem de programação 1 de 2023.1



## Autores

- [@Gabrielarnaud01](https://github.com/Gabrielarnaud01)
  
  - Gabriel Arnaud Paiva torres

- [@luishenriquegj](https://github.com/luishenriquegj)
  
  - Luis Henrique Guedes Jucá
# PASSO-A-PASSO DE INSTALAÇÃO
 
 - 1° crie no diretorio raiz do projeto, a pasta build com o comando:
    - mkdir build
 - 2° entre na pasta build e digite o comando :
   - cmake ..
 - 3° em seguida digite:
    - make
 - 4° após isso digite ./program para iniciar o program

 # OBSERVAÇÃO,PARA GERAR A DOCUMENTÇÃO DO DOXYGEN:
    - 1° crie no diretorio raiz do projeto, a pasta docs com o comando:
      - mkdir docs
    - 2° em seguida digite, *sem entrar na pasta docs* digite:
      - doxygen
# ROTEIRO PARA RODAR O PROGRAMA
  - Existem 9 opções iniciais, sendo elas:
    - 1°: add a new song é preciso passar duas strings. A primeira string é o nome da musica e a segunda é o nome do autor da música.
    - 2°: remove a song from a playlist é preicso passar duas strings. A primeira é o nome da playlista e a segunda é o nome da música que deseja apagar da playlist em específico.
    - 3°: remove s song on system é preciso passar uma string, é responsavel por tirar essa música do sistema e de todas as playlists em que estava cadastrada.
    - 4°: show all songs on system não precisa passar elementos, retorna o nome de todas as músicas do sistema.
    - 5°: add a song to a playlist é preciso passar duas strings. A primeira é o nome da musica que deseja adicionar e a segunda é o nome da playlist que deseja adicionar, essa opção não cria uma música ou uma playlist nesse local, então é preciso que essa playlist e essa música já existam no sistema.
    - 6°: destruct list não é necessário passar elementos, é responsavel por desalocar toda memoría que foi alocada nas listas.
    - 7°: create a new playlist é preciso passar uma string, sendo essa string o nome da playlist que seŕa adiciona ao sistema.
    - 8°: find a playlist não é preciso passar elementos, ela é responsável por retornar todas as playlists com suas músicas.
    - 9°: exit program é a opção para finalizar o programa.
  - Não existe ordem necessariamente para cada uma dessas opções por exemplo: é possível criar uma play list e depois adicionar uma música, mas não é possível remover uma música que não existe, é possível dar o comando para visualizar todas as músicas do sistema mesmo que não existam músicas,etc.
  - Para adicionar uma música entre na opção 1. 
  - Para adicionar uma playlist entre na opção 7.
  - Para adicionar uma música a uma playlist entre na opção 1 para criar a música, depois entre na opção 7 para criar a playlist e em seguinda entre na opção 5 para atribuir uma musica a uma playlist.
  - Para remover uma música do sistema entre na opção 3.
  - Para remover uma música de uma playlista, entre na opção 2 e digite o nome da playlist e em seguida o nome música a ser removida.
  - Para visualizar todas as músicas do sistema entre na opção 4.
  - Para desalocar a memória entre na opção 6.
  - Para visualizar todas as músicas de todas as playlists entre na opção 8.
  - Para finalizar o programa entre na opção 9.

# LIMITAÇÕES DO PROGRAMA
  - Atualmente o programa não consegue diferenciar maiúsculas e minúsculas, então para todas as opções é necessário passar exatamente como foi escrito, por exemplo para adicionar a música "teste 1" na playlist "playlist1" é preciso entrar na opção 5 e digitar o nome da música e o nome da playlist exatamente como foi passado para o sistema.
  - Atualmente o código da segmentation fault nessa circunstâncias: 
    - Quando é tentado adicionar uma música que não existe a uma playlist.
    - Quando é tentado adicionar uma música a uma playlist que não existe.
    - Quando é tentado remover uma musica que não existe de uma playlist específica.
    - Quando é tentado remover uma música do sistema que não existe.
  - Não fizemos os itens 3c e 3d que foi pedido no txt do projeto.
