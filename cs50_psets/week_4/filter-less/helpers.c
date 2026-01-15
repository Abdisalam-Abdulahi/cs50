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
            float sopiaRed = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) +
                             (0.189 * image[i][j].rgbtBlue);
            float sopiaGreen = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) +
                               (0.168 * image[i][j].rgbtBlue);
            float sopiaBlue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) +
                              (0.131 * image[i][j].rgbtBlue);
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
    for (int i = 0; i < height; i++)
    {
        int t_width = width - 1;
        for (int j = 0; j < width; j++)
        {
            if (j >= (width / 2))
            {
                break;
            }
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][t_width];
            image[i][t_width] = temp;
            t_width--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float div = 0;
            float avrgRed = copy[i][j].rgbtRed;
            float avrgBlue = copy[i][j].rgbtBlue;
            float avrgGreen = copy[i][j].rgbtGreen;
            div++;
            if (j != (width - 1))
            {
                avrgRed += copy[i][j + 1].rgbtRed;
                avrgBlue += copy[i][j + 1].rgbtBlue;
                avrgGreen += copy[i][j + 1].rgbtGreen;
                div++;
            }
            if (j != 0)
            {
                avrgRed += copy[i][j - 1].rgbtRed;
                avrgBlue += copy[i][j - 1].rgbtBlue;
                avrgGreen += copy[i][j - 1].rgbtGreen;
                div++;                
            }
            if (i != 0)
            {
                avrgRed += copy[i - 1][j].rgbtRed;
                avrgBlue += copy[i - 1][j].rgbtBlue;
                avrgGreen += copy[i - 1][j].rgbtGreen;
                div++;                
            }
            if (i != 0 && j != 0)
            {
                avrgRed += copy[i - 1][j - 1].rgbtRed;
                avrgBlue += copy[i - 1][j - 1].rgbtBlue;
                avrgGreen += copy[i - 1][j - 1].rgbtGreen;
                div++;                
            }
            if (i != 0 && j != (width - 1))
            {
                avrgRed += copy[i - 1][j + 1].rgbtRed;
                avrgBlue += copy[i - 1][j + 1].rgbtBlue;
                avrgGreen += copy[i - 1][j + 1].rgbtGreen;
                div++;                
            }
            if (i != (height - 1))
            {
                avrgRed += copy[i + 1][j].rgbtRed;
                avrgBlue += copy[i + 1][j].rgbtBlue;
                avrgGreen += copy[i + 1][j].rgbtGreen;
                div++;                 
            }
            if (i != (height - 1) && j != 0)
            {
                avrgRed += copy[i + 1][j - 1].rgbtRed;
                avrgBlue += copy[i + 1][j - 1].rgbtBlue;
                avrgGreen += copy[i + 1][j - 1].rgbtGreen;
                div++;                
            }
            if (i != (height - 1) && j != (width - 1))
            {
                avrgRed += copy[i + 1][j + 1].rgbtRed;
                avrgBlue += copy[i + 1][j + 1].rgbtBlue;
                avrgGreen += copy[i + 1][j + 1].rgbtGreen;
                div++;
            }
            avrgRed = avrgRed / div;
            avrgBlue = avrgBlue / div;
            avrgGreen = avrgGreen / div;

            avrgRed = round(avrgRed);
            avrgBlue = round(avrgBlue);
            avrgGreen = round(avrgGreen);

            image[i][j].rgbtRed = avrgRed;
            image[i][j].rgbtBlue = avrgBlue;
            image[i][j].rgbtGreen = avrgGreen;
        }
    }
    return;
}

void check(float *sophiaColor)
{
    if (*sophiaColor > 255)
    {
        *sophiaColor = 255;
    }
}