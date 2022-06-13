#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/first-unique-character-in-a-string/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "leetcode";
    CHECK(sol.firstUniqChar(s) == 0);

    s = "loveleetcode";
    CHECK(sol.firstUniqChar(s) == 2);

    s = "aabb";
    CHECK(sol.firstUniqChar(s) == -1);

    s = "ngdvupdfafpemlerwdtpgffhcqntjapfxjibatgriwjacatrqnmrdwistnnrbpxkldwkiluovjxcxuwmbssdqpkknpljdrxgdoghmillwvrcbondjlvffkbhaibdpwaqnpiaukfcmdgjbxrmqawwjnajuvhhfvrksrkfpabsxdgnwgjqfimjoqmjaiewnxstccwgwkalpmbhkenijdalcuxffbagoduductdjkjnegiqtbosedbngiixdilbrkgkskrmineivskgcetagfppcvpvcewfwmqikkrslgrudahtpwmihusbfdnrkvqmnacnnjklclbrppqvcokmggtujrirkmruwwnjdqfaeulhoiuwcfedvljguqthmrcpihavmwaccsaolttnbksukeebhhdkodjufldxamfxmfghnpornwfrgbvlkxckbdjsljhaojmrsuhideeuxbmrjjtovahxeqhdlstrhglxdadlwlfvhsxmsvwixjdbjdnwuwhqtseajiaooejuecwsduhtccnqwlcdieexchgokvildojbiicdcxuguuvemjpkferuuckipodieseejvcxanibwhdnlvttmhorqvxwauppdxlfaippfhqmhcadtwoxnvunxavafpwhoouuvkhjanohbgdpmnqeqfkijlewnohqoxrcatmolojcckmpnjclviqswuvabbdstbsfakoxulkndpmepltftvpcoghojkjfeegwwhtcetxaefshtklqtnfkqhdqvgbjlkfoslfrlxtlntogoxtnvpmkwpionauowqxteoucbotggcjdtcsvrueioqwbjoiuojvhmxwpfrjkwrkfqcihhuefrhfxiixttsnrspnpbimvhajdxhwkgomjghgjdxjlfgsanoqjlsmbhbppgllihtuupvaaclfftdbwgtqxmpcexsdqglxikkfxsuttfllxpbukfomieqviodvghscsxegarsirtxtcprsmcqemsvvuonvjiofogaxjspwmorghmdeefrrdaflhfaurshxephbavmntuhlnnwrcvarfmbnlmdbowgrurjthurnfgrslutrodwocxrghdwniktcwvvvnvnhemiddhreapkqtrutdcdhaovssluqrkrcxwexuajlajvgwbsohippmmubatflnjmhgdmgvvlvpjhiubewtxnffkkibmqgilpnjeagawodtwpowpkmhfdkmcewtahjspcejrbjmvclnsfbsmtodtrvpcnlpfanlhueukhobirxgllqkqaoxrqgiktqwuljtjnwlpcohbaxucwtelqmewqgvuweonrocwgbwijxhocjbobdcmehquauqppprhktighvweedpqfpebrhtfmpurjiiswsomvqorxtbemsaojimjjpguxmjwscnwkeesdfcwhcbijlcsxvtpplvkwhvludodmvfkllnxpsuikwokwniddupwapkipdnjdwqewricgmethlcpialnxrekvepmkqjhinvqthjampitklirspevalmuxwlrfekxtveftwkjsthgrfwqoatsijhwuoanrwapltvngnjeirdnejwmugavhdfouufbggeiqjaotuqdvadqehxeewtofjxfiosmtnurdonjsmousqhhqqajekmzjetkawxajkjemknvetlagrhrsuldprukdlspldedhwuqcooubmpxketphbhstljfegvkjobowhtuojrmjecrgilsrregrbefegsmefojwhhjxephkfufbgpxatkoikwlsclnrcmmwwjhwngtxofeluabuijligfxhsgflvjxgcaftwqigqnxfnuplwbntwljkpvdqfgjqntvnodqxjutpouaaatepbpqeqhaikemjguvforcmlstibrfbtviexqfuvtveerweosokfrnkwaorvjohrabtrajthliumxqpmfqvtlkebmtskglrrnoeowcbfojpjujcaftvjpjhuptsrxmhtcigwcqnhmkwlkdgdswtwukgpswbatqlqrhjjufhfnbikqeldutocmmptduikmithilxauxrybqoxvfidtixvxicomfpujuhqr";
    CHECK(sol.firstUniqChar(s) == 1676);
}
