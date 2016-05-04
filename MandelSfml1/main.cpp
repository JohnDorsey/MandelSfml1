
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like cute_image.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "FractalVis.hpp"

FractalVis fractVis;

int main(int argc, char const** argv)
{
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML window");
    
    printf("a");
    
    // Set the Icon
    //sf::Image icon;
    //if (!icon.loadFromFile("icon.png")) {
    //    return EXIT_FAILURE;
    //}
    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    texture.create(256, 256);
    texture.setSmooth(true);
    sf::Sprite sprite(texture);
    //sprite.setOrigin(256.0f, 256.0f);
    sprite.setPosition(0.0f, 512.0f);
    sprite.setScale(2.0f, 2.0f);
    sprite.setRotation(270.0f);

    // Create a graphical text to display
    //sf::Font font;
    //if (!font.loadFromFile("sansation.ttf")) {
    //    return EXIT_FAILURE;
    //}
    //sf::Text text("Hello SFML", font, 50);
    //text.setColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();

    
    fractVis.doFrame(texture);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            if (event.type == sf::Event::Resized) {
                sf::Vector2u newSize = window.sf::Window::getSize();
                int newAvg = (newSize.x + newSize.y) / 2;
                newSize.x = newAvg;
                newSize.y = newAvg;
                window.setSize(newSize);
            }
        }
        
        //for (int ti = 0; ti < 12800; ti++) {
        //    fractVis.fractRast.fractPanel.inx.inci(1);
        //    fractVis.fractRast.fractPanel.inx.incii(1);
        //}
        //for (int ti = 0; ti < 12799; ti++) {
        //    fractVis.fractRast.fractPanel.inx.inci(-1);
        //    fractVis.fractRast.fractPanel.inx.incii(-1);
        //}
        //fractVis.fractRast.fractPanel.inx.incii(2);
        //fractVis.fractRast.fractPanel.inx.incii(1);
        
        //fractVis.fractRast.fractPanel.dbgSet(123, 123, 24);
        //fractVis.fractRast.fractPanel.dbgSet(125, 125, 24);
        //fractVis.fractRast.dbgFillCorner();
        
        fractVis.doFrame(texture);
        // Clear screen
        window.clear();

        
        // Draw the sprite
        window.draw(sprite);

        // Draw the string
        //window.draw(text);
        

        // Update the window
        window.display();
        
        //printf("%i %i", texture.getSize().x, texture.getSize().y);
        
        //printf(" frameComplete");
//        for (int i = 0; i < 524288; i++) {
//            printf("AAABBBCCCDDDEEEFFFGGGHHHIIIJJJKKKLLLMMMNNNOOOPPPQQQRRRSSSTTTUUUVVVWWWXXXYYYZZ");
//        }
    }

    return EXIT_SUCCESS;
}
