class GroupSelector:

    def __init__(self, groups, classes):
        self.groups = groups
        self.classes = classes
        self.students = []

        for students_class in self.classes:
            self.students.extend(students_class)

    def groups_by_class(self):

        id_by_class = [[student[0] for student in student_class] for student_class in self.classes]
        groups = [list() for _ in range(len(self.classes))]
        for group in self.groups:
            if group[1] == -1:
                continue
            for class_id in range(len(self.classes)):
                if group[1][0][0] in id_by_class[class_id]:
                    groups[class_id].append(group)
                    break
        return groups

    def get_single_students(self):

        grouped_students = []
        for group in self.groups:
            if group and group[1] != -1:
                grouped_students.extend(group[1])

        grouped_students_ids = [student[0] for student in grouped_students]

        single_students = []
        for student in self.students:
            if student[0] not in grouped_students_ids:
                single_students.append(student)

        return single_students

    def get_multiclass_groups(self):


    def get_heterogeneous(self):

        heterogenous_groups = []
        for group in self.groups:
            if group and group[1] != -1 and len(group[1]) != 4:
                heterogenous_groups.append(group)

        return heterogenous_groups

    def get_bad_formatted(self):

        bad_formatted_groups = []
        for group in self.groups:
            if not group or group[1] == -1:
                bad_formatted_groups.append(group)

        return bad_formatted_groups

    def get_invalid_students(self):
        invalid_students = []
        students_ids = [student[0] for student in self.students]
        for group in self.groups:
            if group[1] == -1:
                continue
            for student in group[1]:
                if student and student[0] not in students_ids:
                    invalid_students.append((student, group[0]))

        return invalid_students
