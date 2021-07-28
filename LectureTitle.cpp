#include <iostream>
#include <string>

using namespace std;

struct Specialization {
	string value;
	explicit Specialization(string new_value) {
		value = new_value;
	}
};

struct Course {
	string value;
	explicit Course(const string& new_value) {
		value = new_value;
	}
};

struct Week {
	string value;
	explicit Week(const string& new_value) {
		value = new_value;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(const Specialization& s, const Course& w, const Week& k) {
		specialization = s.value;
		course = w.value;
		week = k.value;
	}
};

void PrintLecture(const LectureTitle& Lecture) {
	cout << Lecture.specialization << "." << Lecture.course << "."
		<< Lecture.week << "\n";
}

int main() {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	PrintLecture(title);
	return 0;
}
