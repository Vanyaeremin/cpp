#include "graphics.hpp"

std::string font_path = "C:/Users/vanyu/Documents/ÌÈÑÈÑ/Ïðîãà/ÎÎÏ/bin.dbg/ArialRegular.ttf";

Button::Button(const sf::String& text, const sf::Font& font, const sf::Vector2f& size, const int x, const int y) {
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(50);
    this->shape.setSize(size);
    this->shape.setPosition(x, y);
    this->text.setPosition(x, y);
    this->size = size;
}

void Button::update(sf::RenderWindow& window) {
    window.draw(this->shape);
    window.draw(this->text);
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (this->shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        this->shape.setFillColor(sf::Color(150, 150, 150));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->action();
        }
    }
    else {
        this->shape.setFillColor(sf::Color(200, 250, 50));
    }
}

void Button::setAction(std::function<void()> action) {
    this->action = action;
}

sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
unsigned int screen_x = desktop.width;
unsigned int screen_y = desktop.height;

void openResultWindow(std::string& new_filename) {
    sf::RenderWindow window_result(sf::VideoMode(screen_x, screen_y), "Result");

    sf::Texture texture;
    texture.loadFromFile(new_filename);
    sf::Sprite sprite(texture);
    sf::Vector2u windowSize = window_result.getSize();
    sprite.setScale(0.5f * windowSize.x / texture.getSize().x, 0.5f * windowSize.x / texture.getSize().y);
    sf::Font font;
    font.loadFromFile(font_path);

    sf::Text title;
    title.setFont(font);
    title.setString("The text segmentation file was saved successfully");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(screen_x * 0.25 - title.getGlobalBounds().width / 2 + screen_x*0.5, screen_y*0.3);

    bool but11 = 0;
    bool but12 = 0;

    Button button11("Delete", font, sf::Vector2f(300, 100), screen_x * 0.5+(screen_x*0.5-600)/2, screen_y*0.5);
    button11.setAction([&but11]() { but11 = 1; });

    Button button12("Exit (Esc)", font, sf::Vector2f(300, 100), screen_x * 0.5 + 300 + (screen_x * 0.5 - 600) / 2, screen_y * 0.5);
    button12.setAction([&but12]() { but12 = 1; });

    while (window_result.isOpen())
    {
        sf::Event event;
        while (window_result.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_result.close();
            }
            if (but11 == 1) {
                std::remove(new_filename.c_str());
                window_result.close();
                but11 = 0;
            }
            if (but12 == 1) {
                window_result.close();
                but12 = 0;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window_result.close();
            }
        }
        window_result.clear(sf::Color::White);
        window_result.draw(sprite);
        window_result.draw(title);
        button11.update(window_result);
        button12.update(window_result);
        window_result.display();
    }
}

void openStartWindow() {
    sf::RenderWindow window(sf::VideoMode(screen_x, screen_y), "Text Segmentation");

    sf::Text text;
    sf::Text text2;
    sf::Text texter;
    sf::Text text3;
    sf::Text userText;
    sf::Font font;
    std::string dir;

    bool but1 = 0;
    bool but2 = 0;
    bool but3 = 0;
    bool but4 = 0;


    Button button("Segmentation", font, sf::Vector2f(460, 100), (screen_x * 0.25 - 460)/2, screen_y * 0.5);
    button.setAction([&but1]() { but1 = 1; });

    Button button1("Exit (Esc)", font, sf::Vector2f(460, 100), (screen_x * 0.25 - 460) / 2, screen_y * 0.5 + 100);
    button1.setAction([&but2]() { but2 = 1; });

    Button button2("Overview", font, sf::Vector2f(460, 100), (screen_x * 0.25 - 460) / 2, screen_y * 0.5 - 100);
    button2.setAction([&but3]() { but3 = 1; });

    Button button3("X", font, sf::Vector2f(50, 50), screen_x * 0.95, screen_y * 0.5 - 5);
    button3.setAction([&but4]() { but4 = 1; });

    texter.setFont(font);
    texter.setCharacterSize(50);
    texter.setStyle(sf::Text::Bold);
    texter.setString("");
    
    font.loadFromFile(font_path);
    text.setFont(font);
    text.setString("Text Segmentation");
    text.setCharacterSize(150);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    float textWidth = text.getGlobalBounds().width;
    float screenCenterX = (screen_x - screen_x * 0.25) / 2;
    text.setPosition(screenCenterX - textWidth / 2 + screen_x * 0.25, 0);

    userText.setFont(font);
    userText.setCharacterSize(50);
    userText.setFillColor(sf::Color::Black);
    textWidth = userText.getGlobalBounds().width;
    userText.setPosition(screen_x * 0.25 + 20, screen_y * 0.5 - 5);

    text2.setFont(font);
    text2.setString("Enter the path to the image");
    text2.setCharacterSize(50);
    text2.setFillColor(sf::Color::Black);
    text2.setStyle(sf::Text::Bold);
    float textWidth1 = text2.getGlobalBounds().width;
    text2.setPosition(screenCenterX - textWidth1 / 2 + screen_x * 0.25, screen_y * 0.5 + 60);

    text3.setFont(font);
    text3.setString("_______________________________________________");
    text3.setCharacterSize(50);
    text3.setFillColor(sf::Color::Black);
    text3.setStyle(sf::Text::Bold);
    text3.setPosition(screen_x * 0.25 + 20, screen_y * 0.5);

    sf::RectangleShape rectangle(sf::Vector2f(screen_x*0.25, screen_y));
    rectangle.setFillColor(sf::Color(100, 250, 50));

    bool er = 0;

    const std::string allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890/\\:._-' '";
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (but2 == 1) {
                window.close();
            }

            if (but3 == 1) {
                OPENFILENAME ofn;
                char szFile[260];
                for (size_t i = 0; i < 260; ++i) {
                    szFile[i] = L'\0';
                }
                ZeroMemory(&ofn, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = NULL;
                ofn.lpstrFile = szFile;
                ofn.lpstrFile[0] = '\0';
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = "Image Files (*.jpg, *.png, *.bmp)\0*.jpg;*.png;*.bmp";
                ofn.nFilterIndex = 1;
                ofn.lpstrFileTitle = NULL;
                ofn.nMaxFileTitle = 0;
                ofn.lpstrInitialDir = NULL;
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
                if (GetOpenFileName(&ofn))
                {
                    TCHAR* filename = ofn.lpstrFile;
                }
                std::string filepath = "";
                for (size_t i = 0; i != 260; ++i) {
                    if (szFile[i] == '\\') {
                        filepath += '/';
                    }
                    else if (allowedCharacters.find_first_of(szFile[i]) != std::string::npos) {
                        filepath += szFile[i];
                    }
                }
                userText.setString(filepath);
                texter.setString("");
                for (size_t i = 0; i < 260; ++i) {
                    szFile[i] = '\0';
                }
                filepath = "";
                but3 = 0;
            }

            if (event.type == sf::Event::TextEntered) {
                char character = static_cast<char>(event.text.unicode);

                if (allowedCharacters.find(character) != std::string::npos) {
                    userText.setString(userText.getString() + character);
                    texter.setString("");
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
                std::string text = userText.getString();
                if (!text.empty()) {
                    text.pop_back();
                    userText.setString(text);
                    texter.setString("");
                }
            }
            else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) || but1 == 1) {
                dir = userText.getString();
                cv::Mat img = cv::imread(dir);
                if (img.empty()) {
                    texter.setString("The path to the file is incorrect");
                    texter.setFillColor(sf::Color::Red);
                    texter.setPosition(screen_x * 0.25 + 20, screen_y * 0.5 - 5);
                    userText.setString("");
                    but1 = 0;
                }
                else {
                    cv::Mat output = img.clone();
                    cv::Mat prepareim = prepare(img);
                    result(prepareim, output);
                    cv::bitwise_not(img, img);
                    cv::Mat prepareim2 = prepare(img);
                    result(prepareim2, output);
                    std::string filename = dir.substr(0, dir.find_last_of('.'));
                    std::string extension = dir.substr(dir.find_last_of('.'));
                    std::string new_filename = filename + "_segmentation" + extension;
                    cv::imwrite(new_filename, output);
                    texter.setString("");
                    openResultWindow(new_filename);
                    but1 = 0;
                }
            }
            else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Delete) || but4 == 1) {
                userText.setString("");
                texter.setString("");
                but4 = 0;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::EventType::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                    std::string s1 = sf::Clipboard::getString();
                    if (s1[0] == '"' && s1[s1.size() - 1] == '"') {
                        s1.erase(s1.begin());
                        s1.erase(s1.end() - 1);
                    }
                    sf::String buf(s1);
                    userText.setString(userText.getString() + buf);
                    texter.setString("");
                    event.key.control = false;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    sf::Clipboard::setString(userText.getString());
                    event.key.control = false;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                    sf::Clipboard::setString(userText.getString());
                    userText.setString("");
                    event.key.control = false;
                }
            }

        }
        window.clear(sf::Color::White);
        window.draw(rectangle);
        button.update(window);
        button1.update(window);
        button2.update(window);
        button3.update(window);
        window.draw(texter);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(userText);
        window.display();
    }
}