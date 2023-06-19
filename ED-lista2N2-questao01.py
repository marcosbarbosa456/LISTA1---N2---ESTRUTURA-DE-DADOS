
#Função : Criar uma base de dados usando a técnica de lista encadeada para gerir os livros de uma
#biblioteca. A informação de cada livro é: autor, título, editora, ano de edição
#Autor : Joel Adelaide Medeiros - P3 CC Unip� - RGM 29799384
#		 Marcos Barbosa Vieira Filho - P3 CC Unip� - RGM 30174503
# Data : 19/06/2023
# Observa��es:


class Livro:
    def __init__(self, autor, titulo, editora, ano):
        self.autor = autor
        self.titulo = titulo
        self.editora = editora
        self.ano = ano
        self.proximo = None

class Biblioteca:
    def __init__(self):
        self.primeiro = None

    def inserir_livro(self, autor, titulo, editora, ano):
        novo_livro = Livro(autor, titulo, editora, ano)

        if self.primeiro is None:
            self.primeiro = novo_livro
        else:
            atual = self.primeiro
            anterior = None

            while atual is not None and atual.titulo < titulo:
                anterior = atual
                atual = atual.proximo

            if anterior is None:
                novo_livro.proximo = self.primeiro
                self.primeiro = novo_livro
            else:
                anterior.proximo = novo_livro
                novo_livro.proximo = atual

    def remover_livro(self, titulo):
        atual = self.primeiro
        anterior = None

        while atual is not None and atual.titulo != titulo:
            anterior = atual
            atual = atual.proximo

        if atual is None:
            print("Livro não encontrado.")
        elif anterior is None:
            self.primeiro = atual.proximo
        else:
            anterior.proximo = atual.proximo

    def alterar_livro(self, titulo, novo_autor, nova_editora, novo_ano):
        atual = self.primeiro

        while atual is not None and atual.titulo != titulo:
            atual = atual.proximo

        if atual is None:
            print("Livro não encontrado.")
        else:
            atual.autor = novo_autor
            atual.editora = nova_editora
            atual.ano = novo_ano

    def buscar_por_titulo(self, titulo):
        atual = self.primeiro

        while atual is not None and atual.titulo != titulo:
            atual = atual.proximo

        if atual is None:
            print("Livro não encontrado.")
        else:
            print("Autor:", atual.autor)
            print("Editora:", atual.editora)
            print("Ano de edição:", atual.ano)

    def buscar_por_autor(self, autor):
        atual = self.primeiro
        encontrado = False

        while atual is not None:
            if atual.autor == autor:
                print("Título:", atual.titulo)
                print("Editora:", atual.editora)
                print("Ano de edição:", atual.ano)
                encontrado = True

            atual = atual.proximo

        if not encontrado:
            print("Nenhum livro encontrado para o autor informado.")

    def exibir_livros(self):
        if self.primeiro is None:
            print("A biblioteca está vazia.")
        else:
            atual = self.primeiro

            while atual is not None:
                print("Título:", atual.titulo)
                print("Autor:", atual.autor)
                print("Editora:", atual.editora)
                print("Ano de edição:", atual.ano)
                print("----------------------")
                atual = atual.proximo


# Exemplo de uso
biblioteca = Biblioteca()

while True:
    print("----- MENU -----")
    print("1 - Inserir livro")
    print("2 - Remover livro")
    print("3 - Alterar livro")
    print("4 - Buscar livro por título")
    print("5 - Buscar livros por autor")
    print("6 - Exibir todos os livros")
    print("0 - Sair")

    opcao = input("Digite a opção desejada: ")

    if opcao == "1":
        autor = input("Digite o autor do livro: ")
        titulo = input("Digite o título do livro: ")
        editora = input("Digite a editora do livro: ")
        ano = input("Digite o ano de edição do livro: ")

        biblioteca.inserir_livro(autor, titulo, editora, ano)
        print("Livro inserido com sucesso.")

    elif opcao == "2":
        titulo = input("Digite o título do livro a ser removido: ")
        biblioteca.remover_livro(titulo)

    elif opcao == "3":
        titulo = input("Digite o título do livro a ser alterado: ")
        novo_autor = input("Digite o novo autor do livro: ")
        nova_editora = input("Digite a nova editora do livro: ")
        novo_ano = input("Digite o novo ano de edição do livro: ")

        biblioteca.alterar_livro(titulo, novo_autor, nova_editora, novo_ano)
        print("Livro alterado com sucesso.")

    elif opcao == "4":
        titulo = input("Digite o título do livro a ser buscado: ")
        biblioteca.buscar_por_titulo(titulo)

    elif opcao == "5":
        autor = input("Digite o autor dos livros a serem buscados: ")
        biblioteca.buscar_por_autor(autor)

    elif opcao == "6":
        biblioteca.exibir_livros()

    elif opcao == "0":
        break

    else:
        print("Opção inválida. Digite novamente.")
    print()

