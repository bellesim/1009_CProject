#include "Game.h"
#include "MainMenu.h"
#include "AssetManager.h"
#include "Enums.h"

MainMenu::MainMenu() : main(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default)
{
    main.setFramerateLimit(60);
}

void MainMenu::run()
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

    while (main.isOpen())
    {
        sf::Event event;
        while (main.pollEvent(event))
        {
            if (event.type == Event::Closed){
                main.close();
            }

           if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (buttonS.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
                        std::cout << "Button pressed START" << std::endl;
                        GameState gameState = GameState::GAME_PLAY;
                        main.close();

                        Game newGame;
                        newGame.run();
                    }
                    else if(buttonE.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        main.close();

                    }
                }
            }
            main.draw(background);
            title.setString("Ace Combat");
            txtEnd.setString("EXIT");
            txtStart.setString("START");
            txtStart.setPosition(920.0f - buttonS.getLocalBounds().width, 570.0f);
            txtEnd.setPosition(930.0f - buttonS.getLocalBounds().width, 770.0f);

            main.draw(title);
            main.draw(buttonS);
            main.draw(txtStart);
            main.draw(buttonE);
            main.draw(txtEnd);

            main.display();
        }
    }
}