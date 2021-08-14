#include "GameState.h"


void GameState::initButton() {
	this->paused = false;
	this->secondPlayer = false;

	this->btns["voltar"] = new Button(600, 200, 350, 80, "Continuar", &this->font,
		sf::Color(0, 0, 0, 230),
		sf::Color(10, 10, 10, 200),
		sf::Color(20, 20, 20, 150));

	this->btns["jogador"] = new Button(600, 300, 350, 80, "Adicionar Jogador", &this->font,
		sf::Color(0, 0, 0, 230),
		sf::Color(10, 10, 10, 200),
		sf::Color(20, 20, 20, 150));

	this->btns["salvarScore"] = new Button(600, 400, 350, 80, "Salvar Pontuacao", &this->font,
		sf::Color(0, 0, 0, 230),
		sf::Color(10, 10, 10, 200),
		sf::Color(20, 20, 20, 150));
	this->btns["SalvarJogo"] = new Button(600, 500, 350, 80, "Salvar Jogo", &this->font,
		sf::Color(0, 0, 0, 230),
		sf::Color(10, 10, 10, 200),
		sf::Color(20, 20, 20, 150));
	this->btns["CarregarJogo"] = new Button(600, 600, 350, 80, "Carregar Jogo", &this->font,
		sf::Color(0, 0, 0, 230),
		sf::Color(10, 10, 10, 200),
		sf::Color(20, 20, 20, 150));
	this->btns["SAIR"] = new Button(600, 700, 350, 80, "Sair", &this->font,
		sf::Color(0, 0, 0, 230),
		sf::Color(10, 10, 10, 200),
		sf::Color(20, 20, 20, 150));
}
void GameState::initScore(int score) {
	bool write = true;
	this->score = score;
	this->ScoreText.setFont(this->font);
	this->ScoreText.setFillColor(sf::Color::White);
	this->ScoreText.setCharacterSize(70);
	this->ScoreText.setPosition(sf::Vector2f(1300.f, 30.f));
}
void GameState::initLife() {
	this->LifeText.setFont(this->font);
	this->LifeText.setFillColor(sf::Color::White);
	this->LifeText.setCharacterSize(70);
	this->LifeText.setPosition(sf::Vector2f(200.f, 30.f));
}


void GameState::initTextures() {
	
	try{
		this->textures["PLAYER_SHEET"].loadFromFile("Resources/sprites/pinkman.png");
		this->textures["ENEMY_SHEET"].loadFromFile("Resources/sprites/manpink.png");
		this->textures["PORTAL_SHEET"].loadFromFile("Resources/sprites/portal.png");
		this->textures["BUNNY_SHEET"].loadFromFile("Resources/sprites/bunny.png");
		this->textures["PLANT_SHEET"].loadFromFile("Resources/sprites/plant.png");
		this->textures["FLAME_SHEET"].loadFromFile("Resources/sprites/flame.png");
		this->textures["BOX"].loadFromFile("Resources/sprites/box.png");
	}
	catch (const std::exception&){
		throw("PLAYER_SHEET COULD NOT LOAD\n");
	}	
}


void GameState::initPlayers() {
	player = new Player(100,100,textures["PLAYER_SHEET"]);
}


void GameState::initList() {
	entities.add(new Enemy(900, 800, textures["ENEMY_SHEET"]));
	
	entities.add(new Plant(600, 300, textures["PLANT_SHEET"]));
	
	entities.add(new Bunny(900, 500, textures["BUNNY_SHEET"]));
	
	entities.add(new Portal(1000, 80, textures["PORTAL_SHEET"]));
	
	entities.add(new Flame(500, 750, textures["FLAME_SHEET"]));
	entities.add(new Flame(600, 480, textures["FLAME_SHEET"]));
	entities.add(new Flame(80, 480, textures["FLAME_SHEET"]));
	
	entities.add(new Box(200, 784, textures["BOX"]));
	entities.add(new Box(400, 784, textures["BOX"]));
	entities.add(new Box(840, 784, textures["BOX"]));
}

void GameState::initPauseMenu() {
	
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states)
{
	
	initFont();
	initTextures();
	initPlayers();
	initList();
	initPauseMenu();


	initButton();
	initScore(0);
	initLife();


	collisions.add(player, &entities);
	this->map = new MainTileMap();
}


GameState::~GameState() {
	delete player;
	
	entities.destroy();

	auto it = this->btns.begin();

	for (it = this->btns.begin(); it != this->btns.end(); ++it)
	{
		delete it->second;
	}

}

void GameState::updateKeybinds(const float& dt) {
	this->checkQuit();
}

void GameState::updateInput(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

		paused = true;
		this->write = true;

	}
}

void GameState::updatePlayerInput(const float& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->move(dt, 0.f, 1.f);


	for (auto& it : this->btns) {
		it.second->update(this->mousePosView);
	}

	// SAIR DO JOGO
	if (this->btns["SAIR"]->isPressed()) {
		this->quit = true;
	}
	else if (this->btns["voltar"]->isPressed()) {
		this->paused = false;
	}
	else if (this->btns["jogador"]->isPressed()) {
		this->secondPlayer = true;
	}
	else if (this->btns["salvarScore"]->isPressed()) {
		//salvar pontuação 
		save();
	}
	else if (this->btns["SalvarJogo"]->isPressed()) {
		// salvar jogo
	}
	else if (this->btns["CarregarJogo"]->isPressed()) {
		//carregar jogo
	}
}


void GameState::updateBtn() {
	for (auto& it : this->btns) {
		it.second->update(this->mousePosView);
	}
}

void GameState::updateScore() {
	this->ScoreText.setString(std::to_string(this->score));
}

void GameState::updateLife() {
	int vida = this->player->getID();
	this->LifeText.setString(std::to_string(vida));
	if (vida <= 0) {
		//this->quit = true;
	}
}



void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	updateInput(dt);
	updateMousePosition();
	updatePlayerInput(dt);
	//updateCollision();

	if (!paused) {
				
		player->update(dt);		
		entities.update(dt);
		collisions.update(dt);
		map->updateCollision(player, dt);
	
		updateScore();
		updateLife();
	}
	if(paused) {
		updateBtn();
	}	
}


void GameState::renderBtn(sf::RenderTarget& target) {
	if (this->paused) {
		for (auto& it : this->btns) {
			it.second->render(target);
		}
	}
}

void GameState::renderScore(sf::RenderTarget& target) {
	target.draw(this->ScoreText);
}

void GameState::renderLife(sf::RenderTarget& target) {
	target.draw(this->LifeText);
}


void GameState::render(sf::RenderTarget& target){
	this->map->render(target);
	
	entities.render(target);

	player->render(target);
	
	renderScore(target);

	renderLife(target);

	renderBtn(target);
}



void GameState::save() {
	if (write) {
		arquivoPlacar.open("Score/score.txt", std::ios::app);
		arquivoPlacar << score << "\n";
		arquivoPlacar.close();
		this->write = false;
	}
}




