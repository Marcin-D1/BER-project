#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct FileHeader {
    short signature;
    int fileSize;
    short reserved1;
    short reserved2;
    int fileOffset;
} FileHeader;

struct PictureHeader {
    int pictureSize;
    int width;
    int height;
    short planes;
    short bitsPerPixel;
    int comporession;
    int imgeSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    int ColorsInColorTable;
    int importantColorCount;
} PictureHeader;

int main(int arc, char * argv[]) {

    FILE* bmpFile = fopen("test.bmp", "rb");

    printf("\nMETADATA\n");

    fread(&FileHeader.signature, sizeof(FileHeader.signature), 1, bmpFile);
    printf("\nSignature: %x", FileHeader.signature);

    fread(&FileHeader.fileSize, sizeof(FileHeader.fileSize), 1, bmpFile);
    printf("\n File size (bytes): %d ", FileHeader.fileSize);

    fread(&FileHeader.reserved1, sizeof(FileHeader.reserved1), 1, bmpFile);
    printf("\n Reserved 1: %d", FileHeader.reserved1);

    fread(&FileHeader.reserved2, sizeof(FileHeader.reserved2), 1, bmpFile);
    printf("\n Reserved 2: %d", FileHeader.reserved2);

    fread(&FileHeader.fileOffset, sizeof(FileHeader.fileOffset), 1, bmpFile);
    printf("\n File offset to PixelArray: %d", FileHeader.fileOffset);

    fseek(bmpFile, 14, SEEK_SET);
    fread(&PictureHeader.pictureSize, sizeof(PictureHeader.pictureSize), 1, bmpFile);
    printf("\n DIB Header Size: %d", PictureHeader.pictureSize);

    fread(&PictureHeader.width, sizeof(PictureHeader.width), 1, bmpFile);
    printf("\n Width (pixels): %d", PictureHeader.width);

    fread(&PictureHeader.height, sizeof(PictureHeader.height), 1, bmpFile);
    printf("\n Height (pixels): %d", PictureHeader.height);

    fread(&PictureHeader.planes, sizeof(PictureHeader.planes), 1, bmpFile);
    printf("\n Planes:: %d", PictureHeader.planes);

    fread(&PictureHeader.bitsPerPixel, sizeof(PictureHeader.bitsPerPixel), 1, bmpFile);
    printf("\n Bits per pixel: %d ", PictureHeader.bitsPerPixel);

    fread(&PictureHeader.comporession, sizeof(PictureHeader.comporession), 1, bmpFile);
    printf("\n Compression type: %d", PictureHeader.comporession);

    fread(&PictureHeader.imgeSize, sizeof(PictureHeader.imgeSize), 1, bmpFile);
    printf("\n Image size: %d", PictureHeader.imgeSize);

    fread(&PictureHeader.xPixelsPerMeter, sizeof(PictureHeader.xPixelsPerMeter), 1, bmpFile);
    printf("\n X Pixels per meter: %d", PictureHeader.xPixelsPerMeter);

    fread(&PictureHeader.yPixelsPerMeter, sizeof(PictureHeader.yPixelsPerMeter), 1, bmpFile);
    printf("\n Y Pixels per meter: %d", PictureHeader.yPixelsPerMeter);

    fread(&PictureHeader.ColorsInColorTable, sizeof(PictureHeader.ColorsInColorTable), 1, bmpFile);
    printf("\n Colors in color table: %d", PictureHeader.ColorsInColorTable);

    fread(&PictureHeader.importantColorCount, sizeof(PictureHeader.importantColorCount), 1, bmpFile);
    printf("\n Important colors count: %d", PictureHeader.importantColorCount);

}
