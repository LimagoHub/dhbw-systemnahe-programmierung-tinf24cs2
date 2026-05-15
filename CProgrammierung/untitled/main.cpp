#include <iostream>

class Schwein {
private:
    int gewicht;
public:
    int getGewicht() const {
        return gewicht;
    }

    void setGewicht(int gewicht) {
        Schwein::gewicht = gewicht;
    }
};

int main() {


    unsigned char foo =0x0f;
    

    Schwein piggy;

    piggy.setGewicht()
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
