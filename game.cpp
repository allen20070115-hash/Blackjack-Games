#include "game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

game::game() : window(sf::VideoMode({1600,1200}), "Blackjack SFML 3.0") {
    srand(static_cast<unsigned>(time(nullptr))); //隨機種子
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {// 錯誤處理
    }
    reset();
}

void game::reset() {//初始化
    deck.clear(); 
    playerHand.clear(); 
    dealerHand.clear();
    isGameOver = false; 
    msg = "Press H to Hit, S to Stand";

    string names[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    for (int i=0;i<4;++i){
        for (int j=0;j<13;++j){
            deck.push_back(Card(values[j], static_cast<Card::Suit> (i),names[j]));// 生成牌組
        }
    }

    for (int i = static_cast<int>(deck.size()) - 1; i > 0; --i) {// 洗牌
        int j = rand() % (i + 1); // 產生 0 到 i 之間的隨機整數
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    deal();
    deal();
}

void game::deal() {// 發牌
    playerHand.addCard(deck.back());
    deck.pop_back();

    dealerHand.addCard(deck.back());
    deck.pop_back();
}

void game::hit() {// 要牌
    playerHand.addCard(deck.back());
    deck.pop_back();
    if (playerHand.getTotal() > 21) {
        isGameOver = true; msg = "Bust! You Lose. (Press any key)";
    }
}

void game::stand() {// 不要牌
    while (dealerHand.getTotal()<17) {//莊家要牌直到點數達到17或以上
        dealerHand.addCard(deck.back());//
        deck.pop_back();
    }
    int p=playerHand.getTotal(),d=dealerHand.getTotal();
    if (d>21||p>d) msg = "You Win!";
        else if (p<d)
            msg = "Dealer Wins!";
        else 
            msg = "Tie!";
    isGameOver = true;
    msg+="(Press any key to restart)";
}

void game::run() {
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {// 事件處理
            if (event->is<sf::Event::Closed>())
                window.close();
            if (!isGameOver) {
                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                    if (keyPressed->code == sf::Keyboard::Key::H) 
                        hit();
                    if (keyPressed->code == sf::Keyboard::Key::S)
                        stand();
                }
            } 
            else {
                if (event->is<sf::Event::KeyPressed>())
                    reset();
            }
        }
        render();
    }
}

void game::render() {// 畫面渲染
    window.clear(sf::Color(30, 120, 30));//背景
    auto& pCards = playerHand.getCards();//玩家牌
    for (size_t i = 0; i < pCards.size(); ++i)//畫牌
        pCards[i].draw(window, {200.f + i * 180, 800.f}, true, font);
    auto& dCards = dealerHand.getCards();//莊家牌
    for (size_t i = 0; i < dCards.size(); ++i)//畫牌
        dCards[i].draw(window,{200.f + i * 180, 200.f},(isGameOver || i > 0),font);
    
    sf::Text text(font, msg, 60);//訊息文字
    text.setFillColor(sf::Color::Yellow);//文字顏色
    text.setPosition({400.f, 560.f});//文字位置
    window.draw(text);//畫文字
    window.display();//顯示畫面
}