static volatile int expected[16][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {120, 136, 152, 168, 184, 200, 216, 232, 248, 264, 280, 296, 312, 328, 344, 360},
    {240, 272, 304, 336, 368, 400, 432, 464, 496, 528, 560, 592, 624, 656, 688, 720},
    {360, 408, 456, 504, 552, 600, 648, 696, 744, 792, 840, 888, 936, 984, 1032, 1080},
    {480, 544, 608, 672, 736, 800, 864, 928, 992, 1056, 1120, 1184, 1248, 1312, 1376, 1440},
    {600, 680, 760, 840, 920, 1000, 1080, 1160, 1240, 1320, 1400, 1480, 1560, 1640, 1720, 1800},
    {720, 816, 912, 1008, 1104, 1200, 1296, 1392, 1488, 1584, 1680, 1776, 1872, 1968, 2064, 2160},
    {840, 952, 1064, 1176, 1288, 1400, 1512, 1624, 1736, 1848, 1960, 2072, 2184, 2296, 2408, 2520},
    {960, 1088, 1216, 1344, 1472, 1600, 1728, 1856, 1984, 2112, 2240, 2368, 2496, 2624, 2752, 2880},
    {1080, 1224, 1368, 1512, 1656, 1800, 1944, 2088, 2232, 2376, 2520, 2664, 2808, 2952, 3096, 3240},
    {1200, 1360, 1520, 1680, 1840, 2000, 2160, 2320, 2480, 2640, 2800, 2960, 3120, 3280, 3440, 3600},
    {1320, 1496, 1672, 1848, 2024, 2200, 2376, 2552, 2728, 2904, 3080, 3256, 3432, 3608, 3784, 3960},
    {1440, 1632, 1824, 2016, 2208, 2400, 2592, 2784, 2976, 3168, 3360, 3552, 3744, 3936, 4128, 4320},
    {1560, 1768, 1976, 2184, 2392, 2600, 2808, 3016, 3224, 3432, 3640, 3848, 4056, 4264, 4472, 4680},
    {1680, 1904, 2128, 2352, 2576, 2800, 3024, 3248, 3472, 3696, 3920, 4144, 4368, 4592, 4816, 5040},
    {1800, 2040, 2280, 2520, 2760, 3000, 3240, 3480, 3720, 3960, 4200, 4440, 4680, 4920, 5160, 5400},
};

static volatile int flag = 0;
static volatile int c[16][16];
int exit(int c);
//  = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}, {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12}, {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13}, {14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14}, {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15}};

static volatile int a[16][16];
//  = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}, {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12}, {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13}, {14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14}, {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15}};
static volatile int b[16][16];
//  = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}, {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}, {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}, {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}, {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}, {7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22}, {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}, {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}, {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26}, {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27}, {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28}, {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}};

// static volatile int d = 0;


int multiply(int x, int y)
{
    int ret = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((y >> i) & 1) == 1)
        {
            ret += (x << i);
        }
    }
    return ret;
}

int arrEquals(volatile int a[16][16], volatile int b[16][16])
{
    // int a[16][16] = expected;
    // volatile int b[16][16]
    // int b[16][16] = c;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            putchar(a[i][j]);
            putchar(b[i][j]);
            if (a[i][j] != b[i][j])
            {
             
                // putchar(i);
                // putchar(j);
                // putchar('\n');
                return 0;
            }
        }
    }

    // putchar('\n');
    // putchar(d);
    // putchar('\n');
    return 1;
}

// int expected[16][16];

void program_thread0(){

    int sum;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            sum = 0;
            for (int k = 0; k < 16; k++)
            {
                sum += multiply(a[i][k], b[k][j]);
            }
            c[i][j] = sum;
            // putchar('0');
            putchar(sum);
            // putchar('\n');
        }
    }

    // putchar('A');
    // putchar(flag);
    // putchar('\n');
    while (flag == 0); // Wait until thread1 produced the value
    // putchar('F');
    // putchar('\n');
    // arrEquals(expected, c);
    if (arrEquals(expected, c))
    {
        exit(0);
    }
    else
    {
        exit(1);
    }

}


void program_thread1(){
    int sum;
    for (int i = 8; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            sum = 0;
            for (int k = 0; k < 16; k++)
            {
                // sum += 1;
                sum += multiply(a[i][k], b[k][j]);
            }
            c[i][j] = sum;
            // putchar('1');
            putchar(sum);
            // putchar('\n');
        }
    }
    // d = 15;

    // arrEquals(expected, c);

    // mostly since the C compiler is too smart to do flag = 1 or something
    int l = 0;
    for (int i = 0; i < 4; i++){
        l += i;
    }
    flag = l;
    // putchar('W');
    // putchar(flag); 
    // putchar('\n');
    while(1);
}


// int expected[16][16];
int main(int th)
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            a[i][j] = i;
            b[i][j] = i + j;
        }
    }
    // int** ptr;
    // //  = (int**)((int)c);
    // for (int i = 0; i < 16; i++)
    // {
    //     int x[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //     *ptr[i] = x;
    // }
    // **ptr = c;
    if (th == 0) {
        program_thread0();
    } else
    {
        program_thread1();
    }

    // if (arrEquals(expected, c))
    // {
    //     exit(0);
    // }
    // else
    // {
    //     exit(1);
    // }
    // return 0;
}
