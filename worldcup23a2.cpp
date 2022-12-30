#include "worldcup23a2.h"

world_cup_t::world_cup_t()
{
	// TODO: Your code goes h
}

world_cup_t::~world_cup_t()
{
	// TODO: Your code goes here
}

StatusType world_cup_t::add_team(int teamId)
{
	if(teamId<=0){
        return StatusType::INVALID_INPUT;
    }
    if(teamsTreeById.find(teamId) != nullptr){
        return StatusType::FAILURE;
    }
    try{
        shared_ptr<Team> newTeam = std::make_shared<Team>(teamId);
        teamsTreeById.insert(newTeam);
        teamsTreeByAbility.insert(newTeam);
    }
    catch(...){
        return StatusType::ALLOCATION_ERROR;
    }
	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_team(int teamId)
{
    if(teamId<=0){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Team> teamToDelete = teamsTreeById.find(teamId);
    if(teamToDelete == nullptr){
        return StatusType::FAILURE;
    }
    try{
        teamToDelete->setIsInGame(false);
        teamsTreeById.remove(teamToDelete);
        teamsTreeByAbility.remove(teamToDelete);
    }
    catch(...){
        return StatusType::ALLOCATION_ERROR;
    }
	return StatusType::FAILURE;
}

StatusType world_cup_t::add_player(int playerId, int teamId,
                                   const permutation_t &spirit, int gamesPlayed,
                                   int ability, int cards, bool goalKeeper)
{
	if(playerId <= 0 || teamId <= 0 || !spirit.isvalid() || gamesPlayed < 0 || cards < 0){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Team> playerTeam = teamsTreeById.find(playerId);
    shared_ptr<Player> player = playersSets.findPlayer(playerId);
    if((player != nullptr) || (playerTeam== nullptr)){
        return StatusType::FAILURE;
    }
    try{
        player = std::make_shared<Player>(playerId, spirit, gamesPlayed, ability, cards, goalKeeper);
        playersSets.makeSet(player, playerTeam);
        playersSets.addPlayerToTeam(player, playerTeam);
        playerTeam->insertPlayer(player);
    }
    catch(...){
        return StatusType::ALLOCATION_ERROR;
    }

	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::play_match(int teamId1, int teamId2)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::num_played_games_for_player(int playerId)
{
	// TODO: Your code goes here
	return 22;
}

StatusType world_cup_t::add_player_cards(int playerId, int cards)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_player_cards(int playerId)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	// TODO: Your code goes here
	return 30003;
}

output_t<int> world_cup_t::get_ith_pointless_ability(int i)
{
	// TODO: Your code goes here
	return 12345;
}

output_t<permutation_t> world_cup_t::get_partial_spirit(int playerId)
{
	// TODO: Your code goes here
	return permutation_t();
}

StatusType world_cup_t::buy_team(int teamId1, int teamId2)
{
	// TODO: Your code goes here
	return StatusType::SUCCESS;
}
