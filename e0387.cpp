#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>
#include "hutility.hpp"

using namespace std;

#define DEBUG
#ifdef DEBUG
void LOG() {cout << endl;}
template<typename Head, typename... Args>
void LOG(const Head& head, const Args&... args )
{
    cout << head << " ";
    LOG(args...);
}

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/problems/first-unique-character-in-a-string/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> tmap;

        for (int i = 0; i < s.size(); ++i) {
            if (tmap.count(s[i])) {
                tmap[s[i]] += 1;
            } else {
                tmap[s[i]] = 1;
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            if (tmap[s[i]] == 1) return i;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.firstUniqChar("leetcode"));
    LOG(s.firstUniqChar("loveleetcode"));
    LOG(s.firstUniqChar("ngdvupdfafpemlerwdtpgffhcqntjapfxjibatgriwjacatrqnmrdwistnnrbpxkldwkiluovjxcxuwmbssdqpkknpljdrxgdoghmillwvrcbondjlvffkbhaibdpwaqnpiaukfcmdgjbxrmqawwjnajuvhhfvrksrkfpabsxdgnwgjqfimjoqmjaiewnxstccwgwkalpmbhkenijdalcuxffbagoduductdjkjnegiqtbosedbngiixdilbrkgkskrmineivskgcetagfppcvpvcewfwmqikkrslgrudahtpwmihusbfdnrkvqmnacnnjklclbrppqvcokmggtujrirkmruwwnjdqfaeulhoiuwcfedvljguqthmrcpihavmwaccsaolttnbksukeebhhdkodjufldxamfxmfghnpornwfrgbvlkxckbdjsljhaojmrsuhideeuxbmrjjtovahxeqhdlstrhglxdadlwlfvhsxmsvwixjdbjdnwuwhqtseajiaooejuecwsduhtccnqwlcdieexchgokvildojbiicdcxuguuvemjpkferuuckipodieseejvcxanibwhdnlvttmhorqvxwauppdxlfaippfhqmhcadtwoxnvunxavafpwhoouuvkhjanohbgdpmnqeqfkijlewnohqoxrcatmolojcckmpnjclviqswuvabbdstbsfakoxulkndpmepltftvpcoghojkjfeegwwhtcetxaefshtklqtnfkqhdqvgbjlkfoslfrlxtlntogoxtnvpmkwpionauowqxteoucbotggcjdtcsvrueioqwbjoiuojvhmxwpfrjkwrkfqcihhuefrhfxiixttsnrspnpbimvhajdxhwkgomjghgjdxjlfgsanoqjlsmbhbppgllihtuupvaaclfftdbwgtqxmpcexsdqglxikkfxsuttfllxpbukfomieqviodvghscsxegarsirtxtcprsmcqemsvvuonvjiofogaxjspwmorghmdeefrrdaflhfaurshxephbavmntuhlnnwrcvarfmbnlmdbowgrurjthurnfgrslutrodwocxrghdwniktcwvvvnvnhemiddhreapkqtrutdcdhaovssluqrkrcxwexuajlajvgwbsohippmmubatflnjmhgdmgvvlvpjhiubewtxnffkkibmqgilpnjeagawodtwpowpkmhfdkmcewtahjspcejrbjmvclnsfbsmtodtrvpcnlpfanlhueukhobirxgllqkqaoxrqgiktqwuljtjnwlpcohbaxucwtelqmewqgvuweonrocwgbwijxhocjbobdcmehquauqppprhktighvweedpqfpebrhtfmpurjiiswsomvqorxtbemsaojimjjpguxmjwscnwkeesdfcwhcbijlcsxvtpplvkwhvludodmvfkllnxpsuikwokwniddupwapkipdnjdwqewricgmethlcpialnxrekvepmkqjhinvqthjampitklirspevalmuxwlrfekxtveftwkjsthgrfwqoatsijhwuoanrwapltvngnjeirdnejwmugavhdfouufbggeiqjaotuqdvadqehxeewtofjxfiosmtnurdonjsmousqhhqqajekmzjetkawxajkjemknvetlagrhrsuldprukdlspldedhwuqcooubmpxketphbhstljfegvkjobowhtuojrmjecrgilsrregrbefegsmefojwhhjxephkfufbgpxatkoikwlsclnrcmmwwjhwngtxofeluabuijligfxhsgflvjxgcaftwqigqnxfnuplwbntwljkpvdqfgjqntvnodqxjutpouaaatepbpqeqhaikemjguvforcmlstibrfbtviexqfuvtveerweosokfrnkwaorvjohrabtrajthliumxqpmfqvtlkebmtskglrrnoeowcbfojpjujcaftvjpjhuptsrxmhtcigwcqnhmkwlkdgdswtwukgpswbatqlqrhjjufhfnbikqeldutocmmptduikmithilxauxrybqoxvfidtixvxicomfpujuhqr"));


    return 0;
}
