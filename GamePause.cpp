#include "Game.h"
#include "GamePause.h"
#include "AssetManager.h"
#include "Enums.h"

GamePause::GamePause() {}

void GamePause ::gamePauseState(RenderWindow &app)
{
    AssetManager assetManager;

    Texture backgroundTexture = assetManager.getMenuTexture();
    background.setTexture(backgroundTexture);

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

    title.setString("GAME PAUSE ||");
    txtExit.setString("EXIT");
    txtCont.setString("CONTINUE");
    txtCont.setPosition(920.0f - buttonS.getLocalBounds().width, 570.0f);
    txtExit.setPosition(930.0f - buttonS.getLocalBounds().width, 770.0f);

    app.draw(background);
    app.draw(title);
    app.draw(buttonS);
    app.draw(txtCont);
    app.draw(buttonE);
    app.draw(txtExit);
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
        }

        //For esc pressed
        // if (event.type == Event::KeyPressed)
        //     if (event.key.code == Keyboard::Escape)
        //     {
        //         gameState = GAME_PLAY;
        //     }
        // if (Keyboard::isKeyPressed(Keyboard::Escape))
        // {
        //     printf("Esc button clicked");
        //     gameState = GAME_PLAY;
        // }
    title.setString("GAME PAUSE");
    txtExit.setString("EXIT");
    txtCont.setString("CONTINUE");
    txtCont.setPosition(870.0f - buttonC.getLocalBounds().width, 570.0f);
    txtExit.setPosition(930.0f - buttonC.getLocalBounds().width, 770.0f);

    app.draw(background);
    app.draw(title);
    app.draw(buttonC);
    app.draw(txtCont);
    app.draw(buttonE);
    app.draw(txtExit);
}

void GamePause ::run(RenderWindow &app, Event event, GameState &gameState)
{
    app.clear();
    gamePauseState(app);

    while (app.pollEvent(event))
    {
        printf("Pause polling\n");
        if (event.type == Event::Closed)
        {
            app.close();
        }
        // For mouse pressed.
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                printf("Button left click\n");
                if (buttonC.getGlobalBounds().contains(app.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                {
                    printf("Continue click\n");
                    gameState = GAME_PLAY;
                }
                else if (buttonE.getGlobalBounds().contains(app.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                {
                    printf("Exit click\n");
                    app.close();
                }
            }
        }
    }
}
