import csv
import zipfile
from io import TextIOWrapper

from GroupSelector import GroupSelector


class GroupsManager:
    def __init__(self, group_folder, *classes):
        """Use this class to manage many groups of students separated by multiple classes.
        Each group can contain multiple students, and all groups can be filtered using the selector
        object instantiated by the manager.

        Args:
            group_folder: Folder from which to scan all student groups, saved in CSV files.
            *classes: All file names containing students separated by different classes
        """
        self.groups = []

        group_zip = zipfile.ZipFile(group_folder, "r")
        file_list = group_zip.namelist()

        # Scan each group inside group_folder and save separately in groups list.
        for group_name in file_list:

            group_csv = group_zip.open(group_name, 'r')
            try:
                members = csv.reader(TextIOWrapper(group_csv), quotechar='"')
                members = list(members)

                for idx, member in enumerate(members):
                    if member and len(member) != 2:
                        members = []
                        break
                    if member and type(member[0]) == str and not member[0].isdigit():
                        members[idx] = member[0].split(",")
            except UnicodeDecodeError:
                members = []

            if members:
                current_group = (group_name, [member for member in members if member])
            else:
                current_group = (group_name, -1)
            self.groups.append(current_group)
            group_csv.close()

        self.classes = []

        # Reads each class file and saves students read in list
        for student_class in classes:
            file = open(student_class, newline='')
            students = csv.reader(file)
            self.classes.append(list(students))

        # Instantiate selector object with given input files and directories.
        self.selector = GroupSelector(self.groups, self.classes)

    def __str__(self):
        """Returns the string representation of all student groups organized by class."""

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
