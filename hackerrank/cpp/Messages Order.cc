// https://www.hackerrank.com/challenges/messages-order/problem

class Message {
private:
    string _text;
    size_t _id;
public: 
    static size_t __id;
    Message(string text): _text(text), _id(Message::__id++) {}
    const string& get_text() {
        return _text;
    }
    bool operator<(const Message& other) {
        return _id < other._id;
    }
};
size_t Message::__id = 0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text);
    }
};
