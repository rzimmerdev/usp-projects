from abc import ABC


class Person(ABC):
    _person_record: str = ""

    def __init__(self, name: str, address: str, email: str):
        self.name: str = name
        self.address: str = address
        self.email: str = email


class PersonPhysical(Person):
    age: int = -1
    civil_state: str = "Indefinido"

    def __init__(self, cpf: str, name: str, address: str, email: str):
        super().__init__(name, address, email)

        self._person_record: str = cpf

    def get_cpf(self) -> str:
        return self._person_record

    def __eq__(self, other):
        return self._person_record == other.get_cpf()

    def __lt__(self, other):
        return self._person_record < other.get_cpf()


class PersonJudicial(Person):
    state_subscription: str = "Nenhum dado obtido"
    social_reason: str = "Nenhuma razao informada"

    def __init__(self, cnpj: str, name: str, address: str, email: str):
        super().__init__(name, address, email)

        self._person_record: str = cnpj

    def get_cnpj(self) -> str:
        return self._person_record

    def __eq__(self, other):
        return self._person_record == other.get_cnpj()

    def __lt__(self, other):
        return self._person_record < other.get_cnpj()
