#include <iostream>
#include <cstdint>

class RGBA {
    private:
        std::uint_fast8_t mRed;
        std::uint_fast8_t mBlue;
        std::uint_fast8_t mGreen;
        std::uint_fast8_t mAlpha;
    public:
        RGBA(std::uint_fast8_t red = 0, std::uint_fast8_t blue = 0, std::uint_fast8_t green = 0, std::uint_fast8_t alpha = 255)
            : mRed(red), mBlue(blue), mGreen(green), mAlpha(alpha)
        {}
        void print() {
            std::cout << "r=" << static_cast<int>(mRed) 
                << " b=" << static_cast<int>(mBlue) 
                << " c=" << static_cast<int>(mGreen) 
                << " a=" << static_cast<int>(mAlpha) << "\n";
        }
};

int main (int argc, char *argv[]) {
    RGBA teal(0, 127, 127);
    teal.print();
    return 0;
}

