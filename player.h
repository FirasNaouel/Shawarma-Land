#include "coa.h"

using namespace std;

class Player : public COA {
    private:
    static const int emojiSize = 5;
    string emojis[emojiSize] = {"\U0001F600", "\U0001F606", "\U0001F602", "\U0001F911", "\U0001F607"};
    public:
    Player();
    void customize(bool);
    void playerInfo();
};

