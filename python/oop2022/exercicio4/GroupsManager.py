import csv
import zipfile
from io import TextIOWrapper

from GroupSelector import GroupSelector


class GroupsManager:
    def __init__(self, group_folder, *classes):

        self.groups = []

        group_zip = zipfile.ZipFile(group_folder, "r")
        file_list = group_zip.namelist()

        for group_name in file_list:

            group_csv = group_zip.open(group_name, 'r')
            try:
                members = csv.reader(TextIOWrapper(group_csv))
                members = list(members)

                for idx, member in enumerate(members):
                    if member and type(member[0]) == str and not member[0].isdigit():
                        members[idx] = member[0].split(",")
            except UnicodeDecodeError:
                self.groups.append((group_name, -1))
                group_csv.close()
                continue
            current_group = (group_name, [member for member in members if member])

            self.groups.append(current_group)
            group_csv.close()

        self.classes = []

        for student_class in classes:
            file = open(student_class, newline='')
            students = csv.reader(file)
            self.classes.append(list(students))

        self.selector = GroupSelector(self.groups, self.classes)

    def __str__(self):

        representation = ""
        grouped_by_class = self.selector.groups_by_class()
        for idx, student_class in enumerate(grouped_by_class):
            representation += f"-=-=-=-=-=-=-=-=-\nTurma Numero {idx + 1}:\n-=-=-=-=-=-=-=-=-\n"
            for group in student_class:
                representation += "Nome do Grupo: " + group[0] + "\n"
                representation += "Membros: "
                for member in group[1]:
                    representation += f"({member[0]}, {member[1]})" + " "
                representation += "\n\n"

        return representation
