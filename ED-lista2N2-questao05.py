
# Função : Criação de um programa que gerencia uma pilha de processos, com identificadores e descrições
# Autor : Joel Adelaide Medeiros - P3 CC Unip� - RGM 29799384
# 		  Marcos Barbosa Vieira Filho - P3 CC Unip� - RGM 30174503
# Data : 19/06/2023
# Observações:


class Processo:
    def __init__(self, identificador, descricao):
        self.identificador = identificador
        self.descricao = descricao

    def __str__(self):
        return f"#{self.identificador} - {self.descricao}"


class PilhaProcessos:
    def __init__(self):
        self.pilha = []

    def incluir_processo(self, processo):
        self.pilha.append(processo)

    def retirar_processo(self):
        if self.pilha:
            processo_removido = self.pilha.pop()
            return processo_removido
        else:
            return None

    def imprimir_pilha(self):
        if self.pilha:
            print("Conteúdo atual da pilha:")
            for processo in reversed(self.pilha):
                print(processo)
        else:
            print("Pilha vazia.")


def main():
    pilha = PilhaProcessos()

    while True:
        print("\n----- Gerenciador de Pilha de Processos -----")
        print("Selecione a opção desejada:")
        print("1 - Incluir processo")
        print("2 - Retirar processo")
        print("3 - Encerrar programa")

        opcao = input("Opção: ")

        if opcao == "1":
            identificador = input("Digite o identificador do processo: ")
            descricao = input("Digite a descrição do processo: ")
            processo = Processo(identificador, descricao)
            pilha.incluir_processo(processo)
            pilha.imprimir_pilha()
        elif opcao == "2":
            processo_removido = pilha.retirar_processo()
            if processo_removido:
                print(f"Removido o processo {processo_removido} da pilha.")
            else:
                print("Pilha vazia.")
            pilha.imprimir_pilha()
        elif opcao == "3":
            while pilha.pilha:
                processo_removido = pilha.retirar_processo()
                if processo_removido:
                    print(f"Removido o processo {processo_removido} da pilha.")
            print("Encerrando o programa.")
            break
        else:
            print("Opção inválida. Tente novamente.")


if __name__ == "__main__":
    main()

