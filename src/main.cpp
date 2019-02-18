#include "ofAppNoWindow.h"  
#include "ofApp.h"
#include <iostream>
#include "cxxopts.hpp"

cxxopts::ParseResult
parse(int argc, char *argv[])
{
	try
	{
		cxxopts::Options options(argv[0], " - converting MIDI to DMX messages");
		options.add_options()
			("p,port", "port", cxxopts::value<int>())
			("l,list", "list")
			("v,virtualport", "virtualport", cxxopts::value<std::string>()->default_value("ofMIDI2DMX"));
		auto result = options.parse(argc, argv);
		return result;
	}
	catch (const cxxopts::OptionException &e)
	{
		std::cout << "error parsing options: " << e.what() << std::endl;
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	auto result = parse(argc, argv);
	auto arguments = result.arguments();
	// TODO: open virtual port depending on args and print list
	ofAppNoWindow window;
	ofSetupOpenGL(&window, 0, 0, OF_WINDOW);
	ofRunApp(new ofApp());
}

