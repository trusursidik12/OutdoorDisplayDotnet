using System;
using System.IO;
using System.Runtime.InteropServices;

namespace OutdoorDisplay
{
    class Program
    {
        static void Main(string[] args)
        {
            string strParams = "192.168.2.200";
            IntPtr m_pSendParams = Marshal.StringToHGlobalUni(strParams);
            IntPtr pNULL = new IntPtr(0);
            IntPtr pPaths;
            IntPtr pText;
            IntPtr pFontName = Marshal.StringToHGlobalUni("Arial");
            int color_red = CSDKExport.Hd_GetColor(255, 0 , 0);
            int color_green = CSDKExport.Hd_GetColor(0, 255, 0);
            int color_yellow = CSDKExport.Hd_GetColor(255, 255, 0);
            int color_black = CSDKExport.Hd_GetColor(0, 0, 0);
            int screenWidth = 0;
            int screenHeight = 0;
            int screenColor = 0;
            int areaX = 0;
            int areaY = 0;
            int areaWidth = 0;
            int areaHeight = 0;

            int nShowMode = 0;
            int bShowDate = 0;
            int nDateStyle = 0;
            int bShowWeek = 0;
            int nWeekStyle = 0;
            int bShowTime = 0;
            int nTimeStyle = 0;
            int nTextColor = 0;
            int nFontHeight = 0;
            int nShowEffect = 0;
            int nShowSpeed = 0;
            int nClearType = 0;
            int nStayTime = 0;
            int nTextStyle = 0;

            int[] nAreaID = new int[100];
            string datatxt = File.ReadAllText("data.txt");
            string[] data = new String[100];
            if (datatxt.Contains("]]]"))
            {
                data = datatxt.Split("]]]");

                CSDKExport.Cmd_AdjustTime(0, m_pSendParams, pNULL);

                screenWidth = Int16.Parse(data[0].Split("|||")[0]);
                screenHeight = Int16.Parse(data[0].Split("|||")[1]);
                screenColor = Int16.Parse(data[0].Split("|||")[2]);//0 single color, 1 dual color, 2 tricolor.

                Console.WriteLine("Screen : ");
                Console.WriteLine("=========");
                Console.WriteLine("\tWidth\t: " + screenWidth);
                Console.WriteLine("\tHeight\t: " + screenHeight);
                Console.WriteLine("\tColor Type\t: " + screenColor);
                CSDKExport.Hd_CreateScreen(screenWidth, screenHeight, screenColor, 1, 0, pNULL, 0);
                int nProgramID = CSDKExport.Hd_AddProgram(pNULL, 0, 0, pNULL, 0);

                for (int xx = 1; xx < data.Length; xx++)
                {
                    if (data[xx].Contains("|||"))
                    {
                        areaX = Int16.Parse(data[xx].Split("|||")[0]);
                        areaY = Int16.Parse(data[xx].Split("|||")[1]);
                        areaWidth = Int16.Parse(data[xx].Split("|||")[2]);
                        areaHeight = Int16.Parse(data[xx].Split("|||")[3]);
                        nAreaID[xx] = CSDKExport.Hd_AddArea(nProgramID, areaX, areaY, areaWidth, areaHeight, pNULL, 0, 0, pNULL, 0);
                        Console.WriteLine("\n\tArea : ");
                        Console.WriteLine("\t=========");
                        Console.WriteLine("\t\tX\t: " + areaX);
                        Console.WriteLine("\t\tY\t: " + areaY);
                        Console.WriteLine("\t\tWidth\t: " + areaWidth);
                        Console.WriteLine("\t\tHeight\t: " + areaHeight);
                        if (data[xx].Split("|||")[4] == "time")
                        {
                            nShowMode = Int16.Parse(data[xx].Split("|||")[5]);
                            bShowDate = Int16.Parse(data[xx].Split("|||")[6]);
                            nDateStyle = Int16.Parse(data[xx].Split("|||")[7]);
                            bShowWeek = Int16.Parse(data[xx].Split("|||")[8]);
                            nWeekStyle = Int16.Parse(data[xx].Split("|||")[9]);
                            bShowTime = Int16.Parse(data[xx].Split("|||")[10]);
                            nTimeStyle = Int16.Parse(data[xx].Split("|||")[11]);
                            if (data[xx].Split("|||")[12] == "color_red") nTextColor = color_red;
                            if (data[xx].Split("|||")[12] == "color_green") nTextColor = color_green;
                            if (data[xx].Split("|||")[12] == "color_yellow") nTextColor = color_yellow;
                            if (data[xx].Split("|||")[12] == "color_black") nTextColor = color_black;
                            pFontName = Marshal.StringToHGlobalUni(data[xx].Split("|||")[13]);
                            nFontHeight = Int16.Parse(data[xx].Split("|||")[14]);
                            CSDKExport.Hd_AddTimeAreaItem(nAreaID[xx], nShowMode, bShowDate, nDateStyle, bShowWeek, nWeekStyle, bShowTime, nTimeStyle, nTextColor, pFontName, nFontHeight, 0, 0, pNULL, 0);
                            Console.WriteLine("\t\tMode\t: Time");
                            Console.WriteLine("\t\tColor\t: " + data[xx].Split("|||")[12]);
                        }
                        if (data[xx].Split("|||")[4] == "image")
                        {
                            pPaths = Marshal.StringToHGlobalUni(data[xx].Split("|||")[5]);
                            nShowEffect = Int16.Parse(data[xx].Split("|||")[6]);
                            nShowSpeed = Int16.Parse(data[xx].Split("|||")[7]);
                            nClearType = Int16.Parse(data[xx].Split("|||")[8]);
                            nStayTime = Int16.Parse(data[xx].Split("|||")[9]);
                            CSDKExport.Hd_AddImageAreaItem(nAreaID[xx], pPaths, nShowEffect, nShowSpeed, nClearType, nStayTime, pNULL, 0);
                            Console.WriteLine("\t\tMode\t: Image");
                            Console.WriteLine("\t\tPath\t: " + data[xx].Split("|||")[5]);
                        }
                        if (data[xx].Split("|||")[4] == "text")
                        {
                            pText = Marshal.StringToHGlobalUni(data[xx].Split("|||")[5]);
                            if (data[xx].Split("|||")[6] == "color_red") nTextColor = color_red;
                            if (data[xx].Split("|||")[6] == "color_green") nTextColor = color_green;
                            if (data[xx].Split("|||")[6] == "color_yellow") nTextColor = color_yellow;
                            if (data[xx].Split("|||")[6] == "color_black") nTextColor = color_black;
                            nTextStyle = Int16.Parse(data[xx].Split("|||")[7].Split("|")[0]);
                            for (int y=1; y < data[xx].Split("|||")[7].Split("|").Length; y++)
                            {
                                nTextStyle = nTextStyle | Int16.Parse(data[xx].Split("|||")[7].Split("|")[y]);
                            }
                            pFontName = Marshal.StringToHGlobalUni(data[xx].Split("|||")[8]);
                            nFontHeight = Int16.Parse(data[xx].Split("|||")[9]);
                            nShowEffect = Int16.Parse(data[xx].Split("|||")[10]);
                            nShowSpeed = Int16.Parse(data[xx].Split("|||")[11]);
                            CSDKExport.Hd_AddSimpleTextAreaItem(nAreaID[xx], pText, nTextColor, 0, nTextStyle, pFontName, nFontHeight, nShowEffect, nShowSpeed, 201, 3, pNULL, 0);
                            Console.WriteLine("\t\tMode\t: Text");
                            Console.WriteLine("\t\tTextStyle\t: " + nTextStyle);
                        }
                    }
                }

                CSDKExport.Hd_SendScreen(0, m_pSendParams, pNULL, pNULL, 0);
            }
        }
    }
}
