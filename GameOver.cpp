#include "Game.h"
#include "GameOver.h"
#include "AssetManager.h"
#include "Enums.h"

GameOver::GameOver() { endScore = 0; }

void GameOver ::state(RenderWindow &app)
{
    AssetManager assetManager;

    Texture backgroundTexture = assetManager.getMenuTexture();
    background.setTexture(backgroundTexture);

    Text title;
    Font font = assetManager.getFont();
    title.setFont(font);
    title.setCharacterSize(90);
    title.setFillColor(Color::Red);
    title.setPosition(300, 100);

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

    Text label;
    label.setFont(font);
    label.setCharacterSize(50);
    label.setFillColor(Color::Red);
    label.setPosition(290, 350);

    Text score;
    score.setFont(font);
    score.setCharacterSize(50);
    score.setFillColor(Color::Red);
    score.setPosition(650, 350);

    title.setString("Game Over");
    label.setString("Your Score:");

    //////Get score
    score.setString(to_string(endScore));
    //////
    txtStart.setString("RESTART");
    txtEnd.setString("EXIT");

    txtStart.setPosition(890.0f - buttonS.getLocalBounds().width, 570.0f);
    txtEnd.setPosition(930.0f - buttonS.getLocalBounds().width, 770.0f);

    app.draw(background);
    app.draw(title);
    app.draw(label);
    app.draw(score);
    app.draw(buttonS);
    app.draw(txtStart);
    app.draw(buttonE);
    app.draw(txtEnd);
}

void GameOver::run(RenderWindow &app, Event event, GameState &gameState)
{
    app.clear();
    state(app);

    while (app.pollEvent(event))
    {
        if (event.type == Event::Closed)
            app.close();

        // For mouse pressed.
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                if (buttonS.getGlobalBounds().contains(app.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    gameState = GAME_REPLAY;

                else if (buttonE.getGlobalBounds().contains(app.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    app.close();
            }
        }
    }
}

void GameOver::setEndScore(int endScore)
{
    this->endScore = endScore;
}
