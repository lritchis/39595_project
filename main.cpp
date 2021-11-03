#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "XMLParser.h"
#include "Handler.h"

int main(int argc, char** args) {
	// prompt for XML file to parse
	std::string filename;
	bool shouldPause = true;

	// if given a second argument, use that as the XML file
	// means calling "XMLParseDemo studentActivity.xml" will parse the file "studentActivity.xml". The Makefile is set up to supply this argument when using on command line
	if (argc >= 2) {
		filename = args[1];
		shouldPause = false;
	}
	else {
		// if no argument, prompt for filename. This is the form used in running in Visual Studio
		std::cout << "Enter filename: ";
		std::cin >> filename;
		// remove the extra newline character from cin
		std::cin.get();
	}

	// call the parser to parse the XML
	XMLParser parser;
	Dungeon dungeon = parser.parseXML(filename);
	
	Handler handler(&dungeon);

	int check = handler.setItemOwners();
	
	if (check == 0) {
		return EXIT_FAILURE;
	}

	check = handler.handleInput();

	if (check == 0) {
		return EXIT_SUCCESS;
	}

	// print all results
	/*std::cout << "Found " << students.size() << " students" << std::endl;
	for (Student* student : students) {
		std::cout << "Student" << std::endl;
		std::cout << "  Name: " << student->getName() << std::endl;
		std::cout << "  Activities: " << student->getActivities().size() << std::endl;
		for (Activity* activity : student->getActivities()) {
			activity->printData("    ");
		}
	}*/

	// free memory
	/*for (Student* student : students) {
		delete student;
	}
	students.clear(); // not strictly required, I just like to remove references to pointers after deleting them
    */
	// wait for key press to exit, added for the sake of visual studio as the command window closes after the program finishes
	// skipped when a filename is given via command line, that is what the makefile is set up to use
	// worth pointing out that this is not strictly related to XML parsing, it is just done to make testing the program easier
	// if (shouldPause) std::cin.get();

	return EXIT_SUCCESS;
}