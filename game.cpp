#include "game.h"

#include <cstdlib>
#include <ctime>

#include "Card.h"
#include "button.h"
#include "coin.h"

using namespace std;

game::game()
    : window(sf::VideoMode({1200, 900}), "Blackjack"),
      player(5000),
      dealer(5000),
      bet(0) {
    srand(static_cast<unsigned>(time(nullptr))); // 隨機種子
    if (!font.openFromFile("arial.ttf")) {       // 錯誤處理
    }
    reset();
}

void game::reset() { // 初始化
    deck.clear();
    playerHand.clear();
    dealerHand.clear();
    isGameOver = false;
    msg = "Press H to Hit, S to Stand";

    string names[] = {"A", "2", "3",  "4", "5", "6", "7",
                      "8", "9", "10", "J", "Q", "K"};
    int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck.push_back(Card(values[j], static_cast<Card::Suit>(i),
                                names[j])); // 生成牌組
        }
    }

    for (int i = static_cast<int>(deck.size()) - 1; i > 0; --i) { // 洗牌
        int j = rand() % (i + 1); // 產生 0 到 i 之間的隨機整數
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    deal();
    deal();
}

void game::deal() { // 發牌
    playerHand.addCard(deck.back());
    deck.pop_back();

    dealerHand.addCard(deck.back());
    deck.pop_back();
}

void game::hit() { // 要牌
    playerHand.addCard(deck.back());
    deck.pop_back();
    if (playerHand.getTotal() > 21) {
        isGameOver = true;
        msg = "Bust! You Lose. (Press any key)";
        player.setValue(player.getValue() - bet);
        dealer.setValue(dealer.getValue() + bet);
    }
}

void game::stand() {                     // 不要牌
    while (dealerHand.getTotal() < 17) { // 莊家要牌直到點數達到17或以上
        dealerHand.addCard(deck.back());
        deck.pop_back();
    }
    int p = playerHand.getTotal(), d = dealerHand.getTotal();
    if (d > 21 || p > d) {
        msg = "You Win!";
        player.setValue(player.getValue() + bet);
        dealer.setValue(dealer.getValue() - bet);
        isGameOver = true;
        msg += "(Press any key to restart)";
    } else if (p < d) {
        msg = "Dealer Wins!";
        player.setValue(player.getValue() - bet);
        dealer.setValue(dealer.getValue() + bet);
        isGameOver = true;
        msg += "(Press any key to restart)";
    } else {
        msg = "Tie!";
        isGameOver = true;
        msg += "(Press any key to restart)";
    }
}

void game::run() {
    // 按鈕
    Button Button1000({350.f, 500.f}, {150.f, 65.f}, font, "1000");
    Button Button500({550.f, 500.f}, {150.f, 65.f}, font, "500");
    Button Button250({750.f, 500.f}, {150.f, 65.f}, font, "250");

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
            if (player.getValue() <= 0 ||
                dealer.getValue() <= 0) { // ESC 鍵退出
                if (const auto* keyPressed =
                        event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->code == sf::Keyboard::Key::Escape) {
                        window.close();
                    }
                }
                continue;
            }
            // 還沒下注時點擊按鈕
            if (bet == 0) {
                if (Button1000.isClicked(*event, window) &&
                    player.getValue() >= 1000)
                    bet = 1000;
                else if (Button500.isClicked(*event, window) &&
                         player.getValue() >= 500)
                    bet = 500;
                else if (Button250.isClicked(*event, window))
                    bet = 250;
            }

            if (!isGameOver) { // 下注才能要牌或停牌
                if (bet > 0) {
                    if (const auto* keyPressed =
                            event->getIf<sf::Event::KeyPressed>()) {
                        if (keyPressed->code == sf::Keyboard::Key::H) hit();
                        if (keyPressed->code == sf::Keyboard::Key::S) stand();
                    }
                }
            } else {
                // 遊戲結束
                if (event->is<sf::Event::KeyPressed>()) {
                    reset();
                    bet = 0;
                }
            }
        }

        // 變色
        if (bet == 0) {
            Button1000.update(window);
            Button500.update(window);
            Button250.update(window);
        }

        window.clear(sf::Color(30, 120, 30)); // 畫上綠色背景

        render(); // 畫牌與文字

        if (bet == 0) { // 沒下注的話就把按鈕疊加上去
            Button1000.draw(window);
            Button500.draw(window);
            Button250.draw(window);
        }

        window.display(); //  一次性將所有東西推上螢幕
    }
}

void game::render() {                                       // 畫面渲染
    if (player.getValue() <= 0 || dealer.getValue() <= 0) { // 遊戲結束
        window.clear(sf::Color::Black);

        string finalStr;
        sf::Color finalColor;
        if (player.getValue() <= 0) {
            finalStr = "GAME OVER\nYou are Bankrupt!";
            finalColor = sf::Color::Red;
        } else {
            finalStr = "YOU ARE THE CHAMPION\nDealer is Bankrupt!";
            finalColor = sf::Color::Green;
        }

        sf::Text finalText(font, finalStr, 80);
        finalText.setFillColor(finalColor);

        // 將文字置中
        sf::FloatRect bounds = finalText.getLocalBounds();
        finalText.setOrigin({bounds.position.x + bounds.size.x / 2.0f,
                             bounds.position.y + bounds.size.y / 2.0f});
        finalText.setPosition({600.f, 400.f});

        window.draw(finalText);

        // 提示文字
        sf::Text exitText(font, "Press ESC to Exit", 40);
        exitText.setFillColor(sf::Color::White);
        exitText.setPosition({650.f, 800.f});
        window.draw(exitText);

        return;
    }
    auto& pCards = playerHand.getCards();
    for (size_t i = 0; i < pCards.size(); ++i)
        pCards[i].draw(window, {200.f + i * 180, 600.f}, true, font); // 玩家牌

    auto& dCards = dealerHand.getCards();
    for (size_t i = 0; i < dCards.size(); ++i)
        dCards[i].draw(window, {200.f + i * 180, 150.f}, (isGameOver || i > 0),
                       font); // 莊家牌

    sf::Text text(font, msg, 60); // 遊戲訊息
    text.setFillColor(sf::Color::Yellow);
    text.setPosition({250.f, 400.f});
    window.draw(text);

    sf::Text playerMoney(
        font, "Your coins: $" + to_string(player.getValue()), // 玩家金錢
        40);
    playerMoney.setFillColor(sf::Color::White);
    playerMoney.setPosition({800.f, 800.f});
    window.draw(playerMoney);

    sf::Text dealerMoney(
        font, "Dealer coins: $" + to_string(dealer.getValue()), // 莊家金錢
        40);
    dealerMoney.setFillColor(sf::Color::White);
    dealerMoney.setPosition({800.f, 50.f});
    window.draw(dealerMoney);

    sf::Text bet(font, "bet: $" + to_string(this->bet), 40); // 目前下注
    bet.setFillColor(sf::Color::White);
    bet.setPosition({950.f, 500.f});
    window.draw(bet);
}
