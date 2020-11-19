
#include "../header/myheader.h"

class LT1389
{
public:






// error ....在下标0，0插入后，后续插入1， 会变成 010 的。。
// 不如 map<int. vector<int>>     index: {values} ...  桶排序。
// 后续还有多少 idx <= 自己的 动作。
    vector<int> lt1389a(vector<int>& nums, vector<int>& index)
    {
        int arr[101] = {0};
        for (int i : index)
        {
            arr[i]++;
        }
        #ifdef __test
        for (int i : arr)
            cout<<i<<", ";
        cout<<endl;
        #endif // __test
        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); ++i)
        {
            int n = nums[i];
            int idx = index[i];
            arr[idx]--;
            for (int j = 0, mxj = idx; j <= mxj; ++j)
            {
                idx += arr[j];
            }
            #ifdef __test
            cout<<"  "<<idx<<", "<<n<<endl;
            #endif // __test
            ans[idx] = n;
        }
        return ans;
    }

};

int main()
{
//    vector<int> v1 = {0,1,2,3,4};
//    vector<int> v2 = {0,1,2,2,1};

//    vector<int> v1 = {1,2,3,4,0};
//    vector<int> v2 = {0,1,2,3,0};

//    vector<int> v1 = {1};
//    vector<int> v2 = {0};

    vector<int> v1 = {4,2,4,3,2};           //[2,2,4,4,3]
    vector<int> v2 = {0,0,1,3,1};


    LT1389 lt;

    vector<int> v = lt.lt1389a(v1, v2);

    showVectorInt(v);

    return 0;
}
