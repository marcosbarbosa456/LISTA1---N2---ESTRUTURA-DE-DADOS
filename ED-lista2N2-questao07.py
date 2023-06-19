
# Função : Criação de um sistema que ultilize structs e parametros que simule o que seria um sistema de gerenciamento de atendimento para uma clinica medica
# Autor : Joel Adelaide Medeiros - P3 CC Unip� - RGM 29799384
# 		  Marcos Barbosa Vieira Filho - P3 CC Unip� - RGM 30174503
# Data : 19/06/2023
# Observações:

from collections import deque

class Atendimento:
    def __init__(self):
        self.fila = deque()

    def adicionar_paciente(self, paciente):
        self.fila.append(paciente)

    def proximo_paciente(self):
        if self.fila:
            return self.fila.popleft()
        else:
            return "Não há pacientes na fila"

    def quantidade_pacientes(self):
        return len(self.fila)

# Exemplo de uso
atendimento = Atendimento()

atendimento.adicionar_paciente("João")
atendimento.adicionar_paciente("Maria")
atendimento.adicionar_paciente("Pedro")

print("Quantidade de pacientes na fila:", atendimento.quantidade_pacientes())

proximo = atendimento.proximo_paciente()
print("Próximo paciente a ser atendido:", proximo)

print("Quantidade de pacientes na fila:", atendimento.quantidade_pacientes())

proximo = atendimento.proximo_paciente()
print("Próximo paciente a ser atendido:", proximo)

proximo = atendimento.proximo_paciente()
print("Próximo paciente a ser atendido:", proximo)

print("Quantidade de pacientes na fila:", atendimento.quantidade_pacientes())

