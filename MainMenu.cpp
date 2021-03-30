#include "Game.h"
#include "MainMenu.h"
#include "AssetManager.h"
#include "Enums.h"

MainMenu::MainMenu() {}

void MainMenu ::mainMenuState(RenderWindow &app)
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

    buttonS.setSize(sf::Vector2f(460.0f, 100.0f));
    buttonS.setPosition(300.0f, 560.0f);
    buttonS.setFillColor(sf::Color(56, 14, 112));
    buttonS.setOutlineColor(sf::Color::White);
    buttonS.setOutlineThickness(3);

    buttonE.setSize(sf::Vector2f(460.0f, 100.0f));
    buttonE.setPosition(300.0f, 760.0f);
    buttonE.setFillColor(sf::Color(56, 14, 112));
    buttonE.setOutlineColor(sf::Color::White);
    buttonE.setOutlineThickness(3);

    Text txtStart;
    txtStart.setFont(font);
    txtStart.setCharacterSize(50);
    txtStart.setFillColor(Color::White);
    txtStart.setPosition(300.0f, 560.0f);

    Text txtEnd;
    txtEnd.setFont(font);
    txtEnd.setCharacterSize(50);
    txtEnd.setFillColor(Color::White);
    txtEnd.setPosition(300.0f, 760.0f);

    title.setString("Ace Combat");
    txtEnd.setString("EXIT");
    txtStart.setString("START");
    txtStart.setPosition(920.0f - buttonS.getLocalBounds().width, 570.0f);
    txtEnd.setPosition(930.0f - buttonS.getLocalBounds().width, 770.0f);

    app.draw(background);
    app.draw(title);
    app.draw(buttonS);
    app.draw(txtStart);
    app.draw(buttonE);
    app.draw(txtEnd);
}

void MainMenu::run(RenderWindow &app, Event event, GameState &gameState)
{
    app.clear();
    mainMenuState(app);

    while (app.pollEvent(event))
    {
        printf("Main menu polling\n");
        if (event.type == Event::Closed)
        {
            app.close();
        }
        // For mouse pressed.
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                if (buttonS.getGlobalBounds().contains(app.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                {
                    printf("Start click\n");
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
