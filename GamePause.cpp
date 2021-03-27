#include "Game.h"
#include "GamePause.h"
#include "AssetManager.h"
#include "Enums.h"

GamePause::GamePause()
{
    
}

void GamePause::run()
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

        sf::Event event;
        while (main.pollEvent(event))
        {
            if (event.type == Event::Closed){
                main.close();
            }


           if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    if (buttonS.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
                        std::cout << "Button pressed CONT" << std::endl;
                        GameState gameState = GameState::GAME_PLAY;
                        main.close();

//                        Game newGame;
//                        newGame.run();

                    }
                    else if(buttonE.getGlobalBounds().contains(main.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        main.close();

                    }
                }
            }
            //main.draw(background);
            title.setString("GAME PAUSE ||");
            txtExit.setString("EXIT");
            txtCont.setString("CONTINUE");
            txtCont.setPosition(920.0f - buttonS.getLocalBounds().width, 570.0f);
            txtExit.setPosition(930.0f - buttonS.getLocalBounds().width, 770.0f);

            main.draw(title);
            main.draw(buttonS);
            main.draw(txtCont);
            main.draw(buttonE);
            main.draw(txtExit);

            main.display();
        }
    }