#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

typedef struct  WAV_HEADER
{
    /* RIFF Chunk Descriptor */
    uint8_t         RIFF[4];        // RIFF Header Magic header
    uint32_t        ChunkSize;      // RIFF Chunk Size
    uint8_t         WAVE[4];        // WAVE Header
    /* "fmt" sub-chunk */
    uint8_t         fmt[4];         // FMT header
    uint32_t        Subchunk1Size;  // Size of the fmt chunk
    uint16_t        AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
    uint16_t        NumOfChan;      // Number of channels 1=Mono 2=Sterio
    uint32_t        SamplesPerSec;  // Sampling Frequency in Hz
    uint32_t        bytesPerSec;    // bytes per second
    uint16_t        blockAlign;     // 2=16-bit mono, 4=16-bit stereo
    uint16_t        bitsPerSample;  // Number of bits per sample
    /* "data" sub-chunk */
    uint8_t         Subchunk2ID[4]; // "data"  string
    uint32_t        Subchunk2Size;  // Sampled data length
} wav_hdr;


string corr(string str) {
    string corr_str = "" ;
    int len = str.length();
    string car ;
    for (int i=0 ; i<len-3 ; i=i+4) {
        car = str[i] ;
        corr_str.append(car) ;
    }
    return corr_str ;
}

string readaudio(string file_name)
{
    wav_hdr wavHeader;
    int headerSize = sizeof(wav_hdr) ;

    const char* filePath;
    filePath = file_name.c_str();

    FILE* wavFile = fopen(filePath, "r");
    // if (wavFile == nullptr)
    // {
    //     fprintf(stderr, "Unable to open wave file: %s\n", filePath);
    //     return 1;
    // }

    //Read the header
    size_t bytesRead = fread(&wavHeader, 1, headerSize, wavFile);
    string str = "" ;
    if (bytesRead > 0)
    {
        //Read the data
        static const uint32_t BUFFER_SIZE = 22050 ; //Bonne taille à choisir (sans quoi on a que des zéros...), même si on obtient 4 fois trop de points/tirets (d'où la fonction corr)
        int16_t* buffer = new int16_t[BUFFER_SIZE];
        fseek(wavFile, BUFFER_SIZE/2, SEEK_CUR); // Pour voir au milieu de l'échantillon
        while ((bytesRead = fread(buffer, sizeof buffer[0], BUFFER_SIZE / (sizeof buffer[0]), wavFile)) > 0)
        {
            int16_t n = (buffer[0]<<8)+buffer[1] ;
            if (n!=0) {
                str.append("-") ;
            }
            else { str.append(".") ;}
        }
        delete [] buffer;
        buffer = nullptr;
    }
    string cstr = corr(str) ;
    fclose(wavFile);
    return cstr ;
}
