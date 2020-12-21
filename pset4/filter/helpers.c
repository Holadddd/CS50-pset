#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //take each rows
    for (int i = 0; i < height; i++)
    {
        //take each pixel
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE tmpPixel = image[i][j];
            int avgValue = (tmpPixel.rgbtBlue + tmpPixel.rgbtGreen + tmpPixel.rgbtRed) / 3;
            image[i][j].rgbtBlue = avgValue;
            image[i][j].rgbtGreen = avgValue;
            image[i][j].rgbtRed = avgValue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //take each rows
    for (int i = 0; i < height; i++)
    {
        //take each pixel
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE tmpPixel = image[i][j];
            int tmpRed = .393 * tmpPixel.rgbtRed + .769 * tmpPixel.rgbtGreen + .189 * tmpPixel.rgbtBlue;
            int tmpGreen = .349 * tmpPixel.rgbtRed + .686 * tmpPixel.rgbtGreen + .168 * tmpPixel.rgbtBlue;
            int tmpBlue = .272 * tmpPixel.rgbtRed + .534 * tmpPixel.rgbtGreen + .131 * tmpPixel.rgbtBlue;
            image[i][j].rgbtBlue = tmpBlue <= 0xff ? tmpBlue : 0xff;
            image[i][j].rgbtGreen = tmpGreen <= 0xff ? tmpGreen : 0xff;
            image[i][j].rgbtRed = tmpRed <= 0xff ? tmpRed : 0xff;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //take each rows
    for (int i = 0; i < height; i++)
    {
        //take each pixel
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE tmpLeadPixel = image[i][j];
            RGBTRIPLE tmpTrailPixel = image[i][width - 1 - j];
            image[i][j] = tmpTrailPixel;
            image[i][width - j] = tmpLeadPixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImage[height][width];
    //take each rows
    for (int i = 0; i < height; i++)
    {
        //take each pixel
        for (int j = 0; j < width; j++)
        {
            int tmpRedAmount = 0;
            int tmpGreenAmount = 0;
            int tmpBlueAmount = 0;
            int pixelNeighboringCount = 0;
            //take row neighboring pixels
            for (int x = -1; x < 2; x++)
            {
                //Check available pixel
                if (((i + x) < 0) || ((i + x) > (height - 1)))
                {
                    continue;
                }
                for (int y = -1; y < 2; y++)
                {
                    //Check available pixel
                    if (((j + y) < 0) || ((j + y) > (width - 1)))
                    {
                        continue;
                    }
                    //Get available pixel
                    pixelNeighboringCount += 1;
                    RGBTRIPLE tmpPixel = image[i + x][j + y];
                    tmpRedAmount += tmpPixel.rgbtRed;
                    tmpGreenAmount += tmpPixel.rgbtGreen;
                    tmpBlueAmount += tmpPixel.rgbtBlue;
                }

            }
            //Store in the tmpImage
            tmpImage[i][j].rgbtBlue = (tmpBlueAmount / pixelNeighboringCount);
            tmpImage[i][j].rgbtGreen = (tmpGreenAmount / pixelNeighboringCount);
            tmpImage[i][j].rgbtRed = (tmpRedAmount / pixelNeighboringCount);
        }
    }
    //Update original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <width; j++)
        {
            image[i][j].rgbtRed = tmpImage[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmpImage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmpImage[i][j].rgbtBlue;
        }
    }
    return;
}
