
#include"editDistanceLevenshtein.h"

int editDistanceLevenshtein::calculSimilarite(const std::string& s1, const std::string& s2) const
{
    const std::size_t len1 = s1.size(), len2 = s2.size();
    std::vector<int> col(len2+1), prevCol(len2+1);

    for (int i = 0; i < prevCol.size(); i++)
        prevCol[i] = i;
    for (int i = 0; i < len1; i++)
        {
        col[0] = i+1;
        for (int j = 0; j < len2; j++)
            col[j+1] = std::min(std::min(prevCol[1 + j] + 1, col[j] + 1), prevCol[j] + (s1[i]==s2[j] ? 0 : 1) );
        col.swap(prevCol);
        }
    return prevCol[len2];
}
