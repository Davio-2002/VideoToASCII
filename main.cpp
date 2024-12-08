#include <iostream>
#include <VideoToAsciiArtConverter.h>

int main() {
    VideoToAsciiArtConverter video_to_ascii("/home/davit/Downloads/boruto-naruto-next-generations---baryon-naruto-vs-isshiki.mp4", 150, 50);
    video_to_ascii.start();

    return 0;
}