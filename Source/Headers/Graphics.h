#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

/* Graphics class
 * Holds all information dealing with graphics for the game
 */

#include <SDL.h>

#include <map>
#include <string>

//struct SDL_Window;
//struct SDL_Renderer;

class Graphics {

public:
	Graphics();
	~Graphics();

	/* SDL_Surface* LoadImage
	Loads an image into the _spriteSheets map if it doesn't already exist.
	As a result, each image will only be loaded once. Returns the image from 
	the map regardless of whether or not it needed to be loaded.


	*/

	SDL_Surface* loadImage(const std::string &filePath);

	/* void blitSurface
	Draws textures to a certain part of the screen.
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void flip
	Renders everything to the screen.
	*/
	void flip();

	/* void clear
	Clears the screen
	*/
	void clear();

	/*SDL_Renderer* getRenderer
		returns the renderer.
	*/
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	//Holds all spritesheets loaded into the game.
	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif

