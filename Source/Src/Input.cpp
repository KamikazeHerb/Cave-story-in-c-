#include <Input.h>

/*Input class
*keeps track of keyboard state
*
*/


//	This function is called at the beginning of each new frame to reset
//  the keys that are no longer relevant.
void Input::beginNewFrame() {

	this->_pressedKeys.clear();
	this->_releasedKeys.clear();

}

//Called when a key has been pressed
void Input::keyDownEvent(const SDL_Event& event) {

	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;


}

//Called when a key has been released
void Input::keyUpEvent(const SDL_Event& event) {

	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;

}

//Checks if a certain key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key) {

	return this->_pressedKeys[key];
}

//Checks if a certain key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key) {

	return this->_releasedKeys[key];
}

//Check to see if a certain key is held
bool Input::isKeyHeld(SDL_Scancode key) {

	return this->_heldKeys[key];

}