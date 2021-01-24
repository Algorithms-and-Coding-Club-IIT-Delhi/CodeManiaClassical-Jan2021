#include "testlib.h"
#include <set>
#include <vector>

using namespace std;

using i32 = int_fast32_t;
using T = i32;
using Coordinates = std::pair<T, T>;
using CoordinatesList = std::vector<Coordinates>;

set<Coordinates> s;
CoordinatesList queries, a;
int n, q;
CoordinatesList jury_answer;

bool dominates(int a, int b, int x, int y) {
    return a >= x && b >= y;
}

void readAns(bool isParticipant, InStream& stream) {

    if (!isParticipant) {
        for (int i = 0; i < q; ++i) {
            int x = stream.readInt();
            if (x == -1) {
                jury_answer.emplace_back(-1, -1);
            } else {
                jury_answer.emplace_back(x, stream.readInt());
            }
        }
        return;
    }

    for (int i = 0; i < q; ++i) {
        
        int x = stream.readInt();
        
        if (x == -1) {
            if (jury_answer[i].first == -1) {
                continue;
            } else {
                stream.quitf(_wa, "jury has an answer");
            }
        }
        
        int y = stream.readInt();
        
        if (s.find(make_pair(x, y)) == s.end()) {
            stream.quitf(_wa, "answer is not in the given list of coordinates");
        }
        
        if (dominates(x, y, queries[i].first, queries[i].second)) {
            continue;
        } else {
            stream.quitf(_wa, "problem condition not satisfied");
        }
    }
}

int main(int argc, char* argv[]) {

    registerTestlibCmd(argc, argv);
    
    n = inf.readInt();
    q = inf.readInt();

    a.resize(n);
    
    for (auto &[x, y] : a) {
        x = inf.readInt();
        y = inf.readInt();
        s.insert(make_pair(x, y));
    }

    queries.resize(q);
    
    for (auto &[x, y] : queries) {
        x = inf.readInt();
        y = inf.readInt();
    }
    
    readAns(false, ans);
    readAns(true, ouf);
    
    quitf(_ok, "correct");
}

