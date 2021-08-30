# Projeto criado para cadeira Programação Orientada a Objetos II da Unisinos #

## Sistema para controle de estoque de loja ##

A ideia é, inicialmente, cadastrar os produtos e quantidades existentes. Depois o usuário poderá:

- cadastrar novos produtos;
- cadastrar chegada de mais mercadoria;
- cadastrar vendas, informando como foi feita essa venda (presencial ou online, pagamento a vista ou no cartão, parcelado ou não);
- cancelamentos ou devoluções das compras;
- gerar relatórios das compras por período de tempo (retornando quantidade de vendas, valor total somado das vendas, quantidade de cancelamentos/devoluções);


#### Diagrama UML referente ao backend da aplicação ####
![Diagrama UML da aplicação](uml-backend-aplicacao.png)


#### Descrição das classes ####

- As classes de "Compra", "Produto", "Pagamento",  "ProdutoCompra", "Cliente" e "StatusCompra" representam os dados que vão ser manipulados durante a execução da aplicação.
- A classe "DadosSistema" é onde serão armazenados todos os dados, sendo listas de compras e produtos cadastrados.
- Todas as outras são classes auxiliares, onde serão manipulados os dados, editando produtos, adicionando novas compras, cancelando ou devolvendo outras, também gerando os relatórios que serão mostrados para o lojista.