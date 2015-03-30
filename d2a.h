
#ifndef D2A_H
#define D2A_H
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<cmath>


template <typename T>
void write(std::ofstream& stream, const T& t) {
    stream.write((const char*)&t, sizeof(T));
}

template <typename SampleType>
void writeWAVData(const char* outFile, SampleType* buf, size_t bufSize, int sampleRate, short channels)
{
    std::ofstream stream(outFile, std::ios::binary);                // Open file stream at "outFile" location

    /* Header */
    stream.write("RIFF", 4);                                        // sGroupID (RIFF = Resource Interchange File Format)
    write<int>(stream, 36 + bufSize);                               // dwFileLength
    stream.write("WAVE", 4);                                        // sRiffType

    /* Format Chunk */
    stream.write("fmt ", 4);                                        // sGroupID (fmt = format)
    write<int>(stream, 16);                                         // Chunk size (of Format Chunk)
    write<short>(stream, 3);                                        // Format (1 = PCM)
    write<short>(stream, channels);                                 // Channels
    write<int>(stream, sampleRate);                                 // Sample Rate
    write<int>(stream, sampleRate * channels * sizeof(SampleType)); // Byterate
    write<short>(stream, channels * sizeof(SampleType));            // Frame size aka Block align
    write<short>(stream, 8 * sizeof(SampleType));                   // Bits per sample

    /* Data Chunk */
    stream.write("data", 4);                                        // sGroupID (data)
    stream.write((const char*)&bufSize, 4);                         // Chunk size (of Data, and thus of bufferSize)
    stream.write((const char*)buf, bufSize);                        // The samples DATA!!!
}


template <typename SampleType>
void writeWAVHeader(const char* outFile, SampleType* buf, size_t bufSize, int sampleRate, short channels)
{
    std::ofstream stream(outFile, std::ios::binary);                // Open file stream at "outFile" location

    /* Header */
    stream.write("RIFF", 4);                                        // sGroupID (RIFF = Resource Interchange File Format)
    write<int>(stream, 36 + bufSize);                               // dwFileLength
    stream.write("WAVE", 4);                                        // sRiffType

    /* Format Chunk */
    stream.write("fmt ", 4);                                        // sGroupID (fmt = format)
    write<int>(stream, 16);                                         // Chunk size (of Format Chunk)
    write<short>(stream, 3);                                        // Format (1 = PCM)
    write<short>(stream, channels);                                 // Channels
    write<int>(stream, sampleRate);                                 // Sample Rate
    write<int>(stream, sampleRate * channels * sizeof(SampleType)); // Byterate
    write<short>(stream, channels * sizeof(SampleType));            // Frame size aka Block align
    write<short>(stream, 8 * sizeof(SampleType));                   // Bits per sample
}


template <typename SampleType>
void appendWAVData(const char* outFile, SampleType* buf, size_t bufSize)
{

 std::ofstream stream(outFile, std::ios::app | std::ios::binary ); 


  /* Data Chunk */
    stream.write("data", 4);                                        // sGroupID (data)
    stream.write((const char*)&bufSize, 4);                         // Chunk size (of Data, and thus of bufferSize)
    stream.write((const char*)buf, bufSize);                        // The samples DATA!!!
}


template <typename SampleType>
void appendWAVData2(const char* outFile, SampleType* buf, size_t bufSize)
{

 std::ofstream stream(outFile, std::ios::app | std::ios::binary ); 

    stream.write((const char*)buf, bufSize);                        // The samples DATA!!!
}

#endif


