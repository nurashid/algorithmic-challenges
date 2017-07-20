class Solution {
    bool checkNumber(string::iterator& it, const string::iterator endIt, const int num_allowed_points) {
        int n_dig = 0, n_point = 0;
        if (*it == '+' or *it == '-')
            it++;
        for (;it != endIt; ++it) {
            if (*it == '.') {
                if (++n_point > num_allowed_points)
                    return false;
            } else if (isdigit(*it))
                n_dig++;
            else
                break;

        }
        return n_dig > 0;
    }
    public:
    bool isNumber(string s) {
        auto it = s.begin(), eIt = s.end();
        while (*it == ' ') ++it;
        if (checkNumber(it, eIt, 1) == false)
            return false;
        if (*it == 'e' || *it == 'E')
            if (checkNumber(++it, eIt, 0) == false)
                return false;
        while (*it == ' ') ++it;
        return it == eIt;
    }
};
