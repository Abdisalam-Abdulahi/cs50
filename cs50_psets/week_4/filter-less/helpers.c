#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void check(float *sophiaColor);
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           float avrg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
           avrg = round(avrg);
           image[i][j].rgbtBlue = avrg;
           image[i][j].rgbtGreen = avrg;
           image[i][j].rgbtRed = avrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sopiaRed = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);
            float sopiaGreen = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            float sopiaBlue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);
            sopiaRed = round(sopiaRed);
            sopiaBlue = round(sopiaBlue);
            sopiaGreen = round(sopiaGreen);

            check(&sopiaRed);
            check(&sopiaBlue);
            check(&sopiaGreen);

            image[i][j].rgbtBlue = sopiaBlue;
           image[i][j].rgbtGreen = sopiaGreen;
           image[i][j].rgbtRed = sopiaRed;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

void check(float *sophiaColor)
{
    if (*sophiaColor > 255)
    {
        *sophiaColor = 255;
    }
}