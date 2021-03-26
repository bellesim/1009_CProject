#include "MainMenu.h"
#include "AssetManager.h"

MainMenu::MainMenu() : main(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default) {
    main.setFramerateLimit(60);
}

void MainMenu::run() {
    AssetManager assetManager;

    Text text;
    Font font = assetManager.getFont();
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(Color::Red);
    text.setPosition(30, 30);

    while (main.isOpen())
    {
        sf::Event event;
        while (main.pollEvent(event))
        {
            if (event.type == Event::Closed)
                main.close();
        }

        //main.draw(background);

        text.setString("Hit points left: ");
        main.draw(text);
        main.display();
    }
}