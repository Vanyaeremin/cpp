//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <windows.h>
//#include <iostream>
//#include <string>
//#include <functional> 
//
//int main()
//{
//    struct Button {
//        Button(const sf::String& text, const sf::Font& font, sf::Vector2f size, int x, int y) {
//            this->text.setString(text);
//            this->text.setFont(font);
//            this->text.setFillColor(sf::Color::Black);
//            this->text.setCharacterSize(50);
//            this->shape.setSize(size);
//            this->shape.setPosition(x, y);
//            float textWidth = this->text.getGlobalBounds().width;
//            float textH = this->text.getGlobalBounds().height;
//            float screenCenterX = size.x / 2;
//            float screenCenterY = size.y / 2;
//            this->text.setPosition(-4 + x + (screenCenterX - textWidth) / 2, -16 + y + (screenCenterY - textH) / 2);
//            this->size = size;
//        }
//        void update(sf::RenderWindow& window) {
//            window.draw(this->shape);
//            window.draw(this->text);
//            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//            if (this->shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//                this->shape.setFillColor(sf::Color(150, 150, 150));
//                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//                    this->action();
//                }
//            }
//            else {
//                this->shape.setFillColor(sf::Color(200, 250, 50));
//            }
//        }
//        void setAction(std::function<void()> action) {
//            this->action = action;
//        }
//        sf::Text text;
//        sf::RectangleShape shape;
//        sf::Vector2f size;
//        std::function<void()> action;
//    };
//
//    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Text Segmentation");
//    sf::Text text;
//    sf::Text text2;
//    sf::Text text3;
//    sf::Text userText;
//    sf::Font font;
//    std::string dir;
//
//    bool but1 = 0;
//    bool but2 = 0;
//    bool but3 = 0;
//    bool but4 = 0;
//
//    Button button("Save (Enter)", font, sf::Vector2f(480, 100), 10, 490);
//    button.setAction([&but1]() { but1 = 1; });
//
//    Button button1("Exit (Esc)", font, sf::Vector2f(480, 100), 10, 590);
//    button1.setAction([&but2]() { but2 = 1; });
//
//    Button button2("Overview", font, sf::Vector2f(480, 100), 10, 390);
//    button2.setAction([&but3]() { but3 = 1; });
//
//    Button button3("X", font, sf::Vector2f(50, 50), 1833, 495);
//    button3.setAction([&but4]() { but4 = 1; });
//
//    //Заголовок
//    font.loadFromFile("ArialRegular.ttf");
//    text.setFont(font); 
//    text.setString("Text Segmentation");
//    text.setCharacterSize(150); 
//    text.setFillColor(sf::Color::Black);
//    text.setStyle(sf::Text::Bold);
//    float textWidth = text.getGlobalBounds().width;
//    float screenWidth = window.getSize().x;
//    float screenWidthY = window.getSize().y;
//    float screenCenterX = (screenWidth-500) / 2;
//    text.setPosition(screenCenterX - textWidth / 2 + 500, 0);
//
//    //Ввод адреса
//    userText.setFont(font);
//    userText.setCharacterSize(50);
//    userText.setFillColor(sf::Color::Black);
//    textWidth = userText.getGlobalBounds().width;
//    userText.setPosition(520, 488);
//
//    //Подпись поле ввода адреса
//    text2.setFont(font);
//    text2.setString("Enter the path to the image");
//    text2.setCharacterSize(50);
//    text2.setFillColor(sf::Color::Black);
//    text2.setStyle(sf::Text::Bold);
//    float textWidth1 = text2.getGlobalBounds().width;
//    text2.setPosition(screenCenterX - textWidth1 / 2 + 500, 560);
//
//    //Подчёркивание
//    text3.setFont(font);
//    text3.setString("_______________________________________________");
//    text3.setCharacterSize(50);
//    text3.setFillColor(sf::Color::Black);
//    text3.setStyle(sf::Text::Bold);
//    text3.setPosition(520, 490);
//
//    sf::RectangleShape rectangle(sf::Vector2f(500, 1080));
//    rectangle.setFillColor(sf::Color(100, 250, 50));
//
//    const std::string allowedCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890/:._-";
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//
//            else if (but2 == 1) {
//                window.close();
//            }
//
//            if (but3 == 1) {
//                OPENFILENAME ofn;
//                wchar_t szFile[260];
//                ZeroMemory(&ofn, sizeof(ofn));
//                ofn.lStructSize = sizeof(ofn);
//                ofn.hwndOwner = NULL;
//                ofn.lpstrFile = szFile;
//                ofn.lpstrFile[0] = '\0';
//                ofn.nMaxFile = sizeof(szFile);
//                ofn.lpstrFilter = L"Image Files (*.jpg, *.png, *.bmp)\0*.jpg;*.png;*.bmp";
//                ofn.nFilterIndex = 1;
//                ofn.lpstrFileTitle = NULL;
//                ofn.nMaxFileTitle = 0;
//                ofn.lpstrInitialDir = NULL;
//                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
//                if (GetOpenFileName(&ofn))
//                {
//                    TCHAR* filename = ofn.lpstrFile;
//                }
//                std::string filepath;
//                for (size_t i = 0; i != 260; ++i) {
//                    if (szFile[i] == '\\') {
//                        filepath += '/';
//                    }
//                    else if (allowedCharacters.find_first_of(szFile[i]) != std::string::npos) {
//                        filepath += szFile[i];
//                    }
//                }
//                userText.setString(filepath);
//                but3 = 0;
//            }
//
//            if (event.type == sf::Event::TextEntered) {
//                char character = static_cast<char>(event.text.unicode);
//
//                if (allowedCharacters.find(character) != std::string::npos) {
//                    userText.setString(userText.getString() + character);
//                }
//            }
//            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace) {
//                std::string text = userText.getString();
//                if (!text.empty()) {
//                    text.pop_back();
//                    userText.setString(text);
//                }
//            }
//            else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) || but1==1) {
//                window.close();
//                dir = userText.getString();
//            }
//            else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Delete) || but4 == 1) {
//                userText.setString("");
//                but4 = 0;
//            }
//            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                window.close();
//            }
//            if (event.type == sf::Event::EventType::KeyPressed) {
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
//                    userText.setString(userText.getString() + sf::Clipboard::getString());
//                    event.key.control = false;
//                }
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
//                    sf::Clipboard::setString(userText.getString());
//                    event.key.control = false;
//                }
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
//                    sf::Clipboard::setString(userText.getString());
//                    userText.setString("");
//                    event.key.control = false;
//                }
//            }
//
//        }
//        window.clear(sf::Color::White);
//        window.draw(rectangle);
//        button.update(window);
//        button1.update(window);
//        button2.update(window);
//        button3.update(window);
//
//        window.draw(text);
//        window.draw(text2);
//        window.draw(text3);
//        window.draw(userText);
//        window.display();
//    }
//    for (size_t i = 0; i != dir.size(); ++i) {
//        std::cout << dir[i];
//    }
//}
//
