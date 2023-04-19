from typing import List

from People import Person, PersonPhysical, PersonJudicial


class Agenda:
    @staticmethod
    def insertion_sort(to_sort):
        for i in range(1, len(to_sort)):
            current = to_sort[i]

            ins = i - 1
            while (not ins < 0) and to_sort[ins] > current:
                to_sort[ins + 1] = to_sort[ins]
                ins -= 1

            to_sort[ins + 1] = current
        return to_sort

    def __init__(self):
        self._contacts = list()

    def add_contacts(self, new_contacts: list):
        self._contacts.extend(new_contacts)

    def get_contacts(self) -> list:
        return self._contacts

    def search_contacts(self, **kwds) -> List[Person]:

        found_contacts = []

        if "cpf" in kwds and type(kwds.get("cpf")) == str:
            found_contacts.extend([person for person in self._contacts
                                   if type(person) is PersonPhysical and person.get_cpf() == kwds["cpf"]])

        if "cnpj" in kwds and type(kwds.get("cnpj")) == str:
            found_contacts.extend([person for person in self._contacts
                                   if type(person) is PersonJudicial and person.get_cnpj() == kwds["cnpj"]])

        return found_contacts

    def order_contacts(self):
        physical = [person for person in self.get_contacts() if type(person) == PersonPhysical]
        physical_sorted = self.insertion_sort(physical)

        judicial = [person for person in self.get_contacts() if type(person) == PersonJudicial]
        judicial_sorted = self.insertion_sort(judicial)

        physical_sorted.extend(judicial_sorted)

        self._contacts = physical_sorted

    def __str__(self):
        pretty = ""

        for person in self.get_contacts():
            if type(person) == PersonPhysical:
                pretty += "CPF: {}, Nome: {}\nEndereco: {}, Email: {}\n" \
                          "Idade: {}, Estado Civil: {}\n\n" \
                    .format(person.get_cpf(), person.name, person.address, person.email, person.age, person.civil_state)

            elif type(person) == PersonJudicial:
                pretty += "CNPJ: {}, Nome: {}\nEndereco: {}, Email: {}\n" \
                          "Inscricao Estadual: {}, Razao Social: {}\n\n" \
                    .format(person.get_cnpj(), person.name, person.address, person.email,
                            person.state_subscription, person.social_reason)

        return pretty
