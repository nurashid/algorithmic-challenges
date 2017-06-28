class Solution {
    vector<string>array;
    vector<string> result;
    int blanks = 0;

public:
    vector<string> combinationUtil(string digits, int index, int dIndex, int aIndex, string &output)
    {
        if (index == digits.size()-blanks) {
            result.push_back(output);
            return result;
        }
        int num = digits[dIndex] - '0';

        for (int i = 0; i < array[num-2].size(); i++) {
            output[index] = array[num-2][i];
            combinationUtil(digits, index+1, dIndex+1, i, output);
        }

        return result;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> lmap;
        lmap["0"] = "";
        lmap["2"] = "abc";
        lmap["3"] = "def";
        lmap["4"] = "ghi";
        lmap["5"] = "jkl";
        lmap["6"] = "mno";
        lmap["7"] = "pqrs";
        lmap["8"] = "tuv";
        lmap["9"] = "wxyz";

        vector<string> result;

        for (auto digit : digits) {
            vector<string> tresult;
            if (result.size() == 0) {
                for (auto e : lmap[digit])
                    result.emplace_back(e)
            } else {
                for (auto res : result)
                    for (auto e : lmap[digit])
                        tresult.emplace_back(res + e)

            }
            tresult.swap(result);
        }
        return result;
    }
    vector<string> letterCombinations(string digits) {


        string output;
        output.resize(digits.size());
        if (digits.size() == 0)
            return result;

        for (auto a : digits) {
            if (a == '1' || a == '0')
                return result;
        }
        combinationUtil(digits, 0, 0, 0 , output);

        return result;
    }
};
