#include "Game.h"
#include "GamePause.h"
#include "AssetManager.h"
#include "Enums.h"

GamePause::GamePause() {}

void GamePause ::gamePauseState(RenderWindow &app)
{
    AssetManager assetManager;

    Text title;
    Font font = assetManager.getFont();
    title.setFont(font);
    title.setCharacterSize(90);
    title.setFillColor(Color::Red);
    title.setPosition(280, 100);

    sf::RectangleShape buttonS;
    buttonS.setSize(sf::Vector2f(460.0f, 100.0f));
    buttonS.setPosition(300.0f, 560.0f);
    buttonS.setFillColor(sf::Color(56, 14, 112));
    buttonS.setOutlineColor(sf::Color::White);
    buttonS.setOutlineThickness(3);

    sf::RectangleShape buttonE;
    buttonE.setSize(sf::Vector2f(460.0f, 100.0f));
    buttonE.setPosition(300.0f, 760.0f);
    buttonE.setFillColor(sf::Color(56, 14, 112));
    buttonE.setOutlineColor(sf::Color::White);
    buttonE.setOutlineThickness(3);

    Text txtCont;
    txtCont.setFont(font);
    txtCont.setCharacterSize(50);
    txtCont.setFillColor(Color::White);
    txtCont.setPosition(300.0f, 560.0f);

    Text txtExit;
    txtExit.setFont(font);
    txtExit.setCharacterSize(50);
    txtExit.setFillColor(Color::White);
    txtExit.setPosition(300.0f, 760.0f);

    title.setString("GAME PAUSE ||");
    txtExit.setString("EXIT");
    txtCont.setString("CONTINUE");
    txtCont.setPosition(920.0f - buttonS.getLocalBounds().width, 570.0f);
    txtExit.setPosition(930.0f - buttonS.getLocalBounds().width, 770.0f);

    app.draw(title);
    app.draw(buttonS);
    app.draw(txtCont);
    app.draw(buttonE);
    app.draw(txtExit);

    app.display();
}

void GamePause ::run(RenderWindow &app, Event event, GameState &gameState) {

    app.clear();
    gamePauseState(app);

    while (app.pollEvent(event)) {
        printf(" pause polling\n");
        if (event.type == Event::Closed) {
            app.close();
            printf(" pause close\n");

        }
        //For esc pressed
        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Escape) {
                printf("Esc button clicked");
                gameState = GAME_PAUSE;
            } else  {
                gameState = GAME_PLAY;
                printf("Game play");
            }
        }
    }
}
