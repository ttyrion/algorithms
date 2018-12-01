#include "strfind.h"
#include <string.h>
#include <functional>
#include <iostream>

namespace algorithm {
    namespace find{
        int* kmp_get_next(const char *p) {
            const int pn = strlen(p);
            if(pn <= 0) {
                return nullptr;
            }

            int *next = new int[pn];
            next[0] = -1;
            memset(next+1, 0, sizeof(int)*(pn-1));

            for(int pi = 1; pi < pn; ++pi) {
                int k = next[pi-1];
                while(true) {
                    if (k == -1 || p[k] == p[pi-1]) {
                        next[pi] = k + 1;
                        break;
                    }
                    else {
                        k = next[k];
                    }
                }
            } 

            return next;
        }

        int kmp_find_first_of(const char *str, const char *pattern) {
            const int sn = strlen(str);
            const int pn = strlen(pattern);
            int *next = kmp_get_next(pattern);
            int si = 0;
            for(; si <= sn - pn;) {
                int pi = 0;
                for(; pi < pn;) {
                    if(str[si+pi] != pattern[pi]) {
                        /*Changing pi actually moves si.*/
                        si += pi - next[pi];
                        pi = next[pi];
                        break;
                    }
                    ++pi;
                }

                /* match */
                if (pi == pn) {
                    delete next;
                    return si;
                }
            }

            delete next;
            return -1;
        }
    }
}