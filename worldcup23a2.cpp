#include "worldcup23a2.h"

world_cup_t::world_cup_t() : teamsTreeByAbility(AVLTree<shared_ptr<Team>, SortByAbility>()),
                                teamsTreeById(AVLTree<shared_ptr<Team>, SortTeamById>()),
                                playersSets(UnionFind()) {}

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
    return StatusType::FAILURE;
    if(teamId<=0){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Team> teamToDelete = teamsTreeById.find(teamId);
    if(teamToDelete == nullptr){
    }
    try{
        teamToDelete->setIsInGame(false);
        teamsTreeById.remove(teamToDelete);
        teamsTreeByAbility.remove(teamToDelete);
    }
    catch(...){
        return StatusType::ALLOCATION_ERROR;
    }
	return StatusType::SUCCESS;
}

StatusType world_cup_t::add_player(int playerId, int teamId,
                                   const permutation_t &spirit, int gamesPlayed,
                                   int ability, int cards, bool goalKeeper)
{
	if(playerId <= 0 || teamId <= 0 || !spirit.isvalid() || gamesPlayed < 0 || cards < 0){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Team> playerTeam = teamsTreeById.find(teamId);
    shared_ptr<Player> player = playersSets.findPlayer(playerId);
    if((player != nullptr) || (playerTeam== nullptr)){
        if(player != nullptr){
            std::cout << "player is not null";
        }
        if(playerTeam == nullptr){
            std::cout << "No team";
        }

        return StatusType::FAILURE;
    }
    try{
        player = std::make_shared<Player>(playerId, spirit, gamesPlayed, ability, cards, goalKeeper);
        playersSets.makeSet(player, playerTeam);
        playersSets.addPlayerToTeam(player, playerTeam);
        teamsTreeById.remove(playerTeam);
        playerTeam->insertPlayer(player);
        teamsTreeById.insert(playerTeam);
    }
    catch(...){
        return StatusType::ALLOCATION_ERROR;
    }

	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::play_match(int teamId1, int teamId2)
{
    //TODO: recheck all the conditions
	if(teamId1 <=0 || teamId2<=0 || teamId1==teamId2){
        return StatusType::INVALID_INPUT;
    }

    shared_ptr<Team> team1 = teamsTreeById.find(teamId1);
    shared_ptr<Team> team2 = teamsTreeById.find(teamId2);

    if(team1==nullptr || team2==nullptr){
        return StatusType::FAILURE;
    }

    if(team1->getGoalkeepers()<=0 || team2->getGoalkeepers()<=0){
        return StatusType::FAILURE;
    }

    int team1Capability = team1->getTotalPlayersAbility()+team1->getPoints();
    int team2Capability = team2->getTotalPlayersAbility()+team2->getPoints();

    int team1TotalSpirit = team1->getTeamSpirit().strength();
    int team2TotalSpirit = team2->getTeamSpirit().strength();

    team1->getRootInTree()->getPlayer()->updateGamesPlayed(1);
    team2->getRootInTree()->getPlayer()->updateGamesPlayed(1);

    //probably could do more efficient, but suppose to work TODO recheck
    if(team1Capability > team2Capability){
        team1->updatePoints(WIN);
        return team1WonByCapability;
    }
    else if(team1Capability < team2Capability){
        team2->updatePoints(WIN);
        return team2WonByCapability;
    }
    else if(team1TotalSpirit > team2TotalSpirit){
        team1->updatePoints(WIN);
        return team1WonBySpirit;
    }
    else if(team1TotalSpirit < team2TotalSpirit){
        team2->updatePoints(WIN);
        return team2WonBySpirit;
    }
    else{
        team1->updatePoints(DRAW);
        team2->updatePoints(DRAW);
        return wasDraw;
    }
}

output_t<int> world_cup_t::num_played_games_for_player(int playerId)
{
	if(playerId <= 0){
        return StatusType::INVALID_INPUT;
    }
    if(playersSets.findPlayer(playerId)==nullptr){
        return StatusType::FAILURE;
    }
    int playedGames = playersSets.calculatePlayedGames(playerId);   //TODO add proper function or change here
	return playedGames;
}

StatusType world_cup_t::add_player_cards(int playerId, int cards)
{
    if(playerId <= 0 || cards<0){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Player> player = playersSets.findPlayer(playerId);
    if(player==nullptr){
        return StatusType::FAILURE;
    }
    if((playersSets.findPlayerTeam(playerId))->getIsInGame()){ //TODO check the syntax
        player->updateCards(cards);
        return StatusType::SUCCESS;
    }
	return StatusType::FAILURE;
}

output_t<int> world_cup_t::get_player_cards(int playerId)
{
    if(playerId <= 0){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Player> player = playersSets.findPlayer(playerId);
    if(player==nullptr){
        return StatusType::FAILURE;
    }

    return player->getCards();
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	if(teamId<=0){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Team> team = teamsTreeById.find(teamId);
    if(team== nullptr){
        return StatusType::FAILURE;
    }

    return team->getPoints();
}

output_t<int> world_cup_t::get_ith_pointless_ability(int i)
{
    if(teamsTreeByAbility.isEmpty()){
        return StatusType::FAILURE;
    }
    if(i<0 || i>=teamsTreeByAbility.getSize()){
        return StatusType::FAILURE;
    }

    teamsTreeByAbility.printD(teamsTreeByAbility.getRoot(), 10);
    return teamsTreeByAbility.select(i)->getTeamId(); //TODO recheck if this is how it is used
//	if(teamsTreeById.isEmpty() || teamsTreeByAbility.isEmpty()){//both suppose to be the same(by size) so check once?
//        return StatusType::FAILURE;
//    }
//    if(i<0 || i>=teamsTreeById.getSize()){
//        return StatusType::FAILURE;
//    }
//
//	return teamsTreeByAbility.select(i)->getTeamId(); //TODO recheck if this is how it is used
}

output_t<permutation_t> world_cup_t::get_partial_spirit(int playerId)
{
    if(playerId<=0){
        return StatusType::INVALID_INPUT;
    }
    //Todo recheck
    shared_ptr<Player> player = playersSets.findPlayer(playerId);
    shared_ptr<Team> playerTeam = playersSets.findPlayerTeam(playerId);
    if(player == nullptr || !(playerTeam->getIsInGame())){
        return StatusType::FAILURE;
    }

    permutation_t partialSpirit = playersSets.calculateSpirit(playerId);

	return partialSpirit;
}

StatusType world_cup_t::buy_team(int buyerId, int boughtId)
{
	// TODO: Your code goes here
    if(buyerId<=0 || boughtId<=0 || buyerId==boughtId){
        return StatusType::INVALID_INPUT;
    }
    shared_ptr<Team> buyerTeam = teamsTreeById.find(buyerId);
    shared_ptr<Team> boughtTeam = teamsTreeById.find(boughtId);
    if(buyerTeam== nullptr || boughtTeam==nullptr){
        return StatusType::FAILURE;
    }
    playersSets.unionTeams(boughtTeam, buyerTeam);
    boughtTeam->setIsInGame(false);

    buyerTeam->updateAfterBuying(boughtTeam);
    return StatusType::SUCCESS;
}
