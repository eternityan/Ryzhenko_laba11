#include <iostream>
#include <string>
#include <regex>
using namespace std;
class CreditCard {
private:
    string cardNumber;
    string expiryDate;
    string CVV;
public:
    CreditCard(char* cardNum, char* expDate, char* cvv)
        : cardNumber(cardNum), expiryDate(expDate), CVV(cvv) {
    }
    bool isValidCardNumber() {
        regex pattern("^[0-9]{16}$");

        return regex_match(cardNumber, pattern);
    }
    string maskCardNumber() {
        if (!isValidCardNumber()) {
            return "Invalid card number";
        }
        return cardNumber.substr(0, 4) + " **** **** " + cardNumber.substr(12, 4);
    }
    void displayCardInfo() {
        cout << "Card Number: " << maskCardNumber() << endl;
        cout << "Expiry Date: " << expiryDate << endl;
        cout << "CVV: " << CVV << endl;
    }
};

int main() {
    CreditCard card("1234567812345678", "12/25", "123");
    card.displayCardInfo();
    if (card.isValidCardNumber())
        cout << "The card number is valid." << endl;
    else
        cout << "The card number is invalid." << endl;
    return 0;
}
