
class CommunityMember
{
};
class Employee : public CommunityMember
{
};
class Student : public CommunityMember
{
};
class Faculty : public Employee
{
};
class Teacher : public Faculty
{
};

class admin : public Faculty, public Student
{
};
