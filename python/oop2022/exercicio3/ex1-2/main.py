from People import Person, PersonPhysical, PersonJudicial
from Agenda import Agenda


def main():
    pessoas = Agenda()

    new_contacts = [
        PersonPhysical("978.173.427-25", "Thomas Tiago da Cunha", "Rua da Glória, 442", "thomas-dacunha86@gmail.com"),
        PersonJudicial("06.510.003/0001-51", "ABIAS Imoveis", "R. Miguel Petroni, 1316", "abiasimoveis@gmail.com.br"),
        PersonPhysical("406.753.724-70", "Miguel Tiago Moreira", "Avenida Governador Agamenon", "mmoreira@proton.com")
    ]

    new_contacts[0].age = 37
    new_contacts[1].civil_state = "Solteiro"
    new_contacts[2].social_reason = "Imoveis por precos acessiveis!"

    pessoas.add_contacts(new_contacts)
    print("Pessoas:")
    print(pessoas)

    pessoas.order_contacts()
    print("Pessoas Ordenadas por CPF e CNPJ:")
    print(pessoas)


if __name__ == "__main__":
    main()
