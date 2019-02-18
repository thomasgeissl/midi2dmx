#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxDmx.h"

class ofApp : public ofBaseApp, public ofxMidiListener
{

public:
	void setup();
	void update();

	void newMidiMessage(ofxMidiMessage &eventArgs);
	ofxMidiIn _midiIn;
	ofxDmx _dmx;
	std::string _name = "ofMIDIDMX";
};
