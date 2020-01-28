#include "Chess.hpp"

	ChessGame::ChessGame():
	Game(numberOfPlayers_), numOfTurns_(0){}

	void ChessGame::run() noexcept{
		take_turn();
		has_winner();
		result();
	}

	bool ChessGame::has_winner() const noexcept{
		bool hasWinner = false;
		auto b = [&hasWinner , this ]() {
			if(numOfTurns_==MaxTurns_)
				hasWinner= true;
		};
		b();
		return hasWinner;
	}

	void ChessGame::result() noexcept  {
		std::cout << "Winner is player " << currentPlayer << "\n";
	}

	void ChessGame::take_turn()noexcept {
		while(!has_winner()){
		numOfTurns_++;
		std::cout << "Turn taken by " << currentPlayer << "\n";
		currentPlayer = (currentPlayer % 2) + 1;
		}
	}
