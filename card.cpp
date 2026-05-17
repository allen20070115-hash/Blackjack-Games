<<<<<<< Updated upstream
#include "Card.h"
using namespace std;

Card::Card(int v, Suit s, string n){
    value=v;
    suit=s;
    name=n;
}

void Card::draw(sf::RenderWindow& window, sf::Vector2f pos, bool faceUp, const sf::Font& font) const {
    sf::RectangleShape rect({160.f, 240.f});// 卡片大小
    rect.setPosition(pos);// 卡片位置
    rect.setOutlineThickness(2);// 卡片邊框厚度
    rect.setOutlineColor(sf::Color::Black);// 卡片邊框顏色

    if (faceUp){
        rect.setFillColor(sf::Color::White);// 卡片正面白色
        window.draw(rect);// 畫卡片背景
        sf::Text text(font, name, 24);// 卡片文字

        text.setFillColor((suit == Suit::Hearts || suit == Suit::Diamonds) ? sf::Color::Red : sf::Color::Black);// 紅色或黑色
        text.setPosition({pos.x + 20.f, pos.y + 20.f});// 文字位置
        window.draw(text);// 畫卡片文字

    }
    else{
        rect.setFillColor(sf::Color(70, 70, 150));// 卡片背面顏色
        window.draw(rect);// 畫卡片背面
    }
}

int Card::getValue() const {
    return value;
}
string Card::getName() const {
    return name;
}
=======
version https://git-lfs.github.com/spec/v1
oid sha256:c07a0e6f5c7bcc9ec57c7dfbd11f0a0b11c503ea0c4da51f99796489ee4ee887
size 1149
>>>>>>> Stashed changes
