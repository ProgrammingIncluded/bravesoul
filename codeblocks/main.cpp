#include <SFML/Graphics.hpp>


int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("assets/general/logo.png"))
        return 1;
    sf::Sprite sprite(texture);

    // Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                app.close();
            }

            if(event.type == sf::Event::Resized)
            {
                app.setView(sf::View(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height)));
            }

        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return 0;
}
