#pragma once
#include "Resource.h"
#include "Games.h"
using namespace std;

class GameInterface {
	public:
		GameInterface();
		void Start();


	private:
		Game_RSP *GameClinet;
		bool Selector();
		


};