#include "ofApp.h"

void ofApp::setup()
{
	_dmx.connect("tty.usbserial-EN160415");

	_midiIn.listInPorts();
	_midiIn.openVirtualPort(_name);
	_midiIn.ignoreTypes(false, false, false);
	_midiIn.addListener(this);
	_midiIn.setVerbose(true);
}

void ofApp::update()
{
	_dmx.update();
}

void ofApp::newMidiMessage(ofxMidiMessage &msg)
{
	if (msg.status == MIDI_NOTE_ON)
	{
		_dmx.setLevel(msg.pitch, msg.velocity * 2);
	}
}
