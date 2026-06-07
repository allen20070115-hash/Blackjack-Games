#include "Button.h"

// 實作建構子
Button::Button(sf::Vector2f position, sf::Vector2f size, const sf::Font& font,
               const std::string& btnText)
    : text(font, btnText, 20) {
    {
        // 設定背景矩形
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(sf::Color(70, 70, 70));

        // 設定顏色
        text.setFillColor(sf::Color::White);

        // 文字置中
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin({bounds.position.x + bounds.size.x / 2.0f,
                        bounds.position.y + bounds.size.y / 2.0f});
        text.setPosition(position + size / 2.0f);
    }
}

// 懸停
void Button::update(const sf::RenderWindow& window) {
    sf::Vector2f mousePos =
        window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (shape.getGlobalBounds().contains(mousePos)) {
        shape.setFillColor(sf::Color(120, 120, 120)); // 滑鼠懸停時變亮
    } else {
        shape.setFillColor(sf::Color(70, 70, 70)); // 恢復預設顏色
    }
}

// 點擊偵測
bool Button::isClicked(const sf::Event& event, const sf::RenderWindow& window) {
    if (const auto* mousePressed =
            event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            sf::Vector2f mousePos =
                window.mapPixelToCoords(sf::Mouse::getPosition(window));
            return shape.getGlobalBounds().contains(mousePos);
        }
    }
    return false;
}

// 繪製
void Button::draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(text);
}