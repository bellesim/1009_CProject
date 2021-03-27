#include "GameOver.h"
#include "AssetManager.h"

GameOverMenu::GameOverMenu() : main(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default)
{
    main.setFramerateLimit(60);
}

void GameOverMenu::run()
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

    sf::RectangleShape AgainB;
    AgainB.setSize(sf::Vector2f(460.0f, 100.0f));
    AgainB.setPosition(300.0f, 260.0f);
    AgainB.setFillColor(sf::Color(56, 14, 112));
    AgainB.setOutlineColor(sf::Color::White);
    AgainB.setOutlineThickness(3);

    sf::RectangleShape MainB;
    MainB.setSize(sf::Vector2f(460.0f, 100.0f));
    MainB.setPosition(300.0f, 460.0f);
    MainB.setFillColor(sf::Color(56, 14, 112));
    MainB.setOutlineColor(sf::Color::White);
    MainB.setOutlineThickness(3);

    sf::RectangleShape QuitB;
    QuitB.setSize(sf::Vector2f(460.0f, 100.0f));
    QuitB.setPosition(300.0f, 660.0f);
    QuitB.setFillColor(sf::Color(56, 14, 112));
    QuitB.setOutlineColor(sf::Color::White);
    QuitB.setOutlineThickness(3);

    Text txtAgain;
    txtAgain.setFont(font);
    txtAgain.setCharacterSize(50);
    txtAgain.setFillColor(Color::White);
    txtAgain.setPosition(300.0f, 260.0f);

    Text txtMain;
    txtMain.setFont(font);
    txtMain.setCharacterSize(50);
    txtMain.setFillColor(Color::White);
    txtMain.setPosition(300.0f, 460.0f);

    Text txtQuit;
    txtQuit.setFont(font);
    txtQuit.setCharacterSize(50);
    txtQuit.setFillColor(Color::White);
    txtQuit.setPosition(300.0f, 660.0f);

    while (main.isOpen())
    {
        sf::Event event;
        while (main.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                main.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (AgainB.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        std::cout << "Button pressed PLAY AGAIN" << std::endl;
                    }
                    if (MainB.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        std::cout << "Button pressed MAIN MENU" << std::endl;
                    }
                    else if (QuitB.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        main.close();
                    }
                }
            }

            main.draw(background);
            title.setString("Game Over");
            txtAgain.setString("Play Again");
            txtMain.setString("Main Menu");
            txtQuit.setString("Quit Game");

            txtAgain.setPosition(850.0f - AgainB.getLocalBounds().width, 275.0f);
            txtMain.setPosition(860.0f - MainB.getLocalBounds().width, 475.0f);
            txtQuit.setPosition(860.0f - QuitB.getLocalBounds().width, 675.0f);

            main.draw(title);
            main.draw(AgainB);
            main.draw(MainB);
            main.draw(QuitB);
            main.draw(txtAgain);
            main.draw(txtMain);
            main.draw(txtQuit);
            main.display();
        }
    }
}