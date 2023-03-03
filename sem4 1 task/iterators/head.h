template <class Iter, typename T>
int BinSearch(Iter l, Iter r, int a, T arr) {
        auto mid = (l + (r - l) / 2);
        if (*l == a)
            return 0;
        while (1 < r - l) {
            mid = (l + (r - l) / 2);
            if (*mid >= a)
                r = mid;
            else
                l = mid;
            if (*mid == a)
                return mid - arr.begin();
        };

        return -1;
    }

template <class Iter, typename T>
int BinSearchBidirectional(Iter l, Iter r, int a, T arr) {
        auto mid = arr.begin();
        int len = arr.size();
        if (*arr.begin() == a)
            return 0;
        while (len > 0) {
            int i = 0;
            auto mid = l;
            for (i = 0; i < len / 2; ++i, ++mid);
            if (*mid < a) {
                for (i = 0; i < len / 2; ++i, ++l);
                len = len - i;
            }
            else {
                for (i = 0; i < len / 2; ++i, r--);
                len = len - i;
            };

            if (*mid == a) {

                auto fin = arr.begin();
                int i = 0;
                while (*fin != a) {
                    ++fin;
                    i++;
                }
                return i;
            }
            if (len == 1 and *l != a and *r != a)
                return -1;
        }
    }

template <class Iter, typename T>
int BinSearchForward(Iter l, Iter r, int a, T arr) {
        auto mid = arr.begin();
        int len = 1;
        while (l != r) {
            l++;
            len++;
        }
        l = arr.begin();
        int rPos = len - 1;
        if (*arr.begin() == a)
            return 0;
        while (len > 0) {
            int i = 0;

            auto mid = l;

            for (i = 0; i < len / 2; ++i, ++mid);
            if (*mid < a) {
                for (i = 0; i < len / 2; ++i, ++l);
                len = len - i;
            }
            else {
                for (i = 0; i < len / 2; ++i, rPos--);
                r = arr.begin();
                for (int j = 0; j < rPos; ++j, ++r)
                len = len - i;
            };

            if (*mid == a) {

                auto fin = arr.begin();
                int i = 0;
                while (*fin != a) {
                    ++fin;
                    i++;
                }
                return i;
            }
        }
    return -1;
};
