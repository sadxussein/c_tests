#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public:
    Message() {}
    Message(string text, int index): t(std::move(text)), i(index) {}
    const string& get_text() {
        return t;
    }
    bool operator<(Message& other) const {
        return i < other.i;
    }

protected:
    string t;
    int i;
};


class MessageFactory: public Message{
public:
    MessageFactory() {index = 0;}
    Message create_message(const string& text) {
        index ++;
        return {text, index};
    }
private:
    int index;
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
