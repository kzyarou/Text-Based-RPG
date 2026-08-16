#include "loadingSound.hpp"
#include <fstream>
#include <cstdlib>
#include <cmath>

const int SAMPLE_RATE = 44100;

void createTone(
    double frequency,
    double duration,
    double volume
) {
    int samples =
        static_cast<int>(
            SAMPLE_RATE * duration
        );

    std::ofstream file(
        "/tmp/loading_sfx.wav",
        std::ios::binary
    );

    if (!file)
        return;

    int dataSize = samples * 2;
    int fileSize = 36 + dataSize;

    // RIFF
    file.write("RIFF", 4);
    file.write(
        reinterpret_cast<char*>(&fileSize),
        4
    );

    // WAVE
    file.write("WAVE", 4);

    // fmt
    file.write("fmt ", 4);

    int subChunkSize = 16;
    short audioFormat = 1;
    short channels = 1;
    short bitsPerSample = 16;

    file.write(
        reinterpret_cast<char*>(&subChunkSize),
        4
    );

    file.write(
        reinterpret_cast<char*>(&audioFormat),
        2
    );

    file.write(
        reinterpret_cast<char*>(&channels),
        2
    );

    file.write(
        reinterpret_cast<const char*>(&SAMPLE_RATE),
        4
    );

    int byteRate =
        SAMPLE_RATE *
        channels *
        bitsPerSample / 8;

    short blockAlign =
        channels *
        bitsPerSample / 8;

    file.write(
        reinterpret_cast<char*>(&byteRate),
        4
    );

    file.write(
        reinterpret_cast<char*>(&blockAlign),
        2
    );

    file.write(
        reinterpret_cast<char*>(&bitsPerSample),
        2
    );

    // data
    file.write("data", 4);

    file.write(
        reinterpret_cast<char*>(&dataSize),
        4
    );

    // Generate sound
    for (int i = 0; i < samples; i++) {

        double time =
            static_cast<double>(i)
            / SAMPLE_RATE;

        double wave =
            std::sin(
                2.0 *
                M_PI *
                frequency *
                time
            );

        short sample =
            static_cast<short>(
                wave *
                32767 *
                volume
            );

        file.write(
            reinterpret_cast<char*>(&sample),
            sizeof(sample)
        );
    }

    file.close();

    system(
        "paplay /tmp/loading_sfx.wav "
        "> /dev/null 2>&1 &"
    );
}


// Loading tick
void loadingTickSound() {
    createTone(
        700,
        0.04,
        0.25
    );
}


// Loading complete
void loadingCompleteSound() {

    createTone(
        600,
        0.08,
        0.3
    );

    createTone(
        900,
        0.12,
        0.3
    );
}