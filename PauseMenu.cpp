#include "PauseMenu.h"
#include "AssetManager.h"

PauseMenu::PauseMenu() : main(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default)
{
    main.setFramerateLimit(60);
}

void PauseMenu::run()
{
    AssetManager assetManager;

    Texture backgroundTexture = assetManager.getMenuTexture();
    background.setTexture(backgroundTexture);

    Text title;
    Font font = assetManager.getFont();
    title.setFont(font);
    title.setCharacterSize(90);
    title.setFillColor(Color::Red);
    title.setPosition(360, 100);

    sf::RectangleShape ResumeB;
    ResumeB.setSize(sf::Vector2f(460.0f, 100.0f));
    ResumeB.setPosition(300.0f, 260.0f);
    ResumeB.setFillColor(sf::Color(56, 14, 112));
    ResumeB.setOutlineColor(sf::Color::White);
    ResumeB.setOutlineThickness(3);

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

    Text txtResume;
    txtResume.setFont(font);
    txtResume.setCharacterSize(50);
    txtResume.setFillColor(Color::White);
    txtResume.setPosition(300.0f, 260.0f);

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
                    if (ResumeB.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        std::cout << "Button pressed RESUME" << std::endl;
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
            title.setString("Paused");
            txtResume.setString("Resume Game");
            txtMain.setString("Main Menu");
            txtQuit.setString("Quit Game");

            txtResume.setPosition(840.0f - ResumeB.getLocalBounds().width, 275.0f);
            txtMain.setPosition(860.0f - MainB.getLocalBounds().width, 475.0f);
            txtQuit.setPosition(860.0f - QuitB.getLocalBounds().width, 675.0f);

            main.draw(title);
            main.draw(ResumeB);
            main.draw(MainB);
            main.draw(QuitB);
            main.draw(txtResume);
            main.draw(txtMain);
            main.draw(txtQuit);
            main.display();
        }
    }
}