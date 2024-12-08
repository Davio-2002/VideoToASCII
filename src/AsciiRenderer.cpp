#include <AsciiRenderer.h>

namespace {
    void clearConsole() {
        std::cout << "\033[2J\033[H";
    }
}

void AsciiRenderer::render(AsciiArtAliases::StringView) {
    clearConsole();
    std::cout.flush();
}
