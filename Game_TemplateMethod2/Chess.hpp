#ifndef CHESS_HPP
#define CHESS_HPP
#include "Game.hpp"
class ChessGame : public Game{
private:
	const int numberOfPlayers_  = 2;
	int numOfTurns_ = 0;
	const int MaxTurns_ = 10;
	int currentPlayer = 1;
public:
	ChessGame();

	virtual void run() noexcept override;

	virtual void take_turn()noexcept override;

	virtual bool has_winner() const noexcept override;

	virtual void result() noexcept override;
};

#endif
