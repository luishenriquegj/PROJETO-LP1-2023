#include "Music.h"

using namespace std;
/*!
* Construtor  padrão da clase Music(), existe um construtor sobrecarregado que inicializa elementos da classe Music()
* passando os duas string como parametros, string de title e string de author. 
*/

Music::Music(){
    
}
/**
* @brief Construtor sobrecarregado da clase Music()
* que recebe dois parametros, pois a classe Musica tem dois Atributos,
* sendo eles o titulo da música e o nome do autor
* @param string title
* @param string author
*/

Music::Music( string title,string author){
    this-> title = title;
    this-> author = author;
}

/**
* @brief getKey() é uma função responsável por retornar o nome da música, nesse caso o titulo, pois o titulo da
* música é um atributo é privado e precisa de uma função nessa clase que consiga 
* acessar ele, para retornar o atributo em outros locais.
* @return title
*/

string Music::getKey(){
    return this-> title = title;
}

/**
* @brief setTitle() é uma função responsável por definir o nome da música, nesse caso o titulo, pois o titulo da
* música é um atributo privado e precisa de uma função nessa clase que consiga acessar ele, para o usúario conseguir
* definar o nome de alguma música caso ele queira.
* @param string title
*/

void Music::setTitle(string title){
    this->title=title;
}
/**
* @brief getAuthor()) é uma função responsável por retornar o nome do autor pois esse atributo 
* é privado e precisa de uma função nessa clase que consiga acessar ele, para retornar o atributo em outros locais.
* @return author
*/

string Music::getAuthor(){
    return this-> author = author;
}
/**
* @brief setAuthor() é uma função responsável por definir o nome da música, nesse caso o nome do autor, pois o 
* nome do author é um atributo privado e precisa de uma função nessa clase que consiga acessar ele, para o usúario conseguir
* definar o nome de algum autor caso ele queira.
* @param string author 
*/

void Music::setAuthor(string author){
    this->author=author;
}