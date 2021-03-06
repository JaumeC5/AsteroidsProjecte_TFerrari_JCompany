#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include"SDL_mixer.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void init() {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw SDL_GetError();
	const Uint8 imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags)) throw IMG_GetError();
	if (TTF_Init() != 0) printf("problema");
	TTF_Font * font = TTF_OpenFont("../../res/ka1.ttf", 35);
	if (font == NULL) printf("%s", TTF_GetError());
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

