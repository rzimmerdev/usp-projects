"""
Program to manage and analyze groups sent and built by students through CSV files.

@Author: Rafael Zimmer
"""
from GroupsManager import GroupsManager


def main():
    group_manager = GroupsManager("SSC0103-2022-Definição dos grupos-4240978.zip",
                                  "ListadeApoioaoDocente-SSC01032022101.csv",
                                  "ListadeApoioaoDocente-SSC01032022102.csv")
    print(group_manager, end="-------------------------\n\n")

    for student in group_manager.selector.get_single_students():
        print(f"Aluno sem grupo: {student[1]}, nUsp: {student[0]}")

    for student in group_manager.selector.get_invalid_students():
        print(f"Invalido: {student[0]} no grupo {student[1]}")

    for group in group_manager.selector.get_bad_formatted():
        print(f"Grupo invalido: {group[0]}")

    for group in group_manager.selector.get_heterogeneous():
        print(f"Grupo com menos ou mais de 4 integrantes ({len(group[1])} no total): {group[0]}")

    for group in group_manager.selector.get_multiclass_groups():
        print(f"Grupos com integrantes em mais de uma turma: {group[0]}")


if __name__ == "__main__":
    main()
