#include "Hand.h" 
using namespace std;

void Hand::addCard(Card c) {
    cards.push_back(c);// 卡片加入手牌
}
void Hand::clear(){
    cards.clear();// 清空手牌
}
const vector<Card>& Hand::getCards() const {
    return cards;// 回傳手牌中的卡片
}
int Hand::getTotal() const {
    int total = 0, aces = 0;
    for (const auto& c : cards) {// 計算手牌總點數
        total += c.getValue();// 累加卡片點數
        if (c.getName() == "A") // 計算 A 的數量
            aces++;
    }
    while (total > 21 && aces > 0){//如點數超過21而且有A，將A的點數-10
        total -= 10; aces--;
    }
    return total;
}