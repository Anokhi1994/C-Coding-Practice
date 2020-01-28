#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <map>
class Game{
private:
	int numberOfPlayers_;
public:
	Game() =default;

	Game(int numberOfPlayers):
		numberOfPlayers_(numberOfPlayers){}

	virtual void run() noexcept {};

	virtual void take_turn()noexcept = 0;

	virtual bool has_winner() const noexcept = 0;

	virtual void result() noexcept = 0;

	virtual ~Game() = default;
};


#endif
