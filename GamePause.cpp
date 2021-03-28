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

    buttonC.setSize(sf::Vector2f(460.0f, 100.0f));
    buttonC.setPosition(300.0f, 560.0f);
    buttonC.setFillColor(sf::Color(56, 14, 112));
    buttonC.setOutlineColor(sf::Color::White);
    buttonC.setOutlineThickness(3);

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

    app.draw(background);
    title.setString("GAME PAUSE");
    txtExit.setString("EXIT");
    txtCont.setString("CONTINUE");
    txtCont.setPosition(870.0f - buttonC.getLocalBounds().width, 570.0f);
    txtExit.setPosition(930.0f - buttonE.getLocalBounds().width, 770.0f);

    app.draw(title);
    app.draw(buttonC);
    app.draw(txtCont);
    app.draw(buttonE);
    app.draw(txtExit);

    app.display();
}

void GamePause ::run(RenderWindow &app, Event event, GameState &gameState)
{
    app.clear();
    gamePauseState(app);

    while (app.pollEvent(event))
    {
        printf(" pause polling\n");
        if (event.type == Event::Closed)
        {
            app.close();
            printf(" pause close\n");
        }
        // For mouse pressed.
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                printf("button left click\n");
                if (buttonC.getGlobalBounds().contains(app.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                {
                    printf("start click\n");
                    gameState = GAME_PLAY;
                }
                else if (buttonE.getGlobalBounds().contains(app.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                {
                    printf("exit click\n");
                    app.close();
                }
            }
        }
    }
}
