class GroupSelector:

    def __init__(self, groups, classes):
        """Use this class to filter multiple groups separated by classes using different questions."""
        self.groups = groups
        self.classes = classes
        self.students = []

        for students_class in self.classes:
            self.students.extend(students_class)

    def groups_by_class(self):
        """Return given groups separated by the classes their students belong to."""
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
        """Return all students that do not belong to a valid group."""
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
        """Return all groups that have students belonging to more than one class"""
        multiclass_groups = []
        id_by_class = [[student[0] for student in student_class] for student_class in self.classes]
        for group in self.groups:
            if group[1] == -1:
                continue
            class_count = [0 for _ in range(len(self.classes))]
            for student in group[1]:
                for idx in range(len(class_count)):
                    class_count[idx] += student[0] in id_by_class[idx]

            if len(list(filter(lambda num: num != 0, class_count))) > 1:
                multiclass_groups.append(group)

        return multiclass_groups

    def get_heterogeneous(self, expected_size=4):
        """Return all groups with number of members different of expected size."""
        heterogenous_groups = []
        for group in self.groups:
            if group and group[1] != -1 and len(group[1]) != expected_size:
                heterogenous_groups.append(group)

        return heterogenous_groups

    def get_bad_formatted(self):
        """Return all groups which have yielded an invalid read from their CSV file using the standard library."""
        bad_formatted_groups = []
        for group in self.groups:
            if not group or group[1] == -1:
                bad_formatted_groups.append(group)

        return bad_formatted_groups

    def get_invalid_students(self):
        """Return all student-group combinations in which given student id inside the group is not a valid one."""
        invalid_students = []
        students_ids = [student[0] for student in self.students]
        for group in self.groups:
            if group[1] == -1:
                continue
            for student in group[1]:
                if student and student[0] not in students_ids:
                    invalid_students.append((student, group[0]))

        return invalid_students
