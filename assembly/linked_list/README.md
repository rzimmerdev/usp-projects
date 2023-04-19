# Trabalho Prático 1

Membros:
Nome, nUsp
Rafael Zimmer, 12542612
Guilherme Pacheco, 11797091
Victor Fernandes, 12675399

Para o trabalho 1 desenvolvemos uma lista ligada com campos Id e Valor em Assembly MIPS.
Criamos algumas rotinas com funcionalidades específicas para inicializar a lista ligada em si e seus nós, assim como ler da entrada os valores para os nós e printar para o console os nós de uma dada lista.
É possível também criar mais de uma lista ligada no mesmo código, se desejado.


## Desenvolvimento

Quanto ao desenvolvimento do trabalho, primeiramente fizemos a função de escrever os nós, tendo que testar a leitura manualmente campo por campo. Desde o começo estávamos tratando o problema de sobreescrever registradores dentro de uma subrotina, por meio da escrita dos valores dos registradores na memória antes da execução da subrotina, e a releitura após.

Em sequência, tentamos fazer a função de printar todos os nós, contudo percebemos que estavam dando muitos problemas relativo ao ponteiro de stack, sendo que anteriormente estávamos indexando os valores no sentido contrário (Ex: para printar uma string de vários carácteres salvas no stack, o compilador pede o endereço mais próximo do cabeçalho do header, e salva o caráter terminador '\0' o mais longe, sendo que deveríamos então passar o endereço que estávamos salvando + o tamanho da string). 

Assim, antes de terminar a função de printar a lista, refizemos o código para tratar a stack no sentido positivo e não no negativo. Verificamos após trocar essa ordem em que tratávamos a stack que a função de printar os nós estava funcionando perfeitamente, conseguindo printar diversos nós, como mostram as imagens de teste. 

