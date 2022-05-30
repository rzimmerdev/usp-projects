from GroupsManager import GroupsManager
from GroupSelector import GroupSelector


def main():
    group_manager = GroupsManager("SSC0103-2022-Definição dos grupos-4240978.zip",
                                  "ListadeApoioaoDocente-SSC01032022101.csv",
                                  "ListadeApoioaoDocente-SSC01032022102.csv")

    for student in group_manager.selector.get_invalid_students():
        print(f"Invalido: {student[0]} no grupo {student[1]}")

    for group in group_manager.selector.get_bad_formatted():
        print(f"Grupo invalido: {group[0]}")

    for group in group_manager.selector.get_heterogeneous():
        print(f"Grupo com menos ou mais de 4 integrantes: {group[0]}")

    print(group_manager.selector.get_single_students())

    print(group_manager)


if __name__ == "__main__":
    main()
