#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	if (TTF_Init() == -1)
	{
		std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	SDL_Window* win =
		SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(win);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	// Load background image
	SDL_Surface* bgSurface = IMG_Load("../src/resources/data/Graphics/tauler.png");
	if (bgSurface == nullptr)
	{
		std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		return 1;
	}
	SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(ren, bgSurface);
	SDL_FreeSurface(bgSurface); // We no longer need the surface

	// Load font and render text
	TTF_Font* font = TTF_OpenFont("../src/resources/data/fonts/FreeSans.ttf", 24);
	if (font == nullptr)
	{
		std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
		SDL_DestroyTexture(bgTexture);
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	SDL_Color textColor = { 255, 255, 255 }; // White text
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Hello", textColor);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_Rect textRect = { 10, 10, textSurface->w, textSurface->h };
	SDL_FreeSurface(textSurface);

	// Main loop
	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, bgTexture, NULL, NULL); // Draw the background
		SDL_RenderCopy(ren, textTexture, NULL, &textRect); // Draw the text
		SDL_RenderPresent(ren);
	}

	// Cleanup
	SDL_DestroyTexture(textTexture);
	SDL_DestroyTexture(bgTexture);
	TTF_CloseFont(font);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

	return 0;
}
