
#include "../header/myheader.h"

class LT0368
{
public:


// discuss
//            for (int j = i - 1; j >= 0; j--) {
//                if (nums[i] % nums[j] == 0) {
//                    if (1 + count[j] > count[i]) {
//                        count[i] = count[j] + 1;
//                        pre[i] = j;
//                    }
//                }
//            }
// 向前，保存最大count。保存前一个下标。


// gg...
    // 穷举？穷举得2^sz1。。
    // 排序后并查集。不是并查集，只是归类。不行，key无法确认的。
    // i%j or j%i == 0 , 说明是倍数关系，排序后，挨个计算后续有多少个数是它的倍数，就可以了。需要剔除1..bu,是两两互%为0。
    // 应该递归。
    vector<int> lt0368a(vector<int>& nums)
    {
        int sz1 = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> result;
        if (sz1 == 0)
            return result;
        if (sz1 == 1)           // [200000000000000000000]
        {
            result.push_back(nums[0]);
            return result;
        }
        bool arrb1[sz1] = {};
        int i = nums[0] == 1 ? 1 : 0;
        int max1 = 0;
        int maxi = 0;
        int t1 = 0;
        int t2 = 0;
        int tmax = 0;
        int t3 = 0;
        vector<int> vt;
        stack<int> stk1;
        for (; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                if (nums[j] % nums[i] == 0)
                {
                    vt.clear();
                    vt.push_back(nums[i]);
                    vt.push_back(nums[j]);
                    while (!stk1.empty())
                        stk1.pop();

                    t3 = 2;
                    int k = j + 1;
                    int m = j;
                    while (k < sz1)
                    {
                        bool flag = true;
                        for (int vtn : vt)
                        {
                            if (nums[k] % vtn != 0)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            stk1.push(k);
                            vt.push_back(nums[k]);
                        }
//                        if (nums[k] % nums[j] == 0)
//                        {
//                            t3++;
//                            m = k;
//                        }
                        k++;
                    }
                    if (vt.size() > tmax)
                    {
                        tmax = vt.size();
                        result = vt;
//                        t1 = i;
//                        t2 = j;
                    }

                    #ifdef __test
                    cout<<stk1.size()<<",,,"<<stk1.top();
                    cout<<endl;
                    system("pause");
                    #endif // __test

                    while (!stk1.empty())
                    {
                        int top1 = stk1.top();
                        #ifdef __test
                        cout<<"."<<top1<<endl;
                        #endif // __test
                        stk1.pop();
                        vt.pop_back();
                        top1++;
                        while (top1 < sz1)
                        {
                            bool flag = true;
                            for (int vtn : vt)
                            {
                                if (nums[top1] % vtn != 0)
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                stk1.push(top1);
                                vt.push_back(nums[top1]);
                            }
                            top1++;
                        }
                        if (vt.size() > tmax)
                        {
                            tmax = vt.size();
                            result = vt;
                        }
                    }
                }
            }
        }
//        result = new vector<int>(tmax);
//        if (nums[0] == 1)
//            result.push_back(1);
        if (nums[0] == 1)
        {
            result.insert(result.begin(), 1);
            if (result.size() == 1 && nums.size() > 1)      // [1,2,3]....
            {
                result.push_back(nums[1]);
            }
        }
        if (result.empty())         // [546,669]
        {
            result.push_back(nums[0]);
        }
        return result;
    }
};

int main()
{
//    vector<int> v = {1,2,3,4,8,9};
//    vector<int> v = {1,2,3};

//    vector<int> v = {889,27,652,25,468,164,417,98,163,564,4,287,586,947,138,753,756,105,975,993,203,879,775,
//    764,229,448,132,473,529,751,988,777,992,793,596,155,210,45,318,125,49,956,62,347,93,167,454,549,141,447,
//    103,371,573,866,599,372,349,71,900,451,411,317,579,402,461,175,908,22,219,577,147,619,532,560,976,726,771,
//    876,218,569,979,588,196,186,512,897,609,763,79,926,124,892,452,31,913,608,641,491,971,309,819,48,694,266,999,
//    24,853,220,391,2,351,117,814,721,547,91,438,542,226,185,113,556,676,83,864,846,131,295,539,748,645,915,600,
//    136,134,342,489,601,692,605,766,152,857,959,589,750,291,313,369,404,396,838,436,241,320,730,67,46,19,861,531,
//    360,350,483,52,954,248,457,456,126,398,558,310,688,222,30,443,442,778,633,877,370,952,958,683,898,741,896,780,
//    245,262,503,550,862,359,669,808,795,189,238,966,469,525,426,540,895,460,790,987,355,439,951,183,293,314,211,64,642,
//    267,112,89,701,681,773,922,149,574,352,693,385,680,92,709,470,394,243,762,598,638,428,54,887,477,695,506,135,289,815,
//    85,563,963,9,888,53,624,740,732,715,800,553,43,315,58,742,733,980,779,837,634,275,41,834,197,280,433,249,904,172,981,970,
//    323,885,430,365,199,840,397,292,409,481,102,260,88,524,961,362,603,546,643,731,746,923,994,178,686,326,8,929,725,761,
//    768,176,953,28,629,839,716,799,429,690,344,978,684,723,717,625,42,282,252,329,181,769,504,485,796,484,200,177,128,860,
//    554,32,170,493,304,118,142,937,745,498,810,109,826,
//    165,874,658,361,537,921,749,36,918,319,788,628,373,50,833,216,94,802,339,202,985,237,356,655,724,682,75,500,388,321,
//    308,405,393,482,499,635,973,544,296,884,535,607,977,538,10,384,389,917,957,368,180,425,169,850,816,160,51,264,378,240,
//    268,602,656,697,610,659,919,708,528,253,881,215,392,831,593,17,646,332,159,941,353,859,82,534,29,414,281,813,734,377,
//    567,156,15,400,
//    832,166,718,647,471,380,322,948,797,14,254,399,5,354,872,938,906,305,496,303,34,35,518,673,817,336,557,613,37,421,231,
//    236,424,490,406,146,420,805,572,441,257,445,221,886,198,893,789,341,100,182,505,327,758,960,909,121,122,729,949,209,
//    630,996,711,786,145,650,570,848,759,440,7,153,912,302,450,894,232,791,
//    462,772,217,767,263,543,552,787,408,358,519,755,754,407,565,653,858,699,1000,346,720,566,81,662,674,239,73,60,179,193,
//    111,143,616,760,348,99,792,476,812,871,523,585,357,338,962,882,820,474,555,677,488,561,212,841,69,1,950,250,983,70,234,
//    639,580,794,559,190,945,752,843,935,247,705,328,722,873,863,672,902,637,623,578,453,910,984,844,230,171,823,271,943,928,
//    782,72,376,520,495};

    vector<int> v = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,
    2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

    LT0368 lt;
    vector<int> vv = lt.lt0368a(v);

    cout<<endl;
    for_each(vv.begin(), vv.end(), fun_cout);
    cout<<endl;
    return 0;
}
