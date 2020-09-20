// Doors.h
//
// Header file for the class: Game

#ifndef _GAME_H
#define _GAME_H

#include "Doors.h"
#include "Game.h"
#include "Player.h"
#include "Host.h"

class Game
{
    public:
        void RunGame( std::string Name, int action, int UserPickedDoorSetter );
        double AverageScoreReport( int NumberOfGames );

    private:
        int _Outcome = 0;
        int _TotalScore = 0;
        int _GamesPlayed;
        double _AverageScore;
        std::string _ThePlayerName;

};

#endif
